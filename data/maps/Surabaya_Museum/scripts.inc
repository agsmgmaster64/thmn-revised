Surabaya_Museum_MapScripts::
	.byte 0

SurabayaMuseum_EventScript_SignOne::
	msgbox SurabayaMuseum_Text_SignOne, MSGBOX_SIGN
	end
	
SurabayaMuseum_EventScript_SignTwo::
	msgbox SurabayaMuseum_Text_SignTwo, MSGBOX_SIGN
	end
	
SurabayaMuseum_EventScript_SignThree::
	msgbox SurabayaMuseum_Text_SignThree, MSGBOX_SIGN
	end
	
SurabayaMuseum_EventScript_Receptionist::
	msgbox SurabayaMuseum_Text_Receptionist, MSGBOX_NPC
	end
	
SurabayaMuseum_EventScript_OldMan::
	msgbox SurabayaMuseum_Text_OldMan, MSGBOX_NPC
	end
	
SurabayaMuseum_EventScript_Child::
	msgbox SurabayaMuseum_Text_Child, MSGBOX_NPC
	end
	
SurabayaMuseum_Text_Child:
	.string "These huge slabs are so weird!\p"
	.string "I hear they tell of a great\n"
	.string "treasure!$"
	
SurabayaMuseum_Text_OldMan:
	.string "It would seem the text on these\n"
	.string "slabs are derived from the\l"
	.string "ancient Javanese language.$"
	
SurabayaMuseum_Text_Receptionist:
	.string "Welcome to the Surabaya Museum.\p"
	.string "Here, you can view ancient slabs\n"
	.string "that were recovered from the\l"
	.string "Ancient Pyramid.$"
	
SurabayaMuseum_Text_SignOne:
	.string "There is text on the slab.\n"
	.string "It reads…\p"
	.string "“Sinten kemawon ingkang nggadahi\n"
	.string "7 permata ing tangane, dheweke\l"
	.string "bakalan saget nemokaken guo ajaib.”\p"
	.string "… … … … …\p"
	.string "A translation provided below reads…\p"
	.string "“A person who possesses 7 gems,\n"
	.string "he or she would find a magical cave.”$"
	
SurabayaMuseum_Text_SignTwo:
	.string "There is text on the slab.\n"
	.string "It reads…\p"
	.string "“Guo ajiab punika lokasinipun wonten\n"
	.string "ing Ngayogyakarta Hadiningrat.”\p"
	.string "… … … … …\p"
	.string "A translation provided below reads…\p"
	.string "“That magical cave is located in\n"
	.string "Ngayogyakarta Hadiningrat.”$"
	
SurabayaMuseum_Text_SignThree:
	.string "There is text on the slab.\n"
	.string "It reads…\p"
	.string "“Ing guo ajaib punika, panjenenganipun\n"
	.string "bakal ketemu marang Flan.”\p"
	.string "… … … … …\p"
	.string "A translation provided below reads…\p"
	.string "“In that magical cave, you will\n"
	.string "meet with Flan.”$"
