# Pokémon Beaconfall — Chapter 1 Technical Implementation Plan

**Version:** 1.0.0
**Date:** 2026-03-28
**Based on:** Constitution v1.0.0 + Specification v1.0.0

---

## Executive Summary

Pokémon Beaconfall Chapter 1 will be implemented as a decomp-native vertical slice in
`pokeemerald-expansion`. The work is bounded to five maps, two rival battles, one badge, and a
deterministic gym-light puzzle, with all chapter state tracked by flags and variables. Success
means the ROM builds cleanly, the chapter is playable start-to-badge, and the Chapter 2 hook is
unlocked by a single completion flag.

---

## Constitution Check

This plan adheres to all Core Principles and governance rules from the Beaconfall Constitution:

|Principle|Status|Notes|
|---|---|---|
|1. Playable First-Badge Vertical Slice|✓|Scope ends at the first badge and Chapter 2 hook; no extra chapter content is planned.|
|2. Decomp-Native Workflow Is Required|✓|Use Porymap, map-local scripts, shared `.inc` scripts, trainer tables, encounter tables, and `make`.|
|3. Prefer Existing Engine Systems Before Custom Code|✓|Use existing battle, event, and UI systems; no custom engine layer is planned.|
|4. Progression Is Deterministic With Flags and Variables|✓|All gating state lives in flags and variables, including the gym puzzle and chapter completion.|
|5. Quality of Life Is Allowed Only When It Reduces Friction|✓|QoL is limited to friction reduction inside the first chapter loop.|

---

## Technical Context

### Target Engine & Build

|Property|Value|
|---|---|
|Base Repo|`pokeemerald-expansion`|
|Build Target|`pokeemerald.gba`|
|Toolchain|GNU Make + devkitARM|
|Map Authoring|Porymap exports under `data/maps/<MapName>/map.json` plus `scripts.inc`|
|Event Scripting|Map-local `scripts.inc` files and shared `data/scripts/*.inc` flow scripts|
|Trainer Data|`src/data/trainer_parties.h`|
|Wild Encounters|`src/data/wild_encounters.json`|
|Flags|`include/constants/flags.h`|
|Variables|`include/constants/vars.h`|
|External Contracts|None; Chapter 1 is an in-game feature, not a public interface.|

### File and Data Targets

- `data/maps/EmberHollowTown/map.json` and `data/maps/EmberHollowTown/scripts.inc`
- `data/maps/Route1_SaltwindPath/map.json` and `data/maps/Route1_SaltwindPath/scripts.inc`
- `data/maps/CinderReedGrove/map.json` and `data/maps/CinderReedGrove/scripts.inc`
- `data/maps/BrassfallCity/map.json` and `data/maps/BrassfallCity/scripts.inc`
- `data/maps/ForteHallGym/map.json` and `data/maps/ForteHallGym/scripts.inc`
- `data/scripts/new_game.inc` for the opening sequence handoff
- `data/scripts/chapter_1.inc` for shared Chapter 1 progression
- `src/data/trainer_parties.h` for trainer and rival parties
- `src/data/wild_encounters.json` for Chapter 1 encounters
- `include/constants/flags.h` and `include/constants/vars.h` for chapter state
- No `/contracts` directory is required because the chapter does not expose an external API

---

## Project Structure

```text
data/maps/
  EmberHollowTown/
    map.json
    scripts.inc
  Route1_SaltwindPath/
    map.json
    scripts.inc
  CinderReedGrove/
    map.json
    scripts.inc
  BrassfallCity/
    map.json
    scripts.inc
  ForteHallGym/
    map.json
    scripts.inc
data/scripts/
  new_game.inc
  chapter_1.inc
src/data/trainer_parties.h
src/data/wild_encounters.json
include/constants/flags.h
include/constants/vars.h
```

---

## Progression Flags & Variables

### State Tracking

|Flag / Variable|Purpose|Set By|
|---|---|---|
|`FLAG_STARTER_CHOSEN_*`|Starter selection completion|Starter choice event|
|`FLAG_ROUTE_1_CLEARED`|Route traversal milestone|Route 1 battle flow completion|
|`FLAG_CINDER_REED_GROVE_CLEARED`|Grove milestone|Cinder Reed Grove completion|
|`FLAG_BRASSFALL_CITY_ENTERED`|City arrival|Map entry event|
|`VAR_GYM_LIGHT_STATE`|Gym puzzle light state|Gym trainer victories|
|`VAR_RIVAL_BATTLES`|Rival encounter count|Rival battle scripts|
|`FLAG_CHAPTER_1_COMPLETE`|Chapter completion gate|Gym leader defeat and badge award|

### State Model

