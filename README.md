# Pokémon Beaconfall

Pokémon Beaconfall is a coastal GBA ROM hack built on `pokeemerald-expansion`. This repository
tracks the game itself, the Chapter 1 design docs, and the engine code needed to build the ROM.

## Current Focus

- Chapter 1 opens in Ember Hollow Town with Briarune, Pyrevex, or Karatide as the starter trio.
- The first route, grove, city, and gym are built as a playable vertical slice.
- Progress is tracked with flags, vars, and shared script helpers instead of ad hoc state.

## Key Docs

- [`BEACONFALL_SPEC_KIT_PROMPTS.md`](BEACONFALL_SPEC_KIT_PROMPTS.md) - prompt pack used for the Chapter 1 spec.
- [`FIRST_CHAPTER_PLAN.md`](FIRST_CHAPTER_PLAN.md) - implementation plan for the first chapter.
- [`RESEARCH.md`](RESEARCH.md) - research notes and engine decisions behind the chapter structure.
- [`specs/001-beaconfall-ch1-spec/README.md`](specs/001-beaconfall-ch1-spec/README.md) - overview of the Chapter 1 spec folder.
- [`specs/001-beaconfall-ch1-spec/quickstart.md`](specs/001-beaconfall-ch1-spec/quickstart.md) - implementation and validation guide.
- [`specs/001-beaconfall-ch1-spec/tasks.md`](specs/001-beaconfall-ch1-spec/tasks.md) - task list and dependency map.

## Engine Reference

Beaconfall still uses the `pokeemerald-expansion` toolchain, data model, and build flow.
[`FEATURES.md`](FEATURES.md) describes the engine capabilities the game inherits, and
[`INSTALL.md`](INSTALL.md) covers setup and build instructions.

## Contributing

If you want to report a bug or open a pull request, start with [`CONTRIBUTING.md`](CONTRIBUTING.md).
For project updates and community discussion, use the ROM Hacking Hideout Discord server linked
in the engine docs.

<!-- docs-overview:start -->
## Documentation index

This index keeps the Beaconfall project docs close to the top and short-circuits the Chapter 1
spec tree through its local overview at `specs/001-beaconfall-ch1-spec/README.md`.

### Project Docs

- [Beaconfall Spec Kit Prompts](BEACONFALL_SPEC_KIT_PROMPTS.md) - prompt pack for the chapter spec and implementation flow.
- [Beaconfall Chapter 1 Plan](FIRST_CHAPTER_PLAN.md) - the approved first-chapter implementation plan.
- [Beaconfall Research Notes](RESEARCH.md) - technical research and design decisions for the chapter.
- [Beaconfall Chapter 1 Spec Overview](specs/001-beaconfall-ch1-spec/README.md) - entry point for the spec, plan, research, and task docs.

### Engine Docs

- [Features](FEATURES.md) - engine capabilities Beaconfall inherits from `pokeemerald-expansion`.
- [Install Guide](INSTALL.md) - setup and build instructions for the underlying engine toolchain.
- [Contributing](CONTRIBUTING.md) - project and repository contribution guidance.
- [Credits](CREDITS.md) - contributor credits for the engine base.

### Supporting Docs

- [Docs Summary](docs/SUMMARY.md) - documentation index for the existing engine docs tree.
- [Pull Request Template](.github/pull_request_template.md) - standard PR description template.
<!-- docs-overview:end -->
