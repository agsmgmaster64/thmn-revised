Surakarta_MapScripts::
	.byte 0

Surakarta_EventScript_ExhaustedJogger::
	msgbox Surakarta_Text_ExhaustedJogger, MSGBOX_NPC
	end

Surakarta_EventScript_PojokCliffGirl::
	msgbox Surakarta_Text_PojokCliffGirl, MSGBOX_NPC
	end

Surakarta_EventScript_AanHouse::
	msgbox Surakarta_Text_AanHouse, MSGBOX_SIGN
	end

Surakarta_EventScript_CitySign::
	msgbox Surakarta_Text_CitySign, MSGBOX_SIGN
	end

Surakarta_EventScript_MtAuroraSign::
	msgbox Surakarta_Text_MtAuroraSign, MSGBOX_SIGN
	end

Surakarta_Text_ExhaustedJogger:
	.string "I'm… very… exhausted…\p"
	.string "I keep getting jumped by so many\n"
	.string "Bonéka… on that path…\p"
	.string "If only my team were stronger…\n"
	.string "and I had lots of Repels…\p"
	.string "Gotta get rest…$"

Surakarta_Text_PojokCliffGirl:
	.string "Did you visit Pojok Cliff?\n"
	.string "Did you see the strange stone?\p"
	.string "It said “The Dream Stone”.$"

Surakarta_Text_AanHouse:
	.string "Aan's House$"

Surakarta_Text_CitySign:
	.string "Surakarta\n"
	.string "“The former royal capital of Java.”$"

Surakarta_Text_MtAuroraSign:
	.string "Mt. Aurora Entrance Gate.$"
