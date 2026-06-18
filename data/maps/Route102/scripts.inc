Route102_MapScripts::
	.byte 0

Route102_EventScript_LittleBoy::
	msgbox Route102_Text_ImNotVeryTall, MSGBOX_NPC
	end

Route102_EventScript_RouteSignOldale::
	msgbox Route102_Text_RouteSignOldale, MSGBOX_SIGN
	end

Route102_EventScript_RouteSignPetalburg::
	msgbox Route102_Text_RouteSignPetalburg, MSGBOX_SIGN
	end

Route102_EventScript_Boy::
	msgbox Route102_Text_CatchWholeBunchOfPokemon, MSGBOX_NPC
	end

Route102_EventScript_Calvin::
	trainerbattle_single TRAINER_CALVIN_1, Route102_Text_CalvinIntro, Route102_Text_CalvinDefeated, Route102_EventScript_CalvinRegisterMatchCallAfterBattle
	specialvar VAR_RESULT, ShouldTryRematchBattle
	goto_if_eq VAR_RESULT, TRUE, Route102_EventScript_CalvinRematch
	setvar VAR_0x8004, TRAINER_CALVIN_1
	specialvar VAR_RESULT, IsTrainerRegistered
	goto_if_eq VAR_RESULT, FALSE, Route102_EventScript_CalvinTryRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegisterMatchCallAfterBattle::
	special PlayerFaceTrainerAfterBattle
	waitmovement 0
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegisterMatchCall
	release
	end

Route102_EventScript_CalvinRegisterMatchCall::
	msgbox Route102_Text_CalvinRegisterShort, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinTryRegister::
	goto_if_set FLAG_HAS_MATCH_CALL, Route102_EventScript_CalvinRegister
	msgbox Route102_Text_CalvinPostBattle, MSGBOX_DEFAULT
	release
	end

Route102_EventScript_CalvinRegister::
	msgbox Route102_Text_CalvinRegister, MSGBOX_DEFAULT
	register_matchcall TRAINER_CALVIN_1
	release
	end

Route102_EventScript_CalvinRematch::
	trainerbattle_rematch TRAINER_CALVIN_1, Route102_Text_CalvinRematchIntro, Route102_Text_CalvinRematchDefeated
	msgbox Route102_Text_CalvinRematchPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Rick::
	trainerbattle_single TRAINER_RICK, Route102_Text_RickIntro, Route102_Text_RickDefeated
	msgbox Route102_Text_RickPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Tiana::
	trainerbattle_single TRAINER_TIANA, Route102_Text_TianaIntro, Route102_Text_TianaDefeated
	msgbox Route102_Text_TianaPostBattle, MSGBOX_AUTOCLOSE
	end

Route102_EventScript_Allen::
	trainerbattle_single TRAINER_ALLEN, Route102_Text_AllenIntro, Route102_Text_AllenDefeated
	msgbox Route102_Text_AllenPostBattle, MSGBOX_AUTOCLOSE
	end
	
Route102_EventScript_IchiiTrigger1::
	setvar 0x8008, 1
	goto Route102_EventScript_IchiiScene
	end

Route102_EventScript_IchiiTrigger2::
	setvar 0x8008, 2
	goto Route102_EventScript_IchiiScene
	end

Route102_EventScript_IchiiTrigger3::
	setvar 0x8008, 3
	goto Route102_EventScript_IchiiScene
	end
	
Route102_EventScript_IchiiTrigger4::
	setvar 0x8008, 4
	goto Route102_EventScript_IchiiScene
	end
	
Route102_EventScript_IchiiScene::
	lockall
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiLookRight
	waitmovement 0
	delay 20
	playse SE_PIN
	applymovement LOCALID_ROUTE102_ICHII, Common_Movement_ExclamationMark
	waitmovement 0
	applymovement LOCALID_ROUTE102_ICHII, Common_Movement_Delay48
	waitmovement 0
	call_if_eq VAR_0x8008, 1, Route102_EventScript_IchiiApproachPlayer1
	call_if_eq VAR_0x8008, 2, Route102_EventScript_IchiiApproachPlayer2
	call_if_eq VAR_0x8008, 3, Route102_EventScript_IchiiApproachPlayer3
	call_if_eq VAR_0x8008, 4, Route102_EventScript_IchiiApproachPlayer4
	delay 20
	msgbox Route102_Text_IchiiLetsBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_ICHII, Route102_Text_IchiiDefeated
	msgbox Route102_Text_IchiiDefeatedSurprise, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox Route102_Text_IchiiTakeThis, MSGBOX_DEFAULT
	closemessage
	delay 10
	bufferspeciesname STR_VAR_1, SPECIES_CHIBI_SATSUKI
	setvar VAR_TEMP_TRANSFERRED_SPECIES, SPECIES_CHIBI_SATSUKI
	givemon SPECIES_CHIBI_SATSUKI, 5
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PARTY, Route102_EventScript_SendChibiSatsukiToParty
	goto_if_eq VAR_RESULT, MON_GIVEN_TO_PC, Route102_EventScript_RecieveChibiSatsukiPC
	goto Common_EventScript_NoMoreRoomForPokemon
	end
	
Route102_EventScript_IchiiApproachPlayer1::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiApproachPlayer1
	waitmovement 0
	return

Route102_EventScript_IchiiApproachPlayer2::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiApproachPlayer2
	waitmovement 0
	return

