# USB-C Migration Notes

## Goals

Replace legacy micro-USB with mechanically stronger USB-C connectors.

## Key Requirements

- CC resistors
- ESD protection
- reinforced connector footprint
- clean D+ / D- routing
- independent SWD access

## Risks

- assuming USB-C is a direct pin swap
- connector pad lifting
- poor cable negotiation
- noisy power routing

## Recommended Features

- test pads
- strain relief
- protected USB data lines
- boot/recovery access independent of USB
