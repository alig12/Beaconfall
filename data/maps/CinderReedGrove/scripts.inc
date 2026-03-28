CinderReedGrove_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, CinderReedGrove_OnTransition
	.byte 0

CinderReedGrove_OnTransition::
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
	.string "I came here to see the grove glow.$"

CinderReedGrove_Text_MossDefeat::
	.string "I saw that battle coming too late!$"

CinderReedGrove_Text_MossAfter::
	.string "The lights in the trees are a clue.\n"
	.string "Don't ignore them.$"

CinderReedGrove_Text_GroveSign::
	.string "CINDER REED GROVE\p"
	.string "Quiet paths, bright leaves.$"
