@ Interact with cuttable tree
EventScript_CutTree::
	lockall
	checkfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseCutOtherwise
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_CutTreeCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_CUT_ON_TREE
	waitstate
EventScript_CutTreeDown:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
EventScript_CutTreeDownNoFollowerCheck:: 
	applymovement VAR_LAST_TALKED, Movement_CutTreeDown
	waitmovement 0
	removeobject VAR_LAST_TALKED
	releaseall
	end

EventScript_CanUseCutOtherwise::
	partycheckfieldmove FIELD_MOVE_CUT, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseBigAxe
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox Text_WantToCut, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
	buffermovename STR_VAR_2, MOVE_CUT
	msgbox Text_MonAttemptedToUseFieldMove, MSGBOX_DEFAULT
	closemessage
	goto EventScript_CutTreeCommon

EventScript_UseBigAxe::
	lockall
	goto EventScript_UseBigAxe_SkipCheck

EventScript_CanUseBigAxe::
	checkitem ITEM_BIG_AXE, 1
	goto_if_ne VAR_RESULT, TRUE, EventScript_CheckTreeCantCut
	msgbox Text_WantToCutBigAxe, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelCut
EventScript_UseBigAxe_SkipCheck::
	bufferitemname STR_VAR_2, ITEM_BIG_AXE
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	goto EventScript_CutTreeDownNoFollowerCheck

@ Use cut from party menu
EventScript_UseCut::
	lockall
	goto EventScript_CutTreeCommon

Movement_CutTreeDown:
	cut_tree
	step_end

EventScript_CheckTreeCantCut::
	msgbox Text_CantCut, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelCut::
	closemessage
	releaseall
	end

Text_WantToCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!\p"
	.string "Would you like to Cut it?$"

Text_WantToCutBigAxe:
	.string "This tree looks like it can be\n"
	.string "Cut down!\p"
	.string "Would you like to use the Big Axe?$"

Text_MonUsedFieldMove:
	.string "{STR_VAR_1} used {STR_VAR_2}!$"

Text_MonAttemptedToUseFieldMove::
	.string "{STR_VAR_1} attempted to\n"
	.string "use {STR_VAR_2}!$"

Text_PlayerUsedFieldTool::
	.string "{PLAYER} used the {STR_VAR_2}!$"

Text_CantCut:
	.string "This tree looks like it can be\n"
	.string "Cut down!$"

@ Use rock smash from party menu
EventScript_UseRockSmash::
	lockall
	goto EventScript_RockSmashCommon

@ Interact with smashable rock
EventScript_RockSmash::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseRockSmashOtherwise
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_RockSmashCommon:
	@ check if follower should use the field move
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	dofieldeffect FLDEFF_USE_ROCK_SMASH
	waitstate
EventScript_SmashRock:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
EventScript_SmashRockNoFollowerCheck::
	applymovement VAR_LAST_TALKED, Movement_SmashRock
	waitmovement 0
	removeobject VAR_LAST_TALKED
	specialvar VAR_RESULT, TryUpdateRusturfTunnelState
	goto_if_eq VAR_RESULT, TRUE, EventScript_EndSmash
	special RockSmashWildEncounter
	goto_if_eq VAR_RESULT, FALSE, EventScript_EndSmash
	waitstate
	releaseall
	end

EventScript_CanUseRockSmashOtherwise::
	partycheckfieldmove FIELD_MOVE_ROCK_SMASH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUsePickaxe
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox Text_WantToSmash, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
	buffermovename STR_VAR_2, MOVE_ROCK_SMASH
	msgbox Text_MonAttemptedToUseFieldMove, MSGBOX_DEFAULT
	closemessage
	goto EventScript_RockSmashCommon

EventScript_UsePickaxe::
	lockall
	goto EventScript_UsePickaxe_SkipCheck

EventScript_CanUsePickaxe::
	checkitem ITEM_PICKAXE, 1
	goto_if_ne VAR_RESULT, TRUE, EventScript_CantSmashRock
	msgbox Text_WantToSmashItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelSmash
EventScript_UsePickaxe_SkipCheck::
	bufferitemname STR_VAR_2, ITEM_PICKAXE
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
	closemessage
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	goto EventScript_SmashRockNoFollowerCheck

