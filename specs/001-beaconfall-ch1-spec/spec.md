# Feature Specification: Pokémon Beaconfall Chapter 1

**Feature Branch**: `001-beaconfall-ch1-spec`
**Created**: 2026-03-28
**Status**: Draft
**Input**: User description: "Write the Chapter 1 feature specification for Pokémon Beaconfall."

## Goal

Pokémon Beaconfall Chapter 1 is a complete, playable opening chapter that starts a fresh player in
Ember Hollow Town, teaches the core game loop, and ends with the first badge plus a clear next
objective. The starter trio is Growlithe, Wooper, and Budew. It must feel like a full episode on its
own, not a partial demo.

## Clarifications

### Session 2026-03-28

- Q: Which starter trio should Chapter 1 use? → A: Growlithe, Wooper, and Budew.

## Non-goals

- Fusion mechanics, field effects, open-world scaling, multiplayer, or postgame content.
- A second badge, extra gym, or any content beyond the first chapter ending.
- Side quest chains, reputation systems, or cosmetic customization that do not improve the chapter
  loop.
- Any progression that depends on hidden state or unclear unlocks.
- Any feature that expands the chapter beyond the first-badge boundary.

## Player experience

- The opening gets the player into the world quickly and makes the starting objective obvious.
- Early battles teach the basics without feeling long or punishing.
- Exploration stays compact, readable, and forward-moving.
- The gym puzzle feels fair because progress is visible at every step.
- The chapter ends with a reward, a clear next destination, and the feeling that a complete story
  beat was finished.

## Chapter flow

1. The player begins in Ember Hollow Town, meets the professor, and chooses Growlithe, Wooper, or
   Budew as a starter.
2. The player receives the Pokédex and the chapter's first objective.
3. The player moves through Route 1 / Saltwind Path, where the first rival battle and early trainer
   battles teach the loop.
4. The player enters Cinder Reed Grove, a short dungeon-like area that adds a small navigation
   challenge and more trainer battles.
5. The player reaches Brassfall City, recovers, and faces the second rival battle before the gym.
6. The player enters Forte Hall Gym, solves the lighting puzzle, defeats the gym trainers and
   leader, earns the first badge, and receives the Chapter 2 hook.

## Maps

| Map | Purpose | Player experience |
| --- | --- | --- |
| Ember Hollow Town | Opening town | Starter choice, professor intro, Pokédex, first objective |
| Route 1 / Saltwind Path | First route | Early exploration, trainer battles, Rival Battle 1, item pickups |
| Cinder Reed Grove | Dungeon-lite area | Short navigation challenge, trainer battles, story clue, item reward |
| Brassfall City | Hub city | Recovery point, preparation, Rival Battle 2, gym access |
| Forte Hall Gym | Final Chapter 1 challenge | Lighting puzzle, gym battles, badge, next objective |

## Battles

- Rival Battle 1 happens on Route 1 and introduces the chapter's starter match-up.
- Rival Battle 2 happens before the gym and shows the player's growth.
- Route, grove, and gym trainers provide a compact battle set that teaches one lesson at a time.
- The chapter must include at least six trainer battles before the badge.
- The gym leader battle is the capstone and must feel more memorable than the trainer fights
  without becoming a grind.
- Battles must stay readable and short; none should rely on obscure rules or late-game systems.

## Gym puzzle

- Forte Hall Gym uses a lighting puzzle where defeating trainers activates stage lights.
- Each victory must visibly unlock or reveal the next part of the path.
- The player must always understand what changed after a battle.
- The puzzle must not depend on random guesses, hidden switches, or trial-and-error.
- Puzzle progress must survive save/load and leaving the gym.

## Rewards

- The chapter begins with the starter choice and Pokédex.
- The first badge, Beacon Badge, is the main completion reward.
- The badge unlocks the next route and the Chapter 2 story hook.
- Small utility rewards are allowed only if they reduce friction and do not widen scope.
- Rewards must feel earned by the chapter's progress, not handed out early.

## Technical constraints

- The chapter must stay inside the first-badge scope lock.
- Progression must be deterministic and safe to save, reload, and resume.
- The chapter must remain a single-player story experience with no need for out-of-scope systems.
- No fusion, field effects, open-world scaling, multiplayer, or postgame content may be required.
- Any quality-of-life feature must reduce friction in the first chapter loop.
- The chapter must remain compatible with the project's GBA release format and its current chapter
  structure.

## Acceptance criteria

- A new player can start a fresh game, choose a starter, and receive the Pokédex.
- The player can move through all five Chapter 1 locations in the intended order.
- The player encounters exactly two rival battles during the chapter.
- The chapter includes at least six trainer battles before the badge.
- The gym puzzle behaves deterministically and clearly shows progress.
- The player earns the first badge and gets a clear Chapter 2 objective.
- Save and reload preserve starter choice, chapter progress, and puzzle state.
- No out-of-scope systems are needed to finish Chapter 1.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Begin the Chapter (Priority: P1)

A new player starts the game, completes the opening sequence, chooses Growlithe, Wooper, or Budew,
receives the Pokédex, and leaves the starting town with a clear first objective.

