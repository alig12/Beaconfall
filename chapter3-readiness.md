# Chapter 3 Readiness

Chapter 2 now has its core route, puzzle, city, and gym scaffolding in place. This note captures the
handoff points that Chapter 3 should build on.

## What Chapter 2 Leaves Ready

- `FLAG_CHAPTER_2_COMPLETE` marks the story beat that closes the chapter.
- `FLAG_SURF_UNLOCKED` and `FLAG_BADGE02_GET` gate the next travel options.
- `VAR_RIVAL2_STATE`, `VAR_WATER_LEVEL_FLOODGATE`, and `VAR_WATER_LEVEL_GYM` keep Chapter 2 state
  isolated from later content.
- `data/scripts/chapter_2.inc` handles the chapter reset, puzzle state, rival progression, and
  reward unlock flow.

## Chapter 3 Starting Points

- Start from `LumenportCity` and keep the story handoff tied to the completed Chapter 2 flags.
- Reuse the chapter pattern already established for map groups, map scripts, and chapter-scoped
  constants.
- Add any new chapter state in a fresh block of flags and vars so Chapter 2 data stays stable.

## Notes For Future Planning

- Keep the chapter reset path aligned with `data/scripts/new_game.inc`.
- Treat the chapter docs as the place to record new city, route, and gym milestones as they land.
