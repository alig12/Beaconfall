# Tasks: Pokemon Beaconfall Chapter 2

**Input**: Design documents from `specs/002-beaconfall-ch2/`
**Prerequisites**: `plan.md` (required), `spec.md` (required for user stories), `research.md`, `data-model.md`, `quickstart.md`
**Validation**: Build, save/load, and playability validation tasks are included because Chapter 2 release criteria require them.
**Organization**: Tasks are grouped by user story to enable independent implementation and validation of each chapter beat.

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Create the chapter scaffolds and shared data placeholders.

- [ ] T001 Create Saltwind Coast map scaffold in `data/maps/SaltwindCoast/map.json` and `data/maps/SaltwindCoast/scripts.inc`
- [ ] T002 Create Floodgate Tunnels map scaffold in `data/maps/FloodgateTunnels/map.json` and `data/maps/FloodgateTunnels/scripts.inc`
- [ ] T003 Create Lumenport City map scaffold in `data/maps/LumenportCity/map.json` and `data/maps/LumenportCity/scripts.inc`
- [ ] T004 Create Astral Tide Gym map scaffold in `data/maps/AstralTideGym/map.json` and `data/maps/AstralTideGym/scripts.inc`
- [ ] T005 Register the Chapter 2 map group in `data/maps/map_groups.json`
- [ ] T006 Create the shared Chapter 2 progression scaffold in `data/scripts/chapter_2.inc`

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core chapter state that every user story depends on.

**Checkpoint**: The shared flags, variables, and scaffolds exist before any user story work starts.

- [ ] T007 Extend `data/scripts/new_game.inc` to clear Chapter 2 flags and vars on a new game
- [ ] T008 Include `data/scripts/chapter_2.inc` from `data/event_scripts.s`
- [ ] T009 Define Chapter 2 flags in `include/constants/flags.h`
- [ ] T010 Define Chapter 2 variables in `include/constants/vars.h`
- [ ] T011 Define Chapter 2 trainer IDs in `include/constants/opponents.h`
- [ ] T012 Seed Chapter 2 trainer party placeholders in `src/data/trainers.party`
- [ ] T013 Seed Chapter 2 encounter placeholders in `src/data/wild_encounters.json`

---

## Phase 3: User Story 1 - Cross Saltwind Coast (Priority: P1)

**Goal**: The opening route gives the player a safe lane and a riskier lane, then sends them into Floodgate Tunnels.

**Independent Test**: Start from a Chapter 1-complete save, traverse either Saltwind Coast lane, and reach Floodgate Tunnels without soft-locking or touching later chapter content.

### Implementation for User Story 1

- [ ] T014 Implement Saltwind Coast lane layout and traversal flow in `data/maps/SaltwindCoast/map.json`
- [ ] T015 Implement Saltwind Coast route scripts, gate logic, and route-clear state in `data/maps/SaltwindCoast/scripts.inc`
- [ ] T016 Add Saltwind Coast trainer parties in `src/data/trainers.party`
- [ ] T017 Add Saltwind Coast wild encounter tables in `src/data/wild_encounters.json`
- [ ] T018 Validate Saltwind Coast traversal, lane choice, and route pacing using `specs/002-beaconfall-ch2/quickstart.md`

**Checkpoint**: Both lane choices remain completable and lead to the dungeon entrance.

### Sequential Example: User Story 1

```text
Task: "Implement Saltwind Coast lane layout and traversal flow in `data/maps/SaltwindCoast/map.json`"
Task: "Implement Saltwind Coast route scripts, gate logic, and route-clear state in `data/maps/SaltwindCoast/scripts.inc`"
Task: "Add Saltwind Coast trainer parties in `src/data/trainers.party`"
Task: "Add Saltwind Coast wild encounter tables in `src/data/wild_encounters.json`"
```

---

## Phase 4: User Story 2 - Solve Floodgate Tunnels (Priority: P2)

**Goal**: Floodgate Tunnels uses the chapter's water-state mechanic and stays recoverable if the player picks the wrong lever sequence.

**Independent Test**: Enter Floodgate Tunnels, change water levels, and verify the player can open the intended paths and exit to Lumenport City without soft-locking.

### Implementation for User Story 2

- [ ] T019 Implement Floodgate Tunnels room layout and gate flow in `data/maps/FloodgateTunnels/map.json`
- [ ] T020 Implement Floodgate valve scripts, water-state transitions, and progression tracking in `data/maps/FloodgateTunnels/scripts.inc`
- [ ] T021 Add Floodgate trainers, hint NPCs, and item-room behavior in `data/maps/FloodgateTunnels/scripts.inc` and `src/data/trainers.party`
- [ ] T022 Add Floodgate encounter tables in `src/data/wild_encounters.json`
- [ ] T023 Validate Floodgate recovery, water-state transitions, and exit flow using `specs/002-beaconfall-ch2/quickstart.md`

