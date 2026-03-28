BeaconfallChapter1_EventScript_ResetProgress::
	clearflag FLAG_BEACONFALL_STARTER_SELECTED
	clearflag FLAG_ROUTE_1_CLEARED
	clearflag FLAG_CINDER_REED_GROVE_CLEARED
	clearflag FLAG_BRASSFALL_CITY_ENTERED
	clearflag FLAG_CHAPTER_1_COMPLETE
	clearflag FLAG_SYS_POKEMON_GET
	clearflag FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN
	clearflag FLAG_BEACONFALL_GROVE_LAMP_A
	clearflag FLAG_BEACONFALL_GROVE_LAMP_B
	clearflag FLAG_EMBER_NORTH_GATE_TWIN_MOVED
	clearflag FLAG_FORTE_GYM_RIG_LEFT
	clearflag FLAG_FORTE_GYM_RIG_RIGHT
	clearflag FLAG_FORTE_GYM_RIG_CENTER
	setvar VAR_RIVAL_BATTLES, 0
	setvar VAR_GYM_LIGHT_STATE, 0
	setvar VAR_STARTER_MON, 0
	setvar VAR_BEACONFALL_BLACKOUT_MSG, 0
	@ Skip vanilla Littleroot bedroom clock/Mom sequence when reusing those layouts; safe for Beaconfall starts.
	setvar VAR_LITTLEROOT_INTRO_STATE, 7
	setflag FLAG_SET_WALL_CLOCK
	return

BeaconfallChapter1_EventScript_StartJourney::
	setflag FLAG_BEACONFALL_STARTER_SELECTED
	setflag FLAG_SYS_POKEMON_GET
	setflag FLAG_SYS_POKEDEX_GET
	special SetUnlockedPokedexFlags
	setvar VAR_RIVAL_BATTLES, 0
	clearflag FLAG_FORTE_GYM_RIG_LEFT
	clearflag FLAG_FORTE_GYM_RIG_RIGHT
	clearflag FLAG_FORTE_GYM_RIG_CENTER
	setvar VAR_GYM_LIGHT_STATE, 0
	setrespawn HEAL_LOCATION_EMBER_HOLLOW_PLAYERS_HOUSE_2F
	@ Sync HGSS party follower (OW) now that the lead Pokémon is the starter; map reload also calls UpdateFollowingPokemon.
	updatefollowingmon
	return

BeaconfallChapter1_EventScript_MarkRoute1Cleared::
	setflag FLAG_ROUTE_1_CLEARED
	setvar VAR_RIVAL_BATTLES, 2
	return

BeaconfallChapter1_EventScript_MarkGroveCleared::
	setflag FLAG_CINDER_REED_GROVE_CLEARED
	return

BeaconfallChapter1_EventScript_MarkBrassfallEntered::
	setflag FLAG_BRASSFALL_CITY_ENTERED
	setvar VAR_RIVAL_BATTLES, 3
	return

BeaconfallChapter1_EventScript_CompleteChapter::
	setflag FLAG_CHAPTER_1_COMPLETE
	return
