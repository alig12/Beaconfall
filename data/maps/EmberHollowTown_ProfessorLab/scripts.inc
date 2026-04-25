EmberHollowTown_ProfessorLab_MapScripts::
	.byte 0

EmberHollowTown_ProfessorLab_EventScript_Professor::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_1_CLEARED, EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterRoute
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterStarter
	msgbox EmberHollowTown_ProfessorLab_Text_Intro, MSGBOX_DEFAULT
	special ChooseBeaconfallStarter
	waitstate
	call BeaconfallChapter1_EventScript_StartJourney
	msgbox EmberHollowTown_ProfessorLab_Text_StarterDone, MSGBOX_DEFAULT
	call BeaconfallChapter1_EventScript_GiveFirstPokeBalls
	msgbox EmberHollowTown_ProfessorLab_Text_SeeMira, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterStarter::
	call BeaconfallChapter1_EventScript_GiveFirstPokeBalls
	msgbox EmberHollowTown_ProfessorLab_Text_AfterStarter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_ProfessorAfterRoute::
	msgbox EmberHollowTown_ProfessorLab_Text_AfterRoute, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_Mira::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_1_CLEARED, EmberHollowTown_ProfessorLab_EventScript_MiraAfterRoute
	goto_if_unset FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter
	special HealPlayerParty
	turnobject LOCALID_MIRA, DIR_SOUTH
	msgbox EmberHollowTown_ProfessorLab_Text_MiraRouteChallenge, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_MiraBeforeStarter::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_EventScript_MiraAfterRoute::
	msgbox EmberHollowTown_ProfessorLab_Text_MiraLater, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_ProfessorLab_Text_Intro::
	.string "PROF. HOLLOW: The beacons failed.\p"
	.string "Saltwind Path is dark.\p"
	.string "Wild Pokémon are restless.\p"
	.string "Briarune, Pyrevex, and Karatide are ready.\p"
	.string "Pick a partner. We move now.$"

EmberHollowTown_ProfessorLab_Text_StarterDone::
	.string "PROF. HOLLOW: Good. It's yours now.\p"
	.string "Take these Poké Balls too.\p"
	.string "If the route stirs, catch what you can.$"

EmberHollowTown_ProfessorLab_Text_SeeMira::
	.string "MIRA is heading to Saltwind Path.\p"
	.string "She'll test you once you leave town.\p"
	.string "Talk to her if you want a warning,\n"
	.string "then head through the north gate.$"

EmberHollowTown_ProfessorLab_Text_AfterStarter::
	.string "PROF. HOLLOW: North gate is open\n"
	.string "now that you have a partner.\p"
	.string "If I missed your catching kit,\n"
	.string "take it now.\p"
	.string "Expect MIRA on Saltwind Path.$"

EmberHollowTown_ProfessorLab_Text_AfterRoute::
	.string "PROF. HOLLOW: You made it through\n"
	.string "MIRA's first route test.\p"
	.string "Keep moving toward the grove.$"

EmberHollowTown_ProfessorLab_Text_MiraBeforeStarter::
	.string "MIRA: No partner, no test.\p"
	.string "Talk to Prof. Hollow first.$"

EmberHollowTown_ProfessorLab_Text_MiraRouteChallenge::
	.string "MIRA: Good. You picked one.\p"
	.string "I'll test you on Saltwind Path.\p"
	.string "Don't make me wait.$"

EmberHollowTown_ProfessorLab_Text_MiraLater::
	.string "MIRA: Not bad on the route.\p"
	.string "Now prove it wasn't luck.$"
