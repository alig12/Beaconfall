BeaconfallChapter2_EventScript_ResetProgress::
	clearflag FLAG_BADGE02_GET
	clearflag FLAG_RECEIVED_HM_SURF
	clearflag FLAG_SALTWIND_COAST_CLEARED
	clearflag FLAG_FLOODGATE_VALVE_A
	clearflag FLAG_FLOODGATE_VALVE_B
	clearflag FLAG_FLOODGATE_VALVE_C
	clearflag FLAG_FLOODGATE_TUNNELS_CLEARED
	clearflag FLAG_RIVAL2_DONE
	clearflag FLAG_GYM2_CLEARED
	clearflag FLAG_SURF_UNLOCKED
	clearflag FLAG_CHAPTER_2_COMPLETE
	setvar VAR_RIVAL2_STATE, 0
	setvar VAR_WATER_LEVEL_FLOODGATE, 0
	setvar VAR_WATER_LEVEL_GYM, 0
	return

BeaconfallChapter2_EventScript_MarkSaltwindCleared::
	setflag FLAG_SALTWIND_COAST_CLEARED
	return

BeaconfallChapter2_EventScript_SetFloodgateStateDrained::
	setvar VAR_WATER_LEVEL_FLOODGATE, 0
	return

BeaconfallChapter2_EventScript_SetFloodgateStatePartial::
	setvar VAR_WATER_LEVEL_FLOODGATE, 1
	return

BeaconfallChapter2_EventScript_SetFloodgateStateFull::
	setvar VAR_WATER_LEVEL_FLOODGATE, 2
	return

BeaconfallChapter2_EventScript_MarkFloodgateCleared::
	setflag FLAG_FLOODGATE_TUNNELS_CLEARED
	return

BeaconfallChapter2_EventScript_MarkRival2Done::
	setflag FLAG_RIVAL2_DONE
	setvar VAR_RIVAL2_STATE, 1
	return

BeaconfallChapter2_EventScript_SetGymStateDrained::
	setvar VAR_WATER_LEVEL_GYM, 0
	return

BeaconfallChapter2_EventScript_SetGymStatePartial::
	setvar VAR_WATER_LEVEL_GYM, 1
	return

BeaconfallChapter2_EventScript_SetGymStateFull::
	setvar VAR_WATER_LEVEL_GYM, 2
	return

BeaconfallChapter2_EventScript_MarkGym2Cleared::
	setflag FLAG_GYM2_CLEARED
	return

BeaconfallChapter2_EventScript_UnlockSurf::
	setflag FLAG_RECEIVED_HM_SURF
	setflag FLAG_SURF_UNLOCKED
	return

BeaconfallChapter2_EventScript_CompleteChapter::
	setflag FLAG_CHAPTER_2_COMPLETE
	return
