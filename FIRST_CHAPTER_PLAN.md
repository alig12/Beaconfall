# Pokémon Beaconfall — Chapter 1 Design + Spec Kit SDD Prompt Pack
## Target engine: `pokeemerald-expansion`
## Output target: GBA ROM (`pokeemerald.gba`)
## Scope target: Chapter 1 / vertical slice / first playable episode

---

## 1) Project intent

This project is a **new, original Pokémon fan game** built as a **GBA ROM hack** on top of `pokeemerald-expansion`.

The design philosophy is:

- ship a small, polished first chapter
- prove the core loop before adding deep mechanics
- keep the engine/data model compatible with decomp workflows
- avoid feature creep
- use a chapter structure so future releases can expand cleanly

The first chapter is built to feel complete on its own:
- a small starting town
- one route
- one short dungeon-like area
- one city
- one gym
- one rival arc
- one badge
- a hook for Chapter 2

---

## 2) High-level game concept

### Title
**Pokémon Beaconfall**

### Theme
A coastal region where old stage theaters, lighthouse infrastructure, and weathered trade routes have been repurposed into modern towns and gyms. The chapter’s visual identity should mix:
- seaside ports
- faded performance venues
- lanterns, cables, scaffolding, and shipyard infrastructure
- Gen 3 style readability

### Tone
- adventurous
- slightly mysterious
- grounded
- not comedic-heavy
- early-game tension, but not grimdark

### Core chapter promise
The player begins as a local trainee in a harbor town and is pushed into a region-wide restoration effort after the failure of the coastal beacon network. Chapter 1 is about proving yourself by restoring power to a lighthouse district and earning the first badge.

---

## 3) Chapter 1 gameplay goals

### Player experience goals
1. Teach the player the combat loop.
2. Teach exploration and item pickup.
3. Introduce a rival with a clear personality.
4. End with a memorable puzzle gym.
5. Reward the player with a badge and a clear next objective.

### Design pillars
- Clear routing
- Short maps
- Strong visual landmarks
- Fair trainer battles
- Objective-based gym logic
- Minimal backtracking
- Good pacing

---

## 4) Chapter 1 scope lock

### Included
- 1 starting town
- 1 short route
- 1 dungeon-lite area
- 1 city
- 1 gym
- 2 rival battles
- 6–8 trainers total before the badge
- 20–30 wild species in the chapter pool
- starter selection
- Pokédex / party / bag / battle basics
- badge reward and a route unlock for Chapter 2

### Excluded from Chapter 1
- Fusion mechanics
- Field Effects system
- open world scaling
- online features
- side quest chains
- postgame
- mega evolutions, Z-moves, terastallization
- custom battle gimmicks beyond expansion defaults
- complex multi-gym progression

### Chapter control rule
Any new feature must satisfy at least one of these:
- it improves the first 60-second player loop
- it reduces friction
- it is required for the first badge experience
- it is needed for Chapter 2 continuity

Anything else goes to the parking lot.

---

## 5) Chapter 1 world structure

## Map 1: Ember Hollow Town
### Purpose
Starting town and tutorial anchor.

### Key locations
- Player house
- Rival house
- Professor’s lab
- Town square
- Gate to Route 1

### Events
- starter selection
- first talk with professor
- first rival encounter
- one tutorial battle or forced demonstration battle
- receive Pokédex and starter gift

### Visual direction
- sleepy harbor district
- small pier
- wind socks, lantern poles, moored boats
- one old beacon tower visible in the background

---

## Map 2: Route 1 — Saltwind Path
### Purpose
First exploration route.

### Structure
- linear with one side branch
- tall grass pockets
- 3 trainers
- 2 optional item pickups
- small cliffs and shoreline edge

### Wild encounters
Suggested pool:
- Pidgey
- Zigzagoon
- Wurmple
- Shinx
- Budew
- Tentacool (if shore segment is present)
- Wingull
- Lotad

### Teaching beats
- wild battle
- catching tutorial
- status condition tutorial
- held item tutorial via an NPC gift or pickup

### Map feel
- bright, simple, readable
- no large maze
- one visually distinctive bridge or pier section

---

## Map 3: Cinder Reed Grove
### Purpose
Dungeon-lite early challenge.

### Design goal
A short forested area that feels like a dungeon without becoming a maze.

### Structure
- 3 connected rooms
- one dead-end reward path
- one environmental obstacle
- one mini-rest spot
- 3 trainers

### Environmental gimmick
Use **toggleable light posts / beacon lamps** to open or reveal the correct path.

This is not a battle gimmick. It is a simple overworld puzzle:
- some paths are dark and hidden
- activating lamps reveals safe tiles
- the player can always see the solution if they explore

### Reward structure
- Potion
- Repel
- one held item or technical item
- one optional rare encounter

