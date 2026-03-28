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
	msgbox EmberHollowTown_ProfessorLab_Text_MiraIntroUrgent, MSGBOX_DEFAULT
	playse SE_PSYCH_UP
	applymovement LOCALID_MIRA, EmberHollowTown_Movement_MiraStepCloser
	waitmovement 0
	delay 15
	playse SE_THUNDERBOLT
	doshake 3, 2
	delay 10
	msgbox EmberHollowTown_ProfessorLab_Text_MiraIntroAlarm, MSGBOX_DEFAULT
	delay 10
	switch VAR_STARTER_MON
	case 0, EmberHollowTown_ProfessorLab_EventScript_MiraBattleBudew
	case 1, EmberHollowTown_ProfessorLab_EventScript_MiraBattleGrowlithe
	case 2, EmberHollowTown_ProfessorLab_EventScript_MiraBattleWooper
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_Movement_MiraStepCloser::
	walk_right
	walk_right
	step_end

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
	.string "PROF. BIRCH: The beacons just failed. All\n"
	.string "of them along the coast.\p"
	.string "That network held back the worst of the\n"
	.string "wild Pokémon. Without it, the dark roads\l"
	.string "aren't safe for untested trainers.\p"
	.string "You need a partner. Now.$"

EmberHollowTown_ProfessorLab_Text_StarterDone::
	.string "PROF. BIRCH: Good. That Pokédex light\n"
	.string "means you're official.\p"
	.string "MIRA's been pacing. She'll want proof\n"
	.string "you can handle yourself.$"

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

EmberHollowTown_ProfessorLab_Text_MiraIntroUrgent::
	.string "MIRA: Alright, listen up!\p"
	.string "We don't have time to waste with this\n"
	.string "blackout getting worse every minute.$"

EmberHollowTown_ProfessorLab_Text_MiraIntroAlarm::
	.string "MIRA: One quick test to see if you can\n"
	.string "handle a real battle.\l"
	.string "Stay sharp!$"

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
