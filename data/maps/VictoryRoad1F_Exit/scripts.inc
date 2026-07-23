VictoryRoad1F_Exit_MapScripts::
	.byte 0
	
VictoryRoad1F_Exit_EventScript_WallyBattleTrigger::
	lockall
	addobject LOCALID_VICTORY_ROAD_EXIT_WALLY
	applymovement LOCALID_VICTORY_ROAD_EXIT_WALLY, VictoryRoad1F_Exit_Movement_WallyApproachesPlayer
	waitmovement 0
	goto VictoryRoad1F_Exit_EventScript_WallyEntranceBattle
	end

VictoryRoad1F_Exit_EventScript_WallyEntranceBattle::
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox VictoryRoad1F_Exit_Text_WallyNotGoingToLoseAnymore, MSGBOX_DEFAULT
	trainerbattle_no_intro TRAINER_WALLY_VR_1, VictoryRoad1F_Exit_Text_WallyEntranceDefeat
	msgbox VictoryRoad1F_Exit_Text_WallyPostEntranceBattle, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_VICTORY_ROAD_EXIT_WALLY, Common_Movement_WalkUp6
	waitmovement 0
	setflag FLAG_DEFEATED_WALLY_VICTORY_ROAD
	setvar VAR_WALLY_BATTLE_VICTORY_ROAD, 1
	removeobject LOCALID_VICTORY_ROAD_EXIT_WALLY
	releaseall
	end
	
VictoryRoad1F_Exit_Text_WallyNotGoingToLoseAnymore:
	.string "Wally: Hi! {PLAYER}!\p"
	.string "I bet you're surprised to see me here!\p"
	.string "I made it all the way here, and it's\n"
	.string "all thanks to you!\p"
	.string "{PLAYER}, losing to you that time\n"
	.string "made me stronger!\p"
	.string "But I'm not going to lose anymore!\p"
	.string "I'm going to win! For the Puppets who\n"
	.string "gave me courage and strength!\p"
	.string "Okay… Here I come!$"
	
VictoryRoad1F_Exit_Text_WallyEntranceDefeat:
	.string "Wow!\n"
	.string "{PLAYER}, you are strong, after all!$"
	
 VictoryRoad1F_Exit_Text_WallyPostEntranceBattle:
 	.string "Wally: I couldn't beat you today,\n"
	.string "{PLAYER}, but one of these days, I'll\l"
	.string "catch up to you!$"

VictoryRoad1F_Exit_Movement_WallyApproachesPlayer:
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
