Yogyakarta_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Yogyakarta_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Yogyakarta_OnTransition
	.byte 0
	
Yogyakarta_OnLoad:
	call_if_eq VAR_JAVA_GEMS_OBTAINED, 7, Yogyakarta_EventScript_ShowPrismCave
	end
	
Yogyakarta_OnTransition:
	setflag FLAG_VISITED_YOGYAKARTA
	call_if_set FLAG_MT_MERAPI_SAVED, Yogyakarta_EventScript_CalmWeather
	end

Yogyakarta_EventScript_CitySign::
	msgbox Yogyakarta_Text_CitySign, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_AichiHouse::
	msgbox Yogyakarta_Text_AichiHouse, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_OldmanSugiho::
	msgbox Yogyakarta_Text_OldmanSugiho, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_House1::
	msgbox Yogyakarta_Text_House1, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_House2::
	msgbox Yogyakarta_Text_House2, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_ShowPrismCave::
	setmetatile 7, 6, METATILE_General_RockWall_GrassBase_LeftCornerUp, TRUE
	setmetatile 7, 7, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 8, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 9, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 10, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 11, METATILE_General_RockWall_GrassBase_LeftCornerDown, TRUE
	setmetatile 8, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 8, 7, METATILE_General_RockWall_RockBase_LeftCornerUp, TRUE
	setmetatile 8, 8, METATILE_General_RockWall_RockBase_LeftWall, TRUE
	setmetatile 8, 9, METATILE_General_RockWall_RockBase_LeftWall, TRUE
	setmetatile 8, 10, METATILE_General_RockWall_RockBase_LeftCornerDown, TRUE
	setmetatile 8, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 9, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 9, 7, METATILE_General_RockWall_RockBase_NorthCliff, TRUE
	setmetatile 9, 8, METATILE_General_RockWall_Ground, TRUE
	setmetatile 9, 9, METATILE_General_RockWall_Ground, TRUE
	setmetatile 9, 10, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 9, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 10, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 10, 7, METATILE_General_RockWall_RockBase_NorthCliff, TRUE
	setmetatile 10, 8, METATILE_General_RockWall_Ground, TRUE
	setmetatile 10, 9, METATILE_General_RockWall_Ground, TRUE
	setmetatile 10, 10, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 10, 11, METATILE_General_CaveEntrance_Bottom, FALSE
	setmetatile 11, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 11, 7, METATILE_General_RockWall_RockBase_NorthCliff, TRUE
	setmetatile 11, 8, METATILE_General_RockWall_Ground, TRUE
	setmetatile 11, 9, METATILE_General_RockWall_Ground, TRUE
	setmetatile 11, 10, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 11, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 12, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 12, 7, METATILE_General_RockWall_RockBase_RightCornerUp, TRUE
	setmetatile 12, 8, METATILE_General_RockWall_RockBase_RightWall, TRUE
	setmetatile 12, 9, METATILE_General_RockWall_RockBase_RightWall, TRUE
	setmetatile 12, 10, METATILE_General_RockWall_RockBase_RightCornerDown, TRUE
	setmetatile 12, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 13, 6, METATILE_General_RockWall_GrassBase_RightCornerUp, TRUE
	setmetatile 13, 7, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 8, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 9, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 10, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 11, METATILE_General_RockWall_GrassBase_RightCornerDown, TRUE
	return
	
Yogyakarta_EventScript_CalmWeather::
	setweather WEATHER_NONE
	doweather
	return
	
Yogyakarta_Text_CitySign:
	.string "Yogyakarta\p"
	.string "A peaceful village where\n"
	.string "people and Bonéka thrive.$"
	
Yogyakarta_Text_AichiHouse:
	.string "Aichi and Yukai's home\n"
	.string "Placeholder for JP text$"
	
Yogyakarta_Text_OldmanSugiho:
	.string "Oldman Sugiho\n"
	.string "The World Merchant\p"
	.string "Buy all your needs here!$"
	
Yogyakarta_Text_House1:
	.string "Base Camp$"
	
Yogyakarta_Text_House2:
	.string "Eatherna & Sheffyne's house$"
