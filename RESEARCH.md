 Architectural Specification for End-to-End Pokémon Fan Game Development: A Forensic Analysis of Legendary Successes
The evolution of Pokémon fan games from simple sprite swaps to sophisticated technical marvels represents a unique intersection of community passion and software engineering discipline. To construct a brand-new, open-source project using modern specification kits like Cursor and VS Code, a developer must understand the underlying patterns that govern the industry's most successful titles. This forensic analysis dissects the architectural, aesthetic, and mechanical foundations of projects like Pokémon Unbound, Infinite Fusion, Reborn, and Radical Red to provide a granular technical blueprint for the next generation of fan-developed RPGs.
Success Metrics and the Psychographics of Completion
The disparity between legendary fan games and the vast graveyard of abandoned projects is rarely a matter of initial talent but rather a matter of scope management and development philosophy. Forensic evidence from successful post-mortems indicates that the primary indicator of completion is the establishment of a rigorous "Minimum Viable Product" (MVP) and a commitment to iterative shipping.
Determinants of Long-Term Project Viability
Analysis of projects such as Pokémon Reborn and Rejuvenation reveals a reliance on episodic releases to maintain momentum. By breaking a massive RPG into manageable chapters, developers create a feedback loop that rewards completion with community engagement. This "fail fast" approach allows for the testing of core mechanics—such as the battle engine or the custom UI—before the entire world map is even drafted. Successful developers often utilize project management tools like Jira, Trello, or Codecks to turn abstract goals into granular tasks, effectively preventing the "vision drift" that occurs when a project expands beyond its original parameters.
Metric Category
Legendary Game Traits
Abandoned Game Traits
Release Strategy
Iterative/Episodic releases (e.g., Reborn).
Single "Big Bang" release attempt.
Feature Prioritization
MoSCoW framework; strict "Won't-have" list.
Feature frenzy; adding "cool" ideas mid-build.
Community Feedback
Public alpha/beta cycles on Discord/GameJolt.
Isolated development without player testing.
Technical Foundation
Well-documented engine (Essentials, Godot, C).
Custom engine built from scratch without a framework.
Documentation
Rigorous Software Design Document (SDD).
Vague or non-existent design documents.
Managing Scope Creep through Structural Discipline
Scope creep is identified as the single largest cause of project failure in the indie and fan-game sphere. Developers often succumb to "Feature Frenzy," where the desire to implement every generation’s mechanics (Mega Evolution, Z-Moves, Terastallization) leads to a recursive cycle of bug-fixing that stalls story progress. Legendary games like Pokémon Unbound manage this by establishing "Constraint Kickoffs" where every new idea is filtered through a mathematical cost-benefit analysis: if a feature does not enhance the "60-second core loop"—what the player does repeatedly for one minute—it is relegated to a "parking lot" for post-game updates.
The technical specification for an open-source project must include a "Change Control Process." This ensures that any deviation from the SDD is assessed for its impact on the timeline and resource allocation. For instance, if a developer decides to add a "Social MMO Hub" (as requested by some players in Emerald Rogue), the architect must evaluate the networking overhead and potential delay to the core single-player experience.
Aesthetics, Mapping, and Art Direction
The visual identity of a Pokémon fan game serves as the primary interface for player immersion. The choice between retro-styled ROM hacking and modern HD-2D engines dictates the technical constraints of the entire project.
Choosing an Art Style and Engine Synergy
Most successful fan games fall into three aesthetic categories: Gen 3 (GBA style), Gen 4/5 (DS style), and custom modern styles. Pokémon Unbound and Radical Red utilize the Gen 3 engine because of its extreme stability and the massive repository of C-based decompilation tools available. Conversely, projects like Reborn and Infinite Fusion utilize RPG Maker XP and Pokémon Essentials to achieve a Gen 4 style that allows for more complex layering and eventing than original GBA hardware could support.
Emerging projects are increasingly looking toward Godot for an "HD-2D" aesthetic. Engines like the Godot-based Pokémon FireLeaf or Project Uranium Godot provide cross-platform compatibility (Windows, Mac, Linux, Android) that RPG Maker cannot natively achieve. This technical flexibility allows for "Screaming Architecture," where the folder structure of the assets (sprites, audio, tiles) directly mirrors the logical structure of the game's code.
Map Design: Linear Narratives vs. Open-World Agency
The architectural philosophy of the world map determines the game's pacing. Linear maps, typical of traditional Pokémon regions, allow for a curated difficulty curve where the developer knows exactly what tools the player has at any given time. However, "Open-World" designs like Pokémon Crystal Clear or Pokémon ROWE introduce a "Scaling Orderless Gym" system.
Technically, open-world implementation requires a global variable—often called the "Badge Constant"—that modifies every trainer's party and wild Pokémon levels based on the player's current progression. This avoids the pitfall of the official Scarlet and Violet, where an open world without level scaling results in players accidentally wandering into high-level areas or steamrolling low-level gyms.
Gym Architecture and Dungeon Design
Legendary gyms are designed as thematic dungeon crawls rather than simple gauntlets of trainers. Forensic analysis of gym puzzles shows a preference for "objective-based" progression.
Gym Theme
Design Motif
Technical Implementation
Normal (Forte)
Singer/Band
Lighting triggers; defeating trainers lights up parts of a stage.
Grass (Woodrow)
War Veteran
Vertical mazes using pitfalls and jungle-themed foliage.
Poison (Mia)
Scientist
Vat-filling puzzles and chemical spill "ice" sliding.
Steel (Kenji)
Samurai/Actor
Logic-gate riddles where correct answers open doors; wrong answers trigger trainers.
Water
Space/Moon
Gravity-flipping or water-level manipulation using lever-controlled event states.
Architects should avoid subjective judging in puzzles and instead rely on unambiguous mechanics—like "Capture the Flag" or "Rubik's Cube" logic—to ensure the player feels the challenge is fair and consistent.
Combat Engineering, Generations, and Custom Mechanics
The combat engine is the most data-intensive component of a Pokémon fan game. Balancing the integration of Gen 1–9 rosters while adding custom gimmicks like fusions requires a robust backend framework.
The Data Structures of Roster Management
Successful games often limit their Pokédex to a "Regional Dex" of 180–400 Pokémon to ensure that every species has a specific niche and appropriate balance within the game's economy. Using a centralized database like Veekun’s SQLite ensures that stats, abilities, and movepools are consistent with official data. In an open-source project, these should be stored as JSON or .tres resources for easy modification via VS Code or Cursor.
Technical Implementation of the Fusion Mechanic
Pokémon Infinite Fusion provides the industry standard for custom mechanics. The fusion system is governed by a strict mathematical inheritance model that prevents the need for manual data entry for every possible combination.
Stat Inheritance Logic
The base stats of a fused Pokémon are calculated using a weighted average formula. Let the "Body" Pokémon be B and the "Head" Pokémon be H:
	•	Physical Stats (Attack, Defense, Speed):
	•	Special Stats (HP, Special Attack, Special Defense):
