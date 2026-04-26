# Beaconfall Chapter 1 Validator

This page documents the Chapter 1 integrity validator and the play-validation workflow used alongside it.

The validator is a fast static check. It does not replace building the ROM or playing the chapter in an emulator.

## Running the Validator

Run the static validator from the repo root:

```bash
make beaconfall-ch1-validate
```

Direct Python usage also works:

```bash
python3 dev_scripts/beaconfall_ch1_validate.py
```

## What the Validator Checks

1. **Map Group Membership**
   - Verifies all Chapter 1 maps and Ember Hollow interiors are in `gMapGroup_BeaconfallChapter1` in the expected order.

2. **Region Map Sections**
   - Confirms each Chapter 1 map uses the intended Beaconfall-scoped region section.
   - `ForteHallGym` intentionally shares `MAPSEC_BRASSFALL_CITY`.

3. **Map Connections**
   - Verifies the route chain is intact:
   - Ember Hollow Town ↔ Saltwind Path ↔ Cinder Reed Grove ↔ Brassfall City

4. **Encounter Coverage**
   - Ensures encounters exist on Saltwind Path and Cinder Reed Grove.
   - Ensures towns and Forte Hall Gym do not have wild encounters.

5. **Saltwind Path Wild Species**
   - Ensures Saltwind Path land encounters stay limited to the early-route species intended for Chapter 1.

6. **Borrowed Metadata Flags**
   - Confirms the Chapter 1 maps do not accidentally set stale Littleroot or Viridian metadata flags.

7. **Expected Chapter State**
   - Confirms the shared Chapter 1 script still uses the expected flags and vars:
   - `FLAG_BEACONFALL_STARTER_SELECTED`
   - `VAR_RIVAL_BATTLES`
   - `VAR_GYM_LIGHT_STATE`
   - `FLAG_ROUTE_1_CLEARED`
   - `FLAG_CINDER_REED_GROVE_CLEARED`
   - `VAR_BEACONFALL_BLACKOUT_MSG`

8. **Ember Hollow Gate Flow**
   - Confirms both north gate twins use `FLAG_EMBER_NORTH_GATE_TWIN_MOVED`.
   - Confirms the gate opens from starter selection, not from a pre-route rival battle.
   - Confirms the Professor Lab does not run a lab Rival Battle 1.

9. **Route 1 Rival Scene**
   - Confirms Mira exists as a visible Route 1 object.
   - Confirms the Route 1 rival trigger fires at `VAR_RIVAL_BATTLES == 0`.
   - Confirms Route 1 victory marks the route cleared.

10. **First Poké Ball Reward**
   - Confirms Professor Hollow gives the early catching kit.
   - Confirms the after-starter branch can repair old or partial saves.

11. **Forte Hall Three-Rig Gym**
   - Confirms KIT, RAYNE, and JAX are present.
   - Confirms Vera checks the three rig flags directly.
   - Confirms `VAR_GYM_LIGHT_STATE` remains derived helper state, not the unlock source.

12. **Progression State Machine**
   - Confirms `VAR_RIVAL_BATTLES` meanings are documented.
   - Confirms the shared repair helper exists.
   - Confirms later flags imply earlier flags.
   - Confirms each Chapter 1 map transition calls the shared repair helper.
   - Confirms stale tutorial-rival gate state is repaired without skipping Route 1 Rival Battle 1.

## Current Chapter 1 Flow

The intended player-facing flow is:

1. Blackout hook in Ember Hollow.
2. Recovery and home/lab onboarding.
3. Professor Hollow starter choice.
4. Professor gives 5 Poké Balls as the first catching kit.
5. North gate twins open after starter selection.
6. Mira / Rival Battle 1 happens on Saltwind Path.
7. Route 1 clears after Rival Battle 1.
8. Cinder Reed Grove traversal.
9. Brassfall City arrival and Rival Battle 2.
10. Forte Hall Gym three-rig puzzle.
11. Vera battle, Beacon Badge, and Chapter 1 completion.

## Progression State Machine

`VAR_RIVAL_BATTLES` has three valid meanings:

```text
0 = Route 1 rival pending
1 = Route 1 cleared; Brassfall rival pending
2 = Brassfall rival cleared
```

Later chapter flags imply earlier flags:

```text
FLAG_CHAPTER_1_COMPLETE
  -> FLAG_BRASSFALL_CITY_ENTERED
  -> FLAG_CINDER_REED_GROVE_CLEARED
  -> FLAG_ROUTE_1_CLEARED
  -> FLAG_EMBER_NORTH_GATE_TWIN_MOVED
```

Every Chapter 1 map transition should call:

```asm
call BeaconfallChapter1_EventScript_RepairProgression
```

This keeps old saves, partial saves, and branch-switch saves from re-opening cleared rival battles or re-closing gates.

## What Static Validation Cannot Prove

The validator cannot prove:

- The ROM builds on a local machine.
- mGBA can run the ROM.
- JAX placement feels good.
- trainer sight ranges feel fair.
- save/load persists the correct state in a real emulator.
- battle transitions have no visual corruption.
- the player can complete the chapter without crashes.

For emulator validation, use:

- `docs/testing/ch1_full_smoke_test.md`
- `docs/testing/ch1_forte_hall_smoke_test.md`
- `docs/testing/ch1_local_emulator_validation.md`

## Updating the Validator

The validator source is at `dev_scripts/beaconfall_ch1_validate.py`.

To add new checks:

1. Add a new `validate_*()` function.
2. Add it to the `validators` list in `main()`.
3. Update this document with the new coverage.
4. Add or update a manual smoke-test doc if gameplay verification is required.

## See Also

- [map_groups.json](../data/maps/map_groups.json) — Map group definitions
- [region_map_sections.json](../src/data/region_map/region_map_sections.json) — Region map sections
- [wild_encounters.json](../src/data/wild_encounters.json) — Encounter tables
- [chapter_1.inc](../data/scripts/chapter_1.inc) — Chapter 1 game state script
- [Full Chapter 1 smoke test](testing/ch1_full_smoke_test.md)
- [Forte Hall Gym smoke test](testing/ch1_forte_hall_smoke_test.md)
- [Local emulator validation](testing/ch1_local_emulator_validation.md)
