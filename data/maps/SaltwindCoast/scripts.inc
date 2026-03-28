SaltwindCoast_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, SaltwindCoast_OnTransition
	.byte 0

SaltwindCoast_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_ROUTE101
	end

SaltwindCoast_EventScript_LaneGuide::
	lock
	faceplayer
	goto_if_set FLAG_SALTWIND_COAST_CLEARED, SaltwindCoast_EventScript_LaneGuideAfter
	msgbox SaltwindCoast_Text_LaneIntro, MSGBOX_DEFAULT
	release
	end

SaltwindCoast_EventScript_LaneGuideAfter::
	msgbox SaltwindCoast_Text_LaneAfter, MSGBOX_DEFAULT
	release
	end

SaltwindCoast_EventScript_TrainerScout::
	trainerbattle_single TRAINER_BEACONFALL_COAST_SCOUT, SaltwindCoast_Text_ScoutIntro, SaltwindCoast_Text_ScoutDefeat, SaltwindCoast_EventScript_TrainerScoutDefeated
	end

SaltwindCoast_EventScript_TrainerScoutDefeated::
	msgbox SaltwindCoast_Text_ScoutAfter, MSGBOX_AUTOCLOSE
	end

SaltwindCoast_EventScript_TrainerBreaker::
	trainerbattle_single TRAINER_BEACONFALL_COAST_BREAKER, SaltwindCoast_Text_BreakerIntro, SaltwindCoast_Text_BreakerDefeat, SaltwindCoast_EventScript_TrainerBreakerDefeated
	end

SaltwindCoast_EventScript_TrainerBreakerDefeated::
	call BeaconfallChapter2_EventScript_MarkSaltwindCleared
	msgbox SaltwindCoast_Text_BreakerAfter, MSGBOX_AUTOCLOSE
	end

SaltwindCoast_EventScript_CoastSign::
	msgbox SaltwindCoast_Text_CoastSign, MSGBOX_SIGN
	end

SaltwindCoast_Text_LaneIntro::
	.string "The coast splits in two here.\p"
	.string "Take the safe lane if you want steady\n"
	.string "fights, or the breaker lane for a\n"
	.string "harder test.$"

SaltwindCoast_Text_LaneAfter::
	.string "You already pushed through Saltwind.\p"
	.string "Floodgate Tunnels are ahead now.$"

SaltwindCoast_Text_ScoutIntro::
	.string "The shoreline is my training ground!$"

SaltwindCoast_Text_ScoutDefeat::
	.string "A clean wave always wins the race!$"

SaltwindCoast_Text_ScoutAfter::
	.string "The safe lane stays steady if you keep\n"
	.string "your footing.$"

SaltwindCoast_Text_BreakerIntro::
	.string "Breaker Lane is rougher, but it hits\n"
	.string "harder too!$"

SaltwindCoast_Text_BreakerDefeat::
	.string "You read the tide before I did!$"

SaltwindCoast_Text_BreakerAfter::
	.string "The breaker lane is clear now.\p"
	.string "Keep that momentum going.$"

SaltwindCoast_Text_CoastSign::
	.string "SALTWIND COAST\p"
	.string "Choose your lane, then keep moving.$"
