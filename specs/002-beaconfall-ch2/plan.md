# Pokemon Beaconfall - Chapter 2 Technical Implementation Plan

**Version:** 1.0  
**Date:** 2026-03-28  
**Based on:** Beaconfall Constitution v1.0.0 + `specs/002-beaconfall-ch2/spec.md`

---

## Executive Summary

Chapter 2 expands Beaconfall from the Chapter 1 slice into a coastal route, a water-control dungeon, a city hub, and a gym finale that awards Badge 2 plus Surf. The implementation stays decomp-native, reuses the existing map/script/battle systems, and carries the chapter forward with deterministic progression flags and variables.

This chapter is intentionally linear. The player should move from Chapter 1 completion into Saltwind Coast, then through Floodgate Tunnels, into Lumenport City, through a rival checkpoint, and finally into Astral Tide Gym. The chapter's signature mechanic is water-level control, reused across exploration, puzzle design, and the gym encounter.

---

## Constraints & Decisions

| Decision | Choice | Why it matters |
|---|---|---|
| Chapter flow | Sequential, chapter-by-chapter implementation | Keeps the chapter shippable and easy to debug |
| Trainer budget | Hybrid approach: keep core battles, trim the optional mini-boss and any extra filler fights | The current trainer ID budget is tight; Chapter 2 should stay within a minimal expansion |
| Battle pacing | Preserve the route -> dungeon -> rival -> gym order | Matches the chapter design and keeps pacing readable |
| State model | Use flags for progression and vars for water states / rival state | Keeps the chapter deterministic and save-safe |
| Map system | Porymap maps with per-map scripts | Matches the existing Beaconfall implementation style |
| Reward flow | Badge 2 first, Surf immediately after | Surf is the chapter's major exploration unlock |
| Testing | Manual emulator playtesting and save/load checks | Matches the repo's ROM-hack workflow |
| Engine scope | No custom battle engine or field system rewrite | Stays inside the constitution and the current codebase patterns |

### Trainer Capacity Note

Chapter 1 already uses the Beaconfall trainer ID range at the top of `include/constants/opponents.h`. Chapter 2 therefore uses a **hybrid content plan**: keep the core trainer battles, trim the optional mini-boss content, and only expand trainer capacity if the final core roster still does not fit. The default target is **9 new Chapter 2 trainer slots** total.

---

## Constitution Check

| Principle | Status | Chapter 2 note |
|---|---|---|
| 1. Chapter 1 Is a Playable First-Badge Vertical Slice | ✓ | Chapter 2 starts only after Chapter 1 completion and ends at Badge 2 + Surf |
| 2. Decomp-Native Workflow Is Required | ✓ | Maps, scripts, trainer data, and encounters stay in the existing repo formats |
| 3. Prefer Existing Engine Systems Before Custom Code | ✓ | Reuse map scripts, flags, vars, and existing battle/event commands |
| 4. Progression Is Deterministic With Flags and Variables | ✓ | Water states, rival state, and chapter milestones are tracked explicitly |
| 5. Quality of Life Is Allowed Only When It Reduces Friction | ✓ | Keep fast text, move reminder access, and similar low-friction QoL only |

No constitution amendment is required for Chapter 2.

---

## Technical Context

| Property | Value | Notes |
|---|---|---|
| Base repo | `pokeemerald-expansion` | Existing Beaconfall foundation |
| Build target | `make` -> `pokeemerald.gba` | Standard ROM build workflow |
| Map editor | Porymap | Chapter 2 maps are Porymap-authored JSON assets |
| Script format | `.inc` event scripts | Use the same script style as Chapter 1 |
| Trainer data | `src/data/trainers.party` | This repo stores Beaconfall party data here |
| Encounter data | `src/data/wild_encounters.json` | Extend the existing JSON format |
| Shared chapter scripts | `data/scripts/chapter_2.inc` | New shared progression helpers for Chapter 2 |
| Reset path | `data/scripts/new_game.inc` | Extend Chapter 1 reset flow to clear Chapter 2 state |
| Script assembly | `data/event_scripts.s` | Include the new Chapter 2 script file here |
| Map grouping | `data/maps/map_groups.json` | Add a Beaconfall Chapter 2 map group |
| Reward script pattern | `data/scripts/surf.inc` | Copy the existing Surf usage pattern for reward unlock flow |

