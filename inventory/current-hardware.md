# Current hardware register

Canonical engineering inventory for this repository. See
[README.md](README.md) for field definitions, status vocabulary, storage codes,
and the update workflow.

All locations, quantities, and condition claims that have not been physically
verified are intentionally marked `TBD`.

## Flight-control and processor hardware

| ID | Item / variant | Qty (total / available / reserved) | Storage | Status | Firmware compatibility | Procurement | Related work | Verified |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| FC-GD32-001 | GD32F405 MCU chips | TBD / TBD / TBD | TBD | untested | Custom target required; not yet verified | Source, date, cost, and reorder part number TBD | [GD32F405 notes](../hardware/gd32f405/README.md) · [bring-up log](../docs/bring-up-log.md) | TBD |
| FC-K66-001 | NXP MK66FN2M0VMD18 / Kinetis K66 MCUs | 6 / TBD / TBD | TBD | untested | Custom target required; compatibility unverified | Source, date, cost, and lifecycle notes TBD | [hardware index](../hardware/README.md) | TBD |
| FC-PCB-001 | Blank flight-controller PCBs, exact revision TBD | 25 / TBD / TBD | TBD | untested | Depends on populated MCU and board revision | Original fabrication/source and reorder files TBD | [GD32F405 notes](../hardware/gd32f405/README.md) · [bring-up log](../docs/bring-up-log.md) | TBD |
| FC-H743-001 | STM32H743 flight controller, exact board revision TBD | 1 / TBD / TBD | TBD | untested | ArduPilot `MATEKH743` and iNav noted; exact board/version unverified | Source, date, and cost TBD | [H743 wing/lift project](../docs/h743-wing-project.md) | TBD |
| FC-APM-001 | APM 2.6-series boards | 3 / TBD / TBD | TBD | untested | Legacy ArduPilot/APM firmware only; exact versions TBD | Existing stock; source and cost TBD | [5-inch test mules](../5in-test-mules/project-overview.md) | TBD |
| FC-NAZA-001 | DJI NAZA V2 hardware | 1 / TBD / TBD | TBD | untested | DJI Assistant/NAZA firmware; exact version and access TBD | Existing stock; source and cost TBD | Related aircraft assignment TBD | TBD |
| CMP-ESP32-001 | Assorted ESP32 modules/development boards | TBD / TBD / TBD | TBD | untested | Arduino, ESP-IDF, and PlatformIO candidates; board-by-board verification required | Source and reorder variants TBD | [firmware roadmap](../firmware/platformio-roadmap.md) | TBD |
| CMP-ESP8266-001 | ESP8266 NodeMCU boards | TBD / TBD / TBD | TBD | untested | Arduino/PlatformIO candidates; exact board profile TBD | Source and reorder variant TBD | Related project TBD | TBD |
| CMP-RPI-001 | Raspberry Pi systems | TBD / TBD / TBD | TBD | untested | OS image and interface compatibility TBD by unit | Source, model counts, and cost TBD | Related project TBD | TBD |

## Handheld, display, and I/O hardware

