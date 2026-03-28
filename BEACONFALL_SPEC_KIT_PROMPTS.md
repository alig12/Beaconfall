# Beaconfall Spec Kit Prompts

## /speckit.constitution

```text
Create the Pokémon Beaconfall constitution for a greenfield GBA fan game built on
pokeemerald-expansion.

Write a full constitution with 5 core principles plus governance sections for
scope lock, release criteria, change control, testing, dispute resolution,
approved amendments, non-goals, communication, and conclusion.

Use the chapter draft as source material. Keep the rules declarative, testable,
and specific to Chapter 1's first-badge scope, decomp-native workflow,
deterministic progression, and friction-only QoL policy.

Preserve the Chapter 2 hook, parking lot, and approved out-of-scope lists as
part of the governance model.

Include version, ratification date, and last-amended metadata at the end.
```

## /speckit.specify

```text
Write the Chapter 1 feature specification for Pokémon Beaconfall.

Keep the scope limited to the first badge and the first playable chapter.

Use these sections:
Goal, Non-goals, Player experience, Chapter flow, Maps, Battles, Gym puzzle,
Rewards, Technical constraints, Acceptance criteria.

Include user stories with priorities, independent tests, acceptance scenarios,
edge cases, functional requirements, key entities, success criteria, and
assumptions.

Mark anything uncertain with [NEEDS CLARIFICATION] instead of guessing.

Do not include file paths, engine details, or implementation steps.
```

## /speckit.clarify

```text
Ask the minimum set of targeted clarification questions needed before planning
Chapter 1 of Pokémon Beaconfall.

Focus on the few decisions that would change scope, balance, puzzle logic, or
chapter boundaries.

Group related questions, explain why each matters, and prefer short
multiple-choice answers where possible.

Resolve any [NEEDS CLARIFICATION] markers from the spec.

Do not ask about low-risk details or create a long questionnaire.
```

## /speckit.plan

```text
Convert the Chapter 1 specification for Pokémon Beaconfall into a technical
implementation plan for pokeemerald-expansion.

Include a summary, a technical context table, a constitution check, project
structure, file and data targets, map and event wiring, progression flags and
variables, build, validation, and release workflow, scope-lock notes, and
complexity tracking only if the plan really needs it.

Use decomp-native concepts like Porymap, map scripts, trainer tables, encounter
tables, and flags or variables.

Do not invent a separate data layer or engine rewrite, and call out any planned
change-control or release-criteria risks explicitly.
```

## /speckit.checklist

```text
Create a checklist that validates the Chapter 1 spec and plan for Pokémon
Beaconfall.

Check for clear scope, no unresolved [NEEDS CLARIFICATION] markers, traceable
requirements, measurable acceptance criteria, and a clean separation between
what and how.

Flag any missing or conflicting sections before tasks are generated.

Output the checklist as pass/fail items with short notes.
```

## /speckit.tasks

```text
Generate Chapter 1 implementation tasks for Pokémon Beaconfall from the approved
spec and plan.

Group tasks by user story and keep them in execution order.

Use exact file paths, mark independent tasks with [P], and include checkpoint
validation after each major chapter beat.

Include automated tests only if the spec explicitly asked for them; otherwise
keep validation focused on build, save/load, and playability checks. For
Beaconfall Chapter 1, build and regression validation tasks are mandatory even
when tests are not requested.

If the repo does not have git metadata, keep any branch/PR wording conditional
rather than required.
```

## /speckit.analyze

```text
Analyze the Chapter 1 spec, plan, and tasks for Pokémon Beaconfall.

Report missing traceability, scope drift, contradictions, or unsupported
assumptions before implementation starts.

Call out any command prompt that no longer matches the current Spec Kit template
behavior.

Output findings grouped by severity, then recommend the minimum fixes.
```

## /speckit.implement

```text
Implement the approved Chapter 1 tasks for Pokémon Beaconfall.

Follow the task order, stop at each checkpoint, and keep the work inside the
scope lock from the spec and plan.

Do not add fusion, field effects, open-world scaling, multiplayer, or other
unapproved systems.

Report any blocker, deviation, or scope expansion before moving on.

If the repo does not have git metadata, keep any branch/PR wording conditional
rather than required.
```
