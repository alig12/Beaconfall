EmberHollowTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EmberHollowTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EmberHollowTown_OnFrame
	.byte 0

@ Weather only here. Blackout text runs from ON_FRAME so msgbox does not run inside
@ RunScriptImmediately (transition scripts), which cannot yield safely and can crash on the next warp.
EmberHollowTown_OnTransition::
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_OnTransition_Bright
	setweather WEATHER_SHADE
	doweather
	end

EmberHollowTown_OnTransition_Bright::
	setweather WEATHER_SUNNY
	doweather
	playbgm MUS_LITTLEROOT, 0
	end

EmberHollowTown_OnFrame::
	map_script_2 VAR_BEACONFALL_BLACKOUT_MSG, 0, EmberHollowTown_EventScript_BlackoutIntroOnce
	.2byte 0

EmberHollowTown_EventScript_BlackoutIntroOnce::
	lockall
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_EventScript_BlackoutIntroDone
	msgbox EmberHollowTown_Text_BlackoutIntro, MSGBOX_DEFAULT
EmberHollowTown_EventScript_BlackoutIntroDone::
	setvar VAR_BEACONFALL_BLACKOUT_MSG, 1
	releaseall
	end

EmberHollowTown_EventScript_NorthGateTrigger::
	lockall
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_EventScript_NorthGateCheckTutorial
	goto EmberHollowTown_EventScript_ForceBackNeedLab

EmberHollowTown_EventScript_NorthGateCheckTutorial::
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_EventScript_NorthGateRelease
EmberHollowTown_EventScript_ForceBackNeedMira::
	msgbox EmberHollowTown_Text_NeedMiraBattle, MSGBOX_DEFAULT
	goto EmberHollowTown_EventScript_ForceBackCommon

EmberHollowTown_EventScript_ForceBackNeedLab::
	msgbox EmberHollowTown_Text_NeedPokemon, MSGBOX_DEFAULT
EmberHollowTown_EventScript_ForceBackCommon::
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_EmberHollowTown_GatePushBack
	waitmovement 0
	releaseall
	end

EmberHollowTown_EventScript_NorthGateRelease::
	releaseall
	end

Movement_EmberHollowTown_GatePushBack::
	walk_down
	step_end

EmberHollowTown_EventScript_ExitGuard::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_EventScript_ExitGuardCheckTutorial
	msgbox EmberHollowTown_Text_GuardNeedMon, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_ExitGuardCheckTutorial::
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_EventScript_ExitGuardOK
	msgbox EmberHollowTown_Text_GuardNeedMira, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_ExitGuardOK::
	msgbox EmberHollowTown_Text_GuardAllClear, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_TownSign::
	msgbox EmberHollowTown_Text_TownSign, MSGBOX_SIGN
	end

EmberHollowTown_Text_BlackoutIntro::
	.string "The harbor lamps just died.\p"
	.string "Somewhere out on the coast, the beacon\n"
	.string "network failed, and the whole town went dim.$"

EmberHollowTown_Text_NeedPokemon::
	.string "GUARD: The route's dark. No way I'm\n"
	.string "letting you cross without a partner.\p"
	.string "PROF. BIRCH is at the lab. Get one first.$"

EmberHollowTown_Text_NeedMiraBattle::
	.string "GUARD: You've got a partner now.\p"
	.string "But MIRA doesn't let rookies waltz past\n"
	.string "the gates. She's testing everyone.\l"
	.string "Handle her first, then we talk.$"

EmberHollowTown_Text_GuardNeedMon::
	.string "GUARD: Lab first. Birch doesn't hand out\n"
	.string "partners for fun. Get one and come back.$"

EmberHollowTown_Text_GuardNeedMira::
	.string "GUARD: Talk to MIRA. She won't let rookies\n"
	.string "wander until she's tested them.$"

EmberHollowTown_Text_GuardAllClear::
	.string "GUARD: Lights are still out, but you've got\n"
	.string "what it takes.\p"
	.string "Saltwind Path's a mess in the dark.\n"
	.string "Watch for wild Pokémon.$"

EmberHollowTown_Text_TownSign::
	.string "EMBER HOLLOW\p"
	.string "Harbor spark of Beaconfall.\p"
	.string "[BEACON NETWORK STATUS: OFFLINE]$"
