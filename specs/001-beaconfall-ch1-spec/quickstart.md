# Quickstart: Beaconfall Chapter 1 Planning

## What this plan covers

Chapter 1 is a five-map, first-badge vertical slice built on `pokeemerald-expansion`.
Implement it with the existing decomp workflow, map-local scripts, shared chapter scripts,
trainer tables, encounter tables, and flags or variables.

## Start here

1. Read `spec.md`, `plan.md`, and `constitution.md` together.
2. Open the five Chapter 1 maps in Porymap.
3. Wire the opening sequence in `data/scripts/new_game.inc` and the shared chapter flow in
   `data/scripts/chapter_1.inc`.
4. Update trainer parties in `src/data/trainer_parties.h`.
5. Update Chapter 1 encounters in `src/data/wild_encounters.json`.
6. Add or adjust chapter flags and variables in `include/constants/flags.h` and
   `include/constants/vars.h`.

## Implementation order

1. Starter choice, Pokédex, and opening objective.
2. Route 1 flow and Rival Battle 1.
3. Cinder Reed Grove traversal and trainer battles.
4. Brassfall City arrival and Rival Battle 2.
5. Forte Hall Gym lights, leader battle, badge award, and Chapter 2 hook.

## Build and check

- Build the ROM with `make`.
- Launch the ROM in an emulator and play from a fresh save.
- Confirm the player can reach the badge without crashes or soft-locks.
- Save and reload during the chapter and verify the same progress resumes.

## What good looks like

- The starter trio is always Briarune, Pyrevex, and Karatide.
- The chapter always ends at the first badge.
- The gym puzzle is deterministic.
- The chapter-complete state is preserved after reload.
- No custom engine layer is introduced.
