MtMerapi_Exterior_MapScripts::
	map_script MAP_SCRIPT_ON_RESUME, MtMerapi_Exterior_OnResume
	map_script MAP_SCRIPT_ON_TRANSITION, MtMerapi_Exterior_OnTransition
	map_script MAP_SCRIPT_ON_LOAD, MtMerapi_Exterior_OnLoad
	.byte 0
	
MtMerapi_Exterior_OnResume:
	setstepcallback STEP_CB_ASH
	end
	
MtMerapi_Exterior_OnLoad:
	call_if_ge VAR_DEFEAT_MT_MERAPI_STATUES, 4, MtMerapi_Exterior_EventScript_ShowCaveEntrance
	end

MtMerapi_Exterior_OnTransition:
	call_if_set FLAG_MT_MERAPI_SAVED, MtMerapi_Exterior_EventScript_CalmWeather
	end

MtMerapi_Exterior_EventScript_CalmWeather::
	setweather WEATHER_NONE
	doweather
	return
	
MtMerapi_Exterior_EventScript_OldmanSugiho::
	msgbox MtMerapi_Exterior_Text_SugihoEruptionHappening, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_MrMNPCFourCaves::
	goto_if_set FLAG_MT_MERAPI_SAVED, MtMerapi_Exterior_EventScript_MrMNPCThankYou
	msgbox MtMerapi_Exterior_Text_MrMFourCaves, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_MrMNPCThankYou::
	msgbox MtMerapi_Exterior_Text_MrMThankYou, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_ShowCaveEntrance::
	setmetatile 24, 8, METATILE_Lavaridge_CaveEntrance_Top, TRUE
	setmetatile 24, 9, METATILE_Lavaridge_CaveEntrance_Bottom, FALSE
	return
	
MtMerapi_Exterior_EventScript_MrMTileAsksForHelp::
	addvar VAR_MR_M_ASKS_FOR_HELP, 1
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	msgbox MtMerapi_Exterior_Text_MrMHeyYouThere, MSGBOX_DEFAULT
	closemessage
	msgbox MtMerapi_Exterior_Text_MrMLookUpAtTheTop, MSGBOX_DEFAULT
	closemessage
	delay 25
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, MtMerapi_Exterior_Movement_CameraPanToVolcano
	waitmovement 0
	special RemoveCameraObject
	msgbox MtMerapi_Exterior_Text_MrMMerapiHasBeenSpreading, MSGBOX_DEFAULT
	closemessage
	delay 25
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	setvar VAR_0x8004, 1  @ vertical pan
	setvar VAR_0x8005, 2  @ horizontal pan
	setvar VAR_0x8006, 8  @ num shakes
	setvar VAR_0x8007, 5  @ shake delay
	special ShakeCamera
	waitstate
	delay 30
	msgbox MtMerapi_Exterior_Text_MrMFeelATremor, MSGBOX_DEFAULT
	closemessage
	special SpawnCameraObject
	applymovement LOCALID_CAMERA, MtMerapi_Exterior_Movement_CameraReturnToMrM
	waitmovement 0
	special RemoveCameraObject
	delay 48
	msgbox MtMerapi_Exterior_Text_MrMWeMustDoSomething, MSGBOX_DEFAULT
	closemessage
	msgbox MtMerapi_Exterior_Text_MrMWhatIsYourName, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MtMerapi_Exterior_Text_MrMListenCarefully, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox MtMerapi_Exterior_Text_MrMIDontKnowWhere, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox MtMerapi_Exterior_Text_LegendTellsOf, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MtMerapi_Exterior_Text_PerhapsThatRuby, MSGBOX_DEFAULT
	closemessage
	delay 10
	msgbox MtMerapi_Exterior_Text_ThatsAllICanSay, MSGBOX_DEFAULT
	closemessage
	release
	end
	
MtMerapi_Exterior_EventScript_MeetingAichi1::
	setvar VAR_TEMP_0, 1
	goto MtMerapi_Exterior_EventScript_MeetingAichiProper
	
MtMerapi_Exterior_EventScript_MeetingAichi2::
	setvar VAR_TEMP_0, 2
	goto MtMerapi_Exterior_EventScript_MeetingAichiProper
	
