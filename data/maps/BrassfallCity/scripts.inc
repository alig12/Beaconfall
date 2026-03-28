BrassfallCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, BrassfallCity_OnTransition
	.byte 0

BrassfallCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	end

BrassfallCity_EventScript_RivalBattle::
	lockall
	trainerbattle_single TRAINER_BEACONFALL_RIVAL2, BrassfallCity_Text_RivalIntro, BrassfallCity_Text_RivalDefeat, BrassfallCity_EventScript_RivalBattleDefeated
	releaseall
	end

BrassfallCity_EventScript_RivalBattleDefeated::
	call BeaconfallChapter1_EventScript_MarkBrassfallEntered
	msgbox BrassfallCity_Text_RivalAfter, MSGBOX_AUTOCLOSE
	end

BrassfallCity_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BRASSFALL_CITY_ENTERED, BrassfallCity_EventScript_GymGuideOpen
	msgbox BrassfallCity_Text_GymGuideBlocked, MSGBOX_DEFAULT
	release
	end

BrassfallCity_EventScript_GymGuideOpen::
	msgbox BrassfallCity_Text_GymGuideOpen, MSGBOX_DEFAULT
	release
	end

BrassfallCity_EventScript_Healer::
	lock
	faceplayer
	msgbox BrassfallCity_Text_Healer, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

BrassfallCity_EventScript_CitySign::
	msgbox BrassfallCity_Text_CitySign, MSGBOX_SIGN
	end

BrassfallCity_Text_RivalIntro::
	.string "You got through the grove?\p"
	.string "Then show me what your starter can do!$"

BrassfallCity_Text_RivalDefeat::
	.string "Not bad.\n"
	.string "You didn't slow down at all.$"

BrassfallCity_Text_RivalAfter::
	.string "Brassfall is yours to explore now.\p"
	.string "The gym is waiting on the other side\n"
	.string "of town.$"

BrassfallCity_Text_GymGuideBlocked::
	.string "The city hums before the battle.\p"
	.string "Take a moment to recover first.$"

BrassfallCity_Text_GymGuideOpen::
	.string "Forte Hall Gym is ready for you.\p"
	.string "Light the hall and challenge the leader.$"

BrassfallCity_Text_Healer::
	.string "You look ready for a rest.\p"
	.string "Let me patch up your team.$"

BrassfallCity_Text_CitySign::
	.string "BRASSFALL CITY\p"
	.string "Where the beacon meets the hall.$"
