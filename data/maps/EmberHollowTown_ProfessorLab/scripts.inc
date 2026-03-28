EmberHollowTown_ProfessorLab_MapScripts::
	.byte 0

EmberHollowTown_ProfessorLab_EventScript_Professor::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_ProfessorLab_EventScript_ProfessorAllDone
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterStarterNeedMira
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
	goto_if_unset FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter
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
	case 0, EmberHollowTown_ProfessorLab_EventScript_MiraBattleTurtwig
	case 1, EmberHollowTown_ProfessorLab_EventScript_MiraBattleChimchar
	case 2, EmberHollowTown_ProfessorLab_EventScript_MiraBattlePiplup
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_Movement_MiraStepCloser::
	walk_right
	walk_right
	step_end

EmberHollowTown_ProfessorLab_EventScript_MiraBattleTurtwig::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_CHIMCHAR, EmberHollowTown_ProfessorLab_Text_MiraIntro, EmberHollowTown_ProfessorLab_Text_MiraDefeat, EmberHollowTown_ProfessorLab_EventScript_MiraDefeated
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBattleChimchar::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_PIPLUP, EmberHollowTown_ProfessorLab_Text_MiraIntro, EmberHollowTown_ProfessorLab_Text_MiraDefeat, EmberHollowTown_ProfessorLab_EventScript_MiraDefeated
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBattlePiplup::
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
	.string "PROF. BIRCH: The beacons just failed.\p"
	.string "Saltwind Path is dark, and the wild\n"
	.string "Pokémon are restless.\l"
	.string "Pick a partner. We move now.$"

EmberHollowTown_ProfessorLab_Text_StarterDone::
	.string "PROF. BIRCH: Good. That partner is yours.\p"
	.string "MIRA's waiting by the desk. She wants to\n"
	.string "see you fight.$"

EmberHollowTown_ProfessorLab_Text_SeeMira::
	.string "Talk to MIRA by the desk when you're ready.$"

EmberHollowTown_ProfessorLab_Text_TalkToMira::
	.string "PROF. BIRCH: MIRA doesn't waste time.\n"
	.string "Go hear her out.$"

EmberHollowTown_ProfessorLab_Text_AfterTutorial::
	.string "PROF. BIRCH: Saltwind Path opens once you\n"
	.string "step outside town.\p"
	.string "Move fast, but don't get careless.$"

EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter::
	.string "MIRA: No partner, no battle.\p"
	.string "Go see Birch first.$"

EmberHollowTown_ProfessorLab_Text_MiraIntroUrgent::
	.string "MIRA: Enough waiting.\p"
	.string "The blackout is spreading fast.$"

EmberHollowTown_ProfessorLab_Text_MiraIntroAlarm::
	.string "MIRA: One quick battle.\p"
	.string "Show me you can handle pressure.$"

EmberHollowTown_ProfessorLab_Text_MiraIntro::
	.string "MIRA: Finally. Let's see what you've got.$"

EmberHollowTown_ProfessorLab_Text_MiraDefeat::
	.string "MIRA: Heh. Not bad for fresh out of the lab.$"

EmberHollowTown_ProfessorLab_Text_MiraAfter::
	.string "MIRA: Gates stay closed in a blackout unless\n"
	.string "you've got a Pokémon. You're clear.\p"
	.string "I'll catch up on Saltwind Path.$"

EmberHollowTown_ProfessorLab_Text_MiraLater::
	.string "MIRA: Don't linger. Every minute without the\n"
	.string "beacons is ugly out there.$"
