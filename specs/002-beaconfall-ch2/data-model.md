# Chapter 2 Data Model

## Overview

Chapter 2 uses a small deterministic state model. Route choice, dungeon water levels, rival progression, and gym completion should all be traceable through explicit flags and variables.

## Entities

### ChapterProgressState

Represents chapter-wide progress through the route, dungeon, city, rival, and gym.

| Field | Type | Meaning |
|---|---|---|
| `chapter1Complete` | flag | Chapter 1 completion gate |
| `saltwindCleared` | flag | Saltwind Coast route milestone |
| `floodgateCleared` | flag | Floodgate Tunnels completion |
| `rival2Done` | flag | Rival checkpoint resolved |
| `gym2Cleared` | flag | Astral Tide Gym cleared |
| `surfUnlocked` | flag | Surf reward available |
| `chapter2Complete` | flag | Overall chapter completion |

### WaterPuzzleState

Represents the water-state machine used by Floodgate Tunnels and Astral Tide Gym.

| Field | Type | Meaning |
|---|---|---|
| `area` | enum | Floodgate or Gym |
| `state` | integer | 0 drained, 1 partial, 2 full |
| `valveA` | flag | First valve milestone |
| `valveB` | flag | Second valve milestone |
| `valveC` | flag | Third valve milestone |

### RouteBranch

Represents Saltwind Coast's safe and breaker lanes.

| Field | Type | Meaning |
|---|---|---|
| `branchName` | string | Safe Lane or Breaker Lane |
| `trainerDensity` | integer | Relative number of battles |
| `riskLevel` | string | Safe or high-risk |
| `rewardBias` | string | Standard items or better items |
| `exitTarget` | string | Floodgate Tunnels entry |

### RivalCheckpoint

Represents the chapter's single rival battle.

| Field | Type | Meaning |
|---|---|---|
| `state` | integer | 0 before battle, 1 after battle |
| `triggerPoint` | string | Location between Floodgate and gym |
| `repeatable` | boolean | False |
| `rewardGate` | flag | Prevents the battle from repeating |

### GymReward

Represents the chapter's badge and traversal unlock.

| Field | Type | Meaning |
|---|---|---|
| `badgeAwarded` | flag | Badge 2 granted |
| `surfUnlocked` | flag | Surf is available |
| `chapterComplete` | flag | Chapter 2 is finished |

### TrainerRoster

Represents the Chapter 2 trainer set.

| Field | Type | Meaning |
|---|---|---|
| `location` | string | Saltwind, Floodgate, rival, or gym |
| `battleRole` | string | Route trainer, dungeon trainer, rival, gym trainer, leader |
| `budget` | integer | Core trainer slot allocation |
| `optional` | boolean | Optional content should be trimmed first |

## State Transitions

1. `chapter1Complete` opens Chapter 2 entry.
2. Saltwind Coast clears first and sets the chapter route milestone.
3. Floodgate water states move from drained to partial to full as valves are solved.
4. Floodgate completion opens the path to Lumenport City.
5. Rival checkpoint resolves once and sets the rival completion flag.
6. Astral Tide Gym resolves after the gym water puzzle.
7. Badge 2 and Surf unlock together at the reward step.
8. Chapter 2 completion is recorded last.

## Validation Rules

- Water states must never leave the player in a dead end.
- Rival state must not allow repeat battles after completion.
- Surf must not unlock before Badge 2.
- Save/load must preserve all chapter progress flags and vars.
- Optional content must never block the main route if it is trimmed for budget reasons.
