# Tasks: Pokémon Beaconfall Chapter 1

**Input**: Design documents from `specs/001-beaconfall-ch1-spec/`
**Prerequisites**: `plan.md` (required), `spec.md` (required for user stories), `research.md`,
`data-model.md`, `quickstart.md`
**Validation**: Automated tests were not explicitly requested. Build, save/load, and playability
validation tasks are included because Chapter 1 release criteria require them.
**Organization**: Tasks are grouped by user story to enable independent implementation and
validation of each chapter beat.

## Phase 1: Setup (Shared Infrastructure)

**Purpose**: Create the chapter scaffolds and shared data placeholders.

- [ ] T001 [P] Create Ember Hollow Town map scaffold in `data/maps/EmberHollowTown/map.json` and
  `data/maps/EmberHollowTown/scripts.inc`
- [ ] T002 [P] Create Route 1 / Saltwind Path map scaffold in
  `data/maps/Route1_SaltwindPath/map.json` and `data/maps/Route1_SaltwindPath/scripts.inc`
- [ ] T003 [P] Create Cinder Reed Grove map scaffold in `data/maps/CinderReedGrove/map.json` and
  `data/maps/CinderReedGrove/scripts.inc`
- [ ] T004 [P] Create Brassfall City map scaffold in `data/maps/BrassfallCity/map.json` and
  `data/maps/BrassfallCity/scripts.inc`
- [ ] T005 [P] Create Forte Hall Gym map scaffold in `data/maps/ForteHallGym/map.json` and
  `data/maps/ForteHallGym/scripts.inc`
- [ ] T006 [P] Register the five Chapter 1 map groups in `data/maps/map_groups.json`
- [ ] T007 [P] Create the opening sequence scaffold in `data/scripts/new_game.inc`
- [ ] T008 [P] Create the shared Chapter 1 progression scaffold in `data/scripts/chapter_1.inc`
- [ ] T009 [P] Seed Chapter 1 trainer party placeholders in `src/data/trainer_parties.h`
- [ ] T010 [P] Seed Chapter 1 encounter placeholders in `src/data/wild_encounters.json`

---

## Phase 2: Foundational (Blocking Prerequisites)

**Purpose**: Core chapter state that every user story depends on.

**Checkpoint**: The shared flags, variables, and scaffolds exist before any user story work starts.

- [ ] T011 [P] Define Chapter 1 flags in `include/constants/flags.h`
- [ ] T012 [P] Define Chapter 1 variables in `include/constants/vars.h`

---

## Phase 3: User Story 1 - Begin the Chapter (Priority: P1) 🎯 MVP

**Goal**: The opening sequence lets the player choose Growlithe, Wooper, or Budew and receive the
Pokédex.

**Independent Test**: Start a fresh save and reach the post-starter state without touching later
maps.

### Implementation for User Story 1

- [ ] T013 [P] [US1] Implement Ember Hollow Town starter selection and professor intro in
  `data/maps/EmberHollowTown/scripts.inc`
- [ ] T014 [P] [US1] Hook the starter reward, Pokédex grant, and opening objective into
  `data/scripts/new_game.inc`
- [ ] T015 [US1] Validate the fresh-start flow, starter persistence, and opening objective using
  `specs/001-beaconfall-ch1-spec/quickstart.md`

**Checkpoint**: Chapter 1 starts cleanly and preserves starter choice across save/load.

### Parallel Example: User Story 1

```text
Task: "Implement Ember Hollow Town starter selection and professor intro in `data/maps/EmberHollowTown/scripts.inc`"
Task: "Hook the starter reward, Pokédex grant, and opening objective into `data/scripts/new_game.inc`"
```

---

## Phase 4: User Story 2 - Traverse the Chapter Path (Priority: P2)

**Goal**: Route 1, Cinder Reed Grove, and Brassfall City flow in order with both rival battles.

**Independent Test**: Start from Route 1 and reach Brassfall City with both rival battles completed.

### Implementation for User Story 2

- [ ] T016 [P] [US2] Implement Route 1 traversal, Rival Battle 1 gate, and route trainer triggers
  in `data/maps/Route1_SaltwindPath/scripts.inc`
- [ ] T017 [P] [US2] Populate Route 1 trainer and rival parties in `src/data/trainer_parties.h`
- [ ] T018 [P] [US2] Implement Cinder Reed Grove navigation, story clue, and grove trainer flow in
  `data/maps/CinderReedGrove/scripts.inc`
- [ ] T019 [P] [US2] Add Route 1 and Cinder Reed Grove encounter tables in
  `src/data/wild_encounters.json`
- [ ] T020 [US2] Implement Brassfall City arrival, Rival Battle 2 gating, and recovery flow in
  `data/maps/BrassfallCity/scripts.inc`