---

## Project Structure

```text
data/maps/
  SaltwindCoast/
    map.json
    scripts.inc
  FloodgateTunnels/
    map.json
    scripts.inc
  LumenportCity/
    map.json
    scripts.inc
  AstralTideGym/
    map.json
    scripts.inc

data/scripts/
  chapter_2.inc
  new_game.inc
  surf.inc
  ... existing shared scripts ...

include/constants/
  flags.h
  vars.h
  opponents.h

src/data/
  trainers.party
  wild_encounters.json

data/event_scripts.s
  # include chapter_2.inc alongside chapter_1.inc

data/maps/map_groups.json
  # add gMapGroup_BeaconfallChapter2
```

---

## Chapter 2 State Model

Chapter 2 should be implemented as a small deterministic state machine. The plan uses explicit flags for chapter milestones and explicit vars for puzzle/water state.

### Progress Flags

| Flag | Purpose | Used by |
|---|---|---|
| `FLAG_CHAPTER_1_COMPLETE` | Entry gate into Chapter 2 | Route and story entry checks |
| `FLAG_CHAPTER_2_COMPLETE` | Overall chapter completion | End-of-chapter gating and future chapter setup |
| `FLAG_FLOODGATE_VALVE_A` | First valve milestone | Floodgate puzzle progress |
| `FLAG_FLOODGATE_VALVE_B` | Second valve milestone | Floodgate puzzle progress |
| `FLAG_FLOODGATE_VALVE_C` | Third valve milestone | Floodgate puzzle progress |
| `FLAG_SALTWIND_COAST_CLEARED` | Saltwind progression marker | Route progression / revisit logic |
| `FLAG_FLOODGATE_TUNNELS_CLEARED` | Dungeon completion marker | City access and state persistence |
| `FLAG_RIVAL2_DONE` | Rival battle complete | Prevent repeat battles |
| `FLAG_GYM2_CLEARED` | Gym complete | Chapter completion and reward flow |
| `FLAG_SURF_UNLOCKED` | Surf reward active | Future exploration unlock |

### Progress Variables

| Variable | Purpose | Notes |
|---|---|---|
| `VAR_RIVAL2_STATE` | Rival checkpoint state | Keeps the rival flow isolated from Chapter 1 logic |
| `VAR_WATER_LEVEL_FLOODGATE` | Floodgate water state | Values: 0 drained, 1 partial, 2 full |
| `VAR_WATER_LEVEL_GYM` | Gym water state | Values: 0 drained, 1 partial, 2 full |

### Design Decisions

- Use a dedicated Chapter 2 rival variable instead of reusing `VAR_RIVAL_BATTLES`.
- Keep water-level logic isolated per area so Floodgate and the gym do not share state.
- Use flags for one-time progression and vars for stateful puzzle logic.
- Treat the optional mini-boss as deferred content unless the trainer budget expands cleanly.

---

## Implementation Phases

### Phase 0 - Research and File Inventory

Goal: confirm the exact repo conventions before writing Chapter 2 content.

#### Research tasks

- Review the Chapter 1 script flow in `data/scripts/chapter_1.inc`.
- Confirm reset behavior in `data/scripts/new_game.inc`.
- Confirm script assembly in `data/event_scripts.s`.
- Confirm the Chapter 1 map grouping in `data/maps/map_groups.json`.
- Confirm trainer-party storage in `src/data/trainers.party`.
- Confirm encounter JSON structure in `src/data/wild_encounters.json`.
- Confirm badge reward flow in `data/maps/ForteHallGym/scripts.inc`.
- Confirm Surf usage / reward pattern in `data/scripts/surf.inc`.

#### Research output

- `research.md` documenting final decisions, alternatives considered, and any constraints that shape the chapter build.

---

### Phase 1 - Shared Chapter 2 Plumbing

Goal: add the chapter-wide state and script hooks once, then reuse them across the maps.

#### File changes

