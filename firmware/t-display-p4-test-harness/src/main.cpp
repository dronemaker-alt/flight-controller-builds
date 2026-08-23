#include "board_port.h"
#include "ui.h"

#include "esp_log.h"
#include "esp_timer.h"
#include "freertos/FreeRTOS.h"
#include "freertos/task.h"

namespace {
constexpr const char* kTag = "p4-harness";
}

extern "C" void app_main() {
  ESP_LOGI(kTag, "starting display test harness");
  if (!harness::board::InitDisplay()) {
    ESP_LOGE(kTag, "display initialization failed");
    return;
  }

  harness::board::LockUi();
  harness::ui::Init();
  harness::board::UnlockUi();
  harness::board::StartUiTask();
  harness::board::StartButtonTask(harness::ui::Handle);

  harness::ui::StatusModel status;
  status.link = "DISPLAY OK";
  status.supply_volts = 5.0F;
  while (true) {
    status.uptime_seconds = esp_timer_get_time() / 1000000ULL;
    harness::board::LockUi();
    harness::ui::Update(status);
    harness::board::UnlockUi();
    vTaskDelay(pdMS_TO_TICKS(1000));
  }
}

