AstralTideGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_GYM2_CLEARED, AstralTideGym_EventScript_GymGuideAfterBadge
	msgbox AstralTideGym_Text_GymGuide, MSGBOX_DEFAULT
	release
	end

AstralTideGym_EventScript_GymGuideAfterBadge::
	msgbox AstralTideGym_Text_GymGuideAfterBadge, MSGBOX_DEFAULT
	release
	end

AstralTideGym_EventScript_TrainerTide::
	trainerbattle_single TRAINER_BEACONFALL_GYM_TIDE, AstralTideGym_Text_TideIntro, AstralTideGym_Text_TideDefeat, AstralTideGym_EventScript_TrainerTideDefeated
	end

AstralTideGym_EventScript_TrainerTideDefeated::
	call BeaconfallChapter2_EventScript_SetGymStatePartial
	msgbox AstralTideGym_Text_TideAfter, MSGBOX_AUTOCLOSE
	end

AstralTideGym_EventScript_TrainerBeam::
	trainerbattle_single TRAINER_BEACONFALL_GYM_SURGE, AstralTideGym_Text_BeamIntro, AstralTideGym_Text_BeamDefeat, AstralTideGym_EventScript_TrainerBeamDefeated
	end

AstralTideGym_EventScript_TrainerBeamDefeated::
	call BeaconfallChapter2_EventScript_SetGymStateFull
	msgbox AstralTideGym_Text_BeamAfter, MSGBOX_AUTOCLOSE
	end

AstralTideGym_EventScript_TrainerMoon::
	trainerbattle_single TRAINER_BEACONFALL_GYM_MOON, AstralTideGym_Text_MoonIntro, AstralTideGym_Text_MoonDefeat, AstralTideGym_EventScript_TrainerMoonDefeated
	end

AstralTideGym_EventScript_TrainerMoonDefeated::
	msgbox AstralTideGym_Text_MoonAfter, MSGBOX_AUTOCLOSE
	end

AstralTideGym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_GYM2_CLEARED, AstralTideGym_EventScript_LeaderAfterBadge
	goto_if_set FLAG_BADGE02_GET, AstralTideGym_EventScript_LeaderReward
	goto_if_eq VAR_WATER_LEVEL_GYM, 2, AstralTideGym_EventScript_LeaderBattle
	msgbox AstralTideGym_Text_LeaderBlocked, MSGBOX_DEFAULT
	release
	end

AstralTideGym_EventScript_LeaderBattle::
	trainerbattle_single TRAINER_BEACONFALL_LEADER2, AstralTideGym_Text_LeaderIntro, AstralTideGym_Text_LeaderDefeat, AstralTideGym_EventScript_LeaderDefeated, NO_MUSIC
	release
	end

AstralTideGym_EventScript_LeaderDefeated::
	setflag FLAG_BADGE02_GET
	message AstralTideGym_Text_ReceivedBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	goto AstralTideGym_EventScript_LeaderReward
	end

AstralTideGym_EventScript_LeaderReward::
	giveitem ITEM_HM_SURF
	goto_if_eq VAR_RESULT, FALSE, AstralTideGym_EventScript_LeaderRewardBagFull
	call BeaconfallChapter2_EventScript_MarkGym2Cleared
	call BeaconfallChapter2_EventScript_UnlockSurf
	call BeaconfallChapter2_EventScript_CompleteChapter
	msgbox AstralTideGym_Text_LeaderReward, MSGBOX_DEFAULT
	release
	end

AstralTideGym_EventScript_LeaderRewardBagFull::
	msgbox AstralTideGym_Text_LeaderRewardBagFull, MSGBOX_DEFAULT
	release
	end

AstralTideGym_EventScript_LeaderAfterBadge::
	msgbox AstralTideGym_Text_LeaderAfterBadge, MSGBOX_DEFAULT
	release
	end

AstralTideGym_EventScript_GymSign::
	msgbox AstralTideGym_Text_GymSign, MSGBOX_SIGN
	end

AstralTideGym_Text_GymGuide::
	.string "The valves change the hall.\p"
	.string "Read the tide carefully and you can\n"
	.string "skip half the fight.$"

AstralTideGym_Text_GymGuideAfterBadge::
	.string "You already earned the tide badge.\p"
	.string "The hall still moves for anyone who\n"
	.string "wants to train.$"

AstralTideGym_Text_TideIntro::
	.string "The current carries weak trainers away!$"

AstralTideGym_Text_TideDefeat::
	.string "The water level shifted after that!$"

AstralTideGym_Text_TideAfter::
	.string "One valve is settled.\n"
	.string "Keep pressing forward.$"

AstralTideGym_Text_BeamIntro::
	.string "I watch the reflections for openings.$"

AstralTideGym_Text_BeamDefeat::
	.string "The hall brightened again!$"

AstralTideGym_Text_BeamAfter::
	.string "The water is at full flow now.$"

AstralTideGym_Text_MoonIntro::
	.string "The moon pulls the tides and the tides\n"
	.string "pull back.$"

AstralTideGym_Text_MoonDefeat::
	.string "The moonlight cut the room open...$"

AstralTideGym_Text_MoonAfter::
	.string "Even a side route can change the room.\p"
	.string "Keep reading the tides.$"

AstralTideGym_Text_LeaderBlocked::
	.string "The hall still isn't aligned.\p"
	.string "Set the water, then face Selene.$"

AstralTideGym_Text_LeaderIntro::
	.string "You learned the tide's rhythm.\p"
	.string "Now let's see if you can hold it.$"

AstralTideGym_Text_LeaderDefeat::
	.string "You stayed ahead of the flow...$"

AstralTideGym_Text_ReceivedBadge::
	.string "You received the TIDE BADGE!$"

AstralTideGym_Text_LeaderReward::
	.string "Badge 2 is yours, and Surf is ready.\p"
	.string "The chapter can open up now.$"

AstralTideGym_Text_LeaderRewardBagFull::
	.string "Make room in your bag and come back.\p"
	.string "I still have Surf waiting for you.$"

AstralTideGym_Text_LeaderAfterBadge::
	.string "The tide badge suits you.\p"
	.string "Keep your balance, and keep moving.$"

AstralTideGym_Text_GymSign::
	.string "ASTRAL TIDE GYM\p"
	.string "Control the water. Challenge Selene.$"
