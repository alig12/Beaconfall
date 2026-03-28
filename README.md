# Pokémon Beaconfall

Pokémon Beaconfall is an original GBA ROM hack built on `pokeemerald-expansion`.
This repository is the game project itself: story, maps, scripts, balance, docs, and the engine
hooks needed to make Beaconfall playable.

## What This Repo Is

- A new-game project, not a generic engine template.
- A story-first ROM hack with Beaconfall as the playable world.
- A place to keep design docs, implementation notes, and game content together.

## Current Chapter

- Chapter 1 is the active vertical slice.
- The opening starts in Ember Hollow Town.
- The starter trio is Growlithe, Wooper, and Budew.
- The current flow runs through Saltwind Path, Cinder Reed Grove, Brassfall City, and Forte Hall Gym.
- The chapter includes rival battles, early trainer battles, and a light-based gym puzzle.

## Repository Layout

- `data/` - maps, scripts, encounters, text, and other game content.
- `src/` - gameplay logic and engine hooks.
- `specs/` - design docs, plans, research, quickstarts, and task lists.
- `docs/` - inherited engine reference docs and navigation.
- `graphics/`, `sound/`, and `tools/` - asset and build support for the ROM hack.

## Project Docs

- [`BEACONFALL_SPEC_KIT_PROMPTS.md`](BEACONFALL_SPEC_KIT_PROMPTS.md) - prompt pack for the chapter spec work.
- [`FIRST_CHAPTER_PLAN.md`](FIRST_CHAPTER_PLAN.md) - implementation plan for Chapter 1.
- [`RESEARCH.md`](RESEARCH.md) - research notes and engine decisions behind the chapter.
- [`specs/001-beaconfall-ch1-spec/README.md`](specs/001-beaconfall-ch1-spec/README.md) - chapter spec index.
- [`specs/001-beaconfall-ch1-spec/quickstart.md`](specs/001-beaconfall-ch1-spec/quickstart.md) - implementation and validation guide.
- [`specs/001-beaconfall-ch1-spec/tasks.md`](specs/001-beaconfall-ch1-spec/tasks.md) - task breakdown and dependencies.

## Setup and Development

- Start with [`INSTALL.md`](INSTALL.md) to set up the toolchain and build the ROM.
- Use [`FEATURES.md`](FEATURES.md) as the inherited engine capability reference.
- Use [`CONTRIBUTING.md`](CONTRIBUTING.md) when opening issues or pull requests.
- Track project milestones in [`CHANGELOG.md`](CHANGELOG.md).
- Use [`CREDITS.md`](CREDITS.md) for upstream engine credit and project contributor credit.

## Need the Engine Docs?

The repo still inherits `pokeemerald-expansion`, so the underlying engine documentation remains
in `docs/`. If you're here to play or extend Beaconfall, start with the project docs above.