- [`include/constants/flags.h`](include/constants/flags.h)
  - Add the Chapter 2 flags in the unused flag range.
- [`include/constants/vars.h`](include/constants/vars.h)
  - Add `VAR_RIVAL2_STATE`, `VAR_WATER_LEVEL_FLOODGATE`, and `VAR_WATER_LEVEL_GYM` in the unused var range.
- [`include/constants/opponents.h`](include/constants/opponents.h)
  - Add Chapter 2 trainer constants, keeping the roster to the hybrid budget.
- [`data/scripts/chapter_2.inc`](data/scripts/chapter_2.inc)
  - New shared progression helpers for Chapter 2.
- [`data/event_scripts.s`](data/event_scripts.s)
  - Include the new Chapter 2 script file next to the Chapter 1 include.
- [`data/scripts/new_game.inc`](data/scripts/new_game.inc)
  - Clear Chapter 2 flags and vars during reset.
- [`data/maps/map_groups.json`](data/maps/map_groups.json)
  - Register the new Chapter 2 map group.

#### Chapter 2 script responsibilities

- Reset chapter state on new game.
- Mark chapter milestones when Saltwind, Floodgate, and the gym are cleared.
- Set the chapter complete flag when Surf is awarded.
- Provide shared helper labels for route entry, dungeon completion, rival completion, and reward flow.

---

### Phase 2 - Saltwind Coast

Goal: build the opening route with a risk/reward lane choice and enough battles to establish Chapter 2's tone.

#### Target files

- [`data/maps/SaltwindCoast/map.json`](data/maps/SaltwindCoast/map.json)
- [`data/maps/SaltwindCoast/scripts.inc`](data/maps/SaltwindCoast/scripts.inc)
- [`src/data/trainers.party`](src/data/trainers.party)
- [`src/data/wild_encounters.json`](src/data/wild_encounters.json)

#### Implementation notes

- Build the route as a single chapter-opening map with distinct safe and breaker lane flow.
- Keep the safe lane straightforward and trainer-heavy.
- Keep the breaker lane lighter on trainers but stronger on wild encounter or item reward pressure.
- Keep the total route trainer budget small enough to fit the hybrid trainer cap.
- Use a map transition script that keeps the world map state consistent with the existing Beaconfall style.
- Put the route clear flag in the route-complete script so later gates can read it cleanly.

#### Validation

- Player can enter Saltwind Coast only after Chapter 1 completion.
- Both lane choices remain completable.
- Route trainers trigger correctly.
- Wild encounters match the chapter tone.
- Revisit behavior stays stable after the route is cleared.

---

### Phase 3 - Floodgate Tunnels

Goal: implement the chapter's central puzzle dungeon and its water-state logic.

#### Target files

- [`data/maps/FloodgateTunnels/map.json`](data/maps/FloodgateTunnels/map.json)
- [`data/maps/FloodgateTunnels/scripts.inc`](data/maps/FloodgateTunnels/scripts.inc)
- [`src/data/trainers.party`](src/data/trainers.party)
- [`src/data/wild_encounters.json`](src/data/wild_encounters.json)

#### Implementation notes

- Use `VAR_WATER_LEVEL_FLOODGATE` as the single source of truth for the dungeon state.
- Use three valves and the associated flags to mark puzzle progress.
- Update map access immediately after each valve interaction so the player can read the state change.
- Keep wrong choices recoverable by moving the player into a backtrackable state rather than resetting the whole dungeon.
- Add a small number of dungeon battles and at least one hint NPC so the player can infer the correct sequence.
- If the final dungeon layout needs a simplification to avoid trainer-cap pressure, trim optional item rooms before trimming puzzle readability.

#### Validation

- Water state is readable in each puzzle room.
- Wrong lever choices never soft-lock the player.
- Dungeon completion unlocks the path to Lumenport City.
- Save/load preserves the dungeon's resolved state.

---

### Phase 4 - Lumenport City, Rival, and Astral Tide Gym

Goal: build the chapter hub, checkpoint rival battle, final gym puzzle, and reward flow.

#### Target files

