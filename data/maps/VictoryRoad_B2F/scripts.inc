VictoryRoad_B2F_MapScripts::
	.byte 0

VictoryRoad_B2F_EventScript_Vito::
	trainerbattle_single TRAINER_VITO, VictoryRoad_B2F_Text_VitoIntro, VictoryRoad_B2F_Text_VitoDefeat
	msgbox VictoryRoad_B2F_Text_VitoPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Owen::
	trainerbattle_single TRAINER_OWEN, VictoryRoad_B2F_Text_OwenIntro, VictoryRoad_B2F_Text_OwenDefeat
	msgbox VictoryRoad_B2F_Text_OwenPostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Caroline::
	trainerbattle_single TRAINER_CAROLINE, VictoryRoad_B2F_Text_CarolineIntro, VictoryRoad_B2F_Text_CarolineDefeat
	msgbox VictoryRoad_B2F_Text_CarolinePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Julie::
	trainerbattle_single TRAINER_JULIE, VictoryRoad_B2F_Text_JulieIntro, VictoryRoad_B2F_Text_JulieDefeat
	msgbox VictoryRoad_B2F_Text_JuliePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_EventScript_Felix::
	trainerbattle_single TRAINER_FELIX, VictoryRoad_B2F_Text_FelixIntro, VictoryRoad_B2F_Text_FelixDefeat, VictoryRoad_B2F_EventScript_ArtemisToHeal
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_AUTOCLOSE
	call VictoryRoad_B2F_EventScript_ArtemisHeal
	msgbox VictoryRoad_B2F_Text_ArtemisAnotherCheckup, MSGBOX_AUTOCLOSE
	end
	
VictoryRoad_B2F_EventScript_ArtemisToHeal::
	msgbox VictoryRoad_B2F_Text_FelixPostBattle, MSGBOX_DEFAULT
	call VictoryRoad_B2F_EventScript_ArtemisHeal
	msgbox VictoryRoad_B2F_Text_ArtemisAnotherCheckup, MSGBOX_DEFAULT
	release
	end
	
VictoryRoad_B2F_EventScript_ArtemisHeal::
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return

VictoryRoad_B2F_EventScript_Dianne::
	trainerbattle_single TRAINER_DIANNE, VictoryRoad_B2F_Text_DianneIntro, VictoryRoad_B2F_Text_DianneDefeat
	msgbox VictoryRoad_B2F_Text_DiannePostBattle, MSGBOX_AUTOCLOSE
	end

VictoryRoad_B2F_Text_VitoIntro:
	.string "I trained together with my whole family,\n"
	.string "every one of us!\l"
	.string "I'm not losing to anyone!$"

VictoryRoad_B2F_Text_VitoDefeat:
	.string "Better than my family?!\n"
	.string "Is that possible?!$"

VictoryRoad_B2F_Text_VitoPostBattle:
	.string "I was better than everyone in my\n"
	.string "family. I've never lost before…\p"
	.string "I've lost my confidence…\n"
	.string "Maybe I'll go home…$"

VictoryRoad_B2F_Text_OwenIntro:
	.string "I'd heard that there was a tough\n"
	.string "little kid around. Do they mean you?$"

VictoryRoad_B2F_Text_OwenDefeat:
	.string "The little shrimp is tough!$"

VictoryRoad_B2F_Text_OwenPostBattle:
	.string "The rumors I heard, that tough little\n"
	.string "kid is from Petalburg City.$"

VictoryRoad_B2F_Text_CarolineIntro:
	.string "You must be getting a little tired.$"

VictoryRoad_B2F_Text_CarolineDefeat:
	.string "No signs of tiring at all!$"

VictoryRoad_B2F_Text_CarolinePostBattle:
	.string "Victory Road and the Hoenn League\n"
	.string "are long and grueling challenges.\l"
	.string "Beware of fatigue!$"

VictoryRoad_B2F_Text_JulieIntro:
	.string "You shouldn't get complacent just\n"
	.string "because you have a lot of Gym Badges.\p"
	.string "There's always going to be someone\n"
	.string "who's better than you!$"

VictoryRoad_B2F_Text_JulieDefeat:
	.string "You're better than me!$"

VictoryRoad_B2F_Text_JuliePostBattle:
	.string "Gaze on your collected Badges and\n"
	.string "remember the trainers you've faced.$"

VictoryRoad_B2F_Text_FelixIntro:
	.string "Why, hello there!\p"
	.string "The famous wandering Puppet Center\n"
	.string "nurse, Artemis, is here to give\l"
	.string "your Puppets a checkup!$"

VictoryRoad_B2F_Text_FelixDefeat:
	.string "Your Puppets are glowing with health!$"

VictoryRoad_B2F_Text_FelixPostBattle:
	.string "Well then, time to heal up your\n"
	.string "Puppets!$"
	
VictoryRoad_B2F_Text_ArtemisAnotherCheckup:
	.string "There, good as new!\p"
	.string "If you need another checkup,\n"
	.string "I'll always be here.$"

VictoryRoad_B2F_Text_DianneIntro:
	.string "The elite among the elite gather in\n"
	.string "this cave.\p"
	.string "How are you finding it?$"

VictoryRoad_B2F_Text_DianneDefeat:
	.string "Not rattled in the least bit!$"

VictoryRoad_B2F_Text_DiannePostBattle:
	.string "You do have guts! I like that!\n"
	.string "Keep it going!$"
