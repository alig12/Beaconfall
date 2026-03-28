ForteHallGym_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, ForteHallGym_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, ForteHallGym_OnTransition
	.byte 0

ForteHallGym_OnLoad::
	call ForteHallGym_EventScript_RecalculateLightVar
	call ForteHallGym_EventScript_ApplyPersistedLights
	end

ForteHallGym_OnTransition::
	call ForteHallGym_EventScript_RecalculateLightVar
	call ForteHallGym_EventScript_UpdateAmbientFlash
	end

@ VAR_GYM_LIGHT_STATE = count of FLAG_FORTE_GYM_RIG_* (0–3). Flags persist which rigs are lit in any order.
ForteHallGym_EventScript_RecalculateLightVar::
	setvar VAR_GYM_LIGHT_STATE, 0
	goto_if_set FLAG_FORTE_GYM_RIG_LEFT, ForteHallGym_Recalc_AddOneA
ForteHallGym_Recalc_CheckRight::
	goto_if_set FLAG_FORTE_GYM_RIG_RIGHT, ForteHallGym_Recalc_AddOneB
ForteHallGym_Recalc_CheckCenter::
	goto_if_set FLAG_FORTE_GYM_RIG_CENTER, ForteHallGym_Recalc_AddOneC
ForteHallGym_Recalc_Done::
	return

ForteHallGym_Recalc_AddOneA::
	addvar VAR_GYM_LIGHT_STATE, 1
	goto ForteHallGym_Recalc_CheckRight

ForteHallGym_Recalc_AddOneB::
	addvar VAR_GYM_LIGHT_STATE, 1
	goto ForteHallGym_Recalc_CheckCenter

ForteHallGym_Recalc_AddOneC::
	addvar VAR_GYM_LIGHT_STATE, 1
	goto ForteHallGym_Recalc_Done

@ Darker flash level = dimmer arena (see Dewford Gym pattern).
ForteHallGym_EventScript_UpdateAmbientFlash::
	goto_if_set FLAG_BADGE01_GET, ForteHallGym_EventScript_FlashClear
	goto_if_ge VAR_GYM_LIGHT_STATE, 3, ForteHallGym_EventScript_FlashClear
	goto_if_eq VAR_GYM_LIGHT_STATE, 2, ForteHallGym_EventScript_FlashLevel2
	goto_if_eq VAR_GYM_LIGHT_STATE, 1, ForteHallGym_EventScript_FlashLevel4
	setflashlevel 6
	return

ForteHallGym_EventScript_FlashLevel4::
	setflashlevel 4
	return

ForteHallGym_EventScript_FlashLevel2::
	setflashlevel 2
	return

ForteHallGym_EventScript_FlashClear::
	setflashlevel 0
	return

ForteHallGym_EventScript_ApplyPersistedLights::
	goto_if_set FLAG_BADGE01_GET, ForteHallGym_EventScript_ApplyAllStageLights
	call ForteHallGym_EventScript_ApplyLitRigsFromFlags
ForteHallGym_EventScript_ApplyLightsDone::
	end

ForteHallGym_EventScript_ApplyLitRigsFromFlags::
	goto_if_set FLAG_FORTE_GYM_RIG_LEFT, ForteHallGym_ApplyDoLeft
ForteHallGym_ApplyAfterLeft::
	goto_if_set FLAG_FORTE_GYM_RIG_RIGHT, ForteHallGym_ApplyDoRight
ForteHallGym_ApplyAfterRight::
	goto_if_set FLAG_FORTE_GYM_RIG_CENTER, ForteHallGym_ApplyDoCenter
ForteHallGym_ApplyAfterCenter::
	return

ForteHallGym_ApplyDoLeft::
	call ForteHallGym_EventScript_LightStageLeftMetatiles
	goto ForteHallGym_ApplyAfterLeft

ForteHallGym_ApplyDoRight::
	call ForteHallGym_EventScript_LightStageRightMetatiles
	goto ForteHallGym_ApplyAfterRight

ForteHallGym_ApplyDoCenter::
	call ForteHallGym_EventScript_LightStageCenterMetatiles
	goto ForteHallGym_ApplyAfterCenter

ForteHallGym_EventScript_ApplyAllStageLights::
	call ForteHallGym_EventScript_LightStageLeftMetatiles
	call ForteHallGym_EventScript_LightStageRightMetatiles
	call ForteHallGym_EventScript_LightStageCenterMetatiles
	end

@ Stage wash lights (Petalburg Gym tileset): left / right / center markers.
ForteHallGym_EventScript_LightStageLeftMetatiles::
	setmetatile 1, 9, METATILE_PetalburgGym_SlidingDoor_Frame4, TRUE
	special DrawWholeMapView
	return

