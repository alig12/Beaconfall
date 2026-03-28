# Beaconfall Chapter 1 Validator

This page documents the Chapter 1 integrity validator and the opening-flow guidance used alongside it.

## Running the Validator

The validator checks the integrity of Beaconfall Chapter 1's map structure, encounters, and metadata:

```bash
make beaconfall-ch1-validate
```

## What the Validator Checks

1. **Map Group Membership**: Verifies all 5 Chapter 1 maps are in `gMapGroup_BeaconfallChapter1` in the correct order:
   - EmberHollowTown
   - Route1_SaltwindPath
   - CinderReedGrove
   - BrassfallCity  
   - ForteHallGym

2. **Region Map Sections**: Confirms each map uses the correct Beaconfall-scoped region section:
   - EmberHollowTown → MAPSEC_EMBER_HOLLOW_TOWN
   - Route1_SaltwindPath → MAPSEC_SALTWIND_PATH
   - CinderReedGrove → MAPSEC_CINDER_REED_GROVE
   - BrassfallCity → MAPSEC_BRASSFALL_CITY
   - ForteHallGym → MAPSEC_BRASSFALL_CITY (shared)

3. **Map Connections**: Verifies the connection chain is intact:
   - Ember Hollow Town ↔ Saltwind Path ↔ Cinder Reed Grove ↔ Brassfall City

4. **Encounter Coverage**: Ensures encounters exist only on Saltwind Path and Cinder Reed Grove (no encounters on towns/gym)

5. **Opening Flow Guidance**: Confirms the player-facing opener follows the intended sequence:
   - Blackout hook in Ember Hollow
   - Mom intro and recovery path
   - Professor lab starter choice
   - Immediate Mira encounter
   - Route 1 unlock after the tutorial rival

6. **Map Metadata**: Verifies no stale borrowed flags are present from Littleroot/Viridian maps

7. **Chapter Script**: Confirms expected game state variables are defined:
   - FLAG_BEACONFALL_STARTER_SELECTED
   - VAR_RIVAL_BATTLES
   - VAR_GYM_LIGHT_STATE
   - FLAG_ROUTE_1_CLEARED
   - FLAG_CINDER_REED_GROVE_CLEARED

## Chapter 1 Opening Notes

The static validator checks structure and state, but the first 60 seconds still need a playtest pass.

### What the opening should feel like
**Blackout hook**
- Show the town is in trouble immediately.

**Starter choice**
- Give the player a fast, meaningful choice and confirm it with a clear prompt.

**First rival**
- Keep the fight difficult but fair.
- The player should be able to lose, return home, heal, and try again without breaking the story state.

**Recovery**
- Mom stays available as the recovery path once the starter has been chosen.

**Progression**
- The chapter should always move in this order: Ember Hollow -> Route 1 -> Cinder Reed Grove -> Brassfall City -> Forte Hall Gym.

## Updating the Validator

The validator source is at `dev_scripts/beaconfall_ch1_validate.py`. To add new checks:

1. Add a new `validate_*()` function
2. Add it to the `validators` list in `main()`
3. Update the Makefile target if needed

## See Also

- [map_groups.json](../data/maps/map_groups.json) — Map group definitions
- [region_map_sections.json](../src/data/region_map/region_map_sections.json) — Region map sections
- [wild_encounters.json](../src/data/wild_encounters.json) — Encounter tables
- [chapter_1.inc](../data/scripts/chapter_1.inc) — Chapter 1 game state script
