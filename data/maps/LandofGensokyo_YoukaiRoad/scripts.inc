LandofGensokyo_YoukaiRoad_MapScripts::
	.byte 0

LandofGensokyoYoukaiRoad_EventScript_YoukaiRoadSign::
	msgbox LandofGensokyoYoukaiRoad_Text_YoukaiRoadSign, MSGBOX_SIGN
	end
	
LandofGensokyoYoukaiRoad_EventScript_HakureiSign::
	msgbox LandofGensokyoYoukaiRoad_Text_HakureiSign, MSGBOX_SIGN
	end
	
LandofGensokyoYoukaiRoad_EventScript_OnsenSign::
	msgbox LandofGensokyoYoukaiRoad_Text_OnsenSign, MSGBOX_SIGN
	end
	
LandofGensokyoYoukaiRoad_EventScript_DirectionSign::
	msgbox LandofGensokyoYoukaiRoad_Text_DirectionSign, MSGBOX_SIGN
	end
	
LandofGensokyoYoukaiRoad_EventScript_HumanVillageSign::
	msgbox LandofGensokyoYoukaiRoad_Text_HumanVillageSign, MSGBOX_SIGN
	end
	
LandofGensokyoYoukaiRoad_Text_YoukaiRoadSign:
	.string "Here is Youkai Road\n"
	.string "{RIGHT_ARROW} Hakurei Shrine$"
	
LandofGensokyoYoukaiRoad_Text_HakureiSign:
	.string "Walk through the mountain\n"
	.string "and you will be at Hakurei Shrine.$"
	
LandofGensokyoYoukaiRoad_Text_OnsenSign:
	.string "Hotspring Onsen\n"
	.string "Rest while you are tired.$"
	
LandofGensokyoYoukaiRoad_Text_DirectionSign:
	.string "Here is Youkai Road\p"
	.string "{LEFT_ARROW} Human Village\n"
	.string "{RIGHT_ARROW} Hakurei Shrine$"
	
LandofGensokyoYoukaiRoad_Text_HumanVillageSign:
	.string "Here is Youkai Road\n"
	.string "{LEFT_ARROW} Human Village$"