EventScript_FollowerFieldMove:
	getdirectiontoface VAR_0x8005, OBJ_EVENT_ID_FOLLOWER, OBJ_EVENT_ID_PLAYER
	specialvar VAR_0x8006, GetPlayerFacingDirection
	goto_if_eq VAR_0x8005, DIR_NONE, EventScript_FollowerFieldMoveEnd
	@ Swap follower and player
	call EventScript_FollowerSwap
	@ Face follower in direction and jump
	switch VAR_0x8006
	case DIR_NORTH, EventScript_FollowerJumpNorth
	case DIR_EAST, EventScript_FollowerJumpEast
	case DIR_SOUTH, EventScript_FollowerJumpSouth
	case DIR_WEST, EventScript_FollowerJumpWest
EventScript_FollowerFieldMoveEnd:
	return

EventScript_FollowerSwap:
	switch VAR_0x8005
	case DIR_NORTH, EventScript_FollowerMoveNorth
	case DIR_EAST, EventScript_FollowerMoveEast
	case DIR_SOUTH, EventScript_FollowerMoveSouth
	case DIR_WEST, EventScript_FollowerMoveWest
	return

EventScript_FollowerMoveNorth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkDown
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceUp
	waitmovement 0
	return

EventScript_FollowerMoveEast:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkLeft
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceRight
	waitmovement 0
	return

EventScript_FollowerMoveSouth:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkUp
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceDown
	waitmovement 0
	return

EventScript_FollowerMoveWest:
	applymovement OBJ_EVENT_ID_PLAYER, Movement_WalkRight
	waitmovement 0
	applymovement OBJ_EVENT_ID_PLAYER, Common_Movement_FaceLeft
	waitmovement 0
	return

EventScript_FollowerJumpNorth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpUp
	waitmovement 0
	return

EventScript_FollowerJumpEast:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpRight
	waitmovement 0
	return

EventScript_FollowerJumpSouth:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpDown
	waitmovement 0
	return

EventScript_FollowerJumpWest:
	applymovement OBJ_EVENT_ID_FOLLOWER, Movement_JumpLeft
	waitmovement 0
	return

EventScript_EndSmash::
	releaseall
	end

Movement_WalkUp:
	walk_up
	step_end

Movement_JumpUp:
	jump_in_place_up
	step_end

Movement_WalkRight:
	walk_right
	step_end

Movement_JumpRight:
	jump_in_place_right
	step_end

Movement_WalkDown:
	walk_down
	step_end

Movement_JumpDown:
	jump_in_place_down
	step_end

Movement_WalkLeft:
	walk_left
	step_end

Movement_JumpLeft:
	jump_in_place_left
	step_end

Movement_SmashRock:
	rock_smash_break
	step_end

EventScript_CantSmashRock::
	msgbox Text_CantSmash, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelSmash::
	closemessage
	releaseall
	end

Text_WantToSmash:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use Rock Smash?$"

Text_WantToSmashItem:
	.string "This rock appears to be breakable.\n"
	.string "Would you like to use the Pickaxe?$"

Text_CantSmash:
	.string "It's a rugged rock, but a Puppet\n"
	.string "may be able to smash it.$"

EventScript_StrengthBoulder::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulder
	checkfieldmove FIELD_MOVE_STRENGTH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseStrengthOtherwise
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
EventScript_StrengthCommon::
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
EventScript_ActivateStrength::
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonUsedStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CanUseStrengthOtherwise::
	partycheckfieldmove FIELD_MOVE_STRENGTH, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUsePowerGlove
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToStrength, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
	closemessage
	dofieldeffect FLDEFF_USE_STRENGTH
	waitstate
	setflag FLAG_SYS_USE_STRENGTH
	msgbox Text_MonAttemptedUseStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_UsePowerGlove::
	lockall
	goto_if_set FLAG_SYS_USE_STRENGTH, EventScript_CheckActivatedBoulderItem
	goto EventScript_UsePowerGlove_SkipCheck

EventScript_CanUsePowerGlove::
	checkitem ITEM_POWER_GLOVE, 1
	goto_if_ne VAR_RESULT, TRUE, EventScript_CantStrength
	msgbox Text_WantToStrengthItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_CancelStrength
EventScript_UsePowerGlove_SkipCheck::
	setflag FLAG_SYS_USE_STRENGTH
	bufferitemname STR_VAR_2, ITEM_POWER_GLOVE
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
EventScript_CheckActivatedBoulderItem:
	bufferitemname STR_VAR_2, ITEM_POWER_GLOVE
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_UseStrength::
	lockall
	goto EventScript_StrengthCommon

EventScript_CantStrength::
	msgbox Text_CantStrength, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CheckActivatedBoulder::
	buffermovename STR_VAR_2, MOVE_STRENGTH
	msgbox Text_StrengthActivated, MSGBOX_DEFAULT
	releaseall
	end

