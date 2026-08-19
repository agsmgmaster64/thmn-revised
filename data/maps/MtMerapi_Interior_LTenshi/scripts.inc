MtMerapi_Interior_LTenshi_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtMerapi_Interior_LTenshi_End_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtMerapi_Interior_LTenshi_End_OnTransition
	.byte 0
	
MtMerapi_Interior_LTenshi_End_OnResume:
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtMerapi_Interior_LTenshi_EventScript_TryRemoveLTenshi
	end
	
MtMerapi_Interior_LTenshi_EventScript_TryRemoveLTenshi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject LOCALID_LAST_WORD_TENSHI
	return
	
MtMerapi_Interior_LTenshi_End_OnTransition:
	call_if_unset FLAG_DEFEATED_L_TENSHI, MtMerapi_Interior_LTenshi_EventScript_ShowLTenshi
	end
	
MtMerapi_Interior_LTenshi_EventScript_ShowLTenshi::
	clearflag FLAG_HIDE_L_TENSHI
	setvar VAR_TEMP_1, 1
	return
	
MtMerapi_Interior_LTenshi_EventScript_LTenshi::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, MtMerapi_Interior_LTenshi_CameraMovesUp
	waitmovement
	delay 25
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_RESULT, 2
	playfanfare MUS_AWAKEN_LEGEND
	playse SE_ORB
	special DoOrbEffect
	delay 120
	applymovement LOCALID_CAMERA, MtMerapi_Interior_LTenshi_CameraMovesDown
	applymovement LOCALID_LAST_WORD_TENSHI, MtMerapi_Interior_LTenshi_Movement_LTenshiApproach
	waitmovement 0
	special RemoveCameraObject
	special FadeOutOrbEffect
	waitse
	playse MUS_DUMMY
	playmoncry SPECIES_LAST_WORD_TENSHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setvar VAR_LAST_TALKED, LOCALID_LAST_WORD_TENSHI
	setwildbattle SPECIES_LAST_WORD_TENSHI, 75
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	setvar VAR_TEMP_1, 0
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtMerapi_Interior_LTenshi_EventScript_DefeatedLTenshi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN,MtMerapi_Interior_LTenshi_EventScript_RanFromLTenshi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtMerapi_Interior_LTenshi_EventScript_RanFromLTenshi
	setflag FLAG_DEFEATED_L_TENSHI
	setflag FLAG_HIDE_MT_MERAPI_NPCS
	setflag FLAG_MT_MERAPI_SAVED
	setflag FLAG_SOUTHERN_PASS_BLOCKED
	clearflag FLAG_HIDE_YOGYAKARTA_NPCS
	clearflag FLAG_HIDE_AICHI_PRESENCE
	addvar VAR_DEFEAT_MT_MERAPI_STATUES, 1
	releaseall
	end
	
MtMerapi_Interior_LTenshi_EventScript_DefeatedLTenshi::
	setflag FLAG_DEFEATED_L_TENSHI
	setflag FLAG_HIDE_MT_MERAPI_NPCS
	setflag FLAG_MT_MERAPI_SAVED
	setflag FLAG_SOUTHERN_PASS_BLOCKED
	clearflag FLAG_HIDE_YOGYAKARTA_NPCS
	clearflag FLAG_HIDE_AICHI_PRESENCE
	addvar VAR_DEFEAT_MT_MERAPI_STATUES, 1
	goto Common_EventScript_RemoveStaticPokemon
	end
	
MtMerapi_Interior_LTenshi_EventScript_RanFromLTenshi::
	setvar VAR_0x8004, SPECIES_LAST_WORD_TENSHI
	goto Common_EventScript_LegendaryFlewAway
	end
	
MtMerapi_Interior_LTenshi_CameraMovesUp:
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	walk_slow_up
	step_end
	
MtMerapi_Interior_LTenshi_CameraMovesDown:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end
	
MtMerapi_Interior_LTenshi_Movement_LTenshiApproach:
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	walk_slow_down
	step_end
