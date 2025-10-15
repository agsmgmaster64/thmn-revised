Semarang_MapScripts::
	.byte 0

Semarang_EventScript_CitySign::
	msgbox Semarang_Text_CitySign, MSGBOX_SIGN
	end

Semarang_EventScript_RahmaHouseSign::
	msgbox Semarang_Text_RahmaSign, MSGBOX_SIGN
	end

Semarang_Text_CitySign:
	.string "Semarang\n"
	.string "Low-growth rate village.$"

Semarang_Text_RahmaSign:
	.string "Rahma's House$"
