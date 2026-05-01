# Chapter 1 Full Smoke Test

## Purpose

Verify Beaconfall Chapter 1 as a playable first-badge vertical slice.

This checklist covers the full route from fresh save to Beacon Badge:

```text
Ember Hollow -> Saltwind Path -> Cinder Reed Grove -> Brassfall City -> Forte Hall Gym -> Beacon Badge
```

Use this after changes to maps, scripts, trainer data, encounter data, flags, vars, starter flow, rival flow, gate flow, gym flow, or chapter completion.

## Test metadata

Fill this before testing.

```text
Tester:
Date:
Commit:
ROM build:
Emulator:
Save type: fresh / existing / migrated
Notes:
```

## Required tools

- Built `pokeemerald.gba`
- mGBA or equivalent GBA emulator
- Normal in-game save

Recommended:

- mGBA save states for fast retry
- Screen recording for failures
- Screenshots at major milestones

## Save-state slots

Use save states only to speed up retesting. Do not use save states as proof of real save/load persistence.

Suggested slots:

```text
Slot 1: before starter choice
Slot 2: after starter / before north gate
Slot 3: before Route 1 rival
Slot 4: after Route 1 rival
Slot 5: before Cinder Reed Grove
Slot 6: before Brassfall rival
Slot 7: before Forte Hall Gym
Slot 8: after two gym rigs
Slot 9: before Vera
Slot 10: after Beacon Badge
```

## Normal save/load checkpoints

Use the in-game save menu and emulator reset for these.

```text
After starter choice
After Route 1 clear
After Brassfall rival
After one or two gym rigs
After Beacon Badge
```

## 1. Fresh start and Ember Hollow opener

### Steps

1. Start a fresh save.
2. Confirm the player starts in the intended Beaconfall opening context.
3. Confirm the blackout hook appears once.
4. Confirm Mom / recovery path works as intended.
5. Walk to Professor Hollow's lab.

### Expected result

- Opening does not crash.
- Blackout hook appears once.
- Recovery path is available.
- Player can reach the lab without softlock.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 2. Starter choice and catching kit

### Steps

1. Talk to Professor Hollow.
2. Choose a starter.
3. Confirm the starter joins the party.
4. Confirm Professor Hollow gives 5 Poké Balls.
5. Re-talk to Professor Hollow.

### Expected result

- Starter is chosen cleanly.
- Player receives 5 Poké Balls.
- Re-talking does not duplicate the reward.
- Professor text points the player toward Saltwind Path.

```text
Pass / Fail:
Starter chosen:
Poké Balls received:
Duplicate reward: yes / no
Notes:
Screenshot/video:
```

## 3. North gate twins

### Steps

1. Try the north gate before starter if available from a save state.
2. Confirm the gate blocks without a partner.
3. After starter choice, approach the north gate.
4. Talk to the twins or step into the trigger.
5. Confirm the twins move aside.
6. Enter Saltwind Path.

### Expected result

- Before starter, gate blocks and pushes the player back.
- After starter, twins open the path.
- No rival battle is required before leaving town.
- Route transition works.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 4. Route 1 / Saltwind Path Rival Battle 1

### Steps

1. Enter Saltwind Path.
2. Confirm Mira is visible on the route.
3. Talk to Mira before stepping into the battle trigger.
4. Step onto the Route 1 rival trigger.
5. Confirm Mira faces the player and starts Rival Battle 1.
6. Win the battle.
7. Confirm Mira is removed and Route 1 is cleared.
8. Re-enter Saltwind Path.

### Expected result

- Mira appears on Route 1.
- Battle transition has no visual corruption.
- Correct starter matchup is used.
- Winning sets Route 1 cleared.
- Re-entry does not retrigger Rival Battle 1.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 5. Route 1 recovery and loss behavior

### Steps

1. Load a save before Rival Battle 1.
2. Lose the battle intentionally if practical.
3. Confirm the player returns to a valid recovery point.
4. Heal.
5. Return to Saltwind Path.
6. Retry Rival Battle 1.