| ID | Item / variant | Qty (total / available / reserved) | Storage | Status | Firmware compatibility | Procurement | Related work | Verified |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| UI-P4-001 | LilyGo T-Display P4 | 2 / TBD / TBD | TBD | mixed: one observed running factory animations; one blank/suspect | Vendor BSP first; PlatformIO/ESP-IDF harness in progress | Source, date, exact revision, and cost TBD | [ESP32-P4 bring-up](../hardware/esp32-p4/README.md) · [test harness](../firmware/t-display-p4-test-harness/README.md) · [issue #2](https://github.com/dronemaker-alt/flight-controller-builds/issues/2) | TBD |
| UI-P4-002 | JC-ESP32P4-M3-DEV | TBD / TBD / TBD | TBD | untested | Exact vendor BSP/toolchain TBD | Source, date, exact revision, and cost TBD | [ESP32-P4 bring-up](../hardware/esp32-p4/README.md) · [issue #1](https://github.com/dronemaker-alt/flight-controller-builds/issues/1) | TBD |
| IO-PCA9685-001 | PCA9685 servo controllers | TBD / TBD / TBD | TBD | untested | I2C library/voltage compatibility TBD | Source and reorder part TBD | Related project TBD | TBD |
| UI-OLED096-001 | 0.96-inch OLED displays | TBD / TBD / TBD | TBD | untested | Controller, address, voltage, and library TBD | Source and reorder part TBD | Related project TBD | TBD |
| UI-DISP25-001 | 2.5-inch TFT/OLED modules | TBD / TBD / TBD | TBD | untested | Controller, bus, voltage, and library TBD | Source and reorder part TBD | [handheld prototype notes](../mechanical/handheld-prototype-notes.md) | TBD |
| IO-USBC-001 | USB-C breakout/interface hardware | TBD / TBD / TBD | TBD | untested | N/A; record CC/ESD/power role by variant | Source and reorder part TBD | [USB-C migration](../hardware/usb-c-migration/README.md) | TBD |

## Fabrication and mechanical stock

| ID | Item / variant | Qty (total / available / reserved) | Storage | Status | Firmware compatibility | Procurement | Related work | Verified |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| MAT-FG-001 | Small-weave fiberglass cloth | 20+ yd / TBD / TBD | TBD | untested | N/A | Source, date, cost, width, and cloth weight TBD | Related airframe project TBD | TBD |
| MAT-2020-001 | 20 × 20 mm aluminum extrusion | TBD / TBD / TBD | TBD | untested | N/A | Existing stock; lengths, source, and replacement cost TBD | Related fixture/project TBD | TBD |
| MAT-PTFE-001 | PTFE cover plates | TBD / TBD / TBD | TBD | untested | N/A | Existing stock; dimensions and source TBD | [handheld prototype notes](../mechanical/handheld-prototype-notes.md) | TBD |
| MAT-OTHER-001 | Delrin and Mylar stock | TBD / TBD / TBD | TBD | untested | N/A | Dimensions, source, and replacement cost TBD | Related fixture/project TBD | TBD |
| MECH-UI-001 | Metal standoffs, pushbuttons, and UI hardware | TBD / TBD / TBD | TBD | untested | Electrical ratings TBD by part | Source and reorder parts TBD | [handheld prototype notes](../mechanical/handheld-prototype-notes.md) | TBD |

## Procurement watch list

These are candidates, not inventory. Move an item into the register only when it
is physically received.

| Item | Need / compatibility gate | Quantity | Preferred source / part | Budget / price | Related work | Status |
| --- | --- | --- | --- | --- | --- | --- |
| SWD debugger | Must support the selected GD32F405/K66 workflow | TBD | TBD | TBD | [GD32F405 notes](../hardware/gd32f405/README.md) | research |
| USB-C connectors and CC resistors | Match footprint and intended source/sink role | TBD | TBD | TBD | [USB-C migration](../hardware/usb-c-migration/README.md) | research |
| TVS / ESD protection | Match USB and external-interface voltage/capacitance needs | TBD | TBD | TBD | [USB-C migration](../hardware/usb-c-migration/README.md) | research |
| Regulators | Select only after rail/current requirements are measured | TBD | TBD | TBD | [power-system notes](../hardware/power-system/README.md) | research |
| Solder paste | Alloy, particle size, storage life, and reflow profile TBD | TBD | TBD | TBD | [bring-up log](../docs/bring-up-log.md) | research |
| Inspection microscope | Working distance and camera/output requirements TBD | 1 | TBD | TBD | [bring-up log](../docs/bring-up-log.md) | research |

## Next physical count

- [ ] Assign real storage-location codes and label the containers.
- [ ] Count each row as total, available, and reserved.
- [ ] Split mixed lots into separate rows when revision or status differs.
- [ ] Give each LilyGo P4 a unique asset tag and record which unit is known-good.
- [ ] Record board revisions, photos, procurement source, and cost where known.
- [ ] Link reservations to the exact build or issue that has claimed the hardware.
