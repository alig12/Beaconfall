EmberHollowTown_PlayersHouse_2F_MapScripts::
	.byte 0

@ Referenced from map.json bg_events (matches Brendan bedroom PC flow).
PlayersHouse_2F_EventScript_PC::
	lockall
	setvar VAR_0x8004, PC_LOCATION_OTHER
	special DoPCTurnOnEffect
	playse SE_PC_ON
	msgbox gText_PlayerHouseBootPC, MSGBOX_DEFAULT
	special BedroomPC
	waitstate
	releaseall
	end
