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
	
NorthPlain_PojokCliffHintKid:
	.string "Have you heard?\p"
	.string "There's a rumor going around about\n"
	.string "some strange flower field beyond\l"
	.string "Pojok Cliff.\p"
	.string "They say you need a special stone\n"
	.string "to even see that flower field.\p"
	.string "But hey, you can't believe\n"
	.string "everything you hear.$"