MtMerapi_Exterior_EventScript_MeetingAichiProper::
	call_if_eq VAR_TEMP_0, 1, MtMerapi_Exterior_EventScript_AichiWalks1
	call_if_eq VAR_TEMP_0, 2, MtMerapi_Exterior_EventScript_AichiWalks2
	msgbox MtMerapi_Exterior_Text_AichiShouldntBe, MSGBOX_DEFAULT
	closemessage
	delay 30
	msgbox MtMerapi_Exterior_Text_AichiIntroduction, MSGBOX_DEFAULT
	closemessage
	delay 10
	compare VAR_DEFEAT_MT_MERAPI_STATUES, 4
	call_if_ge MtMerapi_Exterior_EventScript_YouBeatTheFourStatues
	call_if_lt MtMerapi_Exterior_EventScript_WereTryingToFigureOut
	delay 10
	msgbox MtMerapi_Exterior_Text_AichiLookingConfident, MSGBOX_DEFAULT
	closemessage
	call_if_eq VAR_TEMP_0, 1, MtMerapi_Exterior_EventScript_AichiWalksBack1
	call_if_eq VAR_TEMP_0, 2, MtMerapi_Exterior_EventScript_AichiWalksBack2
	addvar VAR_AICHI_MT_MERAPI, 1
	release
	end
	
MtMerapi_Exterior_EventScript_YouBeatTheFourStatues::
	msgbox MtMerapi_Exterior_Text_AichiFiguredItOut, MSGBOX_DEFAULT
	closemessage
	return
	
MtMerapi_Exterior_EventScript_WereTryingToFigureOut::
	msgbox MtMerapi_Exterior_Text_AichiTryingToFigureOut, MSGBOX_DEFAULT
	closemessage
	return
	
MtMerapi_Exterior_EventScript_AichiWalks1::
	applymovement LOCALID_AICHI, MtMerapi_Exterior_Movement_AichiWalks1
	waitmovement
	return
	
MtMerapi_Exterior_EventScript_AichiWalks2::
	applymovement LOCALID_AICHI, MtMerapi_Exterior_Movement_AichiWalks2
	waitmovement
	return
	
MtMerapi_Exterior_EventScript_AichiWalksBack1::
	applymovement LOCALID_AICHI, MtMerapi_Exterior_Movement_AichiWalksBack1
	waitmovement
	return
	
MtMerapi_Exterior_EventScript_AichiWalksBack2::
	applymovement LOCALID_AICHI, MtMerapi_Exterior_Movement_AichiWalksBack2
	waitmovement
	return
	
MtMerapi_Exterior_EventScript_Iridiana::
	msgbox MtMerapi_Exterior_Text_NowISeeWhy, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_Eatherna::
	msgbox MtMerapi_Exterior_Text_TheAshIsLovely, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_Yuka::
	msgbox MtMerapi_Exterior_Text_ThisIsMyFirstTime, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_HealingWoman::
	faceplayer
	msgbox MtMerapi_Exterior_Text_YouLookTired, MSGBOX_DEFAULT
	call MtMerapi_Exterior_EventScript_OldWomanToHeal
	msgbox MtMerapi_Exterior_Text_BeCareful, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_OldWomanToHeal::
	closemessage
	fadescreen FADE_TO_BLACK
	playfanfare MUS_HEAL
	waitfanfare
	special HealPlayerParty
	fadescreen FADE_FROM_BLACK
	return
	
MtMerapi_Exterior_EventScript_Brahm::
	msgbox MtMerapi_Exterior_Text_VigorousEnergy, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_Kazuki::
	msgbox MtMerapi_Exterior_Text_VolcanicAshNotGood, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_Kenshiro::
	msgbox MtMerapi_Exterior_Text_VolcanoIsABItStrange, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_DarkSaber::
	msgbox MtMerapi_Exterior_Text_HopeSomethingBadWillNotOccur, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_Aichi::
	msgbox MtMerapi_Exterior_Text_OhPlayer, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_Kazumi::
	msgbox MtMerapi_Exterior_Text_Emerald, MSGBOX_NPC
	end
	
MtMerapi_Exterior_EventScript_ZeiChan::
	lock
	goto_if_eq VAR_DEFEAT_MT_MERAPI_STATUES, 4, MtMerapi_Exterior_EventScript_ZeiChanFight
	msgbox MtMerapi_Exterior_Text_ImZeiChan, MSGBOX_NPC
	release
	end
	
MtMerapi_Exterior_EventScript_ZeiChanFight::
	playbgm MUS_ENCOUNTER_MAY, TRUE
	msgbox MtMerapi_Exterior_Text_ZeiChanFoundCaveFirst, MSGBOX_NPC
	trainerbattle_no_intro TRAINER_ZEI_CHAN_1, MtMerapi_Exterior_Text_ZeiChanDefeated
	msgbox MtMerapi_Exterior_Text_ZeiChanGivesUp, MSGBOX_NPC
	goto MtMerapi_Exterior_EventScript_ZeiChanFlyAway
	release
	end
	
