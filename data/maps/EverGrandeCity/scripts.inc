EverGrandeCity_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, EverGrandeCity_OnTransition
	.byte 0

EverGrandeCity_OnTransition:
	call_if_set FLAG_SYS_WEATHER_CTRL, Common_EventScript_SetAbnormalWeather
	call Common_EventScript_SetupRivalGfxId
	end

EverGrandeCity_EventScript_VictoryRoadSign::
	msgbox EverGrandeCity_Text_EnteringVictoryRoad, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_CitySign::
	msgbox EverGrandeCity_Text_CitySign, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_PokemonLeagueSign::
	msgbox EverGrandeCity_Text_EnteringPokemonLeague, MSGBOX_SIGN
	end

EverGrandeCity_EventScript_SetVisitedEverGrande::
	setflag FLAG_VISITED_EVER_GRANDE_CITY
	setvar VAR_TEMP_1, 1
	end
	
EverGrandeCity_EventScript_Rival::
	lock
	faceplayer
	checkplayergender
	goto_if_eq VAR_RESULT, MALE, EverGrandeCity_EventScript_Maribel
	goto_if_eq VAR_RESULT, FEMALE, EverGrandeCity_EventScript_Renko
	end
	
EverGrandeCity_EventScript_Maribel::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_MaribelAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_MaribelAskToBattle
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_DeclineMaribelBattle
	msgbox EverGrandeCity_Text_MaribelWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, EverGrandeCity_EventScript_BattleMaribelTreecko
	case 1, EverGrandeCity_EventScript_BattleMaribelTorchic
	case 2, EverGrandeCity_EventScript_BattleMaribelMudkip
	end

EverGrandeCity_EventScript_MaribelAskToBattle::
	msgbox EverGrandeCity_Text_MaribelVictoryLetsBattle, MSGBOX_YESNO
	return
	
EverGrandeCity_EventScript_MaribelAskToBattleAgain::
	msgbox EverGrandeCity_Text_MaribelBattleMe, MSGBOX_YESNO
	return
	
EverGrandeCity_EventScript_DeclineMaribelBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE
	msgbox EverGrandeCity_Text_MaribelNeedToPrepare, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end
	
EverGrandeCity_EventScript_BattleMaribelTreecko::
	trainerbattle_no_intro TRAINER_MARIBEL_EVER_GRANDE_TREECKO, EverGrandeCity_Text_MaribelDefeat
	goto EverGrandeCity_EventScript_DefeatedMaribel
	end

EverGrandeCity_EventScript_BattleMaribelTorchic::
	trainerbattle_no_intro TRAINER_MARIBEL_EVER_GRANDE_TORCHIC, EverGrandeCity_Text_MaribelDefeat
	goto EverGrandeCity_EventScript_DefeatedMaribel
	end

EverGrandeCity_EventScript_BattleMaribelMudkip::
	trainerbattle_no_intro TRAINER_MARIBEL_EVER_GRANDE_MUDKIP, EverGrandeCity_Text_MaribelDefeat
	goto EverGrandeCity_EventScript_DefeatedMaribel
	end
	
EverGrandeCity_EventScript_DefeatedMaribel::
	msgbox EverGrandeCity_Text_MaribelGiveSurfboard, MSGBOX_DEFAULT
	giveitem ITEM_SURFBOARD_PLUS
	msgbox EverGrandeCity_Text_MaribelExplainsSurfboard, MSGBOX_DEFAULT
	msgbox EverGrandeCity_Text_MaribelGoodLuck, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	goto EverGrandeCity_EventScript_RivalFlyAway
	end
	
EverGrandeCity_EventScript_Renko::
	playbgm MUS_ENCOUNTER_BRENDAN, TRUE
	call_if_set FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_RenkoAskToBattleAgain
	call_if_unset FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE, EverGrandeCity_EventScript_RenkoAskToBattle
	goto_if_eq VAR_RESULT, NO, EverGrandeCity_EventScript_DeclineRenkoBattle
	msgbox EverGrandeCity_Text_RenkoWontBeBeaten, MSGBOX_DEFAULT
	switch VAR_STARTER_MON
	case 0, EverGrandeCity_EventScript_BattleRenkoTreecko
	case 1, EverGrandeCity_EventScript_BattleRenkoTorchic
	case 2, EverGrandeCity_EventScript_BattleRenkoMudkip
	end
	
EverGrandeCity_EventScript_RenkoAskToBattleAgain::
	msgbox EverGrandeCity_Text_RenkoBattleMe, MSGBOX_YESNO
	return
	
EverGrandeCity_EventScript_RenkoAskToBattle::
	msgbox EverGrandeCity_Text_RenkoVictoryLetsBattle, MSGBOX_YESNO
	return
	
EverGrandeCity_EventScript_DeclineRenkoBattle::
	setflag FLAG_DECLINED_RIVAL_BATTLE_EVERGRANDE
	msgbox EverGrandeCity_Text_RenkoNoConfidence, MSGBOX_DEFAULT
	savebgm MUS_DUMMY
	fadedefaultbgm
	release
	end
	
EverGrandeCity_EventScript_BattleRenkoTreecko::
	trainerbattle_no_intro TRAINER_RENKO_EVER_GRANDE_TREECKO, EverGrandeCity_Text_RenkoDefeat
	goto EverGrandeCity_EventScript_DefeatedRenko
	end

EverGrandeCity_EventScript_BattleRenkoTorchic::
	trainerbattle_no_intro TRAINER_RENKO_EVER_GRANDE_TORCHIC, EverGrandeCity_Text_RenkoDefeat
	goto EverGrandeCity_EventScript_DefeatedRenko
	end