This weighting ensures that the "Body" determines the physical bulk and speed, while the "Head" determines the mental/special capabilities.
Typing and Ability Inheritance
Type inheritance is similarly algorithmic: the resulting fusion takes the Head's primary type and the Body's secondary type. If the Head is a dual-type (Poison/Flying) and the Body is mono-type (Poison), the fusion becomes pure Poison to avoid type redundancy. Ability inheritance is managed through a "Hidden Ability Value" (1 or 2); the fusion inherits the value of the Body, which then maps to either the first ability of the Body or the first ability of the Head.
Environmental Combat: Field Effects
Pokémon Reborn’s "Field Effects" represent the pinnacle of environmental battle complexity. There are 37 documented fields, each functioning as a global "Battle State" that modifies move power, accuracy, and secondary effects.
Field Name
move Power Boosts (1.5x)
Mechanical Alterations
Seed Interaction (Elemental/Magical/etc.)
Electric Terrain
Electric-type moves
Nature Power becomes Thunderbolt
Elemental Seed: Raises Speed, applies Charge.
Grassy Terrain
Grass-type moves
Earthquake/Magnitude/Bulldoze damage halved
Elemental Seed: Raises Defense, applies Ingrain.
Burning Field
Fire-type moves
Grass/Ice moves lose power; Nature Power becomes Flamethrower
Elemental Seed: Raises Atk, SpAtk, Speed; applies Fire Spin.
Rainbow Field
Varies (multi-type)
Increases luck-based effects; Nature Power becomes Aurora Beam
Magical Seed: Raises Special Attack, applies Wish.
Chess Board
Psychic/Normal
Multiplies damage by "Piece Rank" logic
Synthetic Seed: Raises SpAtk, applies Magic Coat.
Glitch Field
Varies
Reverts mechanics to Gen 1 logic (e.g., Special stat fusion)
Synthetic Seed: Raises Defense, changes type to???.
The technical implementation of these fields involves a "Field Logic" layer in the battle engine script that checks the currentField variable before every damage calculation. If a damaging move transforms the field (e.g., using "Blizzard" on a "Water Surface" to create an "Icy Field"), the move receives a 1.3x "Transformation Boost".
Difficulty and Nuzlocke Integrations
Legendary games respect the player's time by integrating difficulty settings directly into the engine's core. "Hardcap" systems, seen in Reborn and Rejuvenation, prevent Pokémon from leveling past the next gym leader's highest level, effectively removing the "grind to win" strategy.
Nuzlocke Logic
A built-in Nuzlocke toggle (triggered by a "password" or menu option) enforces the following rules at the engine level:
	•	HP Check: When a Pokémon's HP reaching 0, a persistent flag isFainted is set to true, and the pbHeal function is overridden for that specific member.
	•	Encounter Lock: A "Region Catch Flag" is set once a wild battle results in a capture, preventing subsequent pbWildBattle calls from allowing a Pokéball to be thrown in that map ID.
	•	Wipe-out Logic: If the entire party has the isFainted flag, the engine triggers a GameOver state rather than simply teleporting to the last Pokémon Center.
