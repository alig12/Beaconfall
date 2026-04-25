# Chapter 1 Forte Hall Gym Smoke Test

## Purpose

Verify Forte Hall Gym as a Beaconfall stage/relay puzzle, not a vanilla gym shortcut.

This checklist covers:

- JAX placement and pathing
- trainer sight fairness
- left / right / center rig lighting
- partial save/load persistence
- badge save/load persistence
- Vera unlock rules

Use this after changes to `data/maps/ForteHallGym/map.json`, `data/maps/ForteHallGym/scripts.inc`, trainer data, flags, vars, or badge/chapter completion scripts.

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

## Tools

Required:

- Built `pokeemerald.gba`
- mGBA or equivalent GBA emulator
- Normal in-game save

Recommended:

- mGBA save states for fast retry
- Screen recording for any failure
- Screenshot at each rig state

## Save-state slots

Use save states only to speed repeated checks. Do not use them as proof that normal save/load works.

Suggested slots:

```text
Slot 1: before entering Forte Hall Gym
Slot 2: before KIT
Slot 3: after KIT
Slot 4: after KIT + RAYNE
Slot 5: before JAX
Slot 6: after all three rigs
Slot 7: before Vera
Slot 8: after Beacon Badge
```

## Current expected design

Forte Hall Gym has three crew members and three stage rigs.

```text
KIT   -> left rig   -> FLAG_FORTE_GYM_RIG_LEFT
RAYNE -> right rig  -> FLAG_FORTE_GYM_RIG_RIGHT
JAX   -> center rig -> FLAG_FORTE_GYM_RIG_CENTER
```

Vera should only battle after all three rig flags are set.

`VAR_GYM_LIGHT_STATE` is derived from the rig flags. It should not be the source of truth for Vera unlock.

## 1. JAX placement and pathing

### Setup

Start from a save before entering Forte Hall Gym.

### Steps

1. Enter Forte Hall Gym.
2. Walk from the entrance to KIT.
3. Walk from KIT's lane to RAYNE's lane.
4. Walk from RAYNE's lane to JAX at the center rig.
5. Walk around JAX before fighting him.
6. Walk from JAX toward Vera.
7. Walk from JAX back to the entrance.
8. Fight JAX.
9. After JAX is beaten, repeat the path from entrance to Vera.

### Expected result

- JAX is reachable.
- JAX does not trap the player.
- JAX does not block access to Vera.
- JAX does not block the route back to the entrance.
- JAX placement feels like a stage/relay tech guarding center power.

### Failure notes

Record any awkward pathing, forced one-tile squeeze, softlock, or impossible route.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 2. Trainer sight fairness

### Setup

Start from a save before entering Forte Hall Gym.

### Steps

For KIT, RAYNE, and JAX:

1. Approach from the intended lane.
2. Approach from the side.
3. Approach after beating one other trainer.
4. Try to walk around the trainer.
5. Check whether the battle triggers too early, too late, or through walls.

### Expected result

- Each trainer notices the player at a readable distance.
- Sight ranges do not trigger from the gym entrance.
- Sight ranges do not trigger through walls or from unfair angles.
- The trainers feel like crew members guarding rigs, not random filler battles.

### Failure notes

```text
Trainer:
Pass / Fail:
Issue:
Suggested coordinate/sight change:
Screenshot/video:
```

## 3. Correct rig lighting

### Setup

Start from a save before any Forte Hall trainer has been beaten.

### Steps

Test at least these orders:

```text
KIT -> RAYNE -> JAX
KIT -> JAX -> RAYNE
RAYNE -> KIT -> JAX
JAX -> KIT -> RAYNE
```

After each trainer battle:

1. Check the after-battle text.
2. Check the correct rig lights up.
3. Check already-lit rigs stay lit.
4. Check the room gets brighter as expected.
5. Try Vera before all three rigs are lit.

### Expected result

- KIT lights the left rig only.
- RAYNE lights the right rig only.
- JAX lights the center rig only.
- Existing lit rigs remain lit after later battles.
- Vera blocks until all three rigs are lit.

### Failure notes

```text
Order tested:
Pass / Fail:
Wrong rig:
Missing visual update:
Unexpected Vera behavior:
Screenshot/video:
```

## 4. Partial save/load persistence

Use normal in-game save and emulator reset. Do not use save states for this section.

### Scenario A: one rig lit

1. Enter Forte Hall Gym.
2. Beat KIT.
3. Confirm the left rig is lit.
4. Save using the in-game menu.
5. Reset the emulator.
6. Load the save.
7. Re-enter or remain inside Forte Hall Gym.
8. Try talking to Vera.

Expected:

- Left rig remains lit.
- Right and center rigs remain unlit.
- Vera still blocks.
- The gym is partially brighter, not fully lit.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

### Scenario B: two rigs lit

1. Enter Forte Hall Gym.
2. Beat KIT and RAYNE.
3. Confirm left and right rigs are lit.
4. Save using the in-game menu.
5. Reset the emulator.
6. Load the save.
7. Re-enter or remain inside Forte Hall Gym.
8. Try talking to Vera.

Expected:

- Left and right rigs remain lit.
- Center rig remains unlit.
- Vera still blocks.
- The player still needs to beat JAX.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 5. Badge save/load persistence

Use normal in-game save and emulator reset.

### Steps

1. Beat KIT.
2. Beat RAYNE.
3. Beat JAX.
4. Confirm all three rigs are lit.
5. Talk to Vera.
6. Beat Vera.
7. Confirm Beacon Badge reward text appears.
8. Save using the in-game menu.
9. Reset the emulator.
10. Load the save.
11. Re-enter Forte Hall Gym.
12. Talk to Vera.

### Expected result

- Beacon Badge remains obtained.
- All three rig lights are visible.
- The gym remains bright.
- Vera uses after-badge dialogue.
- Chapter 1 completion remains set.
- No trainer or light state regresses.

```text
Pass / Fail:
Notes:
Screenshot/video:
```

## 6. Vera unlock gate

### Setup

Use save states to quickly test each state, but confirm final behavior with a normal save.

### Test states

Try Vera in all states below.

```text
0 rigs lit
only left lit
only right lit
only center lit
left + right lit
left + center lit
right + center lit
all three lit
after badge
```

### Expected result

```text
0, 1, or 2 rigs lit -> Vera blocks
all three rigs lit -> Vera battles
after badge -> Vera after-badge dialogue
```

### Failure notes

```text
State:
Expected:
Actual:
Pass / Fail:
Screenshot/video:
```

## Bug report template

Use this for any failure.

```text
Build/commit:
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

Do not mark Forte Hall Gym verified until all of these pass:

- JAX does not block pathing.
- Trainer sight ranges feel fair.
- Each trainer lights the correct rig.
- One-rig and two-rig normal save/load states persist correctly.
- Badge normal save/load keeps the hall fully lit.
- Vera only unlocks when all three rig flags are set.
