MtPyre_3F_MapScripts::
	.byte 0

MtPyre_3F_EventScript_William::
	trainerbattle_single TRAINER_WILLIAM, MtPyre_3F_Text_WilliamIntro, MtPyre_3F_Text_WilliamDefeat
	msgbox MtPyre_3F_Text_WilliamPostBattle, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_EventScript_Artemis::
	trainerbattle_single TRAINER_ARTEMIS_3, MtPyre_3F_Text_ArtemisIntro, MtPyre_3F_Text_ArtemisDefeat, AbandonedShip_Rooms2_1F_EventScript_ArtemisToHeal
	msgbox MtPyre_3F_Text_ArtemisPostBattle, MSGBOX_DEFAULT
	call MtPyre_3F_EventScript_ArtemisHeal
	msgbox MtPyre_3F_Text_ArtemisAnotherCheckup, MSGBOX_AUTOCLOSE
	end
	
MtPyre_3F_EventScript_ArtemisToHeal::
	msgbox MtPyre_3F_Text_ArtemisPostBattle, MSGBOX_DEFAULT
	call MtPyre_3F_EventScript_ArtemisHeal
	msgbox MtPyre_3F_Text_ArtemisAnotherCheckup, MSGBOX_DEFAULT
	release
	end
	
MtPyre_3F_EventScript_ArtemisHeal::
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

MtPyre_3F_EventScript_Gabrielle::
	trainerbattle_single TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleIntro, MtPyre_3F_Text_GabrielleDefeat, MtPyre_3F_EventScript_RegisterGabrielle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, MtPyre_3F_EventScript_RematchGabrielle
	msgbox MtPyre_3F_Text_GabriellePostBattle, MSGBOX_DEFAULT
	release
	end

MtPyre_3F_EventScript_RegisterGabrielle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox MtPyre_3F_Text_GabrielleRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_GABRIELLE_1
	release
	end

MtPyre_3F_EventScript_RematchGabrielle::
	trainerbattle_rematch TRAINER_GABRIELLE_1, MtPyre_3F_Text_GabrielleRematchIntro, MtPyre_3F_Text_GabrielleRematchDefeat
	msgbox MtPyre_3F_Text_GabriellePostRematch, MSGBOX_AUTOCLOSE
	end

MtPyre_3F_Text_WilliamIntro:
	.string "The rich atmosphere of the mountain\n"
	.string "has elevated my psychic power!\p"
	.string "A mere child like you…\n"
	.string "You dream of winning?$"

MtPyre_3F_Text_WilliamDefeat:
	.string "I drown in self-pity…$"

MtPyre_3F_Text_WilliamPostBattle:
	.string "My psychic powers have surely\n"
	.string "grown several times, but…$"

MtPyre_3F_Text_ArtemisIntro:
	.string "Why, hello there!\p"
	.string "The famous wandering Puppet Center\n"
	.string "nurse, Artemis, is here to give\l"
	.string "your Puppets a checkup!$"

MtPyre_3F_Text_ArtemisDefeat:
	.string "Your Puppets are glowing with health!$"

MtPyre_3F_Text_ArtemisPostBattle:
	.string "Well then, time to heal up your\n"
	.string "Puppets!$"
	
MtPyre_3F_Text_ArtemisAnotherCheckup:
	.string "There, good as new!\p"
	.string "If you need another checkup,\n"
	.string "I'll always be here.$"

MtPyre_3F_Text_GabrielleIntro:
	.string "Why have you come here?$"

MtPyre_3F_Text_GabrielleDefeat:
	.string "That was amazing!\n"
	.string "You're a very special trainer.$"

MtPyre_3F_Text_GabriellePostBattle:
	.string "Puppets no longer of this world.\n"
	.string "Puppets that are with you now.\p"
	.string "And the Puppets that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "Please remember that.$"

MtPyre_3F_Text_GabrielleRegister:
	.string "I would like to see your Puppets\n"
	.string "when they grow up some more…\p"
	.string "Please, I need to see your TohoNav.$"

MtPyre_3F_Text_GabrielleRematchIntro:
	.string "Oh, it's you…\p"
	.string "Have you come to show me your grown\n"
	.string "Puppets?$"

MtPyre_3F_Text_GabrielleRematchDefeat:
	.string "How amazing!\n"
	.string "You are a special person.$"

MtPyre_3F_Text_GabriellePostRematch:
	.string "Puppets no longer of this world.\n"
	.string "Puppets that are with you now.\p"
	.string "And the Puppets that you will meet\n"
	.string "in the future…\p"
	.string "They are all to be equally cherished.\n"
	.string "I see that you've remembered that.$"
