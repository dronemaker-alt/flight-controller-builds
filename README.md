# Flight Controller Builds

A working engineering repository for custom flight-controller board assembly, bring-up, power-system planning, firmware experiments, and portable field-programmer concepts.

This repository is populated from the active ChatGPT project thread and should be treated as the active design notebook for original work. Mirrored repositories are reference-only and should not be modified from this project.

## Project Focus

- Custom flight-controller PCB bring-up
- GD32F405 MCU assembly and test notes
- NXP Kinetis K66 / MK66FN2M0VMD18 alternate MCU notes
- USB-C migration planning
- Power-system BOM planning
- ESP32 / LilyGo P4 handheld diagnostic tool concepts
- Display, button, enclosure, and field-service UI experiments
- Drone diagnostics, firmware recovery, and portable programming workflows

## Repository Layout

```text
.
├── docs/                         Design notes and build process logs
├── firmware/                     Bring-up firmware and board support notes
├── hardware/                     Board-specific documentation and BOMs
│   ├── gd32f405/
│   ├── k66-mk66fn2m0/
│   ├── power-system/
│   └── usb-c-migration/
├── inventory/                    Known parts and material inventory
├── mechanical/                   Handheld enclosure and mockup notes
├── tools/                        Flashing, backup, and bench-test helpers
└── roadmap/                      Build phases and TODO tracking
```

## Immediate Build Philosophy

Start with one MCU practice placement before assembling a small batch.

1. Identify pin 1 and mark orientation.
2. Confirm paste/flux/hot-air workflow.
3. Inspect all sides under magnification.
4. Verify all power rails before installing sensitive components.
5. Establish SWD/debug access.
6. Confirm USB or bootloader behavior.
7. Document every change in `docs/bring-up-log.md`.

## Current Known Parts From Project Thread

- GD32F405 MCU chips
- Blank flight-controller boards
- NXP MK66FN2M0VMD18 / Kinetis K66 MCUs
- ESP32 boards
- PCA9685 servo controller
- 0.96 inch OLED displays
- 2.5 inch TFT/OLED modules
- LilyGo P4 handheld/prototyping device
- PTFE cover plates for handheld mockup work
- 20+ yards of small-weave fiberglass cloth
- 20x20 aluminum extrusion

## Engineering Ground Rules

- Keep bring-up work reversible where possible.
- Use current-limited power for first energizing.
- Do not assume USB-C is a drop-in connector swap without CC resistors and ESD planning.
- Keep board-specific firmware separate from reusable app/UI logic.
- Log unknowns instead of hiding them.
- Treat flight hardware as an engineering project first, not just a gadget build.

## Status

Initial repository structure seeded. Next steps are board photos, annotated pin-1 diagrams, measured power rails, and first bring-up notes.
