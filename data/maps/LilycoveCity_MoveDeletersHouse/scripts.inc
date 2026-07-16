LilycoveCity_MoveDeletersHouse_MapScripts::
	.byte 0

LilycoveCity_MoveDeletersHouse_EventScript_BerryShop::
	lock
	faceplayer
	message gText_HowMayIServeYou
	waitmessage
	pokemart LilycoveCity_MoveDeletersHouse_Pokemart1
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	releaseall
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_KarelHPFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_KarelFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_KarelYes
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_KarelNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_KarelYes::
	trainerbattle_no_intro TRAINER_KAREL, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_KarelNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

LilycoveCity_MoveDeletersHouse_EventScript_KarelNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_KarelLeaveAlone, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_RubyAtkFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_RubyFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_RubyYes
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_RubyNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_RubyYes::
	trainerbattle_no_intro TRAINER_RUBY, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_RubyNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_RubyNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_RubySenseFear, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_SiNDefFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_SiNFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_SiNYes
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_SiNNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_SiNYes::
	trainerbattle_no_intro TRAINER_SIN, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_SiNNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_SiNNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_RubyShouldntDecline, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_XanSpAFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_XanFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_XanYes
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_XanNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_XanYes::
	trainerbattle_no_intro TRAINER_XAN, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_XanNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_XanNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_XanHelperTeam, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_AquaSpDFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_AquaFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_AquaYes
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_AquaNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_AquaYes::
	trainerbattle_no_intro TRAINER_AQUA, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_AquaNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_AquaNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_AquaFreeTime, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_HemoSpeFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_HemoFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_HemoYes
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_HemoNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_HemoYes::
	trainerbattle_no_intro TRAINER_HEMOGLOBIN_A1C, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_HemoNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_HemoNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_HemoDontForget, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_BlueXPFight::
	lock
	faceplayer
	msgbox LilycoveCity_MoveDeletersHouse_Text_BlueFightQuestion, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, YES, LilycoveCity_MoveDeletersHouse_EventScript_BlueYes50
	goto_if_eq VAR_RESULT, NO, LilycoveCity_MoveDeletersHouse_EventScript_BlueNo
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_BlueYes50::
	goto_if_set FLAG_SYS_GAME_CLEAR, LilycoveCity_MoveDeletersHouse_EventScript_BlueYes75
	trainerbattle_no_intro TRAINER_BLUE_50, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_BlueNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_BlueYes75::
	goto_if_set FLAG_GRAND_LEAGUE_DEFEATED, LilycoveCity_MoveDeletersHouse_EventScript_BlueYes100
	trainerbattle_no_intro TRAINER_BLUE_75, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_BlueNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end

LilycoveCity_MoveDeletersHouse_EventScript_BlueYes100::
	trainerbattle_no_intro TRAINER_BLUE_100, LilycoveCity_MoveDeletersHouse_Text_ILost
	msgbox LilycoveCity_MoveDeletersHouse_Text_BlueNextTime, MSGBOX_DEFAULT
	special HealPlayerParty
	release
	end
	
LilycoveCity_MoveDeletersHouse_EventScript_BlueNo::
	msgbox LilycoveCity_MoveDeletersHouse_Text_BlueHaveSomeTime, MSGBOX_DEFAULT
	release
	end
	
LilycoveCity_MoveDeletersHouse_Pokemart1:
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	pokemartlistend
	
LilycoveCity_MoveDeletersHouse_Text_KarelFightQuestion:
	.string "Karel: This battle is worth\n"
	.string "18 HP EVs. Continue?$"
	
LilycoveCity_MoveDeletersHouse_Text_KarelNextTime:
	.string "Karel: Ugh, I didn't win…\n"
	.string "I'll win next time.$"

LilycoveCity_MoveDeletersHouse_Text_ILost:
	.string "I lost…$"
	
LilycoveCity_MoveDeletersHouse_Text_KarelLeaveAlone:
	.string "Karel: Okay, okay…\n"
	.string "just leave me alone…$"

LilycoveCity_MoveDeletersHouse_Text_RubyFightQuestion:
	.string "Ruby: This battle is worth\n"
	.string "18 Atk EVs. Continue?$"
	
LilycoveCity_MoveDeletersHouse_Text_RubyNextTime:
	.string "It seems there are many strong\n"
	.string "trainers around the world…$"
	
LilycoveCity_MoveDeletersHouse_Text_RubySenseFear:
	.string "Ruby: I can sense your fear…$"
	
