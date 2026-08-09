Route106_MapScripts::
	.byte 0

Route106_EventScript_TrainerTipsSign::
	msgbox Route106_Text_TrainerTips, MSGBOX_SIGN
	end

Route106_EventScript_Douglas::
	trainerbattle_single TRAINER_DOUGLAS, Route106_Text_DouglasIntro, Route106_Text_DouglasDefeated
	msgbox Route106_Text_DouglasPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Kyla::
	trainerbattle_single TRAINER_KYLA, Route106_Text_KylaIntro, Route106_Text_KylaDefeated
	msgbox Route106_Text_KylaPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Elliot::
	trainerbattle_single TRAINER_ELLIOT_1, Route106_Text_ElliotIntro, Route106_Text_ElliotDefeated, Route106_EventScript_ElliotRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route106_EventScript_ElliotRematch
	msgbox Route106_Text_ElliotPostBattle, MSGBOX_DEFAULT
	release
	end

Route106_EventScript_ElliotRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	msgbox Route106_Text_ElliotRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_ELLIOT_1
	release
	end

Route106_EventScript_ElliotRematch::
	trainerbattle_rematch TRAINER_ELLIOT_1, Route106_Text_ElliotRematchIntro, Route106_Text_ElliotRematchDefeated
	msgbox Route106_Text_ElliotRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route106_EventScript_Ned::
	trainerbattle_single TRAINER_NED, Route106_Text_NedIntro, Route106_Text_NedDefeated
	msgbox Route106_Text_NedPostBattle, MSGBOX_AUTOCLOSE
	end
	
Route106_EventScript_JavaSailor::
	faceplayer
	goto_if_set FLAG_MONCOZ_KNOWS_YOU, Route106_EventScript_MoncozKnowsYou
	checkitem ITEM_RUBY
	goto_if_eq VAR_RESULT, 0, Route106_Event_JavaSailorNoGo
	setflag FLAG_MONCOZ_KNOWS_YOU
	msgbox Route106_Text_DoYouWantToGo, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Route106_Event_ComeBackLater
	msgbox Route106_Text_LetsGo, MSGBOX_NPC
	applymovement LOCALID_ROUTE106_MONCOZ, Route106_Movement_MoncozToBoat
	waitmovement
	delay 21
	call_if_eq VAR_FACING, DIR_WEST, Route106_EventScript_PlayerToBoatWest
	call_if_eq VAR_FACING, DIR_EAST, Route106_EventScript_PlayerToBoatEast
	delay 30
	applymovement LOCALID_ROUTE106_MONCOZBOAT, Route106_Movement_MoncozBoatToJava
	waitmovement
	warp MAP_YOGYAKARTA, 17, 33
	waitstate
	release
	end
	
Route106_EventScript_MoncozKnowsYou::
	msgbox Route106_Text_DoYouWantToGoAgain, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Route106_Event_ComeBackLater
	msgbox Route106_Text_LetsGo, MSGBOX_NPC
	applymovement LOCALID_ROUTE106_MONCOZ, Route106_Movement_MoncozToBoat
	waitmovement
	delay 21
	call_if_eq VAR_FACING, DIR_WEST, Route106_EventScript_PlayerToBoatWest
	call_if_eq VAR_FACING, DIR_EAST, Route106_EventScript_PlayerToBoatEast
	delay 30
	applymovement LOCALID_ROUTE106_MONCOZBOAT, Route106_Movement_MoncozBoatToJava
	waitmovement
	warp MAP_YOGYAKARTA, 17, 33
	waitstate
	release
	end
	
Route106_Event_JavaSailorNoGo::
	msgbox Route106_Text_MoncozNormal, MSGBOX_NPC
	release
	end
	
Route106_Event_ComeBackLater::
	msgbox Route106_Text_ComeBackLater, MSGBOX_NPC
	release
	end
	
	
Route106_EventScript_PlayerToBoatWest::
	applymovement LOCALID_PLAYER, Route106_Movement_PlayerToBoatWest
	waitmovement
	return
	
Route106_EventScript_PlayerToBoatEast::
	applymovement LOCALID_PLAYER, Route106_Movement_PlayerToBoatEast
	waitmovement
	return

Route106_Text_TrainerTips:
	.string "Trainer Tips\p"
	.string "Advice on catching Puppets with a Rod:\n"
	.string "Press the A Button if you get a bite.$"

Route106_Text_MoncozNormal:
	.string "I'm Fajar the sailor, but call\n"
	.string "me Moncoz.\p"
	.string "I'm from the Java region.$"
	
Route106_Text_DoYouWantToGo:
	.string "I'm Fajar the sailor, but call\n"
	.string "me Moncoz.\p"
	.string "Ah! Is that the Ruby? So I see you wish\n"
	.string "to come to Java.\p"
	.string "I'll be going there on my old boat.\n"
	.string "Do you want to come with me?$"
	
Route106_Text_LetsGo:
	.string "Moncoz: Alright then!\p"
	.string "We'll set course for Yogyakarta!$"
	
Route106_Text_DoYouWantToGoAgain:
	.string "Moncoz: Welcome back! It's nice to\n"
	.string "see you again!\p"
	.string "Do you want to come with me to the\n"
	.string "Java region?$"
	
Route106_Text_ComeBackLater:
	.string "Moncoz: I'll be here waiting.$"
	
Route106_Movement_MoncozToBoat:
	walk_up
	delay_8
	set_invisible
	step_end
	
Route106_Movement_PlayerToBoatWest:
	walk_left
	walk_up
	delay_8
	set_invisible
	step_end
	
Route106_Movement_PlayerToBoatEast:
	walk_right
	walk_up
	delay_8
	set_invisible
	step_end
	
Route106_Movement_MoncozBoatToJava:
	walk_up
	walk_up
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
