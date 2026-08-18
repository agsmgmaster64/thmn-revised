NorthPlain_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, NorthPlain_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, NorthPlain_OnTransition
	.byte 0
	
NorthPlain_OnLoad:
	call_if_set FLAG_VISITED_SURABAYA, NorthPlain_EventScript_MakeShortcut
	end
	
NorthPlain_OnTransition:
	call_if_set FLAG_MT_MERAPI_SAVED, NorthPlain_EventScript_CalmWeather
	end

NorthPlain_EventScript_PojokCliffHintKid::
	msgbox NorthPlain_PojokCliffHintKid, MSGBOX_NPC
	end
	
NorthPlain_EventScript_CalmWeather::
	setweather WEATHER_NONE
	doweather
	return
	
NorthPlain_EventScript_MakeShortcut::
	setmetatile 14, 45, METATILE_General_TallGrass, FALSE
	setmetatile 15, 45, METATILE_General_TallGrass, FALSE
	setmetatile 14, 46, METATILE_General_SandPit_LeftCornerUp, FALSE
	setmetatile 15, 46, METATILE_General_SandPit_RightCornerUp, FALSE
	setmetatile 14, 47, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 47, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 48, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 48, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 49, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 49, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 50, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 50, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 51, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 51, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 52, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 52, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 53, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 53, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 54, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 54, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 55, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 55, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 56, METATILE_General_SandPit_Left, FALSE
	setmetatile 15, 56, METATILE_General_SandPit_Right, FALSE
	setmetatile 14, 57, METATILE_General_SandPit_LeftCornerDown, FALSE
	setmetatile 15, 57, METATILE_General_SandPit_RightCornerDown, FALSE
	return
	
NorthPlain_EventScript_Chaosuke::
	trainerbattle_single TRAINER_CHAOSUKE, NorthPlain_Text_ChaosukeIntro, NorthPlain_Text_ChaosukeDefeated
	msgbox NorthPlain_Text_ChaosukePostBattle, MSGBOX_AUTOCLOSE
	end
	
NorthPlain_EventScript_Misen::
	trainerbattle_single TRAINER_MISEN, NorthPlain_Text_MisenIntro, NorthPlain_Text_MisenDefeated
	msgbox NorthPlain_Text_MisenPostBattle, MSGBOX_AUTOCLOSE
	end
	
NorthPlain_EventScript_Huncson::
	trainerbattle_single TRAINER_HUNCSON, NorthPlain_Text_HuncsonIntro, NorthPlain_Text_HuncsonDefeated
	msgbox NorthPlain_Text_HuncsonPostBattle, MSGBOX_AUTOCLOSE
	end
	
NorthPlain_EventScript_Ravo::
	trainerbattle_single TRAINER_RAVO, NorthPlain_Text_RavoIntro, NorthPlain_Text_RavoDefeated
	msgbox NorthPlain_Text_RavoPostBattle, MSGBOX_AUTOCLOSE
	end
	
NorthPlain_EventScript_Alie::
	trainerbattle_single TRAINER_ALIE, NorthPlain_Text_AlieIntro, NorthPlain_Text_AlieDefeated
	msgbox NorthPlain_Text_AliePostBattle, MSGBOX_AUTOCLOSE
	end
	
NorthPlain_PojokCliffHintKid:
	.string "Have you heard?\p"
	.string "There's a rumor going around about\n"
	.string "some strange flower field beyond\l"
	.string "Pojok Cliff.\p"
	.string "They say you need a special stone\n"
	.string "to even see that flower field.\p"
	.string "But hey, you can't believe\n"
	.string "everything you hear.$"

NorthPlain_Text_ChaosukeIntro:
	.string "HEN… SHIN…$"
	
NorthPlain_Text_ChaosukeDefeated:
	.string "Over…$"
	
NorthPlain_Text_ChaosukePostBattle:
	.string "Losing the battle is not the\n"
	.string "end of everything…$"
	
NorthPlain_Text_MisenIntro:
	.string "Hi… {PLAYER}{KUN}…$"
	
NorthPlain_Text_MisenDefeated:
	.string "Oh… I lost…$"
	
NorthPlain_Text_MisenPostBattle:
	.string "I will always give\n"
	.string "Maion spirit…\p"
	.string "And always support him…$"
	
NorthPlain_Text_HuncsonIntro:
	.string "No pain no gain…$"

NorthPlain_Text_HuncsonDefeated:
	.string "What a fuzz…$"
	
NorthPlain_Text_HuncsonPostBattle:
	.string "Hmm… I am Global Mod in\n"
	.string "Animac Forum… and don't forget\l"
	.string "visit my personal {COLOR DARK_GRAY}bakayarou.org$"
	
NorthPlain_Text_RavoIntro:
	.string "Excel break mode…$"
	
NorthPlain_Text_RavoDefeated:
	.string "Mode limited…$"

NorthPlain_Text_RavoPostBattle:
	.string "Oh yes… don't call me\n"
	.string "Si Manis Jembatan Excol…$"
	
NorthPlain_Text_AlieIntro:
	.string "Sigh…$"
	
NorthPlain_Text_AlieDefeated:
	.string "… … …$"
	
NorthPlain_Text_AliePostBattle:
	.string "Even I have a lot of trouble, I'll\n"
	.string "always achieve my future…\l"
	.string "and I will never give up…$"
