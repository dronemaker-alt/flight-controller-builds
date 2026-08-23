#include "board_port.h"

#include <cassert>
#include <memory>
#include <utility>

#include "driver/gpio.h"
#include "esp_heap_caps.h"
#include "esp_lcd_panel_ops.h"
#include "esp_lcd_mipi_dsi.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/semphr.h"
#include "freertos/task.h"
#include "lilygo_device_driver_library.h"
#include "lvgl.h"

namespace harness::board {
namespace {
namespace p4 = lilygo_device_driver::t_display_p4;
constexpr uint32_t kTickMs = 1;
constexpr uint32_t kDebounceMs = 30;
constexpr uint32_t kLongPressMs = 700;
SemaphoreHandle_t ui_mutex = nullptr;

#if defined(CONFIG_SCREEN_TYPE_HI8561)
cpp_bus_driver::Hi8561* screen = nullptr;
constexpr int kWidth = p4::device::hi8561::kScreenWidth;
constexpr int kHeight = p4::device::hi8561::kScreenHeight;
#elif defined(CONFIG_SCREEN_TYPE_RM69A10)
cpp_bus_driver::Rm69a10* screen = nullptr;
constexpr int kWidth = p4::device::rm69a10::kScreenWidth;
constexpr int kHeight = p4::device::rm69a10::kScreenHeight;
#else
#error "T-Display-P4 screen type was not selected by the LilyGo driver"
#endif

void UiLoop(void*) {
  while (true) {
    if (xSemaphoreTake(ui_mutex, pdMS_TO_TICKS(50)) == pdTRUE) {
      const uint32_t wait = lv_timer_handler();
      xSemaphoreGive(ui_mutex);
      vTaskDelay(pdMS_TO_TICKS(wait < 2 ? 2 : (wait > 20 ? 20 : wait)));
    }
  }
}

void ButtonLoop(void* context) {
  std::unique_ptr<ActionHandler> handler(static_cast<ActionHandler*>(context));
  bool was_down = false;
  int64_t down_at = 0;
  while (true) {
    const bool down = gpio_get_level(static_cast<gpio_num_t>(p4::gpio::button::kEsp32p4Boot)) == 0;
    const int64_t now = esp_timer_get_time() / 1000;
    if (down && !was_down) down_at = now;
    if (!down && was_down && (now - down_at) >= kDebounceMs) {
      const auto action = (now - down_at) >= kLongPressMs
                              ? ui::Action::kSelect
                              : ui::Action::kNext;
      LockUi();
      (*handler)(action);
      UnlockUi();
    }
    was_down = down;
    vTaskDelay(pdMS_TO_TICKS(10));
  }
}
}  // namespace

void LockUi() { xSemaphoreTake(ui_mutex, portMAX_DELAY); }
void UnlockUi() { xSemaphoreGive(ui_mutex); }

bool InitDisplay() {
  ui_mutex = xSemaphoreCreateMutex();
  if (!ui_mutex) return false;

  auto& driver = lilygo_device_driver::TDisplayP4Driver::GetInstance();
  if (!driver.Init(lilygo_device_driver::TDisplayP4Driver::InitMode::kSync)) return false;

#if defined(CONFIG_SCREEN_TYPE_HI8561)
  screen = driver.chip().hi8561.get();
#else
  screen = driver.chip().rm69a10.get();
#endif
  if (!screen) return false;

  lv_init();
  lv_display_t* display = lv_display_create(kWidth, kHeight);
  lv_display_set_user_data(display, screen);
  lv_display_set_color_format(display, LV_COLOR_FORMAT_RGB565);

  const size_t bytes = static_cast<size_t>(kWidth) * 80 * sizeof(lv_color_t);
  void* buffer = heap_caps_malloc(bytes, MALLOC_CAP_SPIRAM | MALLOC_CAP_8BIT | MALLOC_CAP_DMA);
  assert(buffer);
  lv_display_set_buffers(display, buffer, nullptr, bytes, LV_DISPLAY_RENDER_MODE_PARTIAL);

  lv_display_set_flush_cb(display, [](lv_display_t* disp, const lv_area_t* area, uint8_t* pixels) {
#if defined(CONFIG_SCREEN_TYPE_HI8561)
    auto* panel = static_cast<cpp_bus_driver::Hi8561*>(lv_display_get_user_data(disp));
#else
    auto* panel = static_cast<cpp_bus_driver::Rm69a10*>(lv_display_get_user_data(disp));
#endif
    panel->SendColorStreamCoordinate(area->x1, area->y1, area->x2 + 1, area->y2 + 1, pixels);
  });

  esp_lcd_dpi_panel_event_callbacks_t callbacks = {};
  callbacks.on_color_trans_done = [](esp_lcd_panel_handle_t, esp_lcd_dpi_panel_event_data_t*, void* ctx) {
    lv_display_flush_ready(static_cast<lv_display_t*>(ctx));
    return false;
  };
  ESP_ERROR_CHECK(esp_lcd_dpi_panel_register_event_callbacks(
      driver.bus().screen_mipi_bus->device_handle(), &callbacks, display));

  const esp_timer_create_args_t tick_args = {
      .callback = [](void*) { lv_tick_inc(kTickMs); }, .arg = nullptr,
      .dispatch_method = ESP_TIMER_TASK, .name = "lv_tick", .skip_unhandled_events = true};
  esp_timer_handle_t tick_timer = nullptr;
  ESP_ERROR_CHECK(esp_timer_create(&tick_args, &tick_timer));
  ESP_ERROR_CHECK(esp_timer_start_periodic(tick_timer, kTickMs * 1000));

  gpio_config_t button = {};
  button.pin_bit_mask = 1ULL << p4::gpio::button::kEsp32p4Boot;
  button.mode = GPIO_MODE_INPUT;
  button.pull_up_en = GPIO_PULLUP_ENABLE;
  button.pull_down_en = GPIO_PULLDOWN_DISABLE;
  button.intr_type = GPIO_INTR_DISABLE;
  ESP_ERROR_CHECK(gpio_config(&button));
  return true;
}

void StartUiTask() { xTaskCreate(UiLoop, "ui", 8192, nullptr, 3, nullptr); }

void StartButtonTask(ActionHandler handler) {
  xTaskCreate(ButtonLoop, "button", 4096, new ActionHandler(std::move(handler)), 2, nullptr);
}

}  // namespace harness::board