MtMerapi_Exterior_EventScript_ZeiChanFlyAway::
	closemessage
	applymovement VAR_LAST_TALKED, Common_Movement_WalkInPlaceFasterLeft
	waitmovement 0
	delay 50
	setfieldeffectargument 0, 1
	dofieldeffect FLDEFF_NPCFLY_OUT
	delay 15
	removeobject VAR_LAST_TALKED
	waitfieldeffect FLDEFF_NPCFLY_OUT
	savebgm MUS_DUMMY
	fadedefaultbgm
	setflag FLAG_HIDE_ZEI_CHAN 
	release
	end
	
MtMerapi_Exterior_Text_ZeiChanGivesUp:
	.string "Zei-chan: Okay… I give up…\p"
	.string "It seems this cave is connected\n"
	.string "with the current irregular phenomena.\p"
	.string "We will meet again somewhere.$"
	
MtMerapi_Exterior_Text_ZeiChanDefeated:
	.string "I seriously lost?\n"
	.string "After all my preparations…?$"
	
MtMerapi_Exterior_Text_ZeiChanFoundCaveFirst:
	.string "Zei-chan: Oh, {PLAYER}{KUN}…\n"
	.string "I found this cave first.\p"
	.string "It suddenly opened after a couple\n"
	.string "of tremors.\p"
	.string "I cannot allow you to enter this\n"
	.string "cave before me, because it's\l"
	.string "my discovery of this mountain.\p"
	.string "If you insist on entering, you\n"
	.string "must win in a Puppet battle.\p"
	.string "I cannot afford to lose!$"
	
MtMerapi_Exterior_Text_ImZeiChan:
	.string "Zei-chan: Hi, I'm Zei-chan.\p"
	.string "I came from a faraway place.\p"
	.string "I like traveling, exploring, and\n"
	.string "battling.\p"
	.string "I'm interested with this mountain,\n"
	.string "and kinda curious about this mystery.$"
	
MtMerapi_Exterior_Text_Emerald:
	.string "???: I'm trying to meditate on\n"
	.string "my Emerald here.\p"
	.string "Please, leave me be. I'm trying to\n"
	.string "focus.$"
	
MtMerapi_Exterior_Text_AichiLookingConfident:
	.string "Aichi: You seem to know what\n"
	.string "to do from here. I won't hold\l"
	.string "you up farther.\p"
	.string "I'll be trying to do emergency\n"
	.string "rescues for now.\p"
	.string "Good luck, Ruby holder.$"
	
MtMerapi_Exterior_Text_AichiTryingToFigureOut:
	.string "Aichi: We're trying to figure out\n"
	.string "how to get to the main cavern, but\l"
	.string "the Emerald won't work with the\l"
	.string "statues.$"
	
MtMerapi_Exterior_Text_AichiFiguredItOut:
	.string "Aichi: We were trying to figure out\n"
	.string "how to get to the main cavern, but\l"
	.string "it somehow opened itself instead.$"
	
MtMerapi_Exterior_Text_AichiShouldntBe:
	.string "???: Oh, you shouldn't be-$"

MtMerapi_Exterior_Text_AichiIntroduction:
	.string "I see. So you're who Renzan\n"
	.string "gave his Ruby to…\p"
	.string "I'm sorry, my name is Aichi,\n"
	.string "and I'm here to help…$"
	
MtMerapi_Exterior_Movement_AichiWalks1:
	walk_up
	walk_right
	walk_right
	step_end
	
MtMerapi_Exterior_Movement_AichiWalks2:
	walk_right
	walk_right
	step_end
	
MtMerapi_Exterior_Movement_AichiWalksBack1:
	walk_left
	walk_left
	walk_down
	face_up
	step_end
	
MtMerapi_Exterior_Movement_AichiWalksBack2:
	walk_left
	walk_left
	face_up
	step_end
	
MtMerapi_Exterior_Text_OhPlayer::
	.string "Aichi: Oh, {PLAYER}{KUN}.\p"
	.string "It seems you know how to\n"
	.string "solve this diaster.\p"
	.string "I will stay here and make\n"
	.string "emergency rescues.$"
	
MtMerapi_Exterior_Text_HopeSomethingBadWillNotOccur::
	.string "Dark-Saber: I hope something bad will\n"
	.string "not occur again now.\p"
	.string "… … … … …$"
	
MtMerapi_Exterior_Text_VolcanoIsABItStrange:
	.string "Kenshiro: Hmm…\p"
	.string "The volcano is a bit strange now,\n"
	.string "something must've happened.$"
	
MtMerapi_Exterior_Text_VolcanicAshNotGood:
	.string "Kazuki: This is not good…\p"
	.string "Along with lava plumes, volcanic ash\n"
	.string "is not good for our lungs.$"
	
