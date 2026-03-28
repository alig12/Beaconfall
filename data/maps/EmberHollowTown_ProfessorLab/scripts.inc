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
	@ Mira starts beside the Professor; face the player for the challenge (no walk-in snap)
	turnobject LOCALID_MIRA, DIR_SOUTH
	msgbox EmberHollowTown_ProfessorLab_Text_MiraIntroUrgent, MSGBOX_DEFAULT
	playse SE_M_CHARGE
	delay 10
	playse SE_M_THUNDERBOLT
	setvar VAR_0x8004, 1
	setvar VAR_0x8005, 1
	setvar VAR_0x8006, 3
	setvar VAR_0x8007, 2
	special ShakeScreen
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
	setvar VAR_BEACONFALL_EMBER_TWIN_CUTSCENE, 0
	msgbox EmberHollowTown_ProfessorLab_Text_MiraAfter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_MiraAfter::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraLater, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_Text_Intro::
	.string "BIRCH: The beacons failed.\p"
	.string "Saltwind Path is dark.\p"
	.string "Wild Pokémon are restless.\p"
	.string "Pick a partner. We move now.$"

EmberHollowTown_ProfessorLab_Text_StarterDone::
	.string "BIRCH: Good. It's yours now.\p"
	.string "MIRA's right here with me.\p"
	.string "Talk to her when you're ready.$"

EmberHollowTown_ProfessorLab_Text_SeeMira::
	.string "MIRA's waiting with me.\p"
	.string "She'll test you when you're ready.$"

EmberHollowTown_ProfessorLab_Text_TalkToMira::
	.string "BIRCH: MIRA doesn't waste time.\p"
	.string "Go hear her out.$"

EmberHollowTown_ProfessorLab_Text_AfterTutorial::
	.string "BIRCH: Path opens outside town.\p"
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
	.string "MIRA: Let's see what you've got.$"

EmberHollowTown_ProfessorLab_Text_MiraDefeat::
	.string "MIRA: Not bad.\p"
	.string "Fresh out of the lab, too.$"

EmberHollowTown_ProfessorLab_Text_MiraAfter::
	.string "MIRA: Gates stay closed.\p"
	.string "You'll need a Pokémon first.\p"
	.string "You're clear.\p"
	.string "I'll catch up on Saltwind Path.$"

EmberHollowTown_ProfessorLab_Text_MiraLater::
	.string "MIRA: Don't linger.\p"
	.string "Every minute without the beacons\n"
	.string "is ugly out there.$"
