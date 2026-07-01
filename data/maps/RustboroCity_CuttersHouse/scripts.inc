RustboroCity_CuttersHouse_MapScripts::
	.byte 0

RustboroCity_CuttersHouse_EventScript_Cutter::
	lock
	faceplayer
	goto_if_eq VAR_CUT_BIG_AXE_STATE, 1, RustboroCity_CuttersHouse_EventScript_GetCutAndBigAxe
	goto_if_set FLAG_RECEIVED_HM_CUT, RustboroCity_CuttersHouse_EventScript_ExplainCut
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_ExplainCut::
	goto_if_set FLAG_BADGE01_GET, RustboroCity_CuttersHouse_EventScript_GetBigAxe
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_CuttersHouse_EventScript_GetBigAxe::
	goto_if_set FLAG_RECEIVED_BIG_AXE, RustboroCity_CuttersHouse_EventScript_RecievedBigAxe
	msgbox RustboroCity_CuttersHouse_Text_TakeBigAxe, MSGBOX_DEFAULT
	giveitem ITEM_BIG_AXE
	setflag FLAG_RECEIVED_BIG_AXE
	msgbox RustboroCity_CuttersHouse_Text_ExplainBigAxe, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_CuttersHouse_EventScript_GetCutAndBigAxe::
	goto_if_set FLAG_RECEIVED_BIG_AXE, RustboroCity_CuttersHouse_EventScript_RecievedBigAxe
	msgbox RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse, MSGBOX_DEFAULT
	giveitem ITEM_HM_CUT
	setflag FLAG_RECEIVED_HM_CUT
	msgbox RustboroCity_CuttersHouse_Text_ExplainCut2, MSGBOX_DEFAULT
	giveitem ITEM_BIG_AXE
	setflag FLAG_RECEIVED_BIG_AXE
	msgbox RustboroCity_CuttersHouse_Text_ExplainBigAxe, MSGBOX_DEFAULT
	setvar VAR_CUT_BIG_AXE_STATE, 2
	release
	end
	
RustboroCity_CuttersHouse_EventScript_RecievedBigAxe::
	msgbox RustboroCity_CuttersHouse_Text_ExplainBigAxe, MSGBOX_DEFAULT
	release
	end

RustboroCity_CuttersHouse_EventScript_Lass::
	msgbox RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees, MSGBOX_DEFAULT
	release
	end
	
RustboroCity_CuttersHouse_Text_HereIsBigAxe: 
	msgbox RustboroCity_CuttersHouse_Text_ExplainBigAxe, MSGBOX_NPC

RustboroCity_CuttersHouse_Text_YouCanPutThisHMToGoodUse:
	.string "That determined expression…\n"
	.string "That limber way you move…\l"
	.string "And your well-trained Puppets…\p"
	.string "You're obviously a skilled Trainer!\p"
	.string "No, wait, don't say a word.\n"
	.string "I can tell just by looking at you.\p"
	.string "I'm sure that you can put this\n"
	.string "Hidden Machine to good use.\p"
	.string "No need to be modest or shy.\n"
	.string "Go on, take it!$"

RustboroCity_CuttersHouse_Text_ExplainCut:
	.string "That Hidden Machine, or HM for\n"
	.string "short, is Cut.\p"
	.string "An HM move is one that can be used\n"
	.string "by Puppets outside of battle.\p"
	.string "Any Puppet that's learned Cut can\n"
	.string "chop down thin trees if the Trainer\l"
	.string "has earned the Terra Badge.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.\p"
	.string "However, that is not the only prize\n"
	.string "that I have for you.\p"
	.string "For that one, however, I must see\n"
	.string "proof of your mastery.\p"
	.string "Return to me when you have the Terra\n"
	.string "Badge in hand.$"
	
RustboroCity_CuttersHouse_Text_ExplainCut2:
	.string "That Hidden Machine, or HM for\n"
	.string "short, is Cut.\p"
	.string "An HM move is one that can be used\n"
	.string "by Puppets outside of battle.\p"
	.string "Any Puppet that's learned Cut can\n"
	.string "chop down thin trees if the Trainer\l"
	.string "has earned the Terra Badge.\p"
	.string "And, unlike a TM, an HM can be used\n"
	.string "more than once.\p"
	.string "However, that is not the only prize\n"
	.string "that I have for you.\p"
	.string "The look in your eyes tells me the\n"
	.string "whole story.\p"
	.string "Since you have the Terra Badge with\n"
	.string "you, then take this.$"
	
RustboroCity_CuttersHouse_Text_TakeBigAxe:
	.string "You've refined your movement even\n"
	.string "more since we last met.\p"
	.string "Nothing more needs to be said.\n"
	.string "Take this and put it to good use.$"
	
RustboroCity_CuttersHouse_Text_ExplainBigAxe:
	.string "That is a Big Axe.\n"
	.string "In a skilled trainer's hands, it can\l"
	.string "chop down thin trees.\p"
	.string "I trust that you will use it well.$"

RustboroCity_CuttersHouse_Text_DadHelpedClearLandOfTrees:
	.string "When they were expanding the city of\n"
	.string "Rustboro, my dad helped out.\p"
	.string "He made his Puppets use Cut to clear\n"
	.string "the land of trees.$"
