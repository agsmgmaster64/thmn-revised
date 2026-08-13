CaveofWisdom_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, CaveofWisdom_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, CaveofWisdom_B1F_OnTransition
	.byte 0

CaveofWisdom_B1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, CaveofWisdom_B1F_EventScript_TryRemoveMima
	end
	
CaveofWisdom_B1F_EventScript_TryRemoveMima::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return
	
CaveofWisdom_B1F_OnTransition::
	call_if_unset FLAG_DEFEATED_MIMA, CaveofWisdom_B1F_EventScript_ShowMima
	end
	
CaveofWisdom_B1F_EventScript_ShowMima::
	clearflag FLAG_HIDE_MIMA
	return
	
CaveofWisdomB1F_EventScript_Mima::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_MIMA, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_MIMA, 70
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, CaveofWisdomB1F_EventScript_DefeatedMima
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, CaveofWisdomB1F_EventScript_RanFromMima
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, CaveofWisdomB1F_EventScript_RanFromMima
	setflag FLAG_DEFEATED_MIMA
	release
	end
	
CaveofWisdomB1F_EventScript_DefeatedMima::
	setflag FLAG_DEFEATED_MIMA
	goto Common_EventScript_RemoveStaticPokemon
	end
	
CaveofWisdomB1F_EventScript_RanFromMima::
	setvar VAR_0x8004, SPECIES_MIMA
	goto Common_EventScript_LegendaryFlewAway
	end