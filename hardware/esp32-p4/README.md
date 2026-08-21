# ESP32-P4 hardware bring-up packet

Status: bench characterization required. This packet establishes a repeatable
hardware baseline before adding LVGL, telemetry, or application logic.

Related work: [hardware interfaces and pin mapping](https://github.com/dronemaker-alt/flight-controller-builds/issues/1) ·
[display and input test harness](https://github.com/dronemaker-alt/flight-controller-builds/issues/2) ·
[current hardware inventory](../../inventory/current-hardware.md) ·
[firmware roadmap](../../firmware/platformio-roadmap.md)

## Scope and evidence rules

Two different board designs are in the current inventory:

| Board profile | Inventory evidence | Intended initial role | Current verification |
| --- | --- | --- | --- |
| LilyGo T-Display P4 | Listed under handheld/UI development | Integrated-display handheld and UI test target | Exact revision, display wiring, and pin map unverified |
| JC-ESP32P4-M3-DEV | Listed under handheld/UI development | ESP32-P4 development and expansion test target | Exact revision, connector map, and pin map unverified |

Do not transfer GPIO assignments, connector functions, display configuration,
or supply-rail assumptions from one board to the other. Record the actual PCB
revision and match it to the correct manufacturer's schematic or board-support
package before assigning pins.

Evidence codes:

- **CONFIRMED**: directly measured, photographed, or matched to the exact
  revision's authoritative schematic.
- **OBSERVED**: behavior seen at the bench without a confirmed circuit trace.
- **UNVERIFIED**: plausible or listed by a vendor, but not proven for the board
  in hand.
- **N/A**: feature absent from this specific board.

Keep evidence references beside each entry. A GPIO number without a source is
not a pin map.

## Board identification and photo capture

Complete one copy for **each physical board**, including multiple LilyGo units.

| Field | LilyGo T-Display P4 | JC-ESP32P4-M3-DEV |
| --- | --- | --- |
| Board ID / asset tag | TBD | TBD |
| PCB silkscreen revision | TBD | TBD |
| SoC marking | TBD | TBD |
| Flash / PSRAM markings | TBD | TBD |
| USB connector count and labels | TBD | TBD |
| Display controller / panel marking | TBD | TBD |
| Wireless companion, if fitted | TBD | TBD |
| Factory firmware behavior | TBD | TBD |
| Original firmware backup status | TBD | TBD |
| Schematic / vendor BSP revision | TBD | TBD |
| Known-good / suspect status | TBD | TBD |

Photo set:

- Front and back, square-on, with legible silkscreen and a scale reference.
- USB connectors, power-input connector, battery connector, and switch positions.
- Reset, boot, user buttons, LEDs, and accessible test pads.
- Display flex orientation, connector latch, panel label, and backlight circuitry.
- Regulators and their markings; inductors; large capacitors; any companion MCU.
- Expansion connectors with pin-1 indicators and labels.
- Detailed close-ups of every candidate UART, JTAG, or programming pad.

Use stable filenames such as `photos/<board-id>-front.jpg`,
`photos/<board-id>-back.jpg`, and
`photos/<board-id>-display-flex.jpg`. Annotate copies; preserve originals.

## Connector and interface map

Create separate rows per connector and per board profile.

| Interface | Board / connector ID | Physical location | Signal or purpose | Logic / supply level | Direction | Evidence | Status |
| --- | --- | --- | --- | --- | --- | --- | --- |
| USB power / programming port | TBD | TBD | VBUS, ground, data; exact role TBD | TBD | Bidirectional | TBD | UNVERIFIED |
| Second USB port, if present | TBD | TBD | Host, device, serial bridge, or power-only TBD | TBD | TBD | TBD | UNVERIFIED |
| Battery / auxiliary input | TBD | TBD | Connector type, polarity, and charging path TBD | TBD | Input | TBD | UNVERIFIED |
| UART console | TBD | TBD | TX, RX, ground; routing TBD | TBD | Bidirectional | TBD | UNVERIFIED |
| Reset / enable control | TBD | TBD | EN/reset behavior and accessible node TBD | TBD | Input | TBD | UNVERIFIED |
| Boot / download control | TBD | TBD | Boot-selection control and strap behavior TBD | TBD | Input | TBD | UNVERIFIED |
| JTAG / debug access | TBD | TBD | Native USB debug, exposed pads, or dedicated header TBD | TBD | Bidirectional | TBD | UNVERIFIED |
| Display data interface | TBD | TBD | DSI, RGB, SPI, or another panel interface TBD | TBD | Output | TBD | UNVERIFIED |
| Display control | TBD | TBD | Reset, enable, power-select, and initialization path TBD | TBD | Output | TBD | UNVERIFIED |
| Backlight control | TBD | TBD | GPIO/PWM, enable polarity, and power path TBD | TBD | Output | TBD | UNVERIFIED |
| Touch interface, if present | TBD | TBD | Bus, interrupt, reset, and controller TBD | TBD | Bidirectional | TBD | UNVERIFIED |
| User button inputs | TBD | TBD | GPIO, pull direction, and active state TBD | TBD | Input | TBD | UNVERIFIED |
| I2C expansion | TBD | TBD | SDA/SCL, pull-ups, and addresses TBD | TBD | Bidirectional | TBD | UNVERIFIED |
| SPI expansion / SD | TBD | TBD | Clock, data, chip-select, detect, and power TBD | TBD | Bidirectional | TBD | UNVERIFIED |
| External sensor / camera connector | TBD | TBD | Interface type, pinout, and supply TBD | TBD | TBD | TBD | UNVERIFIED |

Record connector mating part, pitch, pin numbering, and whether any pad is
already shared with the display, boot straps, flash, PSRAM, or another device.

## Power tree and rail measurements

### Before first power

1. Identify the intended input source and trace connector ground.
2. Record battery-connector polarity before attaching any cell.
3. Inspect for damaged flexes, bridged pins, reversed connectors, or loose parts.
4. Measure resistance from each accessible candidate rail to ground with power
   removed. Compare suspect and known-good boards when possible.
5. Locate regulator inputs, outputs, enable pins, and nearby test points.
6. Identify whether a USB port actually carries data or only provides power.
7. Start from the documented USB/input supply or a current-limited equivalent;
   do not apply guessed voltage directly to an internal rail.

### Measurement table

Values below are **targets to identify**, not claims that every board has every
rail. Internal domains and measured values depend on the exact board revision.

| Rail / node | Expected role | Probe / test point | Unpowered resistance to GND | Idle voltage | Display-active voltage | Startup / idle current | Evidence / result |
| --- | --- | --- | --- | --- | --- | --- | --- |
| USB VBUS / external input | Primary board input | TBD | TBD | TBD | TBD | TBD | TBD |
| Battery input, if fitted | Battery supply / charger path | TBD | TBD | TBD | TBD | TBD | TBD |
| Main regulated logic rail | Digital I/O and peripheral supply | TBD | TBD | TBD | TBD | TBD | TBD |
| SoC-required internal rails | Core, memory, analog, or I/O domains as documented | TBD | TBD | TBD | TBD | TBD | TBD |
| External flash / PSRAM supply | Memory supply and I/O compatibility | TBD | TBD | TBD | TBD | TBD | TBD |
| Display logic supply | Panel/controller logic | TBD | TBD | TBD | TBD | TBD | TBD |
| Backlight supply / enable | LED/backlight driver supply and control | TBD | TBD | TBD | TBD | TBD | TBD |
| USB PHY / interface supply, if applicable | USB interface or external transceiver | TBD | TBD | TBD | TBD | TBD | TBD |
| Wireless-companion supply, if fitted | Separate radio/companion device | TBD | TBD | TBD | TBD | TBD | TBD |
| Expansion connector supply | Off-board sensor/peripheral power | TBD | TBD | TBD | TBD | TBD | TBD |

Record input source, current limit, USB cable, software state, meter ground
reference, and measurement time. Compare cold boot, idle, screen-on, and reset.
If a rail is absent, determine whether it is missing, switched off, or simply
not part of that board.

## Programming, console, and debug

For each physical USB connector, record the host enumeration result before
assuming it is the flashing port.

| Item | LilyGo T-Display P4 | JC-ESP32P4-M3-DEV |
| --- | --- | --- |
| Confirmed flashing connector | TBD | TBD |
| USB VID:PID and enumerated interfaces | TBD | TBD |
| USB-to-UART bridge, if any | TBD | TBD |
| Native USB programming / debug path | TBD | TBD |
| Serial device name and console settings | TBD | TBD |
| UART TX GPIO / accessible pad | TBD | TBD |
| UART RX GPIO / accessible pad | TBD | TBD |
| UART logic voltage | TBD | TBD |
| Reset/EN button, GPIO, or pad | TBD | TBD |
| Boot/download button or strap | TBD | TBD |
| Documented bootloader entry sequence | TBD | TBD |
| JTAG access and method | TBD | TBD |
| Flash identification / capacity | TBD | TBD |
| Existing firmware readback / backup | TBD | TBD |
| Recovery / reflash procedure | TBD | TBD |

Minimum programming check:

1. Connect a known-good data-capable USB cable.
2. Record whether the host detects a serial, USB-debug, or other device.
3. Capture the normal power-on/reset boot log.
4. Verify the documented download-mode entry sequence for this board revision.
5. Read chip and flash identification before any erase or write operation.
6. Back up existing firmware when the hardware and protection settings permit.
7. Prove that a reset returns the board to normal boot.

Do not assume the boot strap is GPIO0, or assume both board designs route USB,
UART, and reset identically.

## Display, backlight, and input wiring

Complete separately for each target. A lit backlight is not proof that panel
initialization succeeded; valid serial logs do not prove the display rail exists.

| Display / input item | LilyGo T-Display P4 | JC-ESP32P4-M3-DEV |
| --- | --- | --- |
| Display present / panel part number | TBD | TBD |
| Resolution and orientation | TBD | TBD |
| Panel/controller IC | TBD | TBD |
| Exact board BSP / display-driver source | TBD | TBD |
| Display bus type and connector | TBD | TBD |
| Data / clock / lane GPIOs or dedicated peripheral | TBD | TBD |
| Panel reset GPIO and active polarity | TBD | TBD |
| Panel enable / power GPIO and active polarity | TBD | TBD |
| Backlight enable GPIO and active polarity | TBD | TBD |
| Backlight PWM channel, frequency, and duty | TBD | TBD |
| Touch controller and bus/address, if fitted | TBD | TBD |
| Touch interrupt / reset GPIO, if fitted | TBD | TBD |
| User button GPIOs, pull-ups, and active state | TBD | TBD |
| Shared pins / boot-strap conflicts | TBD | TBD |
| Verified screen-on supply current | TBD | TBD |

### Blank-screen isolation order

1. Confirm host enumeration, serial output, and continued execution.
2. Measure input, main logic, display logic, and backlight supply rails.
3. Compare the suspect unit with a known-good board running the same image.
4. Confirm display flex seating, orientation, and connector latch.
5. Check panel enable and reset sequencing against the correct vendor BSP.
6. Verify backlight enable polarity and explicitly command visible brightness.
7. Verify the actual panel driver, resolution, bus type, and board-revision pin map.
8. Draw a solid-color frame before introducing widgets, touch, or LVGL.
9. Test touch and user buttons independently after the display works.
10. Save the working firmware revision, board profile, logs, and measurements.

If one LilyGo unit shows factory animations and another stays blank, treat the
animation-capable unit as the comparison baseline; do not conclude that the
other panel is defective before checking power, enable/reset, brightness,
firmware, and flex connection.

## Minimal firmware smoke-test contract

The first program should answer hardware questions, not become the product UI.

### Board-support boundary

Keep one board profile per exact hardware revision:

```text
firmware/
├── boards/
│   ├── lilygo-t-display-p4/
│   │   └── board-profile.md
│   └── jc-esp32p4-m3-dev/
│       └── board-profile.md
├── diagnostics/
│   └── esp32-p4-smoke-test/
└── ui/
```

A board profile records the exact development framework/BSP versions, flash
and PSRAM configuration, console transport, display-driver selection,
backlight behavior, button inputs, and only **verified** GPIO assignments.

### Required smoke-test sequence

1. Start the console and print board ID, firmware revision, reset reason, and
   available chip/flash/PSRAM identification.
2. Emit a repeating heartbeat and uptime so a frozen UI is distinguishable
   from a dead board.
3. Initialize only the board power/display prerequisites defined by its profile.
4. Explicitly enable the display backlight at a visible fixed level.
5. Initialize the confirmed panel driver and draw red, green, blue, black,
   and white full-screen frames.
6. Print each user-button transition and its confirmed GPIO/active state.
7. Display a simple status page with board ID, uptime, display status,
   button state, and flash/PSRAM results.
8. Leave LVGL, touch, SD, telemetry, wireless, and camera integration as
   separate follow-on steps after the baseline passes.

Use the exact vendor-supported toolchain or BSP first. Add a PlatformIO
environment only after ESP32-P4 support for the chosen framework, board
definition, flash method, and display driver is confirmed. Record the
known-working versions rather than assuming an arbitrary environment builds.

ESP32-P4 board wireless capability must be verified at **board level**: do not
equate an ESP32-P4 SoC with an onboard Wi-Fi/Bluetooth radio. Identify and test
any separate wireless companion before listing wireless support as available.

## Bench acceptance checklist

- [ ] Both board profiles and exact PCB revisions recorded.
- [ ] Front/back, connectors, regulators, display flex, and debug pads photographed.
- [ ] Exact schematics/BSP revisions linked, or missing sources explicitly noted.
- [ ] USB connector purposes and host enumeration recorded.
- [ ] Input polarity, current limit, and baseline current recorded.
- [ ] Accessible rails measured and compared across startup/idle/display-active states.
- [ ] Flash/programming method and recovery sequence demonstrated.
- [ ] Boot log captured and existing firmware backed up where permitted.
- [ ] UART TX/RX, reset, boot control, and debug access evidence recorded.
- [ ] Display bus, controller, panel supply, reset, and enable identified.
- [ ] Backlight pin, active polarity, and visible brightness verified.
- [ ] Solid-color display test passes without LVGL.
- [ ] User button GPIOs and active states verified.
- [ ] Working board profile, toolchain versions, and smoke-test results saved.
- [ ] Remaining unknowns listed before application firmware grows.

## Bring-up log template

```text
Date / operator:
Board ID / PCB revision:
Source schematic or BSP:
Input source / cable / current limit:
USB enumeration:
Boot / serial log:
Rail measurements:
Programming / recovery result:
Display controller / bus:
Backlight GPIO / polarity / brightness:
Button GPIOs / active states:
Smoke-test result:
Observed anomalies:
Evidence files:
Next action:
```

This packet does not mark either GitHub issue complete. Closure requires the
missing board photos, verified pin/rail evidence, and a working display/input
smoke test.
