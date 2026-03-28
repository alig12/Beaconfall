# Beaconfall Chapter 1 Validator

This page documents the Chapter 1 integrity validator and the new rare encounter species.

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

5. **Standout Species**: Confirms the curated rare species are present in encounters:
   - **Saltwind Path**: Shinx (4%), Eevee (1%)
   - **Cinder Reed Grove**: Growlithe (4%), Riolu (1%), Ralts (1%)

6. **Map Metadata**: Verifies no stale borrowed flags are present from Littleroot/Viridian maps

7. **Chapter Script**: Confirms expected game state variables are defined:
   - VAR_RIVAL_BATTLES
   - VAR_GYM_LIGHT_STATE
   - FLAG_ROUTE_1_CLEARED
   - FLAG_CINDER_REED_GROVE_CLEARED

## Chapter 1 Encounter Overview

Chapter 1 focuses on providing early access to fan-favorite species, each with distinct appeal:

### Saltwind Path (Seaside Route)
**Common Mons:**
- Wurmple, Poochyena, Wingull, Zigzagoon, Taillow

**Rare Standouts:**
- **Shinx** (4%, Lv.4) — Electric-type powerhouse evolution line
- **Eevee** (1%, Lv.5) — Versatile evolution options and fan favorite

### Cinder Reed Grove (Forested Dungeon)
**Common Mons:**
- Shroomish, Seedot, Surskit, Paras, Taillow

**Rare Standouts:**
- **Growlithe** (4%, Lv.6) — Fire-type with strong charm/presence
- **Ralts** (1%, Lv.7) — Psychic-type gem and endgame staple
- **Riolu** (1%, Lv.7) — Fighting/Steel hybrid with high player demand

## Design Rationale

The rare species selection follows successful early-access patterns in fan hacks:
- **Glazed** front-loads high-appeal species like Shinx early for player identity
- **Pokémon Unbound** places Riolu on Route 2 as a standout find
- **Gaia** and **Radical Red** support the "early rare species, clearly curated" design

This approach:
- Rewards thorough exploration with memorable finds
- Maintains route ecology readability (common slots unchanged)
- Gives players meaningful early-chapter choices
- Establishes Beaconfall's character through species availability

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
