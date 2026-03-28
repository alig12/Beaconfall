# Chapter 2 Quickstart

## Build

```bash
make clean && make
```

Expected result: the ROM builds successfully with the Chapter 2 assets integrated.

## Playtest Flow

1. Start from a save that has Chapter 1 completed.
2. Enter Saltwind Coast.
3. Test both lane styles:
   - Safe Lane should feel straightforward and trainer-heavy.
   - Breaker Lane should feel riskier and more rewarding.
4. Enter Floodgate Tunnels.
5. Verify the water-state machine:
   - Drained -> partial -> full transitions are readable.
   - Wrong lever choices remain recoverable.
   - The dungeon never soft-locks the player.
6. Exit to Lumenport City.
7. Confirm the city hub works:
   - Standard services are accessible.
   - Story beats trigger in the right order.
8. Trigger and win the rival battle.
9. Enter Astral Tide Gym.
10. Solve the gym puzzle and win the leader battle.
11. Confirm Badge 2 is awarded and Surf becomes available.
12. Save and reload the game.
13. Verify Chapter 2 progress, rival state, gym clear state, and Surf unlock all persist.

## Expected Results

- Saltwind Coast is completable through either lane.
- Floodgate Tunnels is recoverable after incorrect moves.
- The rival battle triggers once.
- The gym gate opens only after the puzzle is solved.
- Badge 2 and Surf unlock together at the end of the chapter.
- Chapter 2 state survives save/load.

## Common Failure Signs

- A route lane cannot be exited.
- A lever sequence traps the player.
- The rival battle repeats after victory.
- Surf unlocks before the badge.
- A save/load cycle clears chapter progress.