ForteHallGym_EventScript_LightStageRightMetatiles::
	setmetatile 7, 9, METATILE_PetalburgGym_SlidingDoor_Frame4, TRUE
	special DrawWholeMapView
	return

ForteHallGym_EventScript_LightStageCenterMetatiles::
	setmetatile 4, 5, METATILE_PetalburgGym_SlidingDoor_Frame4, TRUE
	special DrawWholeMapView
	return

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
	setflag FLAG_FORTE_GYM_RIG_LEFT
	call ForteHallGym_EventScript_RecalculateLightVar
	call ForteHallGym_EventScript_ApplyLitRigsFromFlags
	call ForteHallGym_EventScript_UpdateAmbientFlash
	playse SE_M_MEGA_KICK
	msgbox ForteHallGym_Text_LampAfter, MSGBOX_AUTOCLOSE
	end

ForteHallGym_EventScript_TrainerBeam::
	trainerbattle_single TRAINER_BEACONFALL_GYM_BEAM, ForteHallGym_Text_BeamIntro, ForteHallGym_Text_BeamDefeat, ForteHallGym_EventScript_TrainerBeamDefeated
	end

ForteHallGym_EventScript_TrainerBeamDefeated::
	setflag FLAG_FORTE_GYM_RIG_RIGHT
	call ForteHallGym_EventScript_RecalculateLightVar
	call ForteHallGym_EventScript_ApplyLitRigsFromFlags
	call ForteHallGym_EventScript_UpdateAmbientFlash
	playse SE_M_MEGA_KICK
	msgbox ForteHallGym_Text_BeamAfter, MSGBOX_AUTOCLOSE
	end

ForteHallGym_EventScript_TrainerTech::
	trainerbattle_single TRAINER_BEACONFALL_GYM_TECH, ForteHallGym_Text_TechIntro, ForteHallGym_Text_TechDefeat, ForteHallGym_EventScript_TrainerTechDefeated
	end

ForteHallGym_EventScript_TrainerTechDefeated::
	setflag FLAG_FORTE_GYM_RIG_CENTER
	call ForteHallGym_EventScript_RecalculateLightVar
	call ForteHallGym_EventScript_ApplyLitRigsFromFlags
	call ForteHallGym_EventScript_UpdateAmbientFlash
	playse SE_M_MEGA_KICK
	msgbox ForteHallGym_Text_TechAfter, MSGBOX_AUTOCLOSE
	end

ForteHallGym_EventScript_Leader::
	lock
	faceplayer
	goto_if_set FLAG_BADGE01_GET, ForteHallGym_EventScript_LeaderAfterBadge
	goto_if_ge VAR_GYM_LIGHT_STATE, 3, ForteHallGym_EventScript_LeaderBattle
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
	.string "Three crew members run the rigs: opener,\n"
	.string "backup, and lead tech.\p"
	.string "Beat them in any order. When all three\n"
	.string "lanes light, VERA steps out.$"

ForteHallGym_Text_GymGuideAfterBadge::
	.string "You already earned the badge.\p"
	.string "The hall still glows for anyone who\n"
	.string "wants to train.$"

ForteHallGym_Text_LampIntro::
	.string "KIT: House lights, house rules.\n"
	.string "Left rig is mine. Prove you belong!$"

ForteHallGym_Text_LampDefeat::
	.string "KIT: Hah... alright, left stack is live.$"

ForteHallGym_Text_LampAfter::
	.string "The left wash cuts through the dark.$"

ForteHallGym_Text_BeamIntro::
	.string "RAYNE: Feel the floor buzz?\n"
	.string "Right side is my solo!$"

ForteHallGym_Text_BeamDefeat::
	.string "RAYNE: Gorgeous. Right truss is up!$"

ForteHallGym_Text_BeamAfter::
	.string "The right wash just punched in.$"

ForteHallGym_Text_TechIntro::
	.string "JAX: I'm on center power. Mess with me\n"
	.string "and the whole grid hears it!$"

ForteHallGym_Text_TechDefeat::
	.string "JAX: Main throw is yours. Go wake the boss.$"

ForteHallGym_Text_TechAfter::
	.string "The center spot finally hits VERA's door.$"

ForteHallGym_Text_LeaderBlocked::
	.string "VERA: Patience.\p"
	.string "I can't read the room until every rig\n"
	.string "is up: three crew, three lights.$"

ForteHallGym_Text_LeaderIntro::
	.string "VERA: There it is. The hall in full beam.\p"
	.string "Show me the spark that carried you!$"

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
	.string "City relay stage. Light three rigs in any\n"
	.string "order, then earn the Beacon Badge.$"
