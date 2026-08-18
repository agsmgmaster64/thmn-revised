YogyakartaBaseCamp_MapScripts::
	.byte 0

YogyakartaBaseCamp_EventScript_DarkSaberFight::
	lock
	faceplayer
	goto_if_set FLAG_GRAND_LEAGUE_DEFEATED, YogyakartaBaseCamp_EventScript_DarkSaberRematch
	msgbox YogyakartaBaseCamp_Text_WantToTestOurPower, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaBaseCamp_EventScript_RejectedDarkSaberFight
	msgbox YogyakartaBaseCamp_Text_TrueDarkPower, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DARK_SABER_1, YogyakartaBaseCamp_Text_DarkSaberDefeated
	msgbox YogyakartaBaseCamp_Text_IWouldHaveWon, MSGBOX_DEFAULT
	closemessage
	release
	end
	
YogyakartaBaseCamp_EventScript_DarkSaberRematch::
	msgbox YogyakartaBaseCamp_Text_WantToTestOurPowerAgain, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaBaseCamp_EventScript_RejectedDarkSaberFight
	msgbox YogyakartaBaseCamp_Text_TrueDarkPower, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_DARK_SABER_2, YogyakartaBaseCamp_Text_DarkSaberDefeatedAgain
	msgbox YogyakartaBaseCamp_Text_IWouldHaveWon, MSGBOX_DEFAULT
	closemessage
	release
	end
	
 YogyakartaBaseCamp_EventScript_RejectedDarkSaberFight::
	msgbox YogyakartaBaseCamp_Text_RejectedDarkSaber, MSGBOX_NPC
	release
	end
	
YogyakartaBaseCamp_EventScript_KenshiroFight::
	lock
	faceplayer
	goto_if_set FLAG_GRAND_LEAGUE_DEFEATED, YogyakartaBaseCamp_EventScript_KenshiroRematch
	msgbox YogyakartaBaseCamp_Text_InterestingBattle, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaBaseCamp_EventScript_RejectedKenshiroFight
	msgbox YogyakartaBaseCamp_Text_LetsGo, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KENSHIRO_1, YogyakartaBaseCamp_Text_KenshiroDefeated
	msgbox YogyakartaBaseCamp_Text_ILostBadly, MSGBOX_NPC
	release
	end
	
YogyakartaBaseCamp_EventScript_RejectedKenshiroFight::
	msgbox YogyakartaBaseCamp_Text_RejectedKenshiro, MSGBOX_NPC
	release
	end
	
YogyakartaBaseCamp_EventScript_KenshiroRematch::
	msgbox YogyakartaBaseCamp_Text_InterestingBattleAgain, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaBaseCamp_EventScript_RejectedKenshiroFight
	msgbox YogyakartaBaseCamp_Text_BroughtScarletSisters, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KENSHIRO_2, YogyakartaBaseCamp_Text_KenshiroDefeatedAgain
	msgbox YogyakartaBaseCamp_Text_ILostBadly, MSGBOX_DEFAULT
	closemessage
	release
	end
	
YogyakartaBaseCamp_EventScript_KazukiFight::
	lock
	faceplayer
	goto_if_set FLAG_GRAND_LEAGUE_DEFEATED, YogyakartaBaseCamp_EventScript_KazukiRematch
	msgbox YogyakartaBaseCamap_Text_NotHandsomeButGoodAtBattles, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaBaseCamp_EventScript_RejectedKazukiFight
	closemessage
	trainerbattle_no_intro TRAINER_KAZUKI_1, YogyakartaBaseCamp_Text_KazukiDefeated
	msgbox YogyakartaBaseCamp_Text_ComeBackForARematch, MSGBOX_NPC
	release
	end
	
YogyakartaBaseCamp_EventScript_RejectedKazukiFight::
	msgbox YogyakartaBaseCamp_Text_RejectedKazuki, MSGBOX_NPC
	release
	end
	
