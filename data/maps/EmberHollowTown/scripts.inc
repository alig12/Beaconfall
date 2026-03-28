EmberHollowTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EmberHollowTown_OnTransition
	.byte 0

EmberHollowTown_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_LITTLEROOT_TOWN
	end

EmberHollowTown_EventScript_Professor::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_EventScript_ProfessorAfterStarter
	msgbox EmberHollowTown_Text_Intro, MSGBOX_DEFAULT
	special ChooseBeaconfallStarter
	waitstate
	call BeaconfallChapter1_EventScript_StartJourney
	msgbox EmberHollowTown_Text_StarterGiven, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_ProfessorAfterStarter::
	msgbox EmberHollowTown_Text_PostStarter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_ExitGuard::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_EventScript_ExitGuardOpen
	msgbox EmberHollowTown_Text_ExitBlocked, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_ExitGuardOpen::
	msgbox EmberHollowTown_Text_ExitOpen, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_TownSign::
	msgbox EmberHollowTown_Text_TownSign, MSGBOX_SIGN
	end

EmberHollowTown_Text_Intro::
	.string "Welcome to EMBER HOLLOW.\p"
	.string "Pick the partner who will start your\n"
	.string "chapter, then meet me by the path.$"

EmberHollowTown_Text_StarterGiven::
	.string "There we go. Take care of your new\n"
	.string "partner and keep moving forward.$"

EmberHollowTown_Text_PostStarter::
	.string "Your journey starts on SALTWIND PATH.\p"
	.string "Train hard, and come back if you need\n"
	.string "anything explained.$"

EmberHollowTown_Text_ExitBlocked::
	.string "Hold up.\p"
	.string "You need to choose a starter before\n"
	.string "leaving town.$"

EmberHollowTown_Text_ExitOpen::
	.string "The road ahead is yours now.\p"
	.string "Saltwind Path leads east to the rest\n"
	.string "of the chapter.$"

EmberHollowTown_Text_TownSign::
	.string "EMBER HOLLOW\p"
	.string "The first spark of Beaconfall.$"