- [`data/maps/LumenportCity/map.json`](data/maps/LumenportCity/map.json)
- [`data/maps/LumenportCity/scripts.inc`](data/maps/LumenportCity/scripts.inc)
- [`data/maps/AstralTideGym/map.json`](data/maps/AstralTideGym/map.json)
- [`data/maps/AstralTideGym/scripts.inc`](data/maps/AstralTideGym/scripts.inc)
- [`src/data/trainers.party`](src/data/trainers.party)
- [`data/scripts/surf.inc`](data/scripts/surf.inc)

#### Implementation notes

- Make Lumenport feel like a real harbor hub with the services the spec calls for.
- Trigger the rival battle after Floodgate and before the gym.
- Use `VAR_RIVAL2_STATE` and `FLAG_RIVAL2_DONE` to keep the rival encounter one-time only.
- Reuse the water-level idea in the gym, but keep the layout tighter than Floodgate.
- Place the gym leader battle behind a readable puzzle gate.
- Award Badge 2 and Surf in the leader reward script.
- Set `FLAG_GYM2_CLEARED`, `FLAG_SURF_UNLOCKED`, and `FLAG_CHAPTER_2_COMPLETE` at the reward step.

#### Validation

- Lumenport services are reachable only after the dungeon flow.
- Rival battle occurs once and does not repeat.
- Gym puzzle gates the leader correctly.
- Badge 2 and Surf unlock together at the end of the chapter.
- The chapter complete state persists after save/load.

---

### Phase 5 - Validation and Polish

Goal: prove the chapter is complete, stable, and ready to hand off to task generation and implementation.

#### Final checks

- Build the ROM with `make clean && make`.
- Run a full fresh-save playthrough from Chapter 1 completion to Badge 2.
- Confirm route, dungeon, city, rival, gym, reward, and Surf flow all work in sequence.
- Verify no soft-locks, duplicate triggers, or broken map transitions.
- Confirm save/load stability after each major milestone.

#### Validation output

- `quickstart.md` with a playtest checklist and expected results.
- `data-model.md` with the final chapter entities and state transitions.
- Updated `research.md` with decisions and rationale.

---

## Dependencies and Execution Order

1. Shared Chapter 2 plumbing must land before any map-specific work.
2. Saltwind Coast must be playable before Floodgate Tunnels is wired.
3. Floodgate must be completable before Lumenport and the rival/gym sequence are finalized.
4. The gym reward flow must be complete before final validation or task generation.
5. Validation must pass before `/speckit.tasks` and `/speckit.analyze` are considered ready.

---

## Risks and Mitigations

| Risk | Impact | Mitigation |
|---|---|---|
| Trainer ID pressure | Could block the planned trainer roster | Keep the roster to the hybrid core set and defer the optional mini-boss |
| Water-state desync | Could create puzzle bugs or soft-locks | Use one var per puzzle area and update the map state immediately |
| Reward gating bugs | Could break Surf unlock or chapter completion | Centralize reward logic in `data/scripts/chapter_2.inc` |
| Map registration mistakes | Could leave maps unreachable | Add the map group once and validate against the build |
| Save/reset bugs | Could corrupt chapter flow between runs | Extend the new game reset path and test save/load repeatedly |

---

## Success Criteria for the Implementation Plan

- Chapter 2 can be built from the repo root with `make`.
- The spec, plan, research, data model, and quickstart artifacts are all present under `specs/002-beaconfall-ch2/`.
- The chapter implementation has a clear file-by-file scope.
- The chapter remains linear and readable, with water-state logic reused across the route, dungeon, and gym.
- The trainer roster fits the hybrid plan without forcing a large engine rewrite.
- The chapter ends with Badge 2 and Surf unlocked, and that unlock remains stable after save/load.

---

## Deliverables

- [`specs/002-beaconfall-ch2/research.md`](specs/002-beaconfall-ch2/research.md)
- [`specs/002-beaconfall-ch2/data-model.md`](specs/002-beaconfall-ch2/data-model.md)
- [`specs/002-beaconfall-ch2/quickstart.md`](specs/002-beaconfall-ch2/quickstart.md)
- [`specs/002-beaconfall-ch2/plan.md`](specs/002-beaconfall-ch2/plan.md)

