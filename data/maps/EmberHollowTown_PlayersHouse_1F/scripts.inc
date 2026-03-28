EmberHollowTown_PlayersHouse_1F_MapScripts::
	.byte 0

EmberHollowTown_PlayersHouse_1F_EventScript_Mom::
	lock
	faceplayer
	goto_if_set FLAG_BEACONFALL_STARTER_SELECTED, EmberHollowTown_PlayersHouse_1F_EventScript_MomHeal
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
	playfanfare MUS_HEAL
	dofieldeffect FLDEFF_POKECENTER_HEAL
	waitfieldeffect FLDEFF_POKECENTER_HEAL
	special HealPlayerParty
	return

EmberHollowTown_PlayersHouse_1F_Text_MomWaitingForNews::
	.string "MOM: I was worried when the\n"
	.string "lights went out.\p"
	.string "The beacons are down.\p"
	.string "Without them, the roads are\n"
	.string "dangerous.\p"
	.string "Please be careful if you go out.$"

EmberHollowTown_PlayersHouse_1F_Text_MomHealingOffer::
	.string "MOM: You've got your partner now.\p"
	.string "Let me patch you up.\p"
	.string "Then head back out there.$"

EmberHollowTown_PlayersHouse_1F_Text_MomHealed::
	.string "MOM: There. You're all patched up.\p"
	.string "If the route gets rough,\n"
	.string "come back here.\p"
	.string "I'll help again.$"