- `StarterChoice` captures the chosen starter and the one-time starter reward state.
- `RivalEncounter` captures the two scripted rival battles and their completion status.
- `GymPuzzleState` captures the current light progress and which sections are unlocked.
- `RewardState` captures badge award, next-route unlock, and the Chapter 2 hook.
- `ChapterProgress` owns the ordered chapter beats and the completion flag.

---

## Map & Event Wiring

### Five Core Maps

|Map|Purpose|Wiring|Primary State|
|---|---|---|---|
|Ember Hollow Town|Opening town|Starter choice, professor intro, Pokédex grant|`FLAG_STARTER_CHOSEN_*`|
|Route 1 / Saltwind Path|First route|Rival Battle 1, route trainers, pickup flow|`VAR_RIVAL_BATTLES = 1`, `FLAG_ROUTE_1_CLEARED`|
|Cinder Reed Grove|Dungeon-lite area|Three trainers, navigation gate, story clue|`FLAG_CINDER_REED_GROVE_CLEARED`|
|Brassfall City|Hub city|Rival Battle 2, recovery, gym access|`FLAG_BRASSFALL_CITY_ENTERED`, `VAR_RIVAL_BATTLES = 2`|
|Forte Hall Gym|Final Chapter 1 challenge|Light puzzle, gym trainers, leader, badge, hook|`VAR_GYM_LIGHT_STATE`, `FLAG_CHAPTER_1_COMPLETE`|

### Event Script Flow

1. The opening sequence in `data/scripts/new_game.inc` routes into the chapter intro and starter
   selection.
2. Starter selection grants the chosen starter, sets the starter flag family, and awards the
   Pokédex.
3. Route 1 unlocks Rival Battle 1 and the first trainer set.
4. Cinder Reed Grove gates progress until the grove beat is cleared and the story clue is
   recovered.
5. Brassfall City marks the recovery point and triggers Rival Battle 2 before gym access.
6. Forte Hall Gym ties each trainer defeat to a light-state update.
7. The gym leader awards the first badge and sets the chapter-complete flag.
8. The Chapter 2 hook plays only after the badge is awarded.
9. Save/load must preserve every flag and variable needed to resume without replaying completed
   beats.

---

## Build, Validation, and Release Workflow

### Build Workflow

- Export or save each map in Porymap and keep the `map.json` and `scripts.inc` files in sync.
- Update trainer parties, encounter tables, flags, and variables alongside the map flow.
- Build the ROM with `make`.
- Load the ROM in an emulator and start a fresh playthrough.

### Validation Gates

- Fresh-start test: starter choice, Pokédex grant, and the first chapter objective work.
- Route test: the player clears Route 1, Cinder Reed Grove, and both rival battles in order.
- Gym test: the light puzzle behaves deterministically and the badge is awarded once.
- Save/load test: starter choice, rival count, puzzle state, and chapter completion survive
  reloads.
- Release test: the chapter can be completed start-to-badge without crashes or soft-locks.

### Release Workflow

- Release is blocked unless all 10 constitution release criteria are green.
- Any failure in save/load persistence, badge award, or Chapter 2 handoff is a hard stop.
- Any request that adds custom code or scope beyond the first badge must go through amendment
  before work starts.
- Change control rejects additions that do not improve the first 60-second loop or reduce
  friction.

---

## Scope Lock Notes

- Chapter 1 is fixed to five maps, two rival battles, one badge, and no postgame.
- The starter trio is fixed to Turtwig, Chimchar, and Piplup.
- Trainer count stays at or below 10 and wild species stay in the 20-30 range.
- Fusion mechanics, field effects, open-world scaling, multiplayer, and postgame content are out
  of scope.
- QoL is allowed only when it reduces friction in the first chapter loop.
- Any feature outside those bounds goes to Chapter 2 or the parking lot.

---

## Complexity Tracking (If Needed)

|System|Complexity|Why it matters|Mitigation|
|---|---|---|---|
|Gym puzzle logic|Medium|Light-state progression must be deterministic and persistent.|Keep all puzzle state in one variable family and validate save/load.|
|Chapter completion gating|Medium|Badge award, hook trigger, and chapter-complete flag must fire once.|Use a single completion path and regression-test it end-to-end.|
|Route and grove balance|Low|The chapter must feel full without adding scope.|Use pacing, trainer design, and item rewards instead of extra systems.|

---

## Success Criteria

- All constitution release criteria are addressed by the design.
- All file and data targets are identified and mapped to existing repo conventions.
- Research, data model, and quickstart artifacts are complete.
- No unresolved scope conflicts or hidden dependencies remain.
- The chapter can be implemented without introducing a new engine layer.

**Plan Approved By:** Pending review
**Date:** 2026-03-28
