BeaconfallChapter1_EventScript_ResetProgress::
	clearflag FLAG_BEACONFALL_STARTER_SELECTED
	clearflag FLAG_ROUTE_1_CLEARED
	clearflag FLAG_CINDER_REED_GROVE_CLEARED
	clearflag FLAG_BRASSFALL_CITY_ENTERED
	clearflag FLAG_CHAPTER_1_COMPLETE
	setvar VAR_RIVAL_BATTLES, 0
	setvar VAR_GYM_LIGHT_STATE, 0
	setvar VAR_STARTER_MON, 0
	return

BeaconfallChapter1_EventScript_StartJourney::
	setflag FLAG_BEACONFALL_STARTER_SELECTED
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setvar VAR_RIVAL_BATTLES, 0
	setvar VAR_GYM_LIGHT_STATE, 0
	return

BeaconfallChapter1_EventScript_MarkRoute1Cleared::
	setflag FLAG_ROUTE_1_CLEARED
	setvar VAR_RIVAL_BATTLES, 1
	return

BeaconfallChapter1_EventScript_MarkGroveCleared::
	setflag FLAG_CINDER_REED_GROVE_CLEARED
	return

BeaconfallChapter1_EventScript_MarkBrassfallEntered::
	setflag FLAG_BRASSFALL_CITY_ENTERED
	setvar VAR_RIVAL_BATTLES, 2
	return

BeaconfallChapter1_EventScript_CompleteChapter::
	setflag FLAG_CHAPTER_1_COMPLETE
	return