MtMerapi_Exterior_Text_VigorousEnergy:
	.string "Brahm: This is the first time I've\n"
	.string "seen Mt. Merapi with such vigorous\l"
	.string "energy.\p"
	.string "Are Bonéka involved with this\n"
	.string "Phenomena?$"
	
MtMerapi_Exterior_Text_YouLookTired:
	.string "Oh, dear, dear.\n"
	.string "Aren't your Bonéka exhausted?\p"
	.string "Please, rest up here.$"
	
MtMerapi_Exterior_Text_BeCareful:
	.string "Be careful out there, child.\p"
	.string "Too much exhaustion and you'll be\n"
	.string "in severe danger.$"
	
MtMerapi_Exterior_Text_ThisIsMyFirstTime:
	.string "Yuka: This is my first time seeing\n"
	.string "Mt. Merapi's eruption.\p"
	.string "I feel something… indescribable.$"

MtMerapi_Exterior_Text_SugihoEruptionHappening:
	.string "Oldman Sugiho: So an eruption is\n"
	.string "happening again this year.\p"
	.string "But…\p"
	.string "… … … … …\p"
	.string "Something is not right…$"
	
MtMerapi_Exterior_Text_TheAshIsLovely:
	.string "Eatherna: The ash is lovely, yet it\n"
	.string "reminds me of the past when many\l"
	.string "people became victims of\l"
	.string "Mt. Merapi's eruptions.$"
	
MtMerapi_Exterior_Text_NowISeeWhy:
	.string "Iridianaa: Now I see why Mt. Merapi\n"
	.string "is so famous.\p"
	.string "Majestic, explosive, and shrouded\n"
	.string "in mystery.$"
	
MtMerapi_Exterior_Text_MrMFourCaves:
	.string "Mr. M: The Four caves must be the key\n"
	.string "to this disaster.$"
	
MtMerapi_Exterior_Text_MrMThankYou:
	.string "Mr. M: {PLAYER}{KUN}, thank you for your\n"
	.string "assistance in solving this disaster.\p"
	.string "Normally Mt. Merapi erupts every few\n"
	.string "years, but this time seemed too quick.$"
	
MtMerapi_Exterior_Movement_CameraPanToVolcano:
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_diag_northwest
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	walk_up
	step_end
	
MtMerapi_Exterior_Movement_CameraReturnToMrM:
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_diag_southeast
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	walk_down
	step_end
	
MtMerapi_Exterior_Text_MrMHeyYouThere:
	.string "??? Hey, you there!\p"
	.string "I am the defender of Mt. Merapi.\n"
	.string "You may call me Mr. M.$"
	
MtMerapi_Exterior_Text_MrMLookUpAtTheTop:
	.string "Mr. M: Please, look up at the top\n"
	.string "of the mountain.$"
	
MtMerapi_Exterior_Text_MrMMerapiHasBeenSpreading:
	.string "Lately, Mt. Merapi has been spreading\n"
	.string "large amounts of volcanic material,\l"
	.string "causing ash to fall all over Java.$"
	
MtMerapi_Exterior_Text_MrMFeelATremor:
	.string "Did you feel a tremor just now?\p"
	.string "It seems something unusual is\n"
	.string "happening…$"
	
MtMerapi_Exterior_Text_MrMWeMustDoSomething:
	.string "We must do something about this\n"
	.string "incident quickly or something\l"
	.string "terrible might happen again.$"
	
MtMerapi_Exterior_Text_MrMWhatIsYourName:
	.string "By the way, what is your name?$"
	
MtMerapi_Exterior_Text_MrMListenCarefully:
	.string "Mr. M: Okay, {PLAYER}{KUN}, listen\n"
	.string "carefully.\p"
	.string "We need your help to solve this\n"
	.string "problem.$"
	
MtMerapi_Exterior_Text_MrMIDontKnowWhere:
	.string "I don't know where it may be, but\n"
	.string "Mt. Merapi's main cavern is somehow\l"
	.string "connected to four smaller caves.$"
	
MtMerapi_Exterior_Text_LegendTellsOf:
	.string "Legend tells of a special stone\n"
	.string "that can quell supernatural phenomena\l"
	.string "like this.\p"
	.string "Kazumi attempted to use her Emerald,\n"
	.string "but it didn't seem to work.$"
	
MtMerapi_Exterior_Text_PerhapsThatRuby:
	.string "Mr. M: Oh? The Ruby? Hmm…\p"
	.string "Perhaps that Ruby you hold could be the\n"
	.string "key to all of this.$"
	
MtMerapi_Exterior_Text_ThatsAllICanSay:
	.string "Mr. M: That's all I can say to you,\n"
	.string "{PLAYER}{KUN}.\p"
	.string "Please help us solve this disaster.$"