### Story purpose
The grove is being used by thieves / looters / smugglers to move stolen parts toward the city.

---

## Map 4: Brassfall City
### Purpose
The first city and badge hub.

### Key locations
- Pokémon Center
- Mart
- Gym
- Harbor bulletin board
- Lighthouse district gate
- NPC side rooms for flavor

### City identity
- industrial port
- band posters
- stage banners
- old power cables
- lighthouse machinery

### City progression
The player arrives after the grove and learns that the city’s gym doubles as a performance hall.

---

## Map 5: Forte Hall Gym
### Gym type
**Normal-type gym**

### Theme
Singer / band / performance stage

### Puzzle type
Objective-based light activation puzzle.

### Gym logic
- The gym is dark at the start.
- Defeating trainers activates stage lights.
- Lights reveal the next section of the hall.
- The final door opens only when all required lights are on.

### Why this works
- deterministic
- fair
- easy to read in a GBA environment
- consistent with the research’s recommendation to avoid subjective puzzles

---

## 6) Chapter 1 story outline

### Opening beat
The player wakes in Ember Hollow during a harbor repair day. The professor is at the lab preparing starter distribution because the beacon network has failed and routes are becoming unsafe.

### Beat 1: starter selection
The player receives a starter and a Pokédex.

Starter trio:
- **Fire:** Growlithe
- **Water:** Wooper
- **Grass:** Budew

These are chosen because they are readable, early-game friendly, and easy to balance for a first chapter.

### Beat 2: rival introduction
The rival is introduced as someone from the harbor district who values speed and “getting things done” over careful planning. They are not evil. They are impatient.

### Beat 3: Route 1 journey
The player crosses Saltwind Path, learns catching basics, and fights 3 trainers.

### Beat 4: grove incident
In Cinder Reed Grove, the player finds evidence of stolen beacon parts being moved through the forest.

### Beat 5: city arrival
Brassfall City is partially dark because the main light channel to the theater hall and harbor district is failing.

### Beat 6: gym challenge
The player enters Forte Hall Gym, solves the light-based stage puzzle, and fights the leader.

### Beat 7: chapter end
The leader gives the first badge and confirms the next objective:
- travel inland to the old relay road
- investigate why the beacon network is failing
- follow the thieves’ trail

---

## 7) Rival battles

## Rival name
**Mira** or **Jett**
Pick one and keep it consistent.

### Rival personality
- quick-talking
- competitive
- not cruel
- slightly arrogant
- respects strength, not ceremony

### Rival Battle 1
Occurs on Route 1.

#### Purpose
- show starter type matchup
- teach basic battle rhythm
- end quickly

#### Team
- starter counterpick, level 6
- one support Pokémon, level 5

### Rival Battle 2
Occurs before the gym entrance.

#### Purpose
- show growth
- force the player to use items if needed
- make the gym feel earned

#### Team
- starter counterpick, level 10
- bird or rodent pivot, level 9
- one utility mon, level 9

### Rival design note
The rival should not be a high-level wall. The goal is pressure, not punishment.

---

## 8) Trainer and boss design

## Pre-gym trainer design rules
- Each trainer teaches one thing.
- No duplicate gimmicks in the same route unless it serves pacing.
- Avoid multi-Pokémon teams too early.
- Keep battles short and readable.

### Trainer roster targets
- Route 1: 3 trainers
- Grove: 3 trainers
- Gym: 3 puzzle trainers + leader

### Example trainer progression
1. Early bug or bird trainer
2. Status-focused trainer
3. Type-coverage trainer
4. Grove grunt with weakened party
5. Grove grunt with surprise item
6. Gym stage manager
7. Gym backup singer
8. Gym lead tech
9. Leader

---

## 9) Gym leader design

## Gym Leader: Vera Forte
### Identity
Lead vocalist and stage director of Forte Hall. She treats battle like a live performance: timing, rhythm, and pressure matter.

### Badge
**Beacon Badge**

### Leader battle level cap
Target cap: **14**

### Team
Keep it small and fair.

Suggested team:
- **Lillipup** — level 12
  Role: opener, early pressure, basic attacks
- **Aipom** — level 13
  Role: utility and tempo
- **Smeargle** — level 14
  Role: ace with a performance-themed moveset

### Smeargle idea
Use a defined, non-random moveset that feels thematic:
- Fake Out
- Swift
- Helping Hand
- Encore

This creates an early boss that feels clever without demanding deep AI systems.

### Leader battle behavior
- opens with tempo pressure
- uses stage-support items sparingly or not at all
- should be hard enough to feel like a boss, but beatable by a prepared level 12–14 team

---

## 10) Chapter 1 encounters and roster slice

### Recommended regional dex slice for the chapter
Use a small chapter pool that supports early balance.

