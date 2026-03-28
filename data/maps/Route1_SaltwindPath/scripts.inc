Route1_SaltwindPath_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, Route1_SaltwindPath_OnTransition
	.byte 0

Route1_SaltwindPath_OnTransition::
	end

Route1_SaltwindPath_EventScript_RivalBattle::
	lockall
	switch VAR_STARTER_MON
	case 0, Route1_SaltwindPath_EventScript_RivalBattleChimchar
	case 1, Route1_SaltwindPath_EventScript_RivalBattlePiplup
	case 2, Route1_SaltwindPath_EventScript_RivalBattleTurtwig
	end

Route1_SaltwindPath_EventScript_RivalBattleChimchar::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_CHIMCHAR, Route1_SaltwindPath_Text_RivalIntro, Route1_SaltwindPath_Text_RivalDefeat
	goto Route1_SaltwindPath_EventScript_RivalBattleDefeated
	end

Route1_SaltwindPath_EventScript_RivalBattlePiplup::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_PIPLUP, Route1_SaltwindPath_Text_RivalIntro, Route1_SaltwindPath_Text_RivalDefeat
	goto Route1_SaltwindPath_EventScript_RivalBattleDefeated
	end

Route1_SaltwindPath_EventScript_RivalBattleTurtwig::
	trainerbattle_single TRAINER_BEACONFALL_RIVAL1_TURTWIG, Route1_SaltwindPath_Text_RivalIntro, Route1_SaltwindPath_Text_RivalDefeat
	goto Route1_SaltwindPath_EventScript_RivalBattleDefeated
	end

Route1_SaltwindPath_EventScript_RivalBattleDefeated::
	call BeaconfallChapter1_EventScript_MarkRoute1Cleared
	msgbox Route1_SaltwindPath_Text_RivalAfter, MSGBOX_AUTOCLOSE
	releaseall
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

Route1_SaltwindPath_EventScript_TrainerCoach::
	trainerbattle_single TRAINER_BEACONFALL_ROUTE_COACH, Route1_SaltwindPath_Text_CoachIntro, Route1_SaltwindPath_Text_CoachDefeat, Route1_SaltwindPath_EventScript_TrainerCoachDefeated
	end

Route1_SaltwindPath_EventScript_TrainerCoachDefeated::
	msgbox Route1_SaltwindPath_Text_CoachAfter, MSGBOX_AUTOCLOSE
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
	.string "Status swings longer fights than raw power.\n"
	.string "Can you keep up when the tempo slips?$"

Route1_SaltwindPath_Text_ScoutDefeat::
	.string "Okay. You didn't panic when it got messy.$"

Route1_SaltwindPath_Text_ScoutAfter::
	.string "Poison, paralysis, sleep. They all buy time.\n"
	.string "Don't ignore your own conditions either.$"

Route1_SaltwindPath_Text_SailorIntro::
	.string "Types are the harbor rules. Break them and\n"
	.string "you get dunked.$"

Route1_SaltwindPath_Text_SailorDefeat::
	.string "You lined up the matchup. Respect.$"

Route1_SaltwindPath_Text_SailorAfter::
	.string "Water and Grass overlap on Ground and Rock.\n"
	.string "Figure out the double-ups early.$"

Route1_SaltwindPath_Text_CoachIntro::
	.string "STAB, movement, clean switches. That's the\n"
	.string "whole drill. One more quick scrimmage.$"

Route1_SaltwindPath_Text_CoachDefeat::
	.string "Textbook wraps. You're ready for the grove.$"

Route1_SaltwindPath_Text_CoachAfter::
	.string "Short route, but it teaches a full toolkit.\n"
	.string "Keep those basics under your belt.$"

Route1_SaltwindPath_Text_RouteSign::
	.string "SALTWIND PATH\p"
	.string "Ember Hollow Town - Cinder Reed Grove$"
