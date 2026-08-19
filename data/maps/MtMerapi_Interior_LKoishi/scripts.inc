MtMerapi_Interior_LKoishi_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtMerapi_InteriorLKoishi_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtMerapi_InteriorLKoishi_OnTransition
	.byte 0

MtMerapi_InteriorLKoishi_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, MtMerapi_InteriorLKoishi_EventScript_TryRemoveLKoishi
	end
	
MtMerapi_InteriorLKoishi_EventScript_TryRemoveLKoishi::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return
	
MtMerapi_InteriorLKoishi_OnTransition::
	call_if_unset FLAG_DEFEATED_L_KOISHI, MtMerapi_InteriorLKoishi_EventScript_ShowLKoishi
	end
	
MtMerapi_InteriorLKoishi_EventScript_ShowLKoishi::
	clearflag FLAG_HIDE_L_KOISHI
	return

MtMerapi_InteriorLKoishi_EventScript_LKoishi::	
	lock
	faceplayer
	msgbox MtMerapi_InteriorLKoishi_Text_ThisStatueMight, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox MtMerapi_InteriorLKoishi_Text_YouHoldAloft, MSGBOX_DEFAULT
	closemessage
	delay 20
	call_if_eq VAR_FACING, DIR_WEST, MtMerapi_InteriorLKoishi_EventScript_PlayerFaceWest
	call_if_eq VAR_FACING, DIR_EAST, MtMerapi_InteriorLKoishi_EventScript_PlayerFaceEast
	call_if_eq VAR_FACING, DIR_SOUTH, MtMerapi_InteriorLKoishi_EventScript_PlayerFaceSouth
	call_if_eq VAR_FACING, DIR_NORTH, MtMerapi_InteriorLKoishi_EventScript_PlayerFaceNorth
	delay 20
	msgbox MtMerapi_InteriorLKoishi_Text_TheRubyIsResponding, MSGBOX_DEFAULT
	waitmovement
	closemessage
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
	playmoncry SPECIES_LAST_WORD_KOISHI, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	msgbox MtMerapi_InteriorLKoishi_Text_TheStatueIs, MSGBOX_DEFAULT
	closemessage
	setwildbattle SPECIES_LAST_WORD_KOISHI, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, MtMerapi_InteriorLKoishi_EventScript_DefeatedLKoishi
	goto_if_eq VAR_RESULT, B_OUTCOME_CAUGHT, MtMerapi_InteriorLKoishi_EventScript_DefeatedLKoishi
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, MtMerapi_InteriorLKoishi_EventScript_RanFromLKoishi
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, MtMerapi_InteriorLKoishi_EventScript_RanFromLKoishi
	setflag FLAG_DEFEATED_L_KOISHI
	release
	end
	
MtMerapi_InteriorLKoishi_EventScript_PlayerFaceNorth::
	playse SE_M_DETECT
	dofieldeffectsparkle 9, 10, 0
	waitfieldeffect FLDEFF_SPARKLE
	return
	
MtMerapi_InteriorLKoishi_EventScript_PlayerFaceSouth::
	playse SE_M_DETECT
	dofieldeffectsparkle 9, 8, 0
	waitfieldeffect FLDEFF_SPARKLE
	return
	
MtMerapi_InteriorLKoishi_EventScript_PlayerFaceEast::
	playse SE_M_DETECT
	dofieldeffectsparkle 8, 9, 0
	waitfieldeffect FLDEFF_SPARKLE
	return
	
MtMerapi_InteriorLKoishi_EventScript_PlayerFaceWest::
	playse SE_M_DETECT
	dofieldeffectsparkle 10, 9, 0
	waitfieldeffect FLDEFF_SPARKLE
	return
	
MtMerapi_InteriorLKoishi_EventScript_DefeatedLKoishi::
	setflag FLAG_DEFEATED_L_KOISHI
	addvar VAR_DEFEAT_MT_MERAPI_STATUES, 1
	compare VAR_DEFEAT_MT_MERAPI_STATUES, 4
	goto_if_ge MtMerapi_InteriorLKoishi_EventScript_CaveOpen
	compare VAR_DEFEAT_MT_MERAPI_STATUES, 3
	goto_if_le MtMerapi_InteriorLKoishi_EventScript_StatueBroken
	end
	
MtMerapi_InteriorLKoishi_EventScript_StatueBroken::
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
	msgbox MtMerapi_InteriorLKoishi_Text_TheTremorsContinue, MSGBOX_DEFAULT
	closemessage
	goto Common_EventScript_RemoveStaticPokemon
	end
	
MtMerapi_InteriorLKoishi_EventScript_CaveOpen::
	delay 25
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	msgbox MtMerapi_InteriorLKoishi_Text_TheWayOpened, MSGBOX_DEFAULT
	closemessage
	goto Common_EventScript_RemoveStaticPokemon
	end

MtMerapi_InteriorLKoishi_EventScript_RanFromLKoishi::
	setvar VAR_0x8004, SPECIES_LAST_WORD_KOISHI
	goto Common_EventScript_LegendaryFlewAway
	end
	
MtMerapi_InteriorLKoishi_Text_TheRubyIsResponding:
	.string "Oh! The Ruby is responding!$"
	
MtMerapi_InteriorLKoishi_Text_TheStatueIs:
	.string "A Last Word Koishi emerges from\n"
	.string "the statue!$"
	
MtMerapi_InteriorLKoishi_Text_TheTremorsContinue:
	.string "The tremors continue once more.$"

MtMerapi_InteriorLKoishi_Text_ThisStatueMight:
	.string "This statue might have something to\n"
	.string "do with solving this disaster.\p"
	.string "The Ruby in your bag feels strange.$"
	
MtMerapi_InteriorLKoishi_Text_YouHoldAloft:
	.string "{PLAYER}{KUN} holds out the Ruby!$"
	
MtMerapi_InteriorLKoishi_Text_TheWayOpened:
	.string "The tremors intensified!\p"
	.string "It sounds like something collapsed\n"
	.string "near the top of the mountain!$"
