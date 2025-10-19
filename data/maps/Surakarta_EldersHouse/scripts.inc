Surakarta_EldersHouse_MapScripts::
	.byte 0

SurakartaElderHouse_EventScript_OldMan::
	msgbox SurakartaElderHouse_Text_OldMan, MSGBOX_NPC
	end

SurakartaElderHouse_EventScript_OldWoman::
	msgbox SurakartaElderHouse_Text_OldWoman, MSGBOX_NPC
	end
	
SurakartaElderHouse_Text_OldMan:
	.string "I always wanted to be a\n"
	.string "Bonéka Professor.\p"
	.string "Life got in the way, though.$"

SurakartaElderHouse_Text_OldWoman:
	.string "Enjoying the old age…$"
