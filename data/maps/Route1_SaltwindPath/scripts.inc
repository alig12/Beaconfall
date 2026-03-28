Route1_SaltwindPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_SaltwindPath_OnTransition
	.byte 0

Route1_SaltwindPath_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE101
	end

Route1_SaltwindPath_EventScript_RivalBattle::
	lockall
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1, Route1_SaltwindPath_Text_RivalIntro, Route1_SaltwindPath_Text_RivalDefeat, Route1_SaltwindPath_EventScript_RivalBattleDefeated
	releaseall
	end

Route1_SaltwindPath_EventScript_RivalBattleDefeated::
	call BeaconfallChapter1_EventScript_MarkRoute1Cleared
	msgbox Route1_SaltwindPath_Text_RivalAfter, MSGBOX_AUTOCLOSE
	end

Route1_SaltwindPath_EventScript_Gatekeeper::
	lock
	faceplayer
	goto_if_set FLAG_ROUTE_1_CLEARED, Route1_SaltwindPath_EventScript_GatekeeperOpen
	msgbox Route1_SaltwindPath_Text_GateBlocked, MSGBOX_DEFAULT
	release
	end

Route1_SaltwindPath_EventScript_GatekeeperOpen::
	msgbox Route1_SaltwindPath_Text_GateOpen, MSGBOX_DEFAULT
	release
	end

Route1_SaltwindPath_EventScript_TrainerScout::
	trainerbattle_single TRAINER_BEACONFALL_ROUTE_SCOUT, Route1_SaltwindPath_Text_ScoutIntro, Route1_SaltwindPath_Text_ScoutDefeat, Route1_SaltwindPath_EventScript_TrainerScoutDefeated
	end

Route1_SaltwindPath_EventScript_TrainerScoutDefeated::
	msgbox Route1_SaltwindPath_Text_ScoutAfter, MSGBOX_AUTOCLOSE
	end

Route1_SaltwindPath_EventScript_TrainerSailor::
	trainerbattle_single TRAINER_BEACONFALL_ROUTE_SAILOR, Route1_SaltwindPath_Text_SailorIntro, Route1_SaltwindPath_Text_SailorDefeat, Route1_SaltwindPath_EventScript_TrainerSailorDefeated
	end

Route1_SaltwindPath_EventScript_TrainerSailorDefeated::
	msgbox Route1_SaltwindPath_Text_SailorAfter, MSGBOX_AUTOCLOSE
	end

Route1_SaltwindPath_EventScript_RouteSign::
	msgbox Route1_SaltwindPath_Text_RouteSign, MSGBOX_SIGN
	end

Route1_SaltwindPath_Text_RivalIntro::
	.string "You made it this far already?\p"
	.string "Let's see if your starter can keep up!$"

Route1_SaltwindPath_Text_RivalDefeat::
	.string "Hah.\n"
	.string "I knew this would be a fight.$"

Route1_SaltwindPath_Text_RivalAfter::
	.string "That was the first test.\p"
	.string "Keep going until the path opens up.$"

Route1_SaltwindPath_Text_GateBlocked::
	.string "The grove is still closed off.\p"
	.string "Win the route battle first, then head\n"
	.string "north.$"

Route1_SaltwindPath_Text_GateOpen::
	.string "Good.\p"
	.string "CINDER REED GROVE is open now.$"

Route1_SaltwindPath_Text_ScoutIntro::
	.string "I'm scouting the path ahead.\n"
	.string "Let's battle!$"

Route1_SaltwindPath_Text_ScoutDefeat::
	.string "I need better footing...$"

Route1_SaltwindPath_Text_ScoutAfter::
	.string "Keep your eyes on the path.\n"
	.string "Waves can hide trouble.$"

Route1_SaltwindPath_Text_SailorIntro::
	.string "The breeze is perfect for a battle!$"

Route1_SaltwindPath_Text_SailorDefeat::
	.string "Whoa, that current carried me away!$"

Route1_SaltwindPath_Text_SailorAfter::
	.string "Saltwind Path is short, but it can\n"
	.string "still catch you off guard.$"

Route1_SaltwindPath_Text_RouteSign::
	.string "SALTWIND PATH\p"
	.string "Ember Hollow Town - Cinder Reed Grove$"
