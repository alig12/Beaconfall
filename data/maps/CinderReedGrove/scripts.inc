CinderReedGrove_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinderReedGrove_OnTransition
	.byte 0

CinderReedGrove_OnTransition::
	setweather WEATHER_SHADE
	doweather
	end

CinderReedGrove_EventScript_Gatekeeper::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_1_CLEARED, CinderReedGrove_EventScript_GatekeeperOpen
	msgbox CinderReedGrove_Text_GateBlocked, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_GatekeeperOpen::
	msgbox CinderReedGrove_Text_GateOpen, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_ClueNPC::
	lock
	faceplayer
	goto_if_set FLAG_CINDER_REED_GROVE_CLEARED, CinderReedGrove_EventScript_ClueNPCAfter
	msgbox CinderReedGrove_Text_ClueIntro, MSGBOX_DEFAULT
	giveitem ITEM_POTION
	goto_if_eq VAR_RESULT, FALSE, CinderReedGrove_EventScript_ClueNPCBagFull
	call BeaconfallChapter1_EventScript_MarkGroveCleared
	msgbox CinderReedGrove_Text_ClueReward, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_ClueNPCBagFull::
	call BeaconfallChapter1_EventScript_MarkGroveCleared
	msgbox CinderReedGrove_Text_ClueBagFull, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_ClueNPCAfter::
	msgbox CinderReedGrove_Text_ClueAfter, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_TrainerReed::
	trainerbattle_single TRAINER_BEACONFALL_GROVE_REED, CinderReedGrove_Text_ReedIntro, CinderReedGrove_Text_ReedDefeat, CinderReedGrove_EventScript_TrainerReedDefeated
	end

CinderReedGrove_EventScript_TrainerReedDefeated::
	msgbox CinderReedGrove_Text_ReedAfter, MSGBOX_AUTOCLOSE
	end

CinderReedGrove_EventScript_TrainerMoss::
	trainerbattle_single TRAINER_BEACONFALL_GROVE_MOSS, CinderReedGrove_Text_MossIntro, CinderReedGrove_Text_MossDefeat, CinderReedGrove_EventScript_TrainerMossDefeated
	end

CinderReedGrove_EventScript_TrainerMossDefeated::
	msgbox CinderReedGrove_Text_MossAfter, MSGBOX_AUTOCLOSE
	end

CinderReedGrove_EventScript_LampA::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_GROVE_LAMP_A, CinderReedGrove_EventScript_LampAAlreadyOn
	playse SE_M_THUNDER_WAVE
	setflag FLAG_BEACONFALL_GROVE_LAMP_A
	msgbox CinderReedGrove_Text_LampAOn, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_LampAAlreadyOn::
	msgbox CinderReedGrove_Text_LampAAlreadyOn, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_LampB::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_GROVE_LAMP_B, CinderReedGrove_EventScript_LampBAlreadyOn
	playse SE_M_THUNDER_WAVE
	setflag FLAG_BEACONFALL_GROVE_LAMP_B
	msgbox CinderReedGrove_Text_LampBOn, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_LampBAlreadyOn::
	msgbox CinderReedGrove_Text_LampBAlreadyOn, MSGBOX_DEFAULT
	release
	end

CinderReedGrove_EventScript_NorthPathTrigger::
	lockall
	goto_if_set FLAG_BEACONFALL_GROVE_LAMP_A, CinderReedGrove_EventScript_NorthPathCheckB
	goto CinderReedGrove_EventScript_NorthPathBlock

CinderReedGrove_EventScript_NorthPathCheckB::
	goto_if_set FLAG_BEACONFALL_GROVE_LAMP_B, CinderReedGrove_EventScript_NorthPathAllow
CinderReedGrove_EventScript_NorthPathBlock::
	msgbox CinderReedGrove_Text_BeaconsStillDark, MSGBOX_DEFAULT
	closemessage
	applymovement OBJ_EVENT_ID_PLAYER, CinderReedGrove_Movement_PushSouthFromNorth
	waitmovement 0
	releaseall
	end

CinderReedGrove_EventScript_NorthPathAllow::
	releaseall
	end

CinderReedGrove_Movement_PushSouthFromNorth::
	walk_down
	step_end

CinderReedGrove_EventScript_GroveSign::
	msgbox CinderReedGrove_Text_GroveSign, MSGBOX_SIGN
	end

CinderReedGrove_Text_GateBlocked::
	.string "The grove is still sealed.\p"
	.string "Clear SALTWIND PATH first.$"

CinderReedGrove_Text_GateOpen::
	.string "Good.\p"
	.string "The reeds will part for you now.$"

CinderReedGrove_Text_ClueIntro::
	.string "This grove hides a path to the city.\p"
	.string "Take this and keep moving.$"

CinderReedGrove_Text_ClueReward::
	.string "The grove has been mapped.\p"
	.string "You can press on to Brassfall City.$"

CinderReedGrove_Text_ClueBagFull::
	.string "You can still move forward.\p"
	.string "Come back when you have room for the\n"
	.string "gift.$"

CinderReedGrove_Text_ClueAfter::
	.string "The grove's secret is already known.\p"
	.string "Keep your head up and keep going.$"

CinderReedGrove_Text_ReedIntro::
	.string "The forest is my training ground!$"

CinderReedGrove_Text_ReedDefeat::
	.string "The brush hid your next move!$"

CinderReedGrove_Text_ReedAfter::
	.string "The reeds rustle when the wind shifts.\n"
	.string "Watch for it.$"

CinderReedGrove_Text_MossIntro::
	.string "SMUGGLER: Quiet. Haul the coil before the\n"
	.string "rangers trace the signal.$"

CinderReedGrove_Text_MossDefeat::
	.string "The beacon bundle's heavier than it looks...$"

CinderReedGrove_Text_MossAfter::
	.string "Those lamps copy harbor pulse frequencies.\n"
	.string "Someone upstream is fencing whole spires.$"

CinderReedGrove_Text_LampAOn::
	.string "The creek-side beacon hums -threads of moss\n"
	.string "that glow like harbor glass.$"

CinderReedGrove_Text_LampAAlreadyOn::
	.string "This lantern already rides the same beat as\n"
	.string "the failed coastal network.$"

CinderReedGrove_Text_LampBOn::
	.string "The hollow lantern answers the first one.\n"
	.string "The reed-line finally reads as a path.$"

CinderReedGrove_Text_LampBAlreadyOn::
	.string "Twin beacons stay tuned. Listen. They tick in\n"
	.string "sync when the wind drops.$"

CinderReedGrove_Text_BeaconsStillDark::
	.string "The northern reed-wall is black without both\n"
	.string "beacon lamps burning.$"

CinderReedGrove_Text_GroveSign::
	.string "CINDER REED GROVE\p"
	.string "Harbor lamps once lined this route. Now\n"
	.string "smugglers borrow the light.$"
