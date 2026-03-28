EmberHollowTown_PlayersHouse_1F_MapScripts::
	.byte 0

EmberHollowTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_TUTORIAL_RIVAL_BEATEN, EmberHollowTown_PlayersHouse_1F_EventScript_MomHeal
	msgbox EmberHollowTown_PlayersHouse_1F_Text_MomWaitingForNews, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_PlayersHouse_1F_EventScript_MomHeal::
	msgbox EmberHollowTown_PlayersHouse_1F_Text_MomHealingOffer, MSGBOX_DEFAULT
	call EmberHollowTown_PlayersHouse_1F_EventScript_PerformHealing
	msgbox EmberHollowTown_PlayersHouse_1F_Text_MomHealed, MSGBOX_DEFAULT
	release
	end

EmberHollowTown_PlayersHouse_1F_EventScript_PerformHealing::
	closemessage
	playse SE_HEAL
	dofieldeffect FLDEFF_HEAL_TEAM_COLOR_FLASH
	waitstate
	playse SE_HEAL
	special HealPlayerParty
	return

EmberHollowTown_PlayersHouse_1F_Text_MomWaitingForNews::
	.string "MOM: Honey! I was so worried when the\n"
	.string "lights went out.\p"
	.string "The beacons are down, and without them,\n"
	.string "the roads are dangerous.\l"
	.string "Please be careful if you go out.$"

EmberHollowTown_PlayersHouse_1F_Text_MomHealingOffer::
	.string "MOM: You look like you've been through\n"
	.string "something already!\p"
	.string "Let me help you recover. I may not have\n"
	.string "Potions, but I can do this much for my\l"
	.string "brave trainer.$"

EmberHollowTown_PlayersHouse_1F_Text_MomHealed::
	.string "MOM: There. You're all patched up.\p"
	.string "Stay safe out there. The world's darker\n"
	.string "without those beacons.$"