EverGrandeCity_EventScript_BattleRenkoMudkip::
	trainerbattle_no_intro TRAINER_RENKO_EVER_GRANDE_MUDKIP, EverGrandeCity_Text_RenkoDefeat
	goto EverGrandeCity_EventScript_DefeatedRenko
	end
	
EverGrandeCity_EventScript_DefeatedRenko::
	msgbox EverGrandeCity_Text_RenkoGiveSurfboard, MSGBOX_DEFAULT
	giveitem ITEM_SURFBOARD_PLUS
	msgbox EverGrandeCity_Text_RenkoExplainsSurfboard, MSGBOX_DEFAULT
	msgbox EverGrandeCity_Text_RenkoShowThemWhoRules, MSGBOX_DEFAULT
	setvar VAR_RESULT, FALSE
	goto EverGrandeCity_EventScript_RivalFlyAway
	end
	
EverGrandeCity_EventScript_RivalFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterDown
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_HIDE_EVER_GRANDE_RIVAL 
	release
	end

EverGrandeCity_Text_EnteringVictoryRoad:
	.string "Entering Victory Road$"

EverGrandeCity_Text_EnteringPokemonLeague:
	.string "Entering Hoenn League\n"
	.string "Center Gate$"

EverGrandeCity_Text_CitySign:
	.string "Ever Grande Isle\p"
	.string "“The paradise of flowers, the sea,\n"
	.string "and Puppets.”$"

EverGrandeCity_Text_MaribelVictoryLetsBattle:
	.string "Maribel: Hey, {PLAYER}{KUN}!\n"
	.string "Took you long enough to get here!\p"
	.string "I thought you'd beat me here for sure…\p"
	.string "Me? Well, I got all the badges!\n"
	.string "I'll be going to the League soon.\p"
	.string "Of course, we both know there can\n"
	.string "only be one Champion…\p"
	.string "Well, we'd have to battle anyway,\n"
	.string "so why not go for it now?$"
	
EverGrandeCity_Text_MaribelDefeat:
	.string "All of our planning…\p"
	.string "Well done! The League won't stand\n"
	.string "any sort of chance!$"
	
EverGrandeCity_Text_MaribelNeedToPrepare:
	.string "Oh, need to prepare?\n"
	.string "Sounds good. I'll be waiting!$"
	
EverGrandeCity_Text_MaribelBattleMe:
	.string "Maribel: Oh, hey, {PLAYER}{KUN}!\n"
	.string "Are you ready now?$"

EverGrandeCity_Text_MaribelWontBeBeaten:
	.string "Maribel: Brace yourself, {PLAYER}{KUN}!\n"
	.string "I'm extra serious this time!$"
	
EverGrandeCity_Text_MaribelGiveSurfboard:
	.string "Maribel: You did really good, {PLAYER}{KUN}.\n"
	.string "You still have a trip ahead of you,\l"
	.string "so please, take this…$"
	
EverGrandeCity_Text_MaribelExplainsSurfboard:
	.string "Maribel: It's an upgrade to your old\n"
	.string "surfboard.\p"
	.string "It lets you climb up waterfalls, like\n"
	.string "the one that lead you here.\p"
	.string "It will probably help you out\n"
	.string "in Victory Road…$"
	
EverGrandeCity_Text_MaribelGoodLuck:
	.string "Maribel: No, no no no!\n"
	.string "I'm not upset, don't get me wrong!\p"
	.string "Since you beat me, I doubt that I\n"
	.string "could have handled the Elite Four.\p"
	.string "But enough about me, the spotlight's\n"
	.string "all on you now.\p"
	.string "Well, good luck!$"

EverGrandeCity_Text_RenkoBattleMe:
	.string "Renko: Yo! {PLAYER}{KUN}!\n"
	.string "You ready to battle yet?$"

EverGrandeCity_Text_RenkoVictoryLetsBattle:
	.string "Renko: {PLAYER}{KUN}!\n"
	.string "What kept you?\p"
	.string "Huh? Saving the world?\n"
	.string "Okay, I'll buy that.\p"
	.string "Well, while you were doing that, I\n"
	.string "got all the badges!\p"
	.string "Though… what you did kind of\n"
	.string "dwarfs that, huh.\p"
	.string "Well, hey, while we're here, want\n"
	.string "to have a battle?\p"
	.string "After all, there can only be one\n"
	.string "Champion.$"
	
EverGrandeCity_Text_RenkoNoConfidence:
	.string "Renko: Oh, not ready yet?\n"
	.string "All right, take your time.$"
	
EverGrandeCity_Text_RenkoWontBeBeaten:
	.string "Renko: All right. I won't hold\n"
	.string "back…\p"
	.string "I expect the same from you!$"
	
EverGrandeCity_Text_RenkoDefeat:
	.string "Huh…\p"
	.string "Yeah, you got this.$"
	
EverGrandeCity_Text_RenkoGiveSurfboard:
	.string "Renko: Good work, {PLAYER}{KUN}.\n"
	.string "You trained your Puppets well, yeah.\p"
	.string "Here, take this.$"
	
EverGrandeCity_Text_RenkoExplainsSurfboard:
	.string "Renko: You like it? It's a better\n"
	.string "surfboard than you had.\p"
	.string "It lets you climb up waterfalls\n"
	.string "like the one behind you!\p"
	.string "I'm sure it'll help you out\n"
	.string "in places like Victory Road.$"

EverGrandeCity_Text_RenkoShowThemWhoRules:
	.string "Renko: It's all you from here on.\l"
	.string "Don't you dare go losing now!\p"
	.string "Well, see you!\n"
	.string "Go on, show them who rules!$"
