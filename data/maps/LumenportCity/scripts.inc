LumenportCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, LumenportCity_OnTransition
	.byte 0

LumenportCity_OnTransition::
	setworldmapflag FLAG_WORLD_MAP_VIRIDIAN_CITY
	end

LumenportCity_EventScript_Healer::
	lock
	faceplayer
	msgbox LumenportCity_Text_Healer, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

LumenportCity_EventScript_MartClerk::
	lock
	faceplayer
	message LumenportCity_Text_MartIntro
	waitmessage
	pokemart LumenportCity_Pokemart
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end

	.align 2
LumenportCity_Pokemart:
	.2byte ITEM_POKE_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_REPEL
	pokemartlistend

LumenportCity_EventScript_MoveReminder::
	lock
	faceplayer
	goto_if_set FLAG_TEMP_1, LumenportCity_EventScript_AskTeachMove
	msgbox LumenportCity_Text_MoveReminderIntro, MSGBOX_DEFAULT
	setflag FLAG_TEMP_1
	goto LumenportCity_EventScript_AskTeachMove
	end

LumenportCity_EventScript_AskTeachMove::
	checkitem ITEM_HEART_SCALE
	goto_if_eq VAR_RESULT, FALSE, LumenportCity_EventScript_ComeBackWithHeartScale
	msgbox LumenportCity_Text_ThatsAHeartScaleWantMeToTeachMove, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, LumenportCity_EventScript_ComeBackWithHeartScale
	goto LumenportCity_EventScript_ChooseMon
	end

LumenportCity_EventScript_ChooseMon::
	msgbox LumenportCity_Text_MoveReminderWhichMon, MSGBOX_DEFAULT
	setmoverelearnerstate MOVE_RELEARNER_LEVEL_UP_MOVES
	chooseboxmon SELECT_PC_MON_MOVE_RELEARNER
	waitstate
	goto_if_eq VAR_0x8004, PARTY_NOTHING_CHOSEN, LumenportCity_EventScript_ComeBackWithHeartScale
	special IsSelectedMonEgg
	goto_if_eq VAR_RESULT, TRUE, LumenportCity_EventScript_CantTeachEgg
	special HasMovesToRelearn
	goto_if_eq VAR_RESULT, FALSE, LumenportCity_EventScript_NoMoveToTeachMon
	goto LumenportCity_EventScript_ChooseMove
	end

LumenportCity_EventScript_ChooseMove::
	msgbox LumenportCity_Text_MoveReminderWhichMove, MSGBOX_DEFAULT
	special TeachMoveRelearnerMove
	waitstate
	goto_if_eq VAR_0x8004, 0, LumenportCity_EventScript_ChooseMon
	msgbox LumenportCity_Text_HandedOverHeartScale, MSGBOX_DEFAULT
	removeitem ITEM_HEART_SCALE
	goto LumenportCity_EventScript_ComeBackWithHeartScale
	end

LumenportCity_EventScript_NoMoveToTeachMon::
	msgbox LumenportCity_Text_DontHaveMoveToTeachPokemon, MSGBOX_DEFAULT
	goto LumenportCity_EventScript_ChooseMon
	end

LumenportCity_EventScript_CantTeachEgg::
	msgbox LumenportCity_Text_CantTeachEgg, MSGBOX_DEFAULT
	goto LumenportCity_EventScript_ChooseMon
	end

LumenportCity_EventScript_ComeBackWithHeartScale::
	msgbox LumenportCity_Text_ComeBackWithHeartScale, MSGBOX_DEFAULT
	release
	end

LumenportCity_EventScript_Dockworker::
	lock
	faceplayer
	goto_if_set FLAG_RIVAL2_DONE, LumenportCity_EventScript_DockworkerAfterRival
	goto_if_set FLAG_FLOODGATE_TUNNELS_CLEARED, LumenportCity_EventScript_DockworkerAfterFloodgate
	msgbox LumenportCity_Text_DockworkerIntro, MSGBOX_DEFAULT
	release
	end

LumenportCity_EventScript_DockworkerAfterFloodgate::
	msgbox LumenportCity_Text_DockworkerAfterFloodgate, MSGBOX_DEFAULT
	release
	end

LumenportCity_EventScript_DockworkerAfterRival::
	msgbox LumenportCity_Text_DockworkerAfterRival, MSGBOX_DEFAULT
	release
	end

LumenportCity_EventScript_RivalBattle::
	lockall
	trainerbattle_single TRAINER_BEACONFALL_RIVAL3, LumenportCity_Text_RivalIntro, LumenportCity_Text_RivalDefeat, LumenportCity_EventScript_RivalBattleDefeated
	releaseall
	end

LumenportCity_EventScript_RivalBattleDefeated::
	call BeaconfallChapter2_EventScript_MarkRival2Done
	msgbox LumenportCity_Text_RivalAfter, MSGBOX_AUTOCLOSE
	end

LumenportCity_EventScript_CitySign::
	msgbox LumenportCity_Text_CitySign, MSGBOX_SIGN
	end

LumenportCity_Text_Healer::
	.string "The harbor is rough today.\p"
	.string "Let me get your team back in shape.$"

LumenportCity_Text_MartIntro::
	.string "We stock for travelers, engineers, and\n"
	.string "gym challengers alike.$"

LumenportCity_Text_MoveReminderIntro::
	.string "I'm the MOVE REMINDER.\p"
	.string "I can help POKéMON remember old moves\n"
	.string "if you have a HEART SCALE.$"

LumenportCity_Text_ThatsAHeartScaleWantMeToTeachMove::
	.string "Oh! That's a HEART SCALE.\p"
	.string "You want me to teach a move?$"

LumenportCity_Text_MoveReminderWhichMon::
	.string "Which POKéMON needs tutoring?$"

LumenportCity_Text_MoveReminderWhichMove::
	.string "Which move should I teach?$"

LumenportCity_Text_HandedOverHeartScale::
	.string "The move reminder took the HEART SCALE.\p"
	.string "Keep bringing your team back here.$"

LumenportCity_Text_DontHaveMoveToTeachPokemon::
	.string "That POKéMON has nothing to remember.\p"
	.string "Try another one.$"

LumenportCity_Text_CantTeachEgg::
	.string "EGGS can't relearn moves yet.$"

LumenportCity_Text_ComeBackWithHeartScale::
	.string "Come back when you have a HEART SCALE.$"

LumenportCity_Text_DockworkerIntro::
	.string "The floodgates were shaking all day.\p"
	.string "Something in the tunnels felt wrong.$"

LumenportCity_Text_DockworkerAfterFloodgate::
	.string "They moved a stolen relic through the\n"
	.string "docks after the tunnel drained.\p"
	.string "Keep your eyes open at the gym.$"

LumenportCity_Text_DockworkerAfterRival::
	.string "The rival already headed for Selene.\p"
	.string "Astral Tide Gym is your next stop.$"

LumenportCity_Text_RivalIntro::
	.string "You got through the tunnels, huh?\p"
	.string "Then let's see if you can keep up now!$"

LumenportCity_Text_RivalDefeat::
	.string "Tch. You read that fight too well.$"

LumenportCity_Text_RivalAfter::
	.string "I was heading to Astral Tide Gym anyway.\p"
	.string "Don't slow down now.$"

LumenportCity_Text_CitySign::
	.string "LUMENPORT CITY\p"
	.string "Harbor lights, tide machines, and glass.$"
