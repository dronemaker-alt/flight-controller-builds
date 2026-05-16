# Firmware Roadmap

## Initial Firmware Strategy

The goal is to separate:

- reusable logic
- board support
- UI code
- communications stacks
- diagnostics tools
- hardware abstraction

This prevents the project from becoming a spaghetti monster held together by caffeine and optimism.

## Early Firmware Targets

### ESP32 / ESP32-P4

- display test
- button input test
- SD card test
- UART console
- Wi-Fi/Bluetooth validation
- LVGL UI experiments

### Flight Controller Boards

- power validation firmware
- LED heartbeat test
- IMU detection
- UART passthrough
- bootloader access

## Suggested Layout

```text
firmware/
├── boards/
├── common/
├── ui/
├── diagnostics/
├── communications/
├── telemetry/
└── experiments/
```

## Engineering Rules

- Board-specific code stays isolated.
- Shared code must compile cleanly across platforms.
- Prototype fast, but document assumptions.
- Preserve original firmware backups before experimentation.