### Expected result

- Loss does not softlock the story.
- Mira / rival state remains retryable.
- Player can heal and continue.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 6. Route 1 trainers and wild encounters

### Steps

1. Walk through Saltwind Path after Rival Battle 1.
2. Fight route trainers.
3. Trigger at least one wild encounter.
4. Try catching a wild Pokémon with the starter-kit Poké Balls.
5. Reach the north path toward Cinder Reed Grove.

### Expected result

- Route trainers work.
- Wild encounters occur only where expected.
- Catching is possible.
- Gatekeeper / route progression allows movement after Route 1 clear.

```text
Pass / Fail:
Caught Pokémon:
Notes:
Screenshot/video:
```

## 7. Cinder Reed Grove

### Steps

1. Enter Cinder Reed Grove.
2. Traverse the grove.
3. Fight intended trainers.
4. Use or inspect grove lamps / clue interactions.
5. Confirm the Potion reward remains separate from the starter Poké Ball kit.
6. Reach Brassfall City.

### Expected result

- Grove traversal works.
- No crashes or softlocks.
- Trainer battles work.
- Potion reward works.
- Player reaches Brassfall City.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 8. Brassfall City and Rival Battle 2

### Steps

1. Enter Brassfall City.
2. Confirm Rival Battle 2 triggers at the intended point.
3. Win the battle.
4. Confirm Brassfall city state advances.
5. Heal at the city healer.
6. Confirm Forte Hall Gym can be reached.

### Expected result

- Rival Battle 2 triggers once.
- Correct starter matchup is used.
- Winning advances `VAR_RIVAL_BATTLES` to the completed city-rival state.
- City healer works.
- Gym is accessible.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 9. Forte Hall Gym overview

For full Forte Hall details, use:

```text
docs/testing/ch1_forte_hall_smoke_test.md
```

Minimum full-chapter check:

1. Beat KIT.
2. Beat RAYNE.
3. Beat JAX.
4. Confirm all three rigs are lit.
5. Confirm Vera unlocks only after all three rigs are lit.
6. Beat Vera.
7. Confirm Beacon Badge reward.

### Expected result

- Three-rig progression works.
- Vera does not unlock early.
- Beacon Badge is awarded.
- Chapter 1 completion is set.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 10. Save/load regression pass

Use normal in-game save and emulator reset.

### Checkpoints

1. Save after starter choice.
2. Reset and load.
3. Confirm starter and Poké Balls persist.
4. Save after Route 1 clear.
5. Reset and load.
6. Confirm Mira does not reappear and Route 1 remains clear.
7. Save after Brassfall Rival Battle 2.
8. Reset and load.
9. Confirm Forte Hall remains reachable.
10. Save after one or two gym rigs.
11. Reset and load.
12. Confirm partial lighting persists.
13. Save after Beacon Badge.
14. Reset and load.
15. Confirm full-lit gym and after-badge dialogue persist.

### Expected result

- No save/load regression.
- No story-state rollback.
- No repeated one-time rewards or one-time rival battles.
- No stuck gate or softlock.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## Bug report template

Use this for any failure.

```text
Build/commit:
ROM build:
Emulator:
Save type: fresh / existing / migrated / save-state
Starting state:
Steps:
Expected:
Actual:
Can reproduce: yes / no
Screenshot/video:
Notes:
```

## Release gate

Do not mark Chapter 1 playable until all of these pass:

- Fresh save reaches starter choice.
- Starter and 5 Poké Balls are granted.
- North gate opens after starter.
- Rival Battle 1 happens on Saltwind Path.
- Route 1 can be cleared.
- Cinder Reed Grove can be crossed.
- Rival Battle 2 happens in Brassfall.
- Forte Hall three-rig puzzle works.
- Vera awards Beacon Badge.
- Normal save/load preserves progress at every checkpoint.
- No crash, freeze, or softlock occurs on the full path.
