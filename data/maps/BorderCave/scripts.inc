BorderCave_MapScripts::
	.byte 0

BorderCave_EventScript_ObtainRuby::
	lockall
	applymovement LOCALID_PLAYER, Common_Movement_FaceUp
	applymovement LOCALID_BORDERCAVE_HEXMANIAC, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BorderCave_Text_Discovery, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BorderCave_Text_Denial, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BORDERCAVE_HEXMANIAC, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BorderCave_Text_GiveUp, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, BorderCave_Movement_SuzakurenzanApproachHexManiac
	waitmovement 0
	msgbox BorderCave_Text_DontGiveUp, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_BORDERCAVE_HEXMANIAC, Common_Movement_WalkInPlaceFasterUp
	waitmovement 0
	msgbox BorderCave_Text_VeryWell, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BORDERCAVE_HEXMANIAC, Common_Movement_FaceDown
	waitmovement 0
	delay 30
	msgbox BorderCave_Text_YouSaw, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_PLAYER, BorderCave_Movement_PushPlayerOutOfWay
	applymovement LOCALID_BORDERCAVE_HEXMANIAC, BorderCave_Movement_ShameRun
	waitmovement 0
	delay 20
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, BorderCave_Movement_WalkToPlayer
	waitmovement 0
	msgbox BorderCave_Text_Apologies, MSGBOX_DEFAULT
	closemessage
	msgbox BorderCave_Text_YouLookFamiliar, MSGBOX_DEFAULT
	closemessage
	delay 40
	msgbox BorderCave_Text_AhAChampion, MSGBOX_DEFAULT
	closemessage
	giveitem ITEM_RUBY
	setvar VAR_OBTAIN_RUBY, 1
	addvar VAR_JAVA_GEMS_OBTAINED, 1
	setflag FLAG_OBTAINED_RUBY
	setflag FLAG_HIDE_YOGYAKARTA_NPCS
	msgbox BorderCave_Text_ExplainRuby, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, Common_Movement_FaceUp
	waitmovement 0
	delay 30
	msgbox BorderCave_Text_ShouldGoHome, MSGBOX_DEFAULT
	closemessage
	delay 30
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, Common_Movement_FaceLeft
	waitmovement 0
	delay 30
	msgbox BorderCave_Text_MindWandered, MSGBOX_DEFAULT
	closemessage
	msgbox BorderCave_Text_ExplainJava, MSGBOX_DEFAULT
	closemessage
	msgbox BorderCave_Text_ReturningHome, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, BorderCave_Movement_SuzakurenzanLeaves1
	waitmovement 0
	delay 20
	msgbox BorderCave_Text_YouReallyLookFamiliar, MSGBOX_DEFAULT
	closemessage
	applymovement LOCALID_BORDERCAVE_SUZAKURENZAN, BorderCave_Movement_SuzakurenzanLeaves2
	waitmovement 0
	removeobject LOCALID_BORDERCAVE_SUZAKURENZAN
	removeobject LOCALID_BORDERCAVE_HEXMANIAC
	releaseall
	end
	
BorderCave_Text_Discovery:
	.string "This is what I felt! The strange\n"
	.string "feeling!\p"
	.string "Could this be a way to another\n"
	.string "world?$"
	
BorderCave_Text_Denial:
	.string "At one time, perhaps. But now?\n"
	.string "Whatever was here has faded away.$"

BorderCave_Text_GiveUp:
	.string "Is that so…?\p"
	.string "Perhaps I'm not good at seeking\n"
	.string "out wonders after all…\p"
	.string "Perhaps I should just give up.$"
	
BorderCave_Text_DontGiveUp:
	.string "No one ever gets it right all\n"
	.string "the time.\p"
	.string "Even I've run into dead ends in\n"
	.string "the past.\p"
	.string "Though it may be hard, don't let\n"
	.string "your failures keep you down.\p"
	.string "One day, I'm certain you will find\n"
	.string "something amazing out there.$"
	
BorderCave_Text_VeryWell:
	.string "Very well… Thank you for hearing\n"
	.string "me out.\p"
	.string "I… think I will try again. Elsewhere…$"
	
BorderCave_Text_YouSaw:
	.string "… … … … …\n"
	.string "You saw me like…$"
	
BorderCave_Text_Apologies:
	.string "Apologies for her, she seems rather\n"
	.string "shy. Don't take it too personally.$"
	
BorderCave_Text_YouLookFamiliar:
	.string "Hmm… Now that I get a closer look\n"
	.string "at you, you look familiar…$"

BorderCave_Text_AhAChampion:
	.string "Ah! You must be the new Hoenn Champion!\n"
	.string "Well, isn't it a small world out there!\p"
	.string "Here, I have a small gift for you.\n"
	.string "Take it, please.$"
	
BorderCave_Text_ExplainRuby:
	.string "This is a very special Ruby, you see.\p"
	.string "Near Dewford Town, there is a sailor\n"
	.string "who awaits a trainer with this Ruby.\p"
	.string "If you show it to him, he will take\n"
	.string "you to a distant region known as Java.$"
	
BorderCave_Text_ShouldGoHome:
	.string "Perhaps now it's time to finally\n"
	.string "return home…$"
	
BorderCave_Text_MindWandered:
	.string "Oh! I'm sorry, my mind wandered.$"
	
BorderCave_Text_ExplainJava:
	.string "Java is a region far to the south.\n"
	.string "Many powerful trainers and mighty\l"
	.string "puppets are waiting for a new\l"
	.string "challenger.\p"
	.string "It's a place you can truly test your\n"
	.string "puppets.$"
	
BorderCave_Text_ReturningHome:
	.string "As for me, it is time for to return\n"
	.string "home.\p"
	.string "A life of adventure is hard, especially\n"
	.string "as age begins to catch up to you.\p"
	.string "I wish you luck, Champion.$"
	
BorderCave_Text_YouReallyLookFamiliar:
	.string "It's baffling. Even beyond your victory\n"
	.string "at Ever Grande, you still look so\l"
	.string "familiar…\p"
	.string "Hmm… I suppose when you get as old as I\n"
	.string "am, things blur together.$"
	
BorderCave_Movement_WalkToPlayer:
	walk_left
	walk_down
	walk_down
	walk_down
	face_left
	step_end
	
BorderCave_Movement_SuzakurenzanApproachHexManiac:
	walk_right
	face_down
	step_end
	
BorderCave_Movement_PushPlayerOutOfWay:
	delay_8
	delay_4
	delay_2
	walk_in_place_faster_right
	lock_facing_direction
	walk_left
	unlock_facing_direction
	face_right
	step_end
	
BorderCave_Movement_ShameRun:
	walk_fast_left
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_down
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	walk_fast_right
	step_end
	
BorderCave_Movement_SuzakurenzanLeaves1:
	walk_right
	walk_right
	delay_16
	delay_16
	face_left
	step_end
	
BorderCave_Movement_SuzakurenzanLeaves2:
	walk_down
	walk_down
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	walk_right
	step_end
