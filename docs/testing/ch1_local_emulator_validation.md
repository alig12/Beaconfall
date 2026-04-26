# Chapter 1 Local Emulator Validation

## Purpose

This guide explains how to validate Beaconfall Chapter 1 locally with a real ROM build and emulator.

Use it together with:

- `docs/testing/ch1_full_smoke_test.md`
- `docs/testing/ch1_forte_hall_smoke_test.md`
- `docs/beaconfall_chapter1_validator.md`

Static checks can catch wiring mistakes. Emulator validation catches runtime crashes, visual issues, pathing problems, battle transition issues, and save/load regressions.

## What this does and does not prove

This proves:

- the ROM builds locally
- the ROM starts in an emulator
- Chapter 1 can be played from fresh save to Beacon Badge
- save/load persists key Chapter 1 states

This does not prove:

- every optional route is polished
- all trainer sight ranges feel perfect
- every old save migration works
- future changes will remain valid without retesting

## Required tools

- `devkitARM` or compatible `arm-none-eabi` GBA toolchain
- `make`
- `python3`
- mGBA or equivalent GBA emulator

The Makefile uses `DEVKITARM` / `TOOLCHAIN` and `arm-none-eabi-*` tools when building the ROM.

## Static validation first

Run this before building:

```bash
make beaconfall-ch1-validate
python3 verify_ch1_pass.py
```

Expected:

```text
All checks pass.
```

If static validation fails, fix that before spending time in the emulator.

## Build the ROM

### macOS

```bash
make -j$(sysctl -n hw.ncpu)
```

### Linux

```bash
make -j$(nproc)
```

Expected output:

```text
pokeemerald.gba
```

If the build fails because `arm-none-eabi-*` tools are missing, install/configure the GBA toolchain first.

## Launch in mGBA

### macOS

```bash
open -a mGBA pokeemerald.gba
```

Or open mGBA manually and load `pokeemerald.gba`.

### Linux

```bash
mgba pokeemerald.gba
```

If `mgba` is not in your `PATH`, launch it manually and open the ROM.

## Recommended test order

1. Run static validator.
2. Build ROM.
3. Launch ROM in mGBA.
4. Start a fresh save.
5. Follow `docs/testing/ch1_full_smoke_test.md`.
6. Follow `docs/testing/ch1_forte_hall_smoke_test.md` for Forte Hall-specific checks.
7. Record any failure with the bug report template.

## Save-state guidance

Use save states for speed only.

Good use:

- before starter choice
- before Route 1 rival
- before Brassfall rival
- before each Forte Hall trainer
- before Vera

Bad use:

- proving save/load persistence
- proving progression survives reset
- proving badge state persists

For persistence checks, use the normal in-game save menu, then reset the emulator and reload.

## Normal save/load checkpoints

Use normal in-game save and emulator reset at these points:

```text
After starter choice
After Route 1 clear
After Brassfall Rival Battle 2
After one Forte Hall rig
After two Forte Hall rigs
After Beacon Badge
```

Expected:

- one-time rewards do not duplicate
- defeated rival battles do not replay
- gate state remains open
- partial gym lights persist
- badge and chapter-complete state persist

## Minimum pass criteria

Chapter 1 is not considered playable until all of these pass:

- ROM builds successfully.
- ROM boots in emulator.
- Fresh save reaches starter choice.
- Professor gives starter and 5 Poké Balls.
- North gate twins open after starter choice.
- Rival Battle 1 happens on Saltwind Path.
- Route 1 clears after Rival Battle 1.
- Cinder Reed Grove can be crossed.
- Rival Battle 2 happens in Brassfall City.
- Forte Hall Gym three-rig puzzle works.
- Vera awards Beacon Badge.
- Normal save/load works at the required checkpoints.
- No crash, freeze, or softlock appears on the main path.

## Bug report template

```text
Build/commit:
ROM build:
Emulator/version:
OS:
Save type: fresh / existing / migrated / save-state
Starting state:
Steps:
Expected:
Actual:
Can reproduce: yes / no
Screenshot/video:
Notes:
```

## Future automation path

A future automated emulator pass can use mGBA Lua or mGBA headless tooling to:

- launch the ROM
- load save states
- send deterministic inputs
- capture screenshots
- stop on hangs or checkpoint failures

Do not add this until the local build and manual smoke route are stable.
