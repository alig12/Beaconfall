# Feature Specification: Chapter 2 - The Tide Beneath Brassfall

**Feature Branch**: `002-beaconfall-ch2`  
**Created**: 2026-03-28  
**Status**: Draft  
**Input**: User description: "Implement Chapter 2 for Beaconfall: Saltwind Coast with Safe and Breaker lanes; Floodgate Tunnels water-level puzzle using drained, partial, full states; Lumenport City hub; rival battle; Astral Tide Gym with water-level gate; Badge 2 and Surf unlock; no fusion, field effects, open-world scaling, or engine rewrites."

Chapter 2 should move the player from the end of Chapter 1 into a stronger, more focused middle chapter. It introduces a coastal route with a meaningful path choice, a water-control dungeon, a city hub, a checkpoint rival battle, and a final gym reward that changes later exploration.

## User Scenarios & Testing *(mandatory)*

### User Story 1 - Cross Saltwind Coast (Priority: P1)

As a player, I want to travel through Saltwind Coast and choose between a safer route and a riskier route so that the chapter starts with a clear, replayable decision.

**Why this priority**: This is the entry point to Chapter 2. If the route does not work, the rest of the chapter cannot be reached.

**Independent Test**: Start at the Chapter 2 boundary, take either route through Saltwind Coast, and confirm the player can reach Floodgate Tunnels without needing any later chapter content.

**Acceptance Scenarios**:

1. **Given** Chapter 1 is complete, **When** the player enters Saltwind Coast and follows the safer path, **Then** they can progress through the route, fight the intended trainers, and reach the dungeon entrance.
2. **Given** Chapter 1 is complete, **When** the player chooses the riskier path, **Then** they face a higher-risk, higher-reward experience with stronger encounters and better item access, but still reach the same chapter destination.
3. **Given** the player returns to the route after clearing it, **When** they revisit earlier areas, **Then** the route remains consistent and does not block progress.

---

### User Story 2 - Solve Floodgate Tunnels (Priority: P2)

As a player, I want to solve the Floodgate Tunnels water puzzle so that I can unlock the path to the city and feel the chapter's central mechanic in action.

**Why this priority**: Floodgate Tunnels is the chapter's main mechanic space. It proves the chapter's identity and pacing.

**Independent Test**: Enter Floodgate Tunnels, change water levels, and verify the player can open the intended paths and exit to Lumenport City without soft-locking.

**Acceptance Scenarios**:

1. **Given** the player enters Floodgate Tunnels, **When** they interact with the first puzzle element, **Then** the water state changes in a way that clearly changes available paths.
2. **Given** the player makes an incorrect puzzle choice, **When** the level changes in the wrong direction, **Then** the dungeon remains recoverable and the player can continue without restarting the chapter.
3. **Given** the puzzle is solved, **When** the player reaches the dungeon exit, **Then** they can move on to Lumenport City and the route remains stable on return visits.

---

### User Story 3 - Reach Lumenport, defeat the rival, and clear Astral Tide Gym (Priority: P3)

As a player, I want a city hub, a checkpoint rival battle, and a final gym challenge so that Chapter 2 ends with a meaningful reward and a clear sense of progress.

**Why this priority**: This story closes the chapter. It combines the hub, story beat, boss fight, and reward into the chapter's payoff.

**Independent Test**: From Floodgate completion, visit Lumenport City, trigger the rival battle, clear Astral Tide Gym, and receive Badge 2 plus Surf.

**Acceptance Scenarios**:

1. **Given** the player arrives in Lumenport City, **When** they explore the hub, **Then** they can access the expected services and story beats without losing the main progression path.
2. **Given** the rival encounter has not yet happened, **When** the player reaches the checkpoint, **Then** the battle triggers once and does not repeat after it is resolved.
3. **Given** the player solves the Astral Tide Gym puzzle, **When** they reach the leader, **Then** the final battle opens, the badge is awarded, and Surf becomes available for later exploration.

