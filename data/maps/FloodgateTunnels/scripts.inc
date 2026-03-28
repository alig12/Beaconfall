FloodgateTunnels_EventScript_ValveA::
	lock
	faceplayer
	call BeaconfallChapter2_EventScript_SetFloodgateStatePartial
	setflag FLAG_FLOODGATE_VALVE_A
	msgbox FloodgateTunnels_Text_ValveA, MSGBOX_DEFAULT
	release
	end

FloodgateTunnels_EventScript_ValveB::
	lock
	faceplayer
	call BeaconfallChapter2_EventScript_SetFloodgateStateFull
	setflag FLAG_FLOODGATE_VALVE_B
	msgbox FloodgateTunnels_Text_ValveB, MSGBOX_DEFAULT
	release
	end

FloodgateTunnels_EventScript_ValveC::
	lock
	faceplayer
	call BeaconfallChapter2_EventScript_SetFloodgateStateDrained
	setflag FLAG_FLOODGATE_VALVE_C
	call BeaconfallChapter2_EventScript_MarkFloodgateCleared
	msgbox FloodgateTunnels_Text_ValveC, MSGBOX_DEFAULT
	release
	end

FloodgateTunnels_EventScript_EngineerMara::
	trainerbattle_single TRAINER_BEACONFALL_FLOODGATE_ENGINEER, FloodgateTunnels_Text_EngineerMaraIntro, FloodgateTunnels_Text_EngineerMaraDefeat, FloodgateTunnels_EventScript_EngineerMaraDefeated
	end

FloodgateTunnels_EventScript_EngineerMaraDefeated::
	msgbox FloodgateTunnels_Text_EngineerMaraAfter, MSGBOX_AUTOCLOSE
	end

FloodgateTunnels_EventScript_Worker::
	trainerbattle_single TRAINER_BEACONFALL_FLOODGATE_WORKER, FloodgateTunnels_Text_WorkerIntro, FloodgateTunnels_Text_WorkerDefeat, FloodgateTunnels_EventScript_WorkerDefeated
	end

FloodgateTunnels_EventScript_WorkerDefeated::
	msgbox FloodgateTunnels_Text_WorkerAfter, MSGBOX_AUTOCLOSE
	end

FloodgateTunnels_EventScript_HintNPC::
	lock
	faceplayer
	goto_if_set FLAG_FLOODGATE_TUNNELS_CLEARED, FloodgateTunnels_EventScript_HintNPCAfter
	msgbox FloodgateTunnels_Text_HintIntro, MSGBOX_DEFAULT
	release
	end

FloodgateTunnels_EventScript_HintNPCAfter::
	msgbox FloodgateTunnels_Text_HintAfter, MSGBOX_DEFAULT
	release
	end

FloodgateTunnels_EventScript_TunnelsSign::
	msgbox FloodgateTunnels_Text_TunnelsSign, MSGBOX_SIGN
	end

FloodgateTunnels_Text_ValveA::
	.string "You turned VALVE A.\p"
	.string "The entry channel drains just enough\n"
	.string "to open the first path.$"

FloodgateTunnels_Text_ValveB::
	.string "You turned VALVE B.\p"
	.string "The mid chamber floods back in.$"

FloodgateTunnels_Text_ValveC::
	.string "You turned VALVE C.\p"
	.string "The core drains and the exit opens.$"

FloodgateTunnels_Text_EngineerMaraIntro::
	.string "The pumps answer to pressure, not luck!$"

FloodgateTunnels_Text_EngineerMaraDefeat::
	.string "You kept the flow under control...$"

FloodgateTunnels_Text_EngineerMaraAfter::
	.string "Watch the valves.\n"
	.string "Every room changes when the water does.$"

FloodgateTunnels_Text_WorkerIntro::
	.string "The tunnels shake when the water moves!$"

FloodgateTunnels_Text_WorkerDefeat::
	.string "I misread the current...$"

FloodgateTunnels_Text_WorkerAfter::
	.string "When the core drains, the city opens up.$"

FloodgateTunnels_Text_HintIntro::
	.string "Entry first, chamber second, core last.\p"
	.string "If you lose track, just back up and\n"
	.string "read the room again.$"

FloodgateTunnels_Text_HintAfter::
	.string "The tunnels are open through to the city.\p"
	.string "Take the dry route and keep going.$"

FloodgateTunnels_Text_TunnelsSign::
	.string "FLOODGATE TUNNELS\p"
	.string "Three valves. Three water states.$"