To further respect the player's time, "Minimal Grinding" modes (as seen in Radical Red) set all Pokémon IVs to 31 and eliminate EVs entirely. This shifts the difficulty from "who spent more time grinding" to "who has the better tactical strategy".
Economy, Shops, and Progression Quality of Life (QoL)
The economy of a fan game must be carefully balanced to provide a sense of progression while ensuring the player can access competitive tools for the late-game challenge.
Gating Competitive Items and Shops
In a legendary fan game, items like "Life Orbs," "Choice Specs," and "Expert Belts" are treated as high-tier rewards. They are typically gated behind:
	1	Badge Requirements: Certain items only appear in Department Stores after the 5th or 6th badge.
	2	Side Quests: Side quests reward unique items like the "Lucky Egg" or "Exp. Share".
	3	Battle Point (BP) Markets: Post-game or mid-game "Black Markets" allow players to exchange BP earned in difficult battles for competitive items.
The "Unthinkable" QoL Details
Top-tier games are defined by features that eliminate traditional Pokémon friction. These should be considered the "technical baseline" for any new project developed in VS Code/Cursor.
QoL Feature
Technical Implementation
Impact
Remote PC Access
Global shortcut to the storage menu pbPokeCenterPC from the party screen.
Eliminates backtracking to cities to swap team members.
Instant Text
Setting the text scroll wait-time to 0 frames.
Drastically speeds up the pacing for veteran players.
HM Key Items
Using a "Field Move" flag that checks if a Pokémon could learn the move, rather than requiring it be taught.
Frees up 4 move slots on the player's team.
Auto-Repel
A popup trigger when RepelSteps == 0 asking to use another item.
Removes menu-diving every 100 steps.
IV/EV Viewer
Custom UI overlay on the summary screen displaying exact values.
Allows for competitive planning without external calculators.
Following Pokémon
A persistent event actor that mirrors the player's sprite and position.
Increases player immersion and "bond" with their Pokémon.
Special features like the "Aerodactyl utility"—which allows the player to fly over broken tiles in the overworld—or the "Mow Rotom utility"—which automatically cuts tall grass—serve as "unthinkable" details that reward specific Pokémon lead choices with mechanical benefits.
Technical Architecture (The Developer Side)
Choosing the correct technical stack is the most critical decision in the pre-production phase. Modern developers are moving away from the limitations of RPG Maker XP and toward more flexible, open-source environments.
Engine Deep Dive: RPG Maker vs. Godot vs. C
1. RPG Maker XP + Pokémon Essentials (The Legacy Standard)
Essentials is the most feature-complete framework, with a decade of community plugins for every generation’s mechanics. However, its reliance on a 20-year-old 32-bit engine (RMXP) means it suffers from poor performance on modern hardware and lacks native mobile/cross-platform support.
	•	Language: Ruby (RGSS).
	•	Data Structure: Proprietary .rxdata files (difficult to version control on GitHub).
