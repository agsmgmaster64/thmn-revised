NewMauville_VIVITRoom_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, NewMauville_VIVITRoom_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, NewMauville_VIVITRoom_OnTransition
	.byte 0
	
NewMauville_VIVITRoom_OnResume::
	call_if_set FLAG_SYS_CTRL_OBJ_DELETE, NewMauville_VIVITRoom_EventScript_TryRemoveVIVIT
	end
	
NewMauville_VIVITRoom_EventScript_TryRemoveVIVIT::
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_ne VAR_RESULT, B_OUTCOME_CAUGHT, Common_EventScript_NopReturn
	removeobject VAR_LAST_TALKED
	return
	
NewMauville_VIVITRoom_OnTransition::
	call_if_unset FLAG_DEFEATED_VIVIT, NewMauville_VIVITRoom_EventScript_ShowVIVIT
	end
	
NewMauville_VIVITRoom_EventScript_ShowVIVIT::
	clearflag FLAG_HIDE_VIVIT
	return
	
NewMauville_VIVITRoom_EventScript_VIVIT::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_VIVIT, CRY_MODE_ENCOUNTER
	delay 40
	waitmoncry
	setwildbattle SPECIES_VIVIT, 40
	setflag FLAG_SYS_CTRL_OBJ_DELETE
	special BattleSetup_StartLegendaryBattle
	clearflag FLAG_SYS_CTRL_OBJ_DELETE
	specialvar VAR_RESULT, GetBattleOutcome
	goto_if_eq VAR_RESULT, B_OUTCOME_WON, NewMauville_VIVITRoom_EventScript_DefeatedVIVIT
	goto_if_eq VAR_RESULT, B_OUTCOME_RAN, NewMauville_VIVITRoom_EventScript_RanFromVIVIT
	goto_if_eq VAR_RESULT, B_OUTCOME_PLAYER_TELEPORTED, NewMauville_VIVITRoom_EventScript_RanFromVIVIT
	setflag FLAG_DEFEATED_VIVIT
	release
	end
	
NewMauville_VIVITRoom_EventScript_DefeatedVIVIT::
	setflag FLAG_DEFEATED_VIVIT
	goto Common_EventScript_RemoveStaticPokemon
	end
	
NewMauville_VIVITRoom_EventScript_RanFromVIVIT::
	setvar VAR_0x8004, SPECIES_VIVIT
	goto Common_EventScript_LegendaryFlewAway
	end
