Semarang_TewiHouse_MapScripts::
	.byte 0

SemarangTewiHouse_EventScript_Father::
	msgbox SemarangTewiHouse_Text_Father, MSGBOX_NPC
	end
	
SemarangTewiHouse_EventScript_Mother::
	msgbox SemarangTewiHouse_Text_Mother, MSGBOX_NPC
	end
	
SemarangTewiHouse_EventScript_Child::
	msgbox SemarangTewiHouse_Text_Child, MSGBOX_NPC
	end
	
SemarangTewiHouse_EventScript_Tewi::
	msgbox SemarangTewiHouse_Text_Tewi, MSGBOX_NPC
	end

SemarangTewiHouse_Text_Father:
	.string "Our child was happy when we got\n"
	.string "her that Tewi for her birthday.$"
	
SemarangTewiHouse_Text_Mother:
	.string "Cute as it may be, that Tewi's\n"
	.string "been quite the troublemaker!$"
	
SemarangTewiHouse_Text_Child:
	.string "Gyaaa… Tewi I love you…$"
	
SemarangTewiHouse_Text_Tewi:
	.string "Tewi: Gyaaaah!$"