YogyakartaBaseCamp_EventScript_KazukiRematch::
	msgbox YogyakartaBaseCamp_Text_NotHandsomeButReallyGoodAtBattles, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, YogyakartaBaseCamp_EventScript_RejectedKazukiFight
	msgbox YogyakartaBaseCamp_Text_BroughtScarletSisters, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KAZUKI_2, YogyakartaBaseCamp_Text_KazukiDefeatedAgain
	msgbox YogyakartaBaseCamp_Text_ComeBackForARematch, MSGBOX_DEFAULT
	closemessage
	release
	end
	
YogyakartaBaseCamp_Text_WantToTestOurPower:
	.string "Dark-Saber: Welcome to Jogja Otaku\n"
	.string "basecamp… fufufufufu…\p"
	.string "Want to test our power…?$"
	
YogyakartaBaseCamp_Text_RejectedDarkSaber:
	.string "Dark-Saber: Come back when you\n"
	.string "are ready…$"
	
YogyakartaBaseCamp_Text_TrueDarkPower:
	.string "I shall use my true dark power…$"
	
YogyakartaBaseCamp_Text_DarkSaberDefeated:
	.string "My darkness wasn't enough…$"
	
YogyakartaBaseCamp_Text_IWouldHaveWon:
	.string "Dark-Saber: Tsk… Just a little more\n"
	.string "and I would have won…$"
	
YogyakartaBaseCamp_Text_WantToTestOurPowerAgain:
	.string "Dark-Saber: Our darkness has built\n"
	.string "up. It's overflowing!\p"
	.string "Want to test this new power?$"

YogyakartaBaseCamp_Text_DarkSaberDefeatedAgain:
	.string "Even now my darkness wasn't enough…$"
	
YogyakartaBaseCamp_Text_InterestingBattle:
	.string "Kenshiro: {PLAYER}{KUN}… I saw you\n"
	.string "on Mt. Merapi.\p"
	.string "Yogyakarta is a rather interesting\n"
	.string "area of Java…\l"
	.string "You should explore this place…\p"
	.string "This will be more interesting if we\n"
	.string "battled, right…?$"
	
YogyakartaBaseCamp_Text_RejectedKenshiro:
	.string "Kenshiro: You must be weak then…$"

YogyakartaBaseCamp_Text_LetsGo:
	.string "Kenshiro: Let's go, my EoSD Bonéka!$"
	
YogyakartaBaseCamp_Text_BroughtScarletSisters:
	.string "Now… I bring the Scarlet Sisters…$"
	
YogyakartaBaseCamp_Text_KenshiroDefeated:
	.string "Nooo… EoSD bros…$"
	
YogyakartaBaseCamp_Text_KenshiroDefeatedAgain:
	.string "Nooo… even with the Scarlet Sisters…$"
	
YogyakartaBaseCamp_Text_ILostBadly:
	.string "Kenshiro: Oh no… I lost badly…$"
	
YogyakartaBaseCamp_Text_InterestingBattleAgain:
	.string "Kenshiro: {PLAYER}{KUN}… I saw you\n"
	.string "defeat Haris.\p"
	.string "Java is an interesting region, isn't\n"
	.string "it?\p"
	.string "This will be more interesting if we\n"
	.string "battled, right…?$"
	
YogyakartaBaseCamap_Text_NotHandsomeButGoodAtBattles:
	.string "Kazuki: I may not be handsome, but\n"
	.string "I am good at battles…\p"
	.string "Let's have a battle betwen us…\n"
	.string "Are you prepared?$"
	
YogyakartaBaseCamp_Text_RejectedKazuki:
	.string "Kazuki: Nani…?$"
	
YogyakartaBaseCamp_Text_KazukiDefeated:
	.string "How was I not good enough…?$"
	
YogyakartaBaseCamp_Text_ComeBackForARematch:
	.string "Kazuki: Darn… you are indeed\n"
	.string "very strong…\p"
	.string "Come back for a rematch…$"
	
YogyakartaBaseCamp_Text_NotHandsomeButReallyGoodAtBattles:
	.string "Kazuki: I may not be handsome, but\n"
	.string "now I am really good at battles!\p"
	.string "Let's have a battle between us…\n"
	.string "Are you prepared…?$"
	
YogyakartaBaseCamp_Text_KazukiDefeatedAgain:
	.string "I guess I'm still not good\n"
	.string "enough…$"
