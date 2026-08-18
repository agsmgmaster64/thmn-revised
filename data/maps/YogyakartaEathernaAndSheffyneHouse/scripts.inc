YogyakartaEathernaAndSheffyneHouse_MapScripts::
	.byte 0

YogyakartaEathernaAndSheffyneHouse_EventScript_EathernaFight::
	lock
	faceplayer
	goto_if_set FLAG_GRAND_LEAGUE_DEFEATED, YogyakartaEathernaAndSheffyneHouse_EventScript_EathernaFightRematch
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_IHopeYouLikeOurHouse, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaEathernaAndSheffyneHouse_EventScript_RejectedEathernaFight
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_LoveAlwaysWins, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_EATHERNA_AND_YUKA_1, YogyakartaBaseCamp_Text_EathernaAndYukaDefeated
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_EathernaAndYukaVeryStrong, MSGBOX_NPC
	release
	end
	
YogyakartaEathernaAndSheffyneHouse_EventScript_RejectedEathernaFight::
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_RejectedEathernaFight, MSGBOX_NPC
	release
	end
	
YogyakartaEathernaAndSheffyneHouse_EventScript_EathernaFightRematch::
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_IHopeYouLikeOurHouseRematch, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaEathernaAndSheffyneHouse_EventScript_RejectedEathernaFight
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_LoveAlwaysWinsAgain, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_EATHERNA_AND_YUKA_2, YogyakartaBaseCamp_Text_EathernaAndYukaDefeatedAgain
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_EathernaAndYukaVeryStrong, MSGBOX_NPC
	release
	end

YogyakartaEathernaAndSheffyneHouse_EventScript_YukaFight::
	lock
	faceplayer
	goto_if_set FLAG_GRAND_LEAGUE_DEFEATED, YogyakartaEathernaAndSheffyneHouse_EventScript_YukaFightRematch
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_WelcomeToOurHome, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaEathernaAndSheffyneHouse_EventScript_RejectedYukaFight
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_LoveAlwaysWins, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_EATHERNA_AND_YUKA_1, YogyakartaBaseCamp_Text_EathernaAndYukaDefeated
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_EathernaAndYukaVeryStrong, MSGBOX_NPC
	release
	end
	
YogyakartaEathernaAndSheffyneHouse_EventScript_RejectedYukaFight::
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_RejectedYukaFight, MSGBOX_NPC
	release
	end
	
YogyakartaEathernaAndSheffyneHouse_EventScript_YukaFightRematch::
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_WelcomeToOurHomeRematch, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaEathernaAndSheffyneHouse_EventScript_RejectedEathernaFight
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_LoveAlwaysWinsAgain, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_EATHERNA_AND_YUKA_2, YogyakartaBaseCamp_Text_EathernaAndYukaDefeatedAgain
	msgbox YogyakartaEathernaAndSheffyneHouse_Text_EathernaAndYukaVeryStrong, MSGBOX_NPC
	release
	end
	
YogyakartaEathernaAndSheffyneHouse_Text_IHopeYouLikeOurHouse:
	.string "Eatherna: Welcome {PLAYER}{KUN}…\n"
	.string "I hope you like our house…\p"
	.string "By the way, do you want to battle\n"
	.string "with me and my wife Yuka…?$"
	
YogyakartaEathernaAndSheffyneHouse_Text_RejectedEathernaFight:
	.string "Eatherna: Well… maybe next time…$"
	
YogyakartaEathernaAndSheffyneHouse_Text_LoveAlwaysWins:
	.string "Eatherna & Yuka: Watch out! Love\n"
	.string "always wins!$"
	
YogyakartaBaseCamp_Text_EathernaAndYukaDefeated:
	.string "Eatherna & Yuka: Huh?\n"
	.string "Did we just lose…?$"
	
YogyakartaEathernaAndSheffyneHouse_Text_EathernaAndYukaVeryStrong:
	.string "Eatherna: Very strong indeed…\n"
	.string "You are a good battler indeed…\p"
	.string "Yuka: Great battle…\n"
	.string "No doubt on your strength…\p"
	.string "You can match up with other\n"
	.string "trainers in the Java Region…$"
	
YogyakartaEathernaAndSheffyneHouse_Text_IHopeYouLikeOurHouseRematch:
	.string "Eatherna: Welcome {PLAYER}{KUN}…\n"
	.string "You're a real celebrity, huh?\p"
	.string "I hope you like our house…\n"
	.string "We worked hard on it.\p"
	.string "By the way, do you want to battle\n"
	.string "with me and my wife Yuka…?$"
	
YogyakartaEathernaAndSheffyneHouse_Text_LoveAlwaysWinsAgain:
	.string "Eatherna & Yuka: Grand Champion or\n"
	.string "not: Love always wins!$"
	
YogyakartaBaseCamp_Text_EathernaAndYukaDefeatedAgain:
	.string "Eatherna & Yuka: Huh?\n"
	.string "Even with so much love…?$"
	
YogyakartaEathernaAndSheffyneHouse_Text_WelcomeToOurHome:
	.string "Yuka: Welcome to our home…\p"
	.string "Care to have a double battle with\n"
	.string "my husband Eatherna and I…?$"
	
YogyakartaEathernaAndSheffyneHouse_Text_RejectedYukaFight:
	.string "Yuka: Fine…$"
	
YogyakartaEathernaAndSheffyneHouse_Text_WelcomeToOurHomeRematch:
	.string "Yuka: We saw your big fight,\n"
	.string "{PLAYER}{KUN}…\p"
	.string "Welcome to our home…\p"
	.string "Care to have a double battle with\n"
	.string "my husband Eatherna and I…?$"