Route102_EventScript_IchiiApproachPlayer3::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiApproachPlayer3
	waitmovement 0
	return

Route102_EventScript_IchiiApproachPlayer4::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiApproachPlayer4
	waitmovement 0
	return
	
Route102_EventScript_SendChibiSatsukiToParty::
	call Route102_EventScript_ReceivedChibiSatsukiFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route102_EventScript_IchiiGoodbye
	call Common_EventScript_GetGiftMonPartySlot
	call Common_EventScript_NameReceivedPartyMon
	goto Route102_EventScript_IchiiGoodbye
	end
	
Route102_EventScript_RecieveChibiSatsukiPC::
	call Route102_EventScript_ReceivedChibiSatsukiFanfare
	msgbox gText_NicknameThisPokemon, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, Route102_EventScript_SendChibiSatsukiToPC
	call Common_EventScript_NameReceivedBoxMon
	goto Route102_EventScript_IchiiGoodbye
	end
	
Route102_EventScript_ReceivedChibiSatsukiFanfare::
	playfanfare MUS_OBTAIN_ITEM
	message Route102_Text_PlayerReceivedChibiSatsuki
	waitmessage
	waitfanfare
	bufferspeciesname STR_VAR_1, SPECIES_CHIBI_SATSUKI
	return
	
Route102_EventScript_SendChibiSatsukiToPC::
	call Common_EventScript_TransferredToPC
	goto Route102_EventScript_IchiiGoodbye
	end
	
Route102_EventScript_IchiiGoodbye::
	delay 10
	msgbox Route102_Text_IchiiWillMeetAgain, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_0x8008, 1, Route102_EventScript_IchiiLeaves1
	call_if_eq VAR_0x8008, 2, Route102_EventScript_IchiiLeaves2
	call_if_eq VAR_0x8008, 3, Route102_EventScript_IchiiLeaves3
	call_if_eq VAR_0x8008, 4, Route102_EventScript_IchiiLeaves4
	removeobject LOCALID_ROUTE102_ICHII
	setvar VAR_ICHII_ROUTE_102, 1
	releaseall
	end
	
Route102_EventScript_IchiiLeaves1::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiLeaves1
	waitmovement 0
	return
	
Route102_EventScript_IchiiLeaves2::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiLeaves2
	waitmovement 0
	return
	
Route102_EventScript_IchiiLeaves3::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiLeaves3
	waitmovement 0
	return

Route102_EventScript_IchiiLeaves4::
	applymovement LOCALID_ROUTE102_ICHII, Route102_Movement_IchiiLeaves4
	waitmovement 0
	return
	
Route102_Movement_IchiiLookRight:
	face_right
	step_end
	
Route102_Movement_IchiiApproachPlayer1:
	walk_up
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_Movement_IchiiApproachPlayer2:
	walk_up
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_Movement_IchiiApproachPlayer3:
	walk_right
	walk_right
	walk_right
	walk_right
	step_end

Route102_Movement_IchiiApproachPlayer4:
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
	
Route102_Movement_IchiiLeaves1:
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
Route102_Movement_IchiiLeaves2:
	walk_left
	walk_down
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
Route102_Movement_IchiiLeaves3:
	walk_left
	walk_down
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
Route102_Movement_IchiiLeaves4:
	walk_left
	walk_left
	walk_left
	walk_down
	walk_down
	walk_down
	walk_left
	walk_left
	walk_left
	walk_left
	step_end
	
Route102_Text_IchiiLetsBattle:
	.string "?????: … … … …$"
	
Route102_Text_IchiiDefeated:
	.string "Oh… I underestimated you…$"
	
Route102_Text_IchiiDefeatedSurprise:
	.string "Ugh… I lost…$"
	
Route102_Text_IchiiTakeThis:
	.string "Ichii: I am Ichii, a trainer from\n"
	.string "the Java Region.\p"
	.string "Take this for beating me.$"

Route102_Text_PlayerReceivedChibiSatsuki:
	.string "{PLAYER} received Chibi Satsuki!$"
	
Route102_Text_IchiiWillMeetAgain:
	.string "{PLAYER}, we will meet again.$"

Route102_Text_WatchMeCatchPokemon:
	.string "Wally: {PLAYER}…\n"
	.string "Bonéka hide in tall grass like this,\l"
	.string "don't they?\p"
	.string "Please watch me and see if I can\n"
	.string "catch one properly.\p"
	.string "…Whoa!$"

Route102_Text_WallyIDidIt:
	.string "Wally: I did it… It's my…\n"
	.string "My Bonéka!$"

Route102_Text_LetsGoBack:
	.string "{PLAYER}, thank you!\n"
	.string "Let's go back to the Gym!$"

Route102_Text_ImNotVeryTall:
	.string "I'm…not very tall, so I sink right\n"
	.string "into tall grass.\p"
	.string "The grass goes up my nose and…\n"
	.string "Fwafwafwafwafwa…\p"
	.string "Fwatchoo!$"

Route102_Text_CatchWholeBunchOfPokemon:
	.string "I'm going to catch a whole bunch of\n"
	.string "Bonéka!$"

Route102_Text_RouteSignOldale:
	.string "Route 102\n"
	.string "{RIGHT_ARROW} Oldale Town$"

Route102_Text_RouteSignPetalburg:
	.string "Route 102\n"
	.string "{LEFT_ARROW} Petalburg City$"
