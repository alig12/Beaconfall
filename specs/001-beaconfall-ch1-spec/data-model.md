# Chapter 1 Data Model

## Overview

The Chapter 1 data model is a small set of state objects that describe where the player is in
the story, which battles have happened, and what unlocks have been granted. The model is
designed to be deterministic, save-safe, and easy to validate.

## Core Entities

### ChapterProgress

|Field|Type|Purpose|
|---|---|---|
|`starter_choice`|enum(`Growlithe`,`Wooper`,`Budew`)|Records the chosen starter.|
|`route_1_cleared`|bool|Marks the route traversal beat as complete.|
|`cinder_reed_grove_cleared`|bool|Marks the grove beat as complete.|
|`brassfall_city_entered`|bool|Marks city arrival.|
|`rival_battles_completed`|int|Counts completed rival battles; must stop at 2.|
|`gym_light_state`|int|Tracks the lighting puzzle progress.|
|`badge_received`|bool|Marks the first badge as awarded.|
|`chapter_complete`|bool|Marks the chapter as finished and ready for the hook.|

**Relationships**: Owns `StarterChoice`, `RivalEncounter[]`, `GymPuzzleState`, and
`RewardState`.

**Validation rules**:

- `rival_battles_completed` must never exceed 2.
- `chapter_complete` can only become true after `badge_received` is true.
- `route_1_cleared`, `cinder_reed_grove_cleared`, and `brassfall_city_entered` must follow the
  intended chapter order.

### StarterChoice

|Field|Type|Purpose|
|---|---|---|
|`selected_species`|enum(`Growlithe`,`Wooper`,`Budew`)|Stores the chosen starter.|
|`starter_reward_granted`|bool|Confirms the starter and opening reward were awarded.|
|`pokedex_granted`|bool|Confirms the Pokédex was awarded during the opening.|

**Relationships**: One-to-one with `ChapterProgress`.

**Validation rules**:

- Exactly one starter may be chosen per save.
- The chosen species must be one of the three canonical starters.
- The starter reward and Pokédex must be granted only once.

### RivalEncounter

|Field|Type|Purpose|
|---|---|---|
|`index`|int|Encodes Rival Battle 1 or Rival Battle 2.|
|`location`|string|Names the battle location.|
|`completed`|bool|Marks the battle as finished.|
|`result`|enum(`win`,`loss`)|Tracks the outcome for flow control.|

**Relationships**: Many-to-one with `ChapterProgress`.

**Validation rules**:

- Exactly two rival encounters exist in Chapter 1.
- Rival Battle 1 must occur before Rival Battle 2.
- A completed rival battle must not replay unless the player restarts the chapter.

### GymPuzzleState

|Field|Type|Purpose|
|---|---|---|
|`light_state`|int|Tracks which lights are active.|
|`trainers_defeated`|int|Counts trainers that contribute to the puzzle.|
|`final_door_open`|bool|Tracks whether the gym leader path is unlocked.|

**Relationships**: One-to-one with `ChapterProgress`.

**Validation rules**:

- Light progression must be deterministic.
- Save/load must preserve the current light state.
- The final door may open only when the required lights are active.

### RewardState

|Field|Type|Purpose|
|---|---|---|
|`badge_received`|bool|Confirms the first badge was awarded.|
|`next_route_unlocked`|bool|Confirms the next route opened.|
|`chapter2_hook_shown`|bool|Confirms the Chapter 2 hook played.|

**Relationships**: One-to-one with `ChapterProgress`.

**Validation rules**:

- The badge reward must only appear once.
- The next route and hook must unlock after the gym leader win.
- `chapter2_hook_shown` must not become true before `badge_received`.

## State Transitions

1. `Not Started` -> `Starter Selected`
2. `Starter Selected` -> `Route 1 In Progress`
3. `Route 1 In Progress` -> `Cinder Reed Grove Cleared`
4. `Cinder Reed Grove Cleared` -> `Brassfall City Entered`
5. `Brassfall City Entered` -> `Gym In Progress`
6. `Gym In Progress` -> `Badge Received`
7. `Badge Received` -> `Chapter Complete`

## Persistence Notes

- Starter choice, rival count, puzzle state, and badge state must survive save/load.
- Chapter completion must be derived from the same saved state, not from a separate hidden flag.
- The model should avoid duplicate sources of truth for the same beat.
