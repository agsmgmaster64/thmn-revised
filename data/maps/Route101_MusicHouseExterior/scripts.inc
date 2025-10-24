Route101_MusicHouseExterior_MapScripts::
	.byte 0

Route101MusicHouseExterior_EventScript_SignOne::
	msgbox Route101MusicHouseExterior_Text_SignOne, MSGBOX_SIGN
	end
	
Route101MusicHouseExterior_EventScript_WanderingGuy::
	msgbox Route101MusicHouseExterior_Text_WanderingGuy, MSGBOX_NPC
	end

Route101MusicHouseExterior_Text_SignOne:
	.string "{COLOR RED}{SHADOW LIGHT_RED}Music House\n"
	.string "{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}Great soundtracks galore!$"
	
Route101MusicHouseExterior_Text_WanderingGuy:
	.string "See that huge building there?\p"
	.string "It's crammed full of music boxes\n"
	.string "with cool soundtracks!$"
