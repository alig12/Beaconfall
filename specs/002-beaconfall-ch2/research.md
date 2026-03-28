# Chapter 2 Research

## Decisions

### 1. Use a shared chapter script file
**Decision:** Create `data/scripts/chapter_2.inc` and include it from `data/event_scripts.s`.

**Rationale:** Chapter 1 already centralizes reset and progression in `data/scripts/chapter_1.inc`. Chapter 2 should mirror that pattern so chapter-wide state, completion markers, and reward flow live in one place.

**Alternatives considered:** Keep every map self-contained. Rejected because chapter reset and reward logic would become duplicated across multiple map scripts.

### 2. Use the current trainer-party source of truth
**Decision:** Use `src/data/trainers.party` for Chapter 2 trainer parties.

**Rationale:** The repo already stores Beaconfall parties there. The generated `src/data/trainer_parties.h` file is empty in this workspace, so the real source of truth is the `.party` file.

**Alternatives considered:** Move parties into `trainer_parties.h`. Rejected because that is not how the repo currently stores Beaconfall trainer data.

### 3. Keep Chapter 2 state separate from Chapter 1 state
**Decision:** Add `VAR_RIVAL2_STATE`, `VAR_WATER_LEVEL_FLOODGATE`, and `VAR_WATER_LEVEL_GYM` instead of reusing Chapter 1 variables.

**Rationale:** Chapter 2 should not depend on Chapter 1 battle counters or gym puzzle variables. A dedicated state model keeps the chapter easier to reason about and prevents cross-chapter bugs.

**Alternatives considered:** Reuse `VAR_RIVAL_BATTLES` or `VAR_GYM_LIGHT_STATE`. Rejected because it would couple Chapter 2 logic to Chapter 1 flow.

### 4. Keep the trainer roster to the hybrid budget
**Decision:** Implement only the core Chapter 2 trainer battles and defer the optional mini-boss / filler battles.

**Rationale:** The current Beaconfall trainer ID space is tight. The chapter should ship with the key route, dungeon, rival, and gym battles first.

**Alternatives considered:** Expand the trainer roster without trimming anything. Rejected because that increases pressure on trainer IDs and save space for a non-essential encounter.

### 5. Unlock Surf with the standard reward flow
**Decision:** Reuse the existing Surf usage pattern in `data/scripts/surf.inc` and grant Surf immediately after the gym reward.

**Rationale:** The chapter design says Badge 2 should change exploration. Surf is the cleanest and most visible exploration unlock.

**Alternatives considered:** Delay Surf to a later chapter. Rejected because the chapter design explicitly uses Surf as the reward hook.

### 6. Keep the new map group consistent with the existing Beaconfall layout
**Decision:** Add a `gMapGroup_BeaconfallChapter2` entry to `data/maps/map_groups.json` and keep each new area in its own CamelCase folder.

**Rationale:** Chapter 1 already uses a dedicated Beaconfall map group. Chapter 2 should follow the same structure for maintainability.

**Alternatives considered:** Mix Chapter 2 maps into the Chapter 1 group. Rejected because it would blur chapter boundaries and make navigation harder.

## Files To Touch

- `data/scripts/chapter_2.inc`
- `data/event_scripts.s`
- `data/scripts/new_game.inc`
- `data/maps/map_groups.json`
- `include/constants/flags.h`
- `include/constants/vars.h`
- `include/constants/opponents.h`
- `src/data/trainers.party`
- `src/data/wild_encounters.json`
- `data/scripts/surf.inc` (reference only; reward flow pattern)