EventScript_CancelStrength::
	closemessage
	releaseall
	end

Text_WantToStrength:
	.string "It's a big boulder, but a Puppet\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use Strength?$"

Text_WantToStrengthItem:
	.string "It's a big boulder, but a Puppet\n"
	.string "may be able to push it aside.\p"
	.string "Would you like to use the Power Glove?$"

Text_MonUsedStrength:
	.string "{STR_VAR_1} used Strength!\p"
	.string "{STR_VAR_1}'s Strength made it\n"
	.string "possible to move boulders around!$"

Text_MonAttemptedUseStrength:
	.string "{STR_VAR_1} attempted to\n"
	.string "use Strength!\p"
	.string "{STR_VAR_1}'s attempt made it\n"
	.string "possible to move boulders around!$"

Text_CantStrength:
	.string "It's a big boulder, but a Puppet\n"
	.string "may be able to push it aside.$"

Text_StrengthActivated:
	.string "{STR_VAR_2} made it possible to move\n"
	.string "boulders around.$"

EventScript_UseWaterfall::
	lockall
	checkfieldmove FIELD_MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseWaterfallOtherwise
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	buffermovename STR_VAR_2, MOVE_WATERFALL
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
EventScript_WaterfallCommon::
	hidefollowernpc
	dofieldeffect FLDEFF_USE_WATERFALL
	callnative FollowerNPC_WarpSetEnd
	goto EventScript_EndWaterfall

EventScript_CanUseWaterfallOtherwise::
	partycheckfieldmove FIELD_MOVE_WATERFALL
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseSurfboardPlusWaterfall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToWaterfall, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
	buffermovename STR_VAR_2, MOVE_WATERFALL
	msgbox Text_MonAttemptedToUseFieldMove, MSGBOX_DEFAULT
	goto EventScript_WaterfallCommon

EventScript_UseSurfboardPlusWaterfall::
	lock
	goto EventScript_UseSurfboardPlusWaterfall_SkipCheck

EventScript_CanUseSurfboardPlusWaterfall::
	checkitem ITEM_SURFBOARD_PLUS, 1
	goto_if_ne VAR_RESULT, TRUE, EventScript_CantWaterfall
	msgbox Text_WantToWaterfallItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndWaterfall
EventScript_UseSurfboardPlusWaterfall_SkipCheck::
	bufferitemname STR_VAR_2, ITEM_SURFBOARD_PLUS
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
	waitmessage
	setskipshowanim
	goto EventScript_WaterfallCommon

EventScript_CannotUseWaterfall::
	lockall
EventScript_CantWaterfall::
	msgbox Text_CantWaterfall, MSGBOX_DEFAULT
EventScript_EndWaterfall::
	releaseall
	end

Text_CantWaterfall:
	.string "A wall of water is crashing down with\n"
	.string "a mighty roar.$"

Text_WantToWaterfall:
	.string "It's a large waterfall.\n"
	.string "Would you like to use Waterfall?$"

Text_WantToWaterfallItem:
	.string "It's a large waterfall.\n"
	.string "Would you like to use the Surfboard?$"

EventScript_UseDive::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantDive
	copyvar 0x8004 VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToDive, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndDive
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	setfieldeffectargument 0, VAR_0x8004
	setfieldeffectargument 1, 1
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive
	end

EventScript_CantDive::
	msgbox Text_CantDive, MSGBOX_DEFAULT
	releaseall
	end

EventScript_EndDive::
	releaseall
	end

EventScript_UseScubaGear::
	lockall
	goto EventScript_UseDiveItem_SkipCheck

EventScript_UseDiveItem_SkipCheck::
	bufferitemname STR_VAR_2, ITEM_SCUBA_GEAR
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
	waitmessage
	setskipshowanim
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndDive

EventScript_UseDiveUnderwater::
	lockall
	checkfieldmove FIELD_MOVE_DIVE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantSurface
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	setfieldeffectargument 1, 1
	msgbox Text_WantToSurface, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_NoSurface
	msgbox Text_MonUsedDive, MSGBOX_DEFAULT
	hidefollowernpc
	dofieldeffect FLDEFF_USE_DIVE
	goto EventScript_EndSurface
	end

EventScript_CantSurface::
	lockall
	msgbox Text_CantSurface, MSGBOX_DEFAULT
	goto EventScript_EndSurface
	end

EventScript_EndSurface::
	callnative SetFollowerNPCSurfSpriteAfterDive
EventScript_NoSurface::
	releaseall
	end