Suggested available species:
- Starter trio
- Pidgey
- Zigzagoon
- Wurmple
- Shinx
- Budew
- Wingull
- Lotad
- Tentacool
- Shroomish
- Nincada
- Geodude
- Marill
- Abra
- Meditite
- Machop
- Surskit
- Kricketot
- Oddish
- Ralts

This is enough to make the chapter feel alive without overbuilding the whole region.

---

## 11) Progression rewards

### Badge 1 reward
- Beacon Badge
- access to the next route
- one new overworld traversal permission if needed
- one early-game TM or move tutor unlock

### Chapter 1 optional reward
A small quality-of-life gift from the city attendant:
- fishing rod, or
- bike later, or
- an early utility item

Keep rewards simple. Do not overload Chapter 1.

---

## 12) Technical implementation notes for `pokeemerald-expansion`

This chapter is designed for a GBA ROM built from the decomp toolchain.

### Why this base fits
- `pokeemerald-expansion` is a GBA ROM hack base built on top of pret’s `pokeemerald` decompilation project, and it is not a playable game on its own. citeturn895181view0
- It builds to a `pokeemerald.gba` ROM with `make`. citeturn895181view3
- Porymap is the map editor for the Gen 3 decomp projects, including `pokeemerald`. citeturn895181view4

### Recommended workflow
- map layout in Porymap
- trainers in trainer party data files
- scripts in event script files
- flags/vars for gate logic
- battle data in expansion-supported tables
- build test ROM after each milestone

### Chapter 1 implementation constraints
- use existing event and trainer systems first
- avoid custom engine rewrites
- rely on flags and vars for progression
- add only the minimum extra code needed for the puzzle gym

---

## 13) Data model notes

### Suggested chapter data files
- `data/trainers/chap1_trainers.h`
- `data/maps/chap1_maps.h`
- `data/wild_encounters/chap1_encounters.h`
- `data/scripts/chap1_story.inc`
- `data/flags_vars/chap1_progress.h`

### Suggested flag groups
- starter chosen
- route rival beaten
- grove cleared
- gym puzzle lights activated
- gym leader defeated
- badge received

### Suggested variable groups
- stage light state
- rival battle count
- chapter progression state
- optional tutorial state

---

## 14) Acceptance criteria for Chapter 1

The chapter is complete only if all of these are true:
- player can choose a starter
- player can move from town to route to grove to city
- at least 6 trainer battles work
- rival battle 1 and 2 both trigger correctly
- gym puzzle behaves deterministically
- leader battle ends and gives badge
- chapter progression flag unlocks the next route
- ROM builds successfully into a playable `.gba`

---

# 15) Spec Kit SDD prompt pack

Use the following prompts in order.

---

## Prompt 1 — Project brief

```text
You are creating a new Pokémon fan game for the GBA using pokeemerald-expansion.

Project name: Pokémon Beaconfall
Format: Chapter-based episodic release
Target output: buildable .gba ROM
Primary goal: ship Chapter 1 as a complete vertical slice

You must work within pokeemerald-expansion conventions, use flags/vars/scripts/data tables, and avoid engine rewrites unless absolutely required.

Chapter 1 must include:
- Ember Hollow Town
- Saltwind Path
- Cinder Reed Grove
- Brassfall City
- Forte Hall Gym
- 2 rival battles
- starter selection
- one badge
- a complete chapter end state

Deliverable: ask the minimum necessary clarifying questions, then produce a precise PRD for Chapter 1.
```

---

## Prompt 2 — PRD generation

```text
Write a product requirements document for Chapter 1 of Pokémon Beaconfall.

Use these sections:
1. Goal
2. Non-goals
3. Player experience
4. Chapter flow
5. Maps
6. Battles
7. Gym puzzle
8. Rewards
9. Technical constraints
10. Acceptance criteria

Rules:
- Keep the chapter scope small
- Do not add fusion, field effects, or postgame systems
- Use a Normal-type stage gym with light-triggered progression
- Make the result suitable for a GBA ROM built with pokeemerald-expansion

The PRD must be specific enough that implementation can start directly from it.
```

---

## Prompt 3 — SDD generation

```text
Convert the Chapter 1 PRD into a software design document for a pokeemerald-expansion ROM hack.

The SDD must include:
- system overview
- map and event architecture
- progression flags and variables
- trainer and party data strategy
- battle scripting strategy
- gym puzzle implementation strategy
- build and test workflow
- risks and mitigations
- scope control rules

Use the architecture of pokeemerald-expansion, not a separate engine.
Assume the build target is a playable .gba file.
```

---

## Prompt 4 — Implementation plan

