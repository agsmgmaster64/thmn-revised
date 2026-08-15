MtMerapi_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtMerapi_Exterior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtMerapi_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtMerapi_Exterior_OnLoad
	.byte 0
	
MtMerapi_Exterior_OnResume:
	setstepcallback STEP_CB_ASH
	end
	
MtMerapi_Exterior_OnLoad:
	call_if_eq VAR_DEFEAT_MT_MERAPI_STATUES, 4, MtMerapi_Exterior_EventScript_ShowCaveEntrance
	end

MtMerapi_Exterior_OnTransition:
	call_if_set FLAG_MT_MERAPI_SAVED, MtMerapi_Exterior_EventScript_CalmWeather
	end

MtMerapi_Exterior_EventScript_CalmWeather::
	setweather WEATHER_NONE
	doweather
	return
	
MtMerapi_Exterior_EventScript_ShowCaveEntrance::
	setmetatile 24, 8, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 24, 9, METATILE_General_CaveEntrance_Bottom, FALSE
	return
