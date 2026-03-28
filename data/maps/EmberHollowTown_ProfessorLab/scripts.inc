EmberHollowTown_ProfessorLab_MapScripts::
	.byte 0

EmberHollowTown_ProfessorLab_EventScript_Professor::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_ProfessorLab_EventScript_ProfessorAllDone
	goto_if_set FLAG_SYS_POKEMON_GET, EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterStarterNeedMira
	msgbox EmberHollowTown_ProfessorLab_Text_Intro, MSGBOX_DEFAULT
	special ChooseBeaconfallStarter
	waitstate
	call BeaconfallChapter1_EventScript_StartJourney
	msgbox EmberHollowTown_ProfessorLab_Text_StarterDone, MSGBOX_DEFAULT
	msgbox EmberHollowTown_ProfessorLab_Text_SeeMira, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterStarterNeedMira::
	msgbox EmberHollowTown_ProfessorLab_Text_TalkToMira, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_ProfessorAllDone::
	msgbox EmberHollowTown_ProfessorLab_Text_AfterTutorial, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_Mira::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_ProfessorLab_EventScript_MiraAfter
	goto_if_unset FLAG_SYS_POKEMON_GET, EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter
	special HealPlayerParty
	switch VAR_STARTER_MON
	case 0, EmberHollowTown_ProfessorLab_EventScript_MiraBattleBudew
	case 1, EmberHollowTown_ProfessorLab_EventScript_MiraBattleGrowlithe
	case 2, EmberHollowTown_ProfessorLab_EventScript_MiraBattleWooper
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBattleBudew::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_CHIMCHAR, EmberHollowTown_ProfessorLab_Text_MiraIntro, EmberHollowTown_ProfessorLab_Text_MiraDefeat, EmberHollowTown_ProfessorLab_EventScript_MiraDefeated
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBattleGrowlithe::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_PIPLUP, EmberHollowTown_ProfessorLab_Text_MiraIntro, EmberHollowTown_ProfessorLab_Text_MiraDefeat, EmberHollowTown_ProfessorLab_EventScript_MiraDefeated
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBattleWooper::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_TURTWIG, EmberHollowTown_ProfessorLab_Text_MiraIntro, EmberHollowTown_ProfessorLab_Text_MiraDefeat, EmberHollowTown_ProfessorLab_EventScript_MiraDefeated
	end

EmberHollowTown_ProfessorLab_EventScript_MiraDefeated::
	setflag FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN
	setvar VAR_RIVAL_BATTLES, 1
	msgbox EmberHollowTown_ProfessorLab_Text_MiraAfter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_MiraAfter::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraLater, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_Text_Intro::
	.string "PROF. BIRCH: The beacons just failed. All of\n"
	.string "them along the coast.\p"
	.string "This blackout isn't just spooky. Wild\n"
	.string "Pokémon are panicking in the dark.\p"
	.string "Take a partner. Saltwind Path won't wait.$"

EmberHollowTown_ProfessorLab_Text_StarterDone::
	.string "PROF. BIRCH: Good. That light on your belt\n"
	.string "means you're official.\p"
	.string "MIRA has been pacing. She'll want a word.$"

EmberHollowTown_ProfessorLab_Text_SeeMira::
	.string "Talk to MIRA by the desk when you're ready.$"

EmberHollowTown_ProfessorLab_Text_TalkToMira::
	.string "PROF. BIRCH: MIRA's still fired up. Go hear\n"
	.string "her out.$"

EmberHollowTown_ProfessorLab_Text_AfterTutorial::
	.string "PROF. BIRCH: Saltwind Path clears up past\n"
	.string "the gate once you're outside town.\p"
	.string "Move fast, but not reckless.$"

EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter::
	.string "MIRA: Birch is handling starters first.\n"
	.string "No debates until you've got one.$"

EmberHollowTown_ProfessorLab_Text_MiraIntro::
	.string "MIRA: Finally, one quick bout. Stay on your\n"
	.string "toes.$"

EmberHollowTown_ProfessorLab_Text_MiraDefeat::
	.string "MIRA: Heh. Not bad for fresh out of the lab.$"

EmberHollowTown_ProfessorLab_Text_MiraAfter::
	.string "MIRA: Gates stay closed in a blackout unless\n"
	.string "you've got a Pokémon. You're clear.\p"
	.string "I'll catch up on Saltwind Path.$"

EmberHollowTown_ProfessorLab_Text_MiraLater::
	.string "MIRA: Don't linger. Every minute without the\n"
	.string "beacons is ugly out there.$"