LilycoveCity_MoveDeletersHouse_Text_SiNFightQuestion:
	.string "SiN: This battle is worth\n"
	.string "18 Def EVs. Continue?$"
	
LilycoveCity_MoveDeletersHouse_Text_SiNNextTime:
	.string "Tsk… just a little more\n"
	.string "and I would have won…\p"
	.string "Do you play OSU! often?\n"
	.string "If so, try my beatmap.$"
	
LilycoveCity_MoveDeletersHouse_Text_RubyShouldntDecline:
	.string "Listen well…\p"
	.string "You should not decline a battle\n"
	.string "offer from other trainers.$"
	
LilycoveCity_MoveDeletersHouse_Text_XanFightQuestion:
	.string "Xan: This battle is worth\n"
	.string "18 Sp. Atk EVs. Continue?$"
	
LilycoveCity_MoveDeletersHouse_Text_XanNextTime:
	.string "Xan: Even my helper team is toasted…$"
	
LilycoveCity_MoveDeletersHouse_Text_XanHelperTeam:
	.string "Xan: Well, you should try how strong\n"
	.string "my helper team is… hehehe…$"

LilycoveCity_MoveDeletersHouse_Text_AquaFightQuestion:
	.string "Aqua: This battle is worth\n"
	.string "18 Sp. Def EVs. Continue?$"

LilycoveCity_MoveDeletersHouse_Text_AquaNextTime:
	.string "Aqua: Phew… that was my loss.\n"
	.string "Let's battle again sometime.\p"
	.string "By the way, if you have free time,\n"
	.string "and could play {COLOR BLUE}{SHADOW LIGHT_GRAY}Touhoumon Aqua + Yui{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY},\l"
	.string "I would really appreciate it…$"
	
LilycoveCity_MoveDeletersHouse_Text_AquaFreeTime:
	.string "Aqua: Arara…\p"
	.string "Do you think I am just a weak\n"
	.string "trainer? …never mind.\p"
	.string "If you have free time, you could\n"
	.string "play {COLOR BLUE}{SHADOW LIGHT_GRAY}Touhoumon Aqua + Yui{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}…$"

LilycoveCity_MoveDeletersHouse_Text_HemoFightQuestion:
	.string "HemoglobinA1C: This battle is worth\n"
	.string "18 Spe EVs. Continue?$"
	
LilycoveCity_MoveDeletersHouse_Text_HemoNextTime:
	.string "HemoglobinA1C: You have plenty of skill\n"
	.string "in Puppet battles, it seems.\p"
	.string "But, don't forget to keep playing\n"
	.string "the original {COLOR RED}{SHADOW LIGHT_GRAY}Touhou Ningyougeki{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} and\l"
	.string "{COLOR RED}{SHADOW LIGHT_GRAY}Touhou Puppet Dance Performance:\l"
	.string "Shard of Dreams{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}.$"

LilycoveCity_MoveDeletersHouse_Text_HemoDontForget:
	.string "HemoglobinA1C: Fine, but don't forget\n"
	.string "to play the original {COLOR RED}{SHADOW LIGHT_GRAY}Touhou Ningyougeki{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}\l"
	.string "and {COLOR RED}{SHADOW LIGHT_GRAY}Touhou Puppet Dance Performance:\l"
	.string "Shard of Dreams{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}.$"

LilycoveCity_MoveDeletersHouse_Text_BlueFightQuestion:
	.string "Blue: Huh… a trainer gathering…\n"
	.string "not bad at all.\p"
	.string "Hey you, do you want to battle\n"
	.string "with me?$"
	
LilycoveCity_MoveDeletersHouse_Text_BlueNextTime:
	.string "Blue: Nothing can stop you for sure.\p"
	.string "Do you have some time…?\n"
	.string "If you have, you could play my\l"
	.string "{COLOR BLUE}{SHADOW LIGHT_GRAY}Touhoumon Blue Version{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} or wait\l"
	.string "for {COLOR GREEN}{SHADOW LIGHT_GRAY}Touhoumon Green Version{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}.$"
	
LilycoveCity_MoveDeletersHouse_Text_BlueHaveSomeTime:
	.string "Blue: Well… I should find other\n"
	.string "trainers around here for battling.\p"
	.string "Ahhhh, you could play my\n"
	.string "{COLOR BLUE}{SHADOW LIGHT_GRAY}Touhoumon Blue Version{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY} or wait\l"
	.string "for {COLOR GREEN}{SHADOW LIGHT_GRAY}Touhoumon Green Version{COLOR DARK_GRAY}{SHADOW LIGHT_GRAY}.$"