2. Godot Engine (The Open-Source Future)
Godot projects like Pokémon FireLeaf and Project Uranium Godot are built on modern GDScript, which is Python-based and highly readable. Godot allows for native cross-platform builds and utilizes a "Node-based" architecture that is much more efficient for complex eventing.
	•	Language: GDScript / C#.
	•	Data Structure: Plaintext .tscn and .tres files (perfect for GitHub and Cursor-based code generation).
3. C-Based Decompilation (The ROM Hack Standard)
Projects like Pokémon Unbound and Radical Red are built by modifying the original GBA source code in C. This provides the most "authentic" feel but has a much steeper learning curve and is limited by the original GBA's hardware constraints (e.g., RAM limits for sprites and music).
Directory Architecture and Spec Kit for Cursor
To effectively use Cursor or VS Code for development, the project should follow a "Function-First" directory structure. This allows the AI to easily locate and modify relevant modules without getting lost in a monolithic script.
/my-pokemon-game ├── /src │ ├── /battle_engine # Move logic, field effects, and damage math │ ├── /overworld_logic # NPC interactions, HMs, and mapping scripts │ ├── /ui_management # Summary screens, menus, and text boxes │ └── /save_system # Encryption and persistent state management ├── /data │ ├── /species.json # All Pokémon base stats and learnsets │ ├── /moves.json # Move properties and secondary effects │ └── /items.json # Item effects and shop pricing ├── /assets │ ├── /sprites # Pokémon, trainers, and tilesets │ └── /audio # Adaptive music tracks and cries └── /docs ├── SDD.md # Software Design Document └── Spec_Kit.md # Prompts and rules for Cursor/AI development
Architects should leverage VS Code's "Text Replacement" and "Macro" capabilities to automate repetitive tasks like gift-giving or item-batching.
Case Study: Pokémon Radical Red Trainer Engineering
To understand the "Forensic Level of Detail" required for elite difficulty, one must look at the trainer data structures in Pokémon Radical Red. Every major boss is given a team that functions like a competitive Smogon team.
Case Study: Leader Bugsy (Early Game Boss)
	•	Team Composition: Kleavor (Ace), Scizor, Scyther, Lokix, Araquanid.
	•	AI Directives:
	•	Pivoting: The AI is programmed to use "U-turn" or "Volt Switch" if the current Pokémon is at a type disadvantage.
	•	Item Synergy: Kleavor holds a "Focus Sash" to guarantee a "Stone Axe" (which sets Stealth Rocks). Scyther holds an "Eviolite" for bulk.
	•	Technician Abuse: Both Scizor and Scyther are given movepools (Bullet Punch, Dual Wingbeat) that maximize their "Technician" ability.
	•	Level Scaling: Bugsy’s levels are hard-capped at 24. If a player attempts to enter the gym at level 25, the Pokémon will simply refuse to obey or will have its stats scaled down.
This level of granular detail ensures that even early-game encounters feel like "Boss Battles" rather than simple experience fodder.
Conclusion and Actionable Roadmap
The construction of an open-source Pokémon fan game requires a fusion of high-level architectural planning and low-level mechanical obsession. By following the blueprint established by the genre’s legends, a developer using Cursor and VS Code can avoid the common pitfalls of scope creep and technical debt.
	1	Establish the MVP: Define the "60-second loop" (Battle, Capture, Explore) and build a functional prototype of it before any other feature.
	2	Select the Engine for the Long Term: If cross-platform and open-source transparency are priorities, Godot is the superior choice over the legacy RMXP/Essentials framework.
	3	Implement QoL from Day One: Features like Instant Text and Remote PC Access should be built into the core engine architecture, not added as an afterthought.
	4	Rigorous Data Management: Store all Pokémon and move data in standardized JSON formats to allow for rapid balance changes and community contribution via GitHub.
	5	Iterative Testing: Use "passwords" and "debug modes" to allow for rapid testing of late-game mechanics (like Field Effects or Fusions) during the early development phase.
