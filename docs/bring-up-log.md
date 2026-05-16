# Bring-Up Log

## Purpose

Track all board bring-up events, failures, fixes, measurements, and observations.

## Entry Template

### Board ID

### MCU

### Date

### Power Source

### Current Limit

### Actions Taken

### Rail Measurements

### USB Behavior

### SWD/Programming Status

### Thermal Observations

### Problems Found

### Fixes Attempted

### Final Result

---

# Session 001 — Initial Bench Procedure

## Objective

Establish a repeatable first-power and inspection workflow for custom flight-controller boards and experimental avionics hardware.

## Pre-Power Checklist

- Photograph both sides of board.
- Confirm MCU orientation and pin 1.
- Inspect for solder bridges.
- Verify resistance from power rails to ground.
- Identify regulators and expected outputs.
- Confirm USB, SWD, UART, boot, and reset access.
- Use current-limited power for first energizing.

## First Power Rule

Never fully trust an unverified board.

Initial power-up should use:

- current-limited bench supply
- thermal monitoring
- staged subsystem testing
- measurement before firmware flashing

## Measurement Table

| Check | Expected | Actual | Pass/Fail | Notes |
|---|---:|---:|---|---|
| Input voltage | TBD |  |  |  |
| 5V rail | TBD |  |  |  |
| 3.3V rail | TBD |  |  |  |
| MCU VDD | TBD |  |  |  |
| USB detect | TBD |  |  |  |
| Reset line | TBD |  |  |  |
| Boot pins | TBD |  |  |  |

## Engineering Notes

- Log unknowns instead of guessing.
- Photograph rework before and after changes.
- Change one variable at a time.
- Keep reusable firmware separated from board-specific code.
- Treat mirrored repositories as read-only reference material.