---

### Edge Cases

- What happens if the player chooses the wrong lever sequence in Floodgate Tunnels? The dungeon must stay recoverable and never trap the player without a way forward.
- What happens if the player loses the rival battle? The chapter must allow retrying the encounter without losing story progress.
- What happens if the player revisits cleared areas? Route, dungeon, and city progression must remain stable and readable.
- What happens if the player reaches the gym before clearing the dungeon? The chapter must keep the intended order intact.
- What happens if the player earns the final reward and then returns to older content? The Surf unlock must remain available and should continue to change exploration.

## Requirements *(mandatory)*

### Functional Requirements

- **FR-001**: The chapter MUST begin with a coastal route that follows Chapter 1 and introduces the player to Chapter 2's pacing.
- **FR-002**: Saltwind Coast MUST offer two distinct route experiences: a safer path and a riskier path.
- **FR-003**: Both Saltwind Coast routes MUST remain completable and lead to the same chapter destination.
- **FR-004**: Saltwind Coast MUST include trainer battles, wild encounters, and item placement that support the chapter's coastal tone.
- **FR-005**: Floodgate Tunnels MUST use three clearly readable water states that change path access and puzzle progression.
- **FR-006**: Floodgate Tunnels MUST let the player recover from incorrect puzzle choices without becoming stuck.
- **FR-007**: Floodgate Tunnels MUST open the path to Lumenport City only after the intended puzzle sequence is solved.
- **FR-008**: Lumenport City MUST serve as a hub with the expected services, story beats, and access to the chapter's rival and gym flow.
- **FR-009**: The rival battle MUST happen once as a checkpoint between the dungeon and the gym.
- **FR-010**: Astral Tide Gym MUST reuse the chapter's water concept in a tighter puzzle that gates the leader.
- **FR-011**: Clearing Astral Tide Gym MUST award Badge 2 and Surf.
- **FR-012**: Chapter 2 progression MUST persist after save and reload so the player can continue later without repeating completed chapter milestones.
- **FR-013**: The chapter SHOULD include quality-of-life features that reduce friction without adding unnecessary complexity.
- **FR-014**: The chapter MUST remain compatible with the game's established systems and must not require unrelated new gameplay systems.

### Key Entities *(include if feature involves data)*

- **Chapter Area**: A playable space with a clear role in progression, such as a route, dungeon, city hub, or gym.
- **Water State**: The current state of the Floodgate and gym water flow, which determines what the player can reach.
- **Chapter Progress State**: The player's current story progression through the chapter, including cleared route, dungeon, rival, and gym milestones.
- **Rival Encounter**: The mid-chapter battle that acts as a checkpoint and pacing beat.
- **Reward Unlock**: The chapter-ending reward that grants Badge 2 and Surf and changes future exploration.

## Success Criteria *(mandatory)*

### Measurable Outcomes

- **SC-001**: In validation playthroughs, a player can complete Chapter 2 from the route start to Badge 2 without encountering a progression blocker.
- **SC-002**: In repeated playthroughs, incorrect Floodgate Tunnels puzzle choices never create an unrecoverable state.
- **SC-003**: In playtests, both Saltwind Coast route options are clearly distinct in risk and reward and remain completable.
- **SC-004**: In validation, the rival battle triggers once, the gym can be cleared, and the chapter ends with Badge 2 plus Surf unlocked.
- **SC-005**: In feedback from at least 5 playtest sessions, most testers report that Chapter 2 feels like a meaningful difficulty increase from Chapter 1 while still feeling fair.

## Assumptions

- Chapter 1 completion remains the entry gate for Chapter 2.
- Chapter 2 stays linear overall even though Saltwind Coast offers a route choice and some optional content.
- Existing battle, map, and story systems are reused for this chapter.
- Optional side content remains short and supports pacing instead of becoming a separate subplot.
- Surf is the only new exploration reward required at the end of the chapter.