By treating the project as a professional software engineering task—complete with an SDD and rigorous change control—a developer transforms a "fan project" into a legendary gaming experience that respects both the source material and the player's time.
Works cited
1. How to Avoid Scope Creep in Game Development: Tips and Best Practices - Codecks, https://www.codecks.io/blog/2025/how-to-avoid-scope-creep-in-game-development/ 2. Scope Creep in Games: What It Is & How to Stop It, https://tonogameconsultants.com/scope-creep/ 3. How do you go about minimizing scope creep and planning a game for a jam? - Reddit, https://www.reddit.com/r/gamedev/comments/1qt2ss0/how_do_you_go_about_minimizing_scope_creep_and/ 4. The Best Fan Game Nintendo Ever Killed (Pokemon Uranium Review) - Reddit, https://www.reddit.com/r/pokemonuranium/comments/sphbvg/the_best_fan_game_nintendo_ever_killed_pokemon/ 5. GameDev Protips: How To Kick Scope Creep In The Ass And Ship Your Indie Game | by Daniel Doan | Medium, https://medium.com/@doandaniel/gamedev-protips-how-to-kick-scope-creep-in-the-ass-and-ship-your-indie-game-8fa3051500d1 6. Avoiding Scope Creep in Full-Cycle Game Projects: The Latest Guide - Juego Studios, https://www.juegostudio.com/blog/avoiding-scope-creep-in-full-cycle-game-projects-the-latest-guide 7. Pokeabbie is continuing Emerald Rogue development! : r/PokemonEmeraldRogue - Reddit, https://www.reddit.com/r/PokemonEmeraldRogue/comments/1rcjngx/pokeabbie_is_continuing_emerald_rogue_development/ 8. Hello I'm interested in making a fan game but frankly I'm pretty confused... : r/PokemonRMXP, https://www.reddit.com/r/PokemonRMXP/comments/1jebic2/hello_im_interested_in_making_a_fan_game_but/ 9. Future of Essentials? : r/PokemonRMXP - Reddit, https://www.reddit.com/r/PokemonRMXP/comments/1hf4kya/future_of_essentials/ 10. Essentials v22 gonna be in Godot? : r/PokemonRMXP - Reddit, https://www.reddit.com/r/PokemonRMXP/comments/1hzmf5j/essentials_v22_gonna_be_in_godot/ 11. 2025 might just be the greatest year for Pokemon romhacks ever! : r/PokemonROMhacks - Reddit, https://www.reddit.com/r/PokemonROMhacks/comments/1oyjc93/2025_might_just_be_the_greatest_year_for_pokemon/ 12. Pokabbie/pokeemerald-rogue: Decompilation of Pokémon Emerald - GitHub, https://github.com/Pokabbie/pokeemerald-rogue/ 13. I added the Physical/Special split, the Fairy type, updated battle mechanics and more QoL features to an otherwise vanilla Pokemon Emerald, I call it "QoL Emerald" : r/PokemonROMhacks - Reddit, https://www.reddit.com/r/PokemonROMhacks/comments/tlxh78/i_added_the_physicalspecial_split_the_fairy_type/ 14. Pokémon Infinite Fusion Wiki - Fandom, https://infinitefusion.fandom.com/wiki/Pok%C3%A9mon_Infinite_Fusion 15. acedogblast/Project-Uranium-Godot: A work in progress re-implementation of the game Pokemon Uranium in the Godot Engine. - GitHub, https://github.com/acedogblast/Project-Uranium-Godot 16. SlayHorizon/pokemon-fireleaf-godot: Open-source remake of Pokemon FireRed and LeafGreen built with Godot 4 - GitHub, https://github.com/SlayHorizon/pokemon-fireleaf-godot 17. Are there project architecture style guides? (beyond the official docs) - Godot Forum, https://forum.godotengine.org/t/are-there-project-architecture-style-guides-beyond-the-official-docs/128299 18. Linear or open world? : r/pokemon - Reddit, https://www.reddit.com/r/pokemon/comments/1e9p9fd/linear_or_open_world/ 19. Pokemon Open World vs Linear Worlds #pokemon #gaming #anime #nintendo #nintendoswitch #gamefreak - YouTube, https://www.youtube.com/shorts/V8wfB_Pxu90 20. PokeROMhack list 2025 : r/PokemonROMhacks - Reddit, https://www.reddit.com/r/PokemonROMhacks/comments/1ikj5h8/pokeromhack_list_2025/ 21. Open World vs Linear Pokémon Games | Rocket Roast - YouTube, https://www.youtube.com/watch?v=56pomtnSyc8 22. Gym Design: Unconventional Challenges | Pokémon Tabletop RPG, https://pokemontabletop.com/gym-design-unconventional-challenges/ 23. Gym Leader puzzle ideas : r/PokemonRMXP - Reddit, https://www.reddit.com/r/PokemonRMXP/comments/184n22p/gym_leader_puzzle_ideas/ 24. [Theme Talk] Create your own gym or trial puzzle! : r/pokemon - Reddit, https://www.reddit.com/r/pokemon/comments/6ae3r2/theme_talk_create_your_own_gym_or_trial_puzzle/ 25. PokemonUnity/pklibrary: A C# library to help build Pokémon-esque games. - GitHub, https://github.com/PokemonUnity/pklibrary 26. PokemonUnity/PokemonUnity: A LEGACY Unity project to help build Pokémon-esque RPG games. - GitHub, https://github.com/PokemonUnity/PokemonUnity 27. 5 More COMPLETED Pokemon Fan Games You Should Play In 2025! - YouTube, https://www.youtube.com/watch?v=i_xIbyhc4UE 28. Mechanics - Pokemon Fusion Wiki, http://pokemonfusion.servegame.org/index.php?title=Mechanics 29. On The Fusion Of Species - Your questions about Fusion answered : r/PokemonInfiniteFusion - Reddit, https://www.reddit.com/r/PokemonInfiniteFusion/comments/4f4k4u/on_the_fusion_of_species_your_questions_about/ 30. Field Effects | Pokemon Reborn Wikia | Fandom, https://pokemon-reborn.fandom.com/wiki/Field_Effects 31. pokemon-rejuvenation-re1/Field_Effect_Manual.txt at master - GitHub, https://github.com/AlphaKyogre/pokemon-rejuvenation-re1/blob/master/Field_Effect_Manual.txt 32. Pokemon Reborn Walkthrough | BIGJRA's Walkthroughs, https://bigjra.github.io/reborn/ 33. How do you integrate the fusion mechanics into nuzlocke rules? : r/PokemonInfiniteFusion, https://www.reddit.com/r/PokemonInfiniteFusion/comments/1b3biaj/how_do_you_integrate_the_fusion_mechanics_into/ 34. Pokemon Quetzal: All the QoL features included in v8.2 : r/PokemonROMhacks - Reddit, https://www.reddit.com/r/PokemonROMhacks/comments/1k9okdc/pokemon_quetzal_all_the_qol_features_included_in/ 35. What QoL features, options, small changes etc. would you like to see in a vanilla ROMHack? : r/PokemonROMhacks - Reddit, https://www.reddit.com/r/PokemonROMhacks/comments/1kxp222/what_qol_features_options_small_changes_etc_would/ 36. My big honest review of Pokemon Uranium : r/pokemonuranium - Reddit, https://www.reddit.com/r/pokemonuranium/comments/rf2lnh/my_big_honest_review_of_pokemon_uranium/ 37. FAQ | Pokémon Infinite Fusion Wiki - Fandom, https://infinitefusion.fandom.com/wiki/FAQ 38. What QOL features do you look for most in a fan game? : r/PokemonRMXP - Reddit, https://www.reddit.com/r/PokemonRMXP/comments/1dyg6x3/what_qol_features_do_you_look_for_most_in_a_fan/ 39. Pokemon-like Code Bases in Godot, https://www.polyinnovator.space/pokemon-like-code-bases-in-godot/ 40. Prototyping some QoL changes for Pokemon GO : r/TheSilphRoad - Reddit, https://www.reddit.com/r/TheSilphRoad/comments/pkgkdz/prototyping_some_qol_changes_for_pokemon_go/ 41. Pokémon Radical Red 4.00 Trainer Data (Easy Mode) - GitHub Gist, https://gist.github.com/Rudo2204/c2df216c7ce8c8e8cca7470bf9bb661e 42. Pokémon Radical Red 4.1 Trainer Data (Normal Mode, No Mingrind) · GitHub, https://gist.github.com/Rudo2204/7f9e4a3ceaf077d623d3c37b1f921601 43. Pokémon Radical Red 4.00 Trainer Data (Hardcore Mode) - GitHub Gist, https://gist.github.com/Rudo2204/25b481af4a40a67e854f3d71c3a6b002 44. Design your own Gym | Bulbagarden, https://bulbagarden.net/threads/design-your-own-gym.282890/ 45. INFO, GUIDES, CHOICES, TROUBLESHOOTING, MODS, AND MORE : r/PokemonReborn, https://www.reddit.com/r/PokemonReborn/comments/uee0gk/info_guides_choices_troubleshooting_mods_and_more/
