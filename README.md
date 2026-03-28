# About `pokeemerald-expansion`

![Gif that shows debugging functionality that is unique to pokeemerald-expansion such as rerolling Trainer ID, Cheat Start, PC from Debug Menu, Debug PC Fill, Pokémon Sprite Visualizer, Debug Warp to Map, and Battle Debug Menu](https://github.com/user-attachments/assets/cf9dfbee-4c6b-4bca-8e0a-07f116ef891c) ![Gif that shows overworld functionality that is unique to pokeemerald-expansion such as indoor running, BW2 style map popups, overworld followers, DNA Splicers, Gen 1 style fishing, OW Item descriptions, Quick Run from Battle, Use Last Ball, Wild Double Battles, and Catch from EXP](https://github.com/user-attachments/assets/383af243-0904-4d41-bced-721492fbc48e) ![Gif that shows off a number of modern Pokémon battle mechanics happening in the pokeemerald-expansion engine: 2 vs 1 battles, modern Pokémon, items, moves, abilities, fully customizable opponents and partners, Trainer Slides, and generational gimmicks](https://github.com/user-attachments/assets/50c576bc-415e-4d66-a38f-ad712f3316be)

<!-- If you want to re-record or change these gifs, here are some notes that I used: https://files.catbox.moe/05001g.md -->

**`pokeemerald-expansion`** is a GBA ROM hack base that equips developers with a comprehensive toolkit for creating Pokémon ROM hacks. **`pokeemerald-expansion`** is built on top of [pret's `pokeemerald`](https://github.com/pret/pokeemerald) decompilation project. **It is not a playable Pokémon game on its own.**

# [Features](FEATURES.md)

**`pokeemerald-expansion`** offers hundreds of features from various [core series Pokémon games](https://bulbapedia.bulbagarden.net/wiki/Core_series), along with popular quality-of-life enhancements designed to streamline development and improve the player experience. A full list of those features can be found in [`FEATURES.md`](FEATURES.md).

# [Credits](CREDITS.md)

 [![](https://img.shields.io/github/all-contributors/rh-hideout/pokeemerald-expansion/upcoming)](CREDITS.md)

If you use **`pokeemerald-expansion`**, please credit **RHH (Rom Hacking Hideout)**. Optionally, include the version number for clarity.

```
Based off RHH's pokeemerald-expansion 1.15.0 https://github.com/rh-hideout/pokeemerald-expansion/
```

Please consider [crediting all contributors](CREDITS.md) involved in the project!

# Choosing `pokeemerald` or **`pokeemerald-expansion`**

- **`pokeemerald-expansion`** supports multiplayer functionality with other games built on **`pokeemerald-expansion`**. It is not compatible with official Pokémon games.
- If compatibility with official games is important, use [`pokeemerald`](https://github.com/pret/pokeemerald). Otherwise, we recommend using **`pokeemerald-expansion`**.
- **`pokeemerald-expansion`** incorporates regular updates from `pokeemerald`, including bug fixes and documentation improvements.

# [Getting Started](INSTALL.md)

❗❗ **Important**: Do not use GitHub's "Download Zip" option as it will not include commit history. This is necessary if you want to update or merge other feature branches.

If you're new to git and GitHub, [Team Aqua's Asset Repo](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/) has a [guide to forking and cloning the repository](https://github.com/Pawkkie/Team-Aquas-Asset-Repo/wiki/The-Basics-of-GitHub). Then you can follow one of the following guides:

## 📥 [Installing **`pokeemerald-expansion`**](INSTALL.md)
## 🏗️ [Building **`pokeemerald-expansion`**](INSTALL.md#Building-pokeemerald-expansion)
## 🚚 [Migrating from **`pokeemerald`**](INSTALL.md#Migrating-from-pokeemerald)
## 🚀 [Updating **`pokeemerald-expansion`**](INSTALL.md#Updating-pokeemerald-expansion)

# [Documentation](https://rh-hideout.github.io/pokeemerald-expansion/)

For detailed documentation, visit the [pokeemerald-expansion documentation page](https://rh-hideout.github.io/pokeemerald-expansion/).

# [Contributions](CONTRIBUTING.md)
If you are looking to [report a bug](CONTRIBUTING.md#Bug-Report), [open a pull request](CONTRIBUTING.md#Pull-Requests), or [request a feature](CONTRIBUTING.md#Feature-Request), our [`CONTRIBUTING.md`](CONTRIBUTING.md) has guides for each.

# [Community](https://discord.gg/6CzjAG6GZk)

[![](https://dcbadge.limes.pink/api/server/6CzjAG6GZk)](https://discord.gg/6CzjAG6GZk)

Our community uses the [ROM Hacking Hideout (RHH) Discord server](https://discord.gg/6CzjAG6GZk) to communicate and organize. Most of our discussions take place there, and we welcome anybody to join us!

<!-- docs-overview:start -->
## Documentation index (auto-generated)

This section lists discovered Markdown docs in this repository. Nested `docs/` content is summarized by [`docs/SUMMARY.md`](docs/SUMMARY.md) (subtree short-circuit).

### Repository root

- [Beaconfall Spec Kit Prompts](BEACONFALL_SPEC_KIT_PROMPTS.md) — Markdown document in this repository.
- [Pokeemerald-Expansion Changelogs](CHANGELOG.md) — Index of release notes with links into `docs/changelogs/`.
- [Contributing to pokeemerald-expansion](CONTRIBUTING.md) — First off, thanks for helping improve `pokeemerald-expansion`! ❤️
- [Credits ✨](CREDITS.md) — Thanks goes to these wonderful people ([emoji key](https://allcontributors.org/docs/en/emoji-key)):
- [What features are included?](FEATURES.md) — A lot of features listed below can be turned off as desired. Check which ones in these files
- [Pokémon Beaconfall — Chapter 1 Design + Spec Kit SDD Prompt Pack](FIRST_CHAPTER_PLAN.md) — This project is a **new, original Pokémon fan game** built as a **GBA ROM hack** on top of `pokeemerald-expansion`.
- [Instructions](INSTALL.md) — Install instructions for each supported operating system can be found in their respective directories under `docs/install/`. Lines to those can be found under each heading. This file only contains a short introduction to each supported…
- [RESEARCH](RESEARCH.md) — Architectural specification and forensic analysis of successful Pokémon fan-game projects; scope and engine patterns for long-running ROM hack development.

### .github

- [Description](.github/pull_request_template.md) — <!-- Detail the changes made, why they were made, and any important context. -->

### docs

- [Summary](docs/SUMMARY.md) — Navigation outline for the `docs/` tree: install guides, tutorials, team procedures, and version changelogs.

### migration_scripts

- [Migration Scripts](migration_scripts/README.md) — pokeemerald-expansion rewrites existing systems in pokeemerald to improve their efficiency and make them easier to use and implement for developers. If developers were previously using a system that has been deprecated, it can be…

### tools

- [mGBA](tools/mgba/README.md) — The binaries in this folder are built from `mGBA`, an emulator for running Game Boy Advance games. The source code is available here: <https://github.com/mgba-emu/mgba>. The source code for these specific builds is available from:
- [wav2agb](tools/wav2agb/README.md) — "wav2agb" is a tool to convert standard .wav files to GBA compatible .s or .bin files.  Intended to convert .wav files for the use with the mp2k/m4a sound driver.
<!-- docs-overview:end -->
