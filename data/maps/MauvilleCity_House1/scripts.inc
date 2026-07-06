MauvilleCity_House1_MapScripts::
	.byte 0

MauvilleCity_House1_EventScript_RockSmashDude::
	lock
	faceplayer
	goto_if_eq VAR_ROCK_SMASH_PICKAXE_STATE , 1, MauvilleCity_House1_EventScript_GetRockSmashAndPickaxe
	goto_if_set FLAG_RECEIVED_HM_ROCK_SMASH, MauvilleCity_House1_EventScript_ReceivedRockSmash
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash, MSGBOX_DEFAULT
	release
	end
	
MauvilleCity_House1_EventScript_GetRockSmashAndPickaxe::
	goto_if_set FLAG_RECEIVED_LANTERN, MauvilleCity_House1_EventScript_ReceivedPickaxe
	msgbox MauvilleCity_House1_Text_ImRockSmashDudeTakeThis, MSGBOX_DEFAULT
	giveitem ITEM_HM_ROCK_SMASH
	setflag FLAG_RECEIVED_HM_ROCK_SMASH
	setflag FLAG_HIDE_ROUTE_111_ROCK_SMASH_TIP_GUY
	msgbox MauvilleCity_House1_Text_ExplainRockSmash2, MSGBOX_DEFAULT
	giveitem ITEM_PICKAXE
	setflag FLAG_RECEIVED_PICKAXE
	msgbox MauvilleCity_House1_Text_ExplainPickaxe, MSGBOX_DEFAULT
	setvar VAR_ROCK_SMASH_PICKAXE_STATE, 2
	release
	end

MauvilleCity_House1_EventScript_ReceivedRockSmash::
	goto_if_set FLAG_BADGE03_GET, MauvilleCity_House1_EventScript_GetPickaxe
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end
	
MauvilleCity_House1_EventScript_GetPickaxe::
	goto_if_set FLAG_RECEIVED_PICKAXE, MauvilleCity_House1_EventScript_ReceivedPickaxe
	msgbox MauvilleCity_House1_Text_HereIsPickaxe, MSGBOX_DEFAULT
	giveitem ITEM_PICKAXE
	setflag FLAG_RECEIVED_PICKAXE
	msgbox MauvilleCity_House1_Text_ExplainPickaxe, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_EventScript_ReceivedPickaxe::
	msgbox MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock, MSGBOX_DEFAULT
	release
	end

MauvilleCity_House1_Text_ImRockSmashDudeTakeThis:
	.string "Woohoo!\p"
	.string "I hear people call me the Rock Smash\n"
	.string "Guy, but I find that sort of degrading.\p"
	.string "I think I deserve a bit more respect,\n"
	.string "like maybe the Rock Smash Dude.\p"
	.string "Woohoo!\p"
	.string "Anyways, your Puppets look pretty\n"
	.string "strong.\p"
	.string "I like that!\n"
	.string "Here, take this Hidden Machine!$"

MauvilleCity_House1_Text_ExplainRockSmash:
	.string "That HM contains Rock Smash.\p"
	.string "If you come across large boulders\n"
	.string "that block your path…\p"
	.string "Well, use that HM move and smash\n"
	.string "them right out of your way!\p"
	.string "Yes, sir! Smash rocks aside, I say!\n"
	.string "Woohoo!\p"
	.string "If you get the Dynamo Badge, come on\n"
	.string "back, okay? I got something else cool\l"
	.string "to give you!$"

MauvilleCity_House1_Text_MonCanFlyOutOfSmashedRock:
	.string "Oh, yes, if you smash a rock, a Puppet\n"
	.string "could come flying out of hiding.\p"
	.string "Woohoo!$"

MauvilleCity_House1_Text_ExplainRockSmash2:
	.string "That HM contains Rock Smash.\p"
	.string "If you come across large boulders\n"
	.string "that block your path…\p"
	.string "Well, use that HM move and smash\n"
	.string "them right out of your way!\p"
	.string "Yes, sir! Smash rocks aside, I say!\n"
	.string "Woohoo!\p"
	.string "But wait, there's more! Here, take\n"
	.string "this with you!$"
	
MauvilleCity_House1_Text_ExplainPickaxe:
	.string "This is a Pickaxe. With this, now\n"
	.string "you, too, can smash some rocks with\l"
	.string "your Puppets at your side!\p"
	.string "Admittedly, it's not as cool as Rock\n"
	.string "Smash, but it still smashes and\l"
	.string "bashes rocks with the best of them!$"
	
MauvilleCity_House1_Text_HereIsPickaxe:
	.string "Oh? You got the Dynamo Badge!\n"
	.string "Your Puppets must be really strong!\p"
	.string "Here, come on and take this!$"
