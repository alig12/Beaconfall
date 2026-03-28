# Research: Pokémon Beaconfall Chapter 1 Implementation

## Decision 1: Use the native pokeemerald-expansion workflow

**Decision**: Implement Chapter 1 with the repository's existing decomp-native map,
script, trainer, and encounter systems.

**Rationale**: The constitution requires decomp-native work and explicitly rejects a custom
engine layer unless an amendment approves it. Using the repo's established files keeps the
chapter stable and compatible with the current build.

**Alternatives considered**:

- A custom chapter data layer. Rejected because it duplicates existing functionality and
  increases maintenance cost.
- A new engine abstraction. Rejected because it would violate the scope lock and delay the
  first badge.

## Decision 2: Store progression with flags and variables

**Decision**: Track chapter progression with explicit flags and variables, including starter
choice, rival count, gym light state, and chapter completion.

**Rationale**: The spec and constitution require deterministic progression that survives save
and load. Flags and variables are the clearest way to make Chapter 1 state visible and testable.

**Alternatives considered**:

- Hardcoded event branches. Rejected because they are brittle and harder to validate.
- A bespoke save structure. Rejected because it would add unnecessary complexity for a first
  chapter.

## Decision 3: Keep maps and events split between map-local and shared scripts

**Decision**: Put map-specific logic in each map's `scripts.inc` file and put shared chapter flow
in a shared `data/scripts/chapter_1.inc` file.

**Rationale**: The repository already uses map-local `scripts.inc` files, and the shared script
keeps chapter progression readable without creating a new architecture.

**Alternatives considered**:

- One monolithic chapter script. Rejected because it would be harder to navigate and maintain.
- Per-event ad hoc scripts scattered across files. Rejected because it would make the chapter
  flow harder to trace.

## Decision 4: Treat external contracts as not applicable

**Decision**: Do not create a `/contracts` directory for Chapter 1.

**Rationale**: The feature is an in-game chapter, not a public API, CLI, or web service. The
chapter's interfaces are player-facing interactions, which are captured in the spec and plan
rather than contract files.

**Alternatives considered**:

- Add interface contracts anyway. Rejected because there is no external interface to document.

## Decision 5: Lock the battle and map scope early

**Decision**: Keep the chapter fixed to five maps, two rival battles, one badge, and the
Turtwig / Chimchar / Piplup starter trio.

**Rationale**: The spec and constitution both depend on a small, testable Chapter 1 slice.
Locking the scope now prevents late design drift and keeps release criteria realistic.

**Alternatives considered**:

- Expand the roster or map count during implementation. Rejected because it would break the
  release criteria and raise regression risk.
