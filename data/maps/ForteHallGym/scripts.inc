ForteHallGym_MapScripts::
	.byte 0

ForteHallGym_EventScript_GymGuide::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ForteHallGym_EventScript_GymGuideAfterBadge
	msgbox ForteHallGym_Text_GymGuide, MSGBOX_DEFAULT
	release
	end

ForteHallGym_EventScript_GymGuideAfterBadge::
	msgbox ForteHallGym_Text_GymGuideAfterBadge, MSGBOX_DEFAULT
	release
	end

ForteHallGym_EventScript_TrainerLamp::
	trainerbattle_single TRAINER_BEACONFALL_GYM_LAMP, ForteHallGym_Text_LampIntro, ForteHallGym_Text_LampDefeat, ForteHallGym_EventScript_TrainerLampDefeated
	end

ForteHallGym_EventScript_TrainerLampDefeated::
	addvar VAR_GYM_LIGHT_STATE, 1
	msgbox ForteHallGym_Text_LampAfter, MSGBOX_AUTOCLOSE
	end

ForteHallGym_EventScript_TrainerBeam::
	trainerbattle_single TRAINER_BEACONFALL_GYM_BEAM, ForteHallGym_Text_BeamIntro, ForteHallGym_Text_BeamDefeat, ForteHallGym_EventScript_TrainerBeamDefeated
	end

ForteHallGym_EventScript_TrainerBeamDefeated::
	addvar VAR_GYM_LIGHT_STATE, 1
	msgbox ForteHallGym_Text_BeamAfter, MSGBOX_AUTOCLOSE
	end

ForteHallGym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ForteHallGym_EventScript_LeaderAfterBadge
	goto_if_eq VAR_GYM_LIGHT_STATE, 2, ForteHallGym_EventScript_LeaderBattle
	msgbox ForteHallGym_Text_LeaderBlocked, MSGBOX_DEFAULT
	release
	end

ForteHallGym_EventScript_LeaderBattle::
	trainerbattle_single TRAINER_BEACONFALL_LEADER, ForteHallGym_Text_LeaderIntro, ForteHallGym_Text_LeaderDefeat, ForteHallGym_EventScript_LeaderDefeated, NO_MUSIC
	release
	end

ForteHallGym_EventScript_LeaderDefeated::
	setflag FLAG_BADGE01_GET
	message ForteHallGym_Text_ReceivedBeaconBadge
	waitmessage
	call Common_EventScript_PlayGymBadgeFanfare
	msgbox ForteHallGym_Text_LeaderReward, MSGBOX_DEFAULT
	call BeaconfallChapter1_EventScript_CompleteChapter
	end

ForteHallGym_EventScript_LeaderAfterBadge::
	msgbox ForteHallGym_Text_LeaderAfterBadge, MSGBOX_DEFAULT
	release
	end

ForteHallGym_EventScript_GymSign::
	msgbox ForteHallGym_Text_GymSign, MSGBOX_SIGN
	end

ForteHallGym_Text_GymGuide::
	.string "Beat the trainers to light the hall.\p"
	.string "When both beacons shine, the leader\n"
	.string "will battle you.$"

ForteHallGym_Text_GymGuideAfterBadge::
	.string "You already earned the badge.\p"
	.string "The hall still glows for anyone who\n"
	.string "wants to train.$"

ForteHallGym_Text_LampIntro::
	.string "This is the easy part.\n"
	.string "Let's see if you can handle the glow!$"

ForteHallGym_Text_LampDefeat::
	.string "That light got brighter, didn't it?$"

ForteHallGym_Text_LampAfter::
	.string "One beacon is on.\n"
	.string "Keep pushing.$"

ForteHallGym_Text_BeamIntro::
	.string "I can feel the current in the floor.$"

ForteHallGym_Text_BeamDefeat::
	.string "The hall's brightness jumped again!$"

ForteHallGym_Text_BeamAfter::
	.string "The second beacon is lit.\n"
	.string "The leader should be ready now.$"

ForteHallGym_Text_LeaderBlocked::
	.string "The hall is still dim.\p"
	.string "Light both beacons before facing the\n"
	.string "leader.$"

ForteHallGym_Text_LeaderIntro::
	.string "You lit the hall.\p"
	.string "Now show me the spark that started it!$"

ForteHallGym_Text_LeaderDefeat::
	.string "The light keeps shining even now...$"

ForteHallGym_Text_ReceivedBeaconBadge::
	.string "You received the BEACON BADGE!$"

ForteHallGym_Text_LeaderReward::
	.string "That badge proves you can keep moving\n"
	.string "when the path is bright.$"

ForteHallGym_Text_LeaderAfterBadge::
	.string "The Beacon Badge looks good on you.\p"
	.string "Keep your eyes on the road ahead.$"

ForteHallGym_Text_GymSign::
	.string "FORTE HALL GYM\p"
	.string "Light the beacons. Win the badge.$"
