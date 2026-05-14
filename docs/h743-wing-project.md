# H743 Wing / Lift Platform Project

This document captures the working project thread for the H743-based aircraft build.

## Project Intent

Build a practical, well-documented UAV flight-controller platform around the Matek H743-WLITE class of hardware, with enough structure that the work can support bench bring-up, flight configuration, future diagnostics, and portfolio-level documentation.

The project is treated as an engineering notebook rather than a one-off build.

## Current Concept

The thread has included two closely related build directions:

1. **H743-WLITE modern flight-controller build** — STM32H743-based controller for ArduPilot/iNav class aircraft.
2. **High-lift / stable quad platform** — payload-capable, reliable hovering platform with clean power distribution, smooth throttle response, GPS/telemetry support, and future CAN expansion.

The repository should keep these related notes together while separating confirmed hardware data from assumptions and TODO items.

## Known / Target Flight Controller

- Board family: Matek H743-WLITE / H743 wing-class controller
- MCU class: STM32H743, 480 MHz Cortex-M7
- Firmware family: ArduPilot and iNav capable
- ArduPilot hardware target noted in prior project notes: `MATEKH743`
- Intended use: wing/drone flight-control experiments, bench bring-up, field diagnostics, and later aircraft integration

## Design Goals

- Reliable power and ground layout
- Recoverable firmware workflow
- Clear UART / CAN / PWM assignment table
- GPS and telemetry ready
- SD logging where supported
- Bench-test procedure before flight installation
- Modular documentation so future boards can be added without rewriting the whole repo

## Engineering Style

- Separate confirmed data from assumptions.
- Keep wiring tables explicit.
- Record parameter files and firmware versions.
- Photograph and annotate every connector before first power.
- Keep mirrored/reference repositories read-only unless intentionally forked for experiments.

## Current Status

This repository has been seeded from the project thread. The next useful step is to add annotated photos of the exact H743-WLITE board and capture a first bench-power log.
