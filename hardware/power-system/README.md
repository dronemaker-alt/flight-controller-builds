# Power System

## Design Goals

- stable 3.3V rail
- USB bring-up support
- future battery integration
- low-noise digital rail
- regulator thermal margin
- field-debug friendly test points

## Suggested Core Sections

USB-C -> ESD -> 5V Rail -> 3.3V Regulation -> MCU + Sensors

## Planned Features

- TVS protection
- reverse polarity protection
- test pads
- optional current sensing
- optional filtered analog rail

## First Power-Up Procedure

1. Continuity test.
2. Verify resistance to ground.
3. Apply current-limited power.
4. Verify regulator output.
5. Check thermal behavior.
6. Verify stable idle current.
