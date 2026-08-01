FallarborTown_MapScripts::
	map_script MAP_SCRIPT_ON_TRANSITION, FallarborTown_OnTransition
	.byte 0

FallarborTown_OnTransition:
	setflag FLAG_VISITED_FALLARBOR_TOWN
	setvar VAR_CONTEST_HALL_STATE, 0
	clearflag FLAG_CONTEST_SKETCH_CREATED
	end

FallarborTown_EventScript_ExpertM::
	lock
	faceplayer
	goto_if_set FLAG_DEFEATED_EVIL_TEAM_MT_CHIMNEY, FallarborTown_EventScript_ExpertMNormal
	msgbox FallarborTown_Text_ShadyCharactersCozmosHome, MSGBOX_DEFAULT
	release
	end

FallarborTown_EventScript_ExpertMNormal::
	msgbox FallarborTown_Text_RegionKnownForMeteors, MSGBOX_DEFAULT
	release
	end
	
FallarborTown_EventScript_TreasureHunter::
	goto_if_set FLAG_POWER_GLOVE_GET, FallarborTown_EventScript_TreasureHunterDisappointed
	lock
	faceplayer
	msgbox FallarborTown_Text_HeardThereWasTreasure, MSGBOX_YESNO
	switch VAR_RESULT
	case NO, FallarborTown_EventScript_ExplainTreasure
	msgbox FallarborTown_Text_ItWillBeMine, MSGBOX_NPC
	release
	end
	
FallarborTown_EventScript_ExplainTreasure::
	msgbox FallarborTown_Text_ExplainTreasure, MSGBOX_DEFAULT
	release
	end
	
FallarborTown_EventScript_TreasureHunterDisappointed::
	msgbox FallarborTown_Text_Disappointed, MSGBOX_NPC
	end

FallarborTown_EventScript_Girl::
	msgbox FallarborTown_Text_MyPreciousAzurill, MSGBOX_NPC
	end

FallarborTown_EventScript_Gentleman::
	msgbox FallarborTown_Text_HaveYouChallengedFlannery, MSGBOX_NPC
	end

FallarborTown_EventScript_Azurill::
	lock
	faceplayer
	waitse
	playmoncry SPECIES_AZURILL, CRY_MODE_NORMAL
	msgbox FallarborTown_Text_Azurill, MSGBOX_DEFAULT
	waitmoncry
	release
	end

FallarborTown_EventScript_BattleTentSign::
	msgbox FallarborTown_Text_BattleTentSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_TownSign::
	msgbox FallarborTown_Text_TownSign, MSGBOX_SIGN
	end

FallarborTown_EventScript_MoveTutorSign::
	msgbox FallarborTown_Text_MoveTutorSign, MSGBOX_SIGN
	end

FallarborTown_Text_ShadyCharactersCozmosHome:
	.string "Something's happening,\n"
	.string "and I don't like it!\p"
	.string "I've seen shady characters wandering\n"
	.string "in and out of Prof. Cozmo's home…$"

FallarborTown_Text_RegionKnownForMeteors:
	.string "This region's been known for meteors\n"
	.string "since the olden days.\p"
	.string "They say Meteor Falls was gouged out\n"
	.string "by a falling meteorite long ago.$"

FallarborTown_Text_MyPreciousAzurill:
	.string "See! Take a look!\n"
	.string "This is my precious Mystia!\p"
	.string "It's slick and smooth and plushy, too!$"

FallarborTown_Text_Azurill:
	.string "Mystia: Myysteeaaa.$"

FallarborTown_Text_HaveYouChallengedFlannery:
	.string "Have you already challenged Flannery,\n"
	.string "the Leader of Lavaridge Gym?\p"
	.string "The girl's grandfather was famous.\n"
	.string "He was one of the Elite Four in the\l"
	.string "Hoenn League at one point.\p"
	.string "It wouldn't surprise me to see Flannery\n"
	.string "become a great trainer in her own\l"
	.string "right.$"

FallarborTown_Text_BattleTentSign:
	.string "Battle Tent Fallarbor Site\n"
	.string "“May the Greatest Teams Gather!”$"

FallarborTown_Text_TownSign:
	.string "Fallarbor Town\n"
	.string "“A farm community with small gardens.”$"

FallarborTown_Text_MoveTutorSign:
	.string "Move Tutor's House\n"
	.string "“New moves taught to Puppets.”$"

FallarborTown_Text_HeardThereWasTreasure:
	.string "Hmph. Did you hear about the\n"
	.string "treasure too?$"
	
FallarborTown_Text_ItWillBeMine:
	.string "Don't think you'll get your hands\n"
	.string "on it. I'll be walking away with\l"
	.string "that prize.$"
	
FallarborTown_Text_ExplainTreasure:
	.string "Long ago, there was a bandit king\n"
	.string "that lived in these parts.\p"
	.string "His prized possession was an item\n"
	.string "called the Power Glove.\p"
	.string "With the Power Glove, he could move\n"
	.string "boulders to throw off pursuers.\p"
	.string "Legend has it that those gloves are\n"
	.string "still here, beneath this very town.\p"
	.string "Don't think you'll get your hands\n"
	.string "on it. I'll be walking away with\l"
	.string "that prize.$"
	
FallarborTown_Text_Disappointed:
	.string "So, you got the Power Gloves,\n"
	.string "eh?\p"
	.string "Hmph. Disappointing, but I'm sure\n"
	.string "there's more out there to grab.$"
