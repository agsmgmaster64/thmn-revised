Surabaya_Hospital_1F_MapScripts::
	.byte 0

SurabayaHospital1F_EventScript_LeftNurse::
	msgbox SurabayaHospital1F_Text_LeftNurse, MSGBOX_NPC
	end
	
SurabayaHospital1F_EventScript_RightNurse::
	msgbox SurabayaHospital1F_Text_RightNurse, MSGBOX_NPC
	end
	
SurabayaHospital1F_EventScript_Gentleman::
	msgbox SurabayaHospital1F_Text_Gentleman, MSGBOX_NPC
	end
	
SurabayaHospital1F_EventScript_Receptionist::
	msgbox SurabayaHospital1F_Text_Receptionist, MSGBOX_NPC
	end
	
SurabayaHospital1F_Text_Receptionist:
	.string "Welcome to the Java Hospital.\p"
	.string "… … … … …\p"
	.string "Wait… you're not sick?\p"
	.string "Ah, you must be here to meet with\n"
	.string "our director.\p"
	.string "If you wish to speak with him,\n"
	.string "please go up the stairway to the\l"
	.string "right and you'll be at his office.\p"
	.string "He might be busy, though.$"

	
SurabayaHospital1F_Text_Gentleman:
	.string "My daughter has been brought in\n"
	.string "for a severe illness.\p"
	.string "I'm just hoping she'll get\n"
	.string "cured of it soon.$"
	
SurabayaHospital1F_Text_RightNurse:
	.string "Welcome to the Java Hospital.\p"
	.string "Up here is Director Kamizawa's\n"
	.string "room.$"

SurabayaHospital1F_Text_LeftNurse:
	.string "The rooms beyond this point are\n"
	.string "for our patients who are in\l"
	.string "intensive care.\p"
	.string "I'm sorry, but I cannot allow you\n"
	.string "to pass through here.$"
