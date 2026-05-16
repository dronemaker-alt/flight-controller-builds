# Hardware Documentation

This folder captures board-specific information for flight-controller builds, handheld field tools, and supporting bench hardware.

## Documentation Goals

Each hardware item should eventually have:

- board photos
- pin-1 / orientation notes
- power rail map
- connector map
- programming/debug access notes
- boot mode notes
- known-good test procedure
- known risks and unknowns

## Current Hardware Areas

```text
hardware/
├── gd32f405/
├── k66-mk66fn2m0/
├── power-system/
├── usb-c-migration/
├── esp32-p4/
├── apm2/
├── naza-reference/
└── pixhawk-class/
```

## Rule

Do not trust silkscreen alone. Verify with photos, meter checks, and datasheets when possible.
