# Mirrored and Reference Repositories

## Purpose

This document tracks external repositories cloned or mirrored for research and engineering reference.

These repositories should generally remain unchanged.

Treat them as:

- engineering references
- architecture studies
- firmware examples
- historical snapshots
- integration references

## Ground Rule

Do not develop directly inside mirrored repositories.

Original work should occur in dedicated project repositories with documentation explaining:

- what was learned
- what was reused
- what was modified
- what limitations exist

## Current Known Reference Areas

### Flight Control

- INAV
- ArduPilot
- APM-related legacy systems
- Pixhawk ecosystem

### Embedded Systems

- ESP32 examples
- LVGL UI examples
- display driver examples
- firmware flashing utilities

### Robotics

- quadruped robotics
- servo control examples
- telemetry systems

## Suggested Workflow

```text
mirror repo --> study --> document findings --> implement clean-room version in active project
```

## Engineering Warning

Mirrored repositories become dangerous when:

- undocumented edits accumulate
- local changes diverge silently
- nobody remembers original sources
- experimental hacks leak into production work

Avoid becoming the archaeologist of your own disasters.
