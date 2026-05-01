EmberHollowTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EmberHollowTown_OnTransition
	map_script MAP_SCRIPT_ON_FRAME_TABLE, EmberHollowTown_OnFrame
	.byte 0

@ Weather only here. Blackout text runs from ON_FRAME so msgbox does not run inside
@ RunScriptImmediately (transition scripts), which cannot yield safely and can crash on the next warp.
EmberHollowTown_OnTransition::
	call BeaconfallChapter1_EventScript_RepairProgression
	@ Save repair: older PR builds used a lab tutorial-rival flag to open this gate.
	@ If Route 1 is already cleared, the shared repair helper owns the state and must not be downgraded.
	goto_if_set FLAG_ROUTE_1_CLEARED, EmberHollowTown_OnTransition_Weather
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_OnTransition_RepairOldTutorialGate
	goto EmberHollowTown_OnTransition_Weather

EmberHollowTown_OnTransition_RepairOldTutorialGate::
	setflag FLAG_EMBER_NORTH_GATE_TWIN_MOVED
	clearflag FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN
	setvar VAR_RIVAL_BATTLES, 0
	goto EmberHollowTown_OnTransition_Weather

EmberHollowTown_OnTransition_Weather::
	goto_if_set FLAG_EMBER_NORTH_GATE_TWIN_MOVED, EmberHollowTown_OnTransition_Bright
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
	goto_if_set FLAG_EMBER_NORTH_GATE_TWIN_MOVED, EmberHollowTown_EventScript_BlackoutIntroDone
	msgbox EmberHollowTown_Text_BlackoutIntro, MSGBOX_DEFAULT
EmberHollowTown_EventScript_BlackoutIntroDone::
	setvar VAR_BEACONFALL_BLACKOUT_MSG, 1
	releaseall
	end

EmberHollowTown_EventScript_NorthGateTrigger::
	lockall
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_EventScript_NorthGateCheckOpen
	goto EmberHollowTown_EventScript_ForceBackNeedLab

EmberHollowTown_EventScript_NorthGateCheckOpen::
	goto_if_set FLAG_EMBER_NORTH_GATE_TWIN_MOVED, EmberHollowTown_EventScript_NorthGateRelease
	call EmberHollowTown_EventScript_OpenNorthGateCommon
EmberHollowTown_EventScript_NorthGateRelease::
	releaseall
	end

EmberHollowTown_EventScript_ForceBackNeedLab::
	msgbox EmberHollowTown_Text_NeedPokemon, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, Movement_EmberHollowTown_GatePushBack
	waitmovement 0
	releaseall
	end

Movement_EmberHollowTown_GatePushBack::
	walk_down
	step_end

EmberHollowTown_EventScript_ExitGuard::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_EventScript_ExitGuardCheckOpen
	msgbox EmberHollowTown_Text_GuardNeedMon, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_ExitGuardCheckOpen::
	goto_if_set FLAG_EMBER_NORTH_GATE_TWIN_MOVED, EmberHollowTown_EventScript_ExitGuardOK
	call EmberHollowTown_EventScript_OpenNorthGateCommon
	release
	end

EmberHollowTown_EventScript_ExitGuardOK::
	msgbox EmberHollowTown_Text_GuardAllClear, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_EventScript_OpenNorthGateCommon::
	msgbox EmberHollowTown_Text_GuardOpenPath, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_EMBER_GATE_A, Movement_EmberHollowTown_GateAOpen
	applymovement LOCALID_EMBER_GATE_B, Movement_EmberHollowTown_GateBOpen
	waitmovement 0
	setflag FLAG_EMBER_NORTH_GATE_TWIN_MOVED
	msgbox EmberHollowTown_Text_GuardRouteWarning, MSGBOX_DEFAULT
	return

Movement_EmberHollowTown_GateAOpen::
	walk_left
	step_end

Movement_EmberHollowTown_GateBOpen::
	walk_right
	step_end

EmberHollowTown_EventScript_TownSign::
	msgbox EmberHollowTown_Text_TownSign, MSGBOX_SIGN
	end

EmberHollowTown_Text_BlackoutIntro::
	.string "The harbor lamps just died.\p"
	.string "Somewhere out on the coast.\p"
	.string "The beacon network failed.\p"
	.string "The whole town went dim.$"

EmberHollowTown_Text_NeedPokemon::
	.string "GUARD: The route's dark.\p"
	.string "No way I'm letting you cross\n"
	.string "without a partner.\p"
	.string "PROF. HOLLOW is at the lab.\p"
	.string "Go get one first.$"

EmberHollowTown_Text_GuardNeedMon::
	.string "GUARD: Lab first.\p"
	.string "Prof. Hollow has the partners.\p"
	.string "Get one and come back.$"

EmberHollowTown_Text_GuardOpenPath::
	.string "GUARD: That's a real partner.\p"
	.string "Good. We can let you through now.\p"
	.string "Move aside.$"

EmberHollowTown_Text_GuardRouteWarning::
	.string "GUARD: Saltwind Path is still dark.\p"
	.string "MIRA went ahead.\p"
	.string "She'll test you on the route.$"

EmberHollowTown_Text_GuardAllClear::
	.string "GUARD: Saltwind Path is open.\p"
	.string "Stay sharp. MIRA doesn't wait\n"
	.string "for anyone.$"

EmberHollowTown_Text_TownSign::
	.string "EMBER HOLLOW\p"
	.string "Harbor spark of Beaconfall.\p"
	.string "BEACON NETWORK STATUS: OFFLINE$"
