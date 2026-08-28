# Hardware inventory

This directory is the repo's canonical hardware context. Use
[current-hardware.md](current-hardware.md) for every physical board, module, or
material that can affect a build.

The register is deliberately simple enough to update from the bench. Unknown
facts stay `TBD`; they are not silently converted into assumptions.

## What each field means

| Field | Rule |
| --- | --- |
| ID | Stable short tag. Keep it when the item moves or changes state. |
| Item / variant | Board, module, component, or material and its exact revision when known. |
| Qty | `total / available / reserved`. Use `TBD` until counted. Bad units remain in total. |
| Storage | Physical location code plus container, drawer, or shelf detail. |
| Status | `known-good`, `known-bad`, `suspect`, `untested`, `parts-only`, or `consumed`. |
| Firmware compatibility | Verified target/version first; untested candidates are labeled `unverified`. |
| Procurement | Source, date, unit cost, reorder notes, lifecycle risk, or `TBD`. |
| Related work | Relative links to the build, hardware notes, firmware, issue, or external repo using it. |
| Verified | Date the quantity, location, or status was last physically checked. |

## Storage location codes

Create a code only after the location physically exists. Keep codes short and
put the useful detail in the register.

| Code | Area | Container / detail | Notes |
| --- | --- | --- | --- |
| TBD | Not yet recorded | TBD | Locate and label during the next physical count. |

Suggested pattern: `AREA-CONTAINER-POSITION`, for example
`LAB-CAB01-D03` or `HOUSE-BIN04`. A location code identifies where the item
is now, not where it is supposed to migrate someday.

## Update workflow

1. Search the register by ID, part number, and common name before buying.
2. Update quantity and storage whenever hardware is received, moved, reserved,
   installed, failed, harvested, or discarded.
3. Record a status only after a bench observation; link the evidence when it
   exists.
4. Record the exact working firmware target and version. Keep merely plausible
   compatibility explicitly unverified.
5. Reserve hardware to a related project instead of subtracting it from total.
6. Add the verification date so stale entries are obvious.

## New-row template

```markdown
| ID | Item / variant | Qty (total / available / reserved) | Storage | Status | Firmware compatibility | Procurement | Related work | Verified |
| --- | --- | --- | --- | --- | --- | --- | --- | --- |
| HW-000 | Exact item and revision | TBD / TBD / TBD | TBD | untested | TBD | TBD | [project](../path/to/project.md) | TBD |
```

[Issue #3](https://github.com/dronemaker-alt/flight-controller-builds/issues/3)
tracks expansion of this starter structure.