```text
Break the Chapter 1 SDD into an implementation plan.

Create:
- milestone list
- ordered tasks
- dependencies
- estimated complexity
- test checkpoints
- rollback points

Prioritize tasks so the chapter becomes playable as soon as possible:
1. starter selection
2. route traversal
3. trainer battles
4. grove traversal
5. city arrival
6. gym puzzle
7. gym leader
8. badge and chapter completion

Keep the plan realistic for a decomp ROM hack.
```

---

## Prompt 5 — Map implementation spec

```text
Write a map implementation spec for these maps:
- Ember Hollow Town
- Saltwind Path
- Cinder Reed Grove
- Brassfall City
- Forte Hall Gym

For each map, define:
- purpose
- layout notes
- exits
- scripted events
- required flags
- trainer placements
- item placements
- any puzzle objects or triggers

The maps must be suitable for Porymap and pokeemerald-expansion.
```

---

## Prompt 6 — Event scripting spec

```text
Write the event scripting spec for Chapter 1.

Include:
- starter selection event
- professor introduction
- rival battle 1
- rival battle 2
- route trainers
- grove encounter event
- city arrival event
- gym puzzle light activation events
- leader encounter
- badge award
- chapter completion flag

Use flags and variables instead of hardcoded one-off logic where possible.
Make the scripts deterministic and easy to debug.
```

---

## Prompt 7 — Trainer data spec

```text
Write the trainer data spec for Chapter 1.

Include:
- trainer names
- class names
- party composition
- levels
- held items if needed
- AI notes
- battle purpose

There must be:
- 3 Route 1 trainers
- 3 Grove trainers
- 2 rival battles
- 3 gym trainers
- 1 gym leader

Keep the battles short and readable.
```

---

## Prompt 8 — Gym puzzle spec

```text
Design the Forte Hall Gym puzzle for pokeemerald-expansion.

Requirements:
- Normal-type theme
- stage / performance / lighting motif
- objective-based, not subjective
- deterministic logic
- implemented with lights turning on after trainer defeats
- final door opens when all required lights are on

Provide:
- puzzle rules
- object list
- trigger logic
- failure states if any
- player feedback text
- test cases
```

---

## Prompt 9 — Technical implementation spec

```text
Write the technical implementation spec for Chapter 1 in pokeemerald-expansion.

Cover:
- which files or file groups will change
- how progression flags are stored
- how map transitions are handled
- how trainer battles are wired
- how the badge reward is granted
- how the chapter-complete state unlocks the next route
- how to keep the build stable

Do not introduce custom systems that are not necessary for Chapter 1.
```

---

## Prompt 10 — QA / test spec

```text
Write a QA plan for Chapter 1 of Pokémon Beaconfall.

The plan must test:
- starter selection
- route traversal
- random encounters
- trainer battle flow
- rival battle 1 and 2
- grove event progression
- gym puzzle logic
- badge award
- chapter completion flag
- .gba build output

List edge cases and regression risks.
Include what should be verified after every implementation milestone.
```

---

## Prompt 11 — Change control prompt

```text
Create a change control policy for Pokémon Beaconfall Chapter 1.

Rules:
- any new feature must improve the first chapter’s core loop or reduce friction
- any new mechanic that adds engine complexity must be rejected unless required
- fusion, field effects, and open-world scaling are not allowed in Chapter 1
- any content addition must explain its impact on scope, testing, and build stability

The policy should be strict enough to keep the project shippable.
```

---

## Prompt 12 — Final integration prompt

```text
Assemble the final Chapter 1 implementation package.

Output:
- final SDD
- implementation order
- map/event/task breakdown
- test checklist
- scope lock list

Make sure the result is ready for a GBA ROM hack built with pokeemerald-expansion and can be turned into a playable .gba build.
```

---

# 16) Suggested file set for the repo

```
/docs
  Beaconfall_Chapter1_SDD.md
  Beaconfall_Chapter1_PRD.md
  Beaconfall_Chapter1_SpecKit_Prompts.md

/data
  /trainers
  /wild_encounters
  /scripts
  /flags_vars

/maps
  /EmberHollow
  /SaltwindPath
  /CinderReedGrove
  /BrassfallCity
  /ForteHallGym
```

---

# 17) What not to do in Chapter 1

- do not add fusion
- do not add field effects
- do not add open world scaling
- do not add multiplayer
- do not build a huge dex
- do not over-script the gym
- do not make the rival overly hard
- do not expand beyond the first badge

---

# 18) Final chapter summary

Chapter 1 of Pokémon Beaconfall is a compact vertical slice:
- one starter
- one route
- one forest puzzle area
- one city
- one stage-themed Normal gym
- two rival battles
- one badge
- a clear story hook for Chapter 2

It is deliberately sized to be:
- buildable in a GBA decomp workflow
- easy to test
- easy to extend
- compatible with Spec Kit style planning
- realistic for a first ROM-hack milestone
