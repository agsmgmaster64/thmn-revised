ScorchedSlab_B1F_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, ScorchedSlab_B1F_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, ScorchedSlab_B1F_OnTransition
	.byte 0

ScorchedSlab_B1F_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, ScorchedSlab_B1F_EventScript_TryRemoveElis
	end
	
ScorchedSlab_B1F_EventScript_TryRemoveElis::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return
	
ScorchedSlab_B1F_OnTransition::
	call_if_unset FLAG_DEFEATED_ELIS, ScorchedSlab_B1F_EventScript_ShowElis
	end
	
ScorchedSlab_B1F_EventScript_ShowElis::
	clearflag FLAG_HIDE_ELIS
	return
	
ScorchedSlab_B1F_EventScript_Elis::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_ELIS, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_ELIS, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, ScorchedSlab_B1F_EventScript_DefeatedElis
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, ScorchedSlab_B1F_EventScript_RanFromElis
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, ScorchedSlab_B1F_EventScript_RanFromElis
	setflag FLAG_DEFEATED_ELIS
	release
	end
	
ScorchedSlab_B1F_EventScript_DefeatedElis::
	setflag FLAG_DEFEATED_ELIS
	goto Common_EventScript_RemoveStaticPokemon
	end
	
ScorchedSlab_B1F_EventScript_RanFromElis::
	setvar VAR_0x8004, SPECIES_ELIS
	goto Common_EventScript_LegendaryFlewAway
	end