EventScript_DigCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_DIG
	waitstate
EventScript_DigSealedChamber:: @ fallthrough
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	callnative DoBrailleDigEffect
	releaseall
	end

@ Use Dig from party menu
EventScript_UseDig::
	lockall
	goto EventScript_DigCommon


EventScript_CutGrassCommon:
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if true
	dofieldeffect FLDEFF_USE_CUT_ON_GRASS
	waitstate

@ Use Cut grass from party menu
EventScript_UseCutGrass::
	lockall
	goto EventScript_CutGrassCommon

Text_CantDive:
	.string "The sea is deep here. A Puppet\n"
	.string "may be able to go underwater.$"

Text_WantToDive:
	.string "The sea is deep here.\n"
	.string "Would you like to use Dive?$"

Text_MonUsedDive:
	.string "{STR_VAR_1} used Dive.$"

Text_CantSurface:
	.string "Light is filtering down from above.\n"
	.string "A Puppet may be able to surface.$"

Text_WantToSurface:
	.string "Light is filtering down from above.\n"
	.string "Would you like to use Dive?$"

EventScript_FailSweetScent::
	msgbox Text_FailSweetScent, MSGBOX_SIGN
	end

Text_FailSweetScent:
	.string "Looks like there's nothing here…$"

EventScript_UseDefog::
	lockall
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	buffermovename STR_VAR_2, MOVE_DEFOG
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
	isfollowerfieldmoveuser VAR_0x8004
	setfieldeffectargument 3, VAR_0x8004 @ skip pose if so
	setflag FLAG_SAFE_FOLLOWER_MOVEMENT
	call_if_eq VAR_0x8004, TRUE, EventScript_FollowerFieldMove
	waitmovement 0
	setfieldeffectargument 0, VAR_RESULT
	dofieldeffect FLDEFF_DEFOG
	waitstate
	releaseall
	end

EventScript_UseRockClimb::
	lockall
	checkfieldmove FIELD_MOVE_ROCK_CLIMB, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CantRockClimb
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	setfieldeffectargument 0, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
	buffermovename STR_VAR_2, MOVE_ROCK_CLIMB
	msgbox Text_MonUsedFieldMove, MSGBOX_DEFAULT
	closemessage
EventScript_RockClimbCommon::
	dofieldeffect FLDEFF_USE_ROCK_CLIMB
	waitstate
EventScript_EndRockClimb::
	releaseall
	end

EventScript_CanUseRockClimbOtherwise::
	partycheckfieldmove FIELD_MOVE_ROCK_CLIMB, TRUE
	goto_if_eq VAR_RESULT, PARTY_SIZE, EventScript_CanUseClimbingGear
	setfieldeffectargument 0, VAR_RESULT
	bufferpartymonnick STR_VAR_1, VAR_RESULT
	msgbox Text_WantToRockClimb, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
	buffermovename STR_VAR_2, MOVE_ROCK_CLIMB
	msgbox Text_MonAttemptedToUseFieldMove, MSGBOX_DEFAULT
	closemessage
	goto EventScript_RockClimbCommon

EventScript_UseClimbingGear::
	lock
	goto EventScript_UseClimbingGear_SkipCheck

EventScript_CanUseClimbingGear::
	checkitem ITEM_CLIMBING_GEAR, 1
	goto_if_ne VAR_RESULT, TRUE, EventScript_CantRockClimb
	msgbox Text_WantToRockClimbItem, MSGBOX_YESNO
	goto_if_eq VAR_RESULT, NO, EventScript_EndRockClimb
EventScript_UseClimbingGear_SkipCheck::
	bufferitemname STR_VAR_2, ITEM_CLIMBING_GEAR
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
	waitmessage
	setskipshowanim
	goto EventScript_RockClimbCommon

EventScript_CantRockClimb::
	msgbox Text_CantRockClimb, MSGBOX_DEFAULT
	goto EventScript_EndRockClimb

Text_WantToRockClimb:
	.string "The cliff is steep.\n"
	.string "Would you like to use Rock Climb?$"

Text_WantToRockClimbItem:
	.string "The cliff is steep.\n"
	.string "Would you like to use the Climbing\l"
	.string "Gear?$"

Text_CantRockClimb:
	.string "The cliff is steep.\n"
	.string "A Puppet may be able to climb it.$"

EventScript_UseLantern::
	animateflash 0
	setflashlevel 0
	delay 40
	bufferitemname STR_VAR_2, ITEM_LANTERN
	msgbox Text_PlayerUsedFieldTool, MSGBOX_DEFAULT
	closemessage
	end
