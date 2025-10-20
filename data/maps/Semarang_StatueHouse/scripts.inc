Semarang_StatueHouse_MapScripts::
	.byte 0

SemarangStatueHouse_EventScript_Statue::
	msgbox SemarangStatueHouse_Text_Statue, MSGBOX_NPC
	end

SemarangStatueHouse_EventScript_OldMan::
	msgbox SemarangStatueHouse_Text_OldMan, MSGBOX_NPC
	end
	
SemarangStatueHouse_EventScript_OldManDaughter::
	msgbox SemarangStatueHouse_Text_OldManDaughter, MSGBOX_NPC
	end
	
SemarangStatueHouse_Text_OldManDaughter:
	.string "My father recently found a\n"
	.string "discarded LUtsuho statue in the\l"
	.string "North Plain.\p"
	.string "He's trying to restore it.$"
	
SemarangStatueHouse_Text_Statue:
	.string "An old, worn statue of an LUtsuho\n"
	.string "with an expression of maniacal\l"
	.string "glee.\p"
	.string "Parts of the statue seem to be\n"
	.string "in the process of being restored.$"
	
SemarangStatueHouse_Text_OldMan:
	.string "Ho! This statue needs some polish,\n"
	.string "but soon it will be good as new!\p"
	.string "Soon, I will control the sun too…\n"
	.string "Fufufufu…$"