- [ ] T021 [US2] Validate route-to-city progression, both rival battles, and grove completion using
  `specs/001-beaconfall-ch1-spec/quickstart.md`

**Checkpoint**: The player can reach Brassfall City only after the intended route and grove beats
are complete.

### Parallel Example: User Story 2

```text
Task: "Implement Route 1 traversal, Rival Battle 1 gate, and route trainer triggers in `data/maps/Route1_SaltwindPath/scripts.inc`"
Task: "Populate Route 1 trainer and rival parties in `src/data/trainer_parties.h`"
Task: "Implement Cinder Reed Grove navigation, story clue, and grove trainer flow in `data/maps/CinderReedGrove/scripts.inc`"
Task: "Add Route 1 and Cinder Reed Grove encounter tables in `src/data/wild_encounters.json`"
```

---

## Phase 5: User Story 3 - Earn the Badge (Priority: P3)

**Goal**: Forte Hall Gym lights, the gym leader battle, badge award, and Chapter 2 hook finish
Chapter 1.

**Independent Test**: Start from Brassfall City and complete the gym sequence only.

### Implementation for User Story 3

- [ ] T022 [P] [US3] Implement Forte Hall Gym lighting puzzle and gym access flow in
  `data/maps/ForteHallGym/scripts.inc`
- [ ] T023 [P] [US3] Populate gym trainer and leader parties in `src/data/trainer_parties.h`
- [ ] T024 [US3] Wire badge award, Chapter 2 hook, and chapter-complete flag in
  `data/scripts/chapter_1.inc`
- [ ] T025 [US3] Validate gym determinism, badge award, and save/load persistence using
  `specs/001-beaconfall-ch1-spec/quickstart.md`

**Checkpoint**: Gym progress, badge award, and chapter-complete state persist across save/load.

### Parallel Example: User Story 3

```text
Task: "Implement Forte Hall Gym lighting puzzle and gym access flow in `data/maps/ForteHallGym/scripts.inc`"
Task: "Populate gym trainer and leader parties in `src/data/trainer_parties.h`"
```

---

## Phase 6: Polish & Cross-Cutting Concerns

**Purpose**: Chapter-wide validation and cleanup.

- [ ] T026 Build the ROM with `make clean && make` and fix Chapter 1 compile failures in
  `data/scripts/chapter_1.inc`, `src/data/trainer_parties.h`, `src/data/wild_encounters.json`, and
  the five map scripts under `data/maps/EmberHollowTown/`, `data/maps/Route1_SaltwindPath/`,
  `data/maps/CinderReedGrove/`, `data/maps/BrassfallCity/`, and `data/maps/ForteHallGym/`
- [ ] T027 Run a full start-to-badge regression playthrough against
  `specs/001-beaconfall-ch1-spec/quickstart.md`
- [ ] T028 Run save/load regression checkpoints for starter choice, rival battles, gym state, and
  badge state using `specs/001-beaconfall-ch1-spec/quickstart.md`
- [ ] T029 Tidy any follow-up notes in `specs/001-beaconfall-ch1-spec/research.md` and
  `specs/001-beaconfall-ch1-spec/quickstart.md` if validation exposed gaps

---

## Dependencies & Execution Order

- Phase 1 has no dependencies and can start immediately.
- Phase 2 depends on Phase 1 scaffolds and blocks all story work.
- User Story 1 depends on Phase 2 and is the MVP slice.
- User Story 2 depends on Phase 2 and the opening flow established in User Story 1.
- User Story 3 depends on Phase 2 and the Chapter 1 path established by User Story 2.
- Phase 6 depends on all desired user stories being complete.

## Parallel Opportunities

- Phase 1 tasks T001-T010 can be split across separate map, script, and data files.
- Phase 2 tasks T011-T012 can be split across the two constants files.
- User Story 1 tasks T013-T014 can run in parallel once the scaffolds exist.
- User Story 2 tasks T016-T019 can run in parallel where they touch different files.
- User Story 3 tasks T022-T023 can run in parallel because they touch different files.

## Implementation Strategy

### MVP First (User Story 1 Only)

1. Complete Phase 1: Setup.
2. Complete Phase 2: Foundational.
3. Complete Phase 3: User Story 1.
4. Stop and validate the opening sequence before moving on.

### Incremental Delivery

1. Add User Story 1 and confirm the chapter opens correctly.
2. Add User Story 2 and confirm the route, grove, and city chain works.
3. Add User Story 3 and confirm the badge and Chapter 2 hook complete the slice.
4. Finish with build and regression passes before release.

### Parallel Team Strategy

1. One person can build map scaffolds while another seeds shared data files.
2. Once the scaffolds exist, separate people can work on story-specific map logic and shared data.
3. Final validation should be sequential so the full Chapter 1 path is verified end to end.
