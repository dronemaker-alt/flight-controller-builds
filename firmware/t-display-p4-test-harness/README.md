# T-Display P4 reusable test harness

PlatformIO/ESP-IDF firmware for issue #2. It initializes the LilyGo MIPI display, runs LVGL 9, converts the onboard ESP32-P4 BOOT button into navigation actions, and renders a small status UI whose data boundary is ready for later telemetry.

## Build and flash

Requirements: VS Code with PlatformIO, Git, and a data-capable USB cable.

```sh
pio run -e t_display_p4_tft
pio run -e t_display_p4_tft -t upload
pio device monitor
```

The first build clones LilyGo's current T-Display-P4 tree and its driver submodules into `.pio/vendor`; that directory is generated and should not be committed. The environment targets ESP32-P4 and ESP-IDF 5.5.4 or newer because that is the minimum supported path for the current LilyGo driver.

If upload does not start, hold the P4 `BOOT` button until the transfer begins. The application uses that same active-low GPIO 35 button after boot:

- short press: next page
- hold for 700 ms: select/test action

## Reusable structure

```text
src/main.cpp        application wiring and demo status producer
src/board_port.*    LilyGo driver, MIPI flush, LVGL timing, button input
src/ui.*            pages, navigation, and telemetry-neutral StatusModel
```

Telemetry code should update `StatusModel` from its own task and call `ui::Update()` while holding the UI lock. Do not put MAVLink parsing, radio code, or sensor reads inside `ui.cpp`; the model is deliberately the seam between data acquisition and presentation.

## Bench acceptance check

Successful bring-up shows `DISPLAY OK`, increments uptime once per second, cycles through three pages on short presses, and increments the packet/test counter after a long press. Serial output begins with `starting display test harness` at 115200 baud.

The default environment selects the 4.05-inch HI8561 TFT. For the 4.1-inch RM69A10 AMOLED, substitute `-e t_display_p4_amoled`. Both select RGB565 to limit draw-buffer bandwidth and use a partial 80-line PSRAM buffer.