**Checkpoint**: The dungeon stays readable, recoverable, and linear.

### Sequential Example: User Story 2

```text
Task: "Implement Floodgate Tunnels room layout and gate flow in `data/maps/FloodgateTunnels/map.json`"
Task: "Implement Floodgate valve scripts, water-state transitions, and progression tracking in `data/maps/FloodgateTunnels/scripts.inc`"
Task: "Add Floodgate trainers, hint NPCs, and item-room behavior in `data/maps/FloodgateTunnels/scripts.inc` and `src/data/trainers.party`"
Task: "Add Floodgate encounter tables in `src/data/wild_encounters.json`"
```

---

## Phase 5: User Story 3 - Reach Lumenport, defeat the rival, and clear Astral Tide Gym (Priority: P3)

**Goal**: The city hub, rival checkpoint, final gym puzzle, and reward flow finish the chapter with Badge 2 plus Surf.

**Independent Test**: From Floodgate completion, visit Lumenport City, trigger the rival battle, clear Astral Tide Gym, and receive Badge 2 plus Surf.

### Implementation for User Story 3

- [ ] T024 Implement Lumenport City hub layout and service access in `data/maps/LumenportCity/map.json`
- [ ] T025 Implement Lumenport City story scripts, rival trigger, and rival party data in `data/maps/LumenportCity/scripts.inc` and `src/data/trainers.party`
- [ ] T026 Implement Astral Tide Gym layout and water puzzle in `data/maps/AstralTideGym/map.json`
- [ ] T027 Implement Astral Tide Gym trainer flow, leader battle, and reward script in `data/maps/AstralTideGym/scripts.inc` and `src/data/trainers.party`
- [ ] T028 Wire Badge 2, Surf unlock, and Chapter 2 completion in `data/scripts/chapter_2.inc` and `data/scripts/surf.inc`
- [ ] T029 Validate rival single-trigger behavior, gym completion, and Surf unlock using `specs/002-beaconfall-ch2/quickstart.md`

**Checkpoint**: Rival, gym, Badge 2, and Surf all resolve once and persist after save/load.

### Sequential Example: User Story 3

```text
Task: "Implement Lumenport City hub layout and service access in `data/maps/LumenportCity/map.json`"
Task: "Implement Lumenport City story scripts and rival trigger in `data/maps/LumenportCity/scripts.inc`"
Task: "Implement Astral Tide Gym layout and water puzzle in `data/maps/AstralTideGym/map.json`"
Task: "Implement Astral Tide Gym trainer flow, leader battle, and reward script in `data/maps/AstralTideGym/scripts.inc` and `src/data/trainers.party`"
```

---

## Phase 6: Polish & Cross-Cutting Concerns

**Purpose**: Chapter-wide validation and cleanup.

- [ ] T030 Build the ROM with `make clean && make` and fix compile issues across Chapter 2 files
- [ ] T031 Run a fresh-save Chapter 2 regression playthrough and confirm the route, dungeon, rival, and gym sequence
- [ ] T032 Run save/load regression checkpoints for route progress, water states, rival state, gym clear state, and Surf unlock
- [ ] T033 Tidy follow-up notes or balance tweaks in `research.md` and `quickstart.md` if validation exposes gaps

---

## Dependencies & Execution Order

- Phase 1 has no dependencies and can start immediately.
- Phase 2 depends on Phase 1 scaffolds and blocks all story work.
- User Story 1 depends on Phase 2 and is the MVP slice.
- User Story 2 depends on Phase 2 and the opening flow established in User Story 1.
- User Story 3 depends on Phase 2 and the dungeon flow established in User Story 2.
- Phase 6 depends on all desired user stories being complete.

## Parallel Opportunities

No parallel execution is assumed for this chapter. Follow the checklist sequentially so stateful route, dungeon, rival, and reward logic stays easy to debug.

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup.
2. Complete Phase 2: Foundational.
3. Complete Phase 3: User Story 1.
4. Stop and validate the opening sequence before moving on.

### Incremental Delivery

1. Add User Story 1 and confirm Saltwind Coast works end to end.
2. Add User Story 2 and confirm Floodgate is recoverable and readable.
3. Add User Story 3 and confirm the city, rival, gym, and reward flow complete the chapter.
4. Finish with build and regression passes before release.

### Sequential Validation

1. Validate the route first.
2. Validate the dungeon second.
3. Validate the city, rival, and gym third.
4. Validate the whole chapter last.