**Why this priority**: The opening must work before any later story beats matter. Without starter
selection and the first objective, the chapter cannot begin.

**Independent Test**: Start a fresh game and play only the opening sequence. Verify that the
starter choice completes, the Pokédex is granted, and the player can continue into the chapter
without restarting.

**Acceptance Scenarios**:

1. **Given** a fresh save, **When** the opening sequence ends, **Then** the player can choose one
   of Growlithe, Wooper, or Budew and receives the Pokédex.
2. **Given** a completed starter choice, **When** the player saves and reloads, **Then** the chosen
   starter and opening progress remain intact.

---

### User Story 2 - Traverse the Chapter Path (Priority: P2)

The player explores Route 1 / Saltwind Path, clears the small route and grove challenges, sees
both rival battles, and reaches Brassfall City with the chapter still moving forward.

**Why this priority**: The route and grove are the core of the chapter's pacing and teach the loop
that carries the rest of the game.

**Independent Test**: Start from the route entry and play through to Brassfall City. Verify that the
required battles and story beats happen in sequence without using the gym or any out-of-scope
content.

**Acceptance Scenarios**:

1. **Given** the chapter has begun, **When** the player progresses through Route 1 and Cinder Reed
   Grove, **Then** the required trainer battles and story beats complete and Brassfall City becomes
   reachable.
2. **Given** the player has not completed the route and grove beats, **When** they attempt to enter
   the gym early, **Then** the chapter keeps the player on the unfinished objective and does not
   skip ahead.

---

### User Story 3 - Earn the Badge (Priority: P3)

The player enters Forte Hall Gym, solves the lighting puzzle, defeats the gym trainers and leader,
receives the first badge, and gets a clear next objective.

**Why this priority**: The badge is the chapter's finish line. It is the final proof that the
chapter is complete and ready to hand off to the next one.

**Independent Test**: Start from Brassfall City and complete only the gym sequence. Verify that the
puzzle, battles, badge reward, and next objective all resolve cleanly.

**Acceptance Scenarios**:

1. **Given** the player has reached Brassfall City, **When** they enter Forte Hall Gym, **Then** the
   lighting puzzle reveals the intended path through the gym.
2. **Given** the gym leader is defeated, **When** the battle ends, **Then** the player receives the
   first badge and a clear Chapter 2 objective is shown.

---

### Edge Cases

- If the player loses a rival battle or gym battle, the chapter must return them to a valid state
  without erasing unrelated progress.
- If the player saves during or after a partially solved gym puzzle, the puzzle state must remain
  consistent on reload.
- If the player backtracks through a cleared area, the game must not force them to replay completed
  beats.
- If the player tries to enter the gym before the required story beats, the game must clearly block
  entry rather than soft-locking.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The chapter MUST begin in Ember Hollow Town and let the player choose Growlithe,
  Wooper, or Budew and receive the Pokédex before free exploration starts.
- **FR-002**: The chapter MUST present the main path as a fixed five-location chapter ending at the
  first badge.
- **FR-003**: The chapter MUST include two rival battles at the intended story beats.
- **FR-004**: The chapter MUST include a compact set of route, grove, and gym trainer battles that
  teach the core loop and keep the chapter readable.
- **FR-005**: The gym puzzle MUST use visible lighting progress so the player can tell what changed
  after each trainer battle.
- **FR-006**: The chapter MUST award the first badge and show a clear next objective at the end of
  the gym leader battle.
- **FR-007**: The chapter MUST preserve starter choice, battle progress, and gym puzzle state across
  save/load.
- **FR-008**: The chapter MUST not require fusion mechanics, field effects, open-world scaling,
  multiplayer, or postgame systems to complete.
- **FR-009**: Any QoL feature in Chapter 1 MUST reduce friction in the first chapter loop.
- **FR-010**: The chapter MUST be completable by a first-time player without needing outside
  knowledge of Chapter 2.

### Key Entities *(include if feature involves data)*

- **Chapter Progress**: The ordered set of chapter beats and their completion state.
- **Starter Choice**: The chosen starter from Growlithe, Wooper, or Budew and the state created by
  the opening sequence.
- **Rival Encounter**: One of the two rival battles and its completion status.
- **Gym Puzzle State**: The current light progression and gym access state.
- **Reward State**: The first badge, the unlocked route, and the next objective.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: In 8 out of 10 first-time playtests, Chapter 1 completes in 2-4 hours.
- **SC-002**: 100% of tested fresh starts can reach the first badge.
- **SC-003**: 100% of tested save/load cycles preserve starter choice, chapter progress, and puzzle
  state.
- **SC-004**: 9 out of 10 testers can identify the next objective after the badge without help.
- **SC-005**: Every completed Chapter 1 run includes exactly two rival battles and at least six
  trainer battles.

## Assumptions

- The rival identity and exact reward names are finalized before implementation and remain consistent
  within Chapter 1.
- The chapter is designed for players who may know nothing about Beaconfall before starting.
- Small utility rewards are acceptable only when they make the chapter smoother and do not widen
  scope.
- The chapter's five-location path is the full scope of Chapter 1; anything beyond it belongs later.
