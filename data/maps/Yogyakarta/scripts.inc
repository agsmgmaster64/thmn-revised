Yogyakarta_MapScripts::
	map_script MAP_SCRIPT_ON_LOAD, Yogyakarta_OnLoad
	map_script MAP_SCRIPT_ON_TRANSITION, Yogyakarta_OnTransition
	.byte 0
	
Yogyakarta_OnLoad:
	call_if_eq VAR_JAVA_GEMS_OBTAINED, 7, Yogyakarta_EventScript_ShowPrismCave
	setflag FLAG_PLAYER_IN_JAVA
	end
	
Yogyakarta_OnTransition:
	setflag FLAG_VISITED_YOGYAKARTA
	call_if_set FLAG_MT_MERAPI_SAVED, Yogyakarta_EventScript_CalmWeather
	end

Yogyakarta_EventScript_CitySign::
	msgbox Yogyakarta_Text_CitySign, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_AichiHouse::
	msgbox Yogyakarta_Text_AichiHouse, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_OldmanSugiho::
	msgbox Yogyakarta_Text_OldmanSugiho, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_House1::
	msgbox Yogyakarta_Text_House1, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_House2::
	msgbox Yogyakarta_Text_House2, MSGBOX_SIGN
	end
	
Yogyakarta_EventScript_BlockingScientist::
	msgbox Yogyakarta_Text_BlockingScientist, MSGBOX_NPC
	applymovement LOCALID_YOGYAKARTA_BLOCKING_SCIENTIST, Common_Movement_FaceOriginalDirection
	end
	
Yogyakarta_EventScript_BlockingHiker::
	msgbox Yogyakarta_Text_BlockingHiker, MSGBOX_NPC
	applymovement LOCALID_YOGYAKARTA_BLOCKING_HIKER, Common_Movement_FaceOriginalDirection
	end
	
Yogyakarta_EventScript_AichiHouseLocked::
	msgbox Yogyakarta_Text_AichiHouseLocked, MSGBOX_SIGN
	applymovement LOCALID_PLAYER, Common_Movement_WalkDownSlow
	end
	
Yogyakarta_EventScript_BrahmStart::
	lock
	faceplayer
	compare VAR_JAVA_GEMS_OBTAINED, 7
	goto_if_eq Yogyakarta_EventScript_BrahmFight
	msgbox Yogyakarta_Text_BrahmGivesInfo, MSGBOX_NPC
	end

Yogyakarta_EventScript_BrahmFight::
	msgbox Yogyakarta_Text_BrahmWantsToFight, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Yogyakarta_EventScript_RejectedBrahmFight
	msgbox Yogyakarta_Text_BrahmLetsFight, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_AILE_L_FEU, Yogyakarta_Text_BrahmDefeated
	msgbox Yogyakarta_Text_BrahmWasRight, MSGBOX_DEFAULT
	closemessage
	end
	
Yogyakarta_EventScript_RejectedBrahmFight::
	msgbox Yogyakarta_Text_BrahmRejected, MSGBOX_NPC
	end
	
Yogyakarta_EventScript_OldManSugihoBaseShop::
	lock
	faceplayer
	goto_if_set FLAG_UNLOCK_SUGIHO_OMNISHOP, Yogyakarta_EventScript_OldManSugihoOmniShop
	msgbox Yogyakarta_Text_SugihoPreShop, MSGBOX_DEFAULT
	closemessage
	pokemart Yogyakarta_Mart_Sugiho_Basic
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	
Yogyakarta_EventScript_OldManSugihoOmniShop::
	msgbox Yogyakarta_Text_SugihoPreOmnishop1, MSGBOX_DEFAULT
	closemessage
	msgbox Yogyakarta_Text_SugihoPreOmnishop2, MSGBOX_DEFAULT
	closemessage
	pokemart Yogyakarta_Mart_Sugiho_Omni
	msgbox gText_PleaseComeAgain, MSGBOX_DEFAULT
	release
	end
	
Yogyakarta_EventScript_KazumiIntro::
	lock
	faceplayer
	compare VAR_JAVA_GEMS_OBTAINED, 1
	goto_if_gt Yogyakarta_EventScript_KazumiSearchForWoofle
	msgbox Yogyakarta_Text_KazumiNewFace, MSGBOX_DEFAULT
	closemessage
	delay 20
	msgbox Yogyakarta_Text_KazumiIntroduction, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Yogyakarta_EventScript_KazumiComeBackLater
	msgbox Yogyakarta_Text_KazumiLetsBattle, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KAZUMI, Yogyakarta_Text_KazumiDefeated
	msgbox Yogyakarta_Text_KazumiTakeEmerald, MSGBOX_DEFAULT
	giveitem ITEM_EMERALD
	addvar VAR_JAVA_GEMS_OBTAINED, 1
	msgbox Yogyakarta_Text_KazumiSearchForWoofle, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Yogyakarta_EventScript_KazumiComeBackLater::
	msgbox Yogyakarta_Text_KazumiComeBackLater, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Yogyakarta_EventScript_KazumiSearchForWoofle::
	lock
	faceplayer
	msgbox Yogyakarta_Text_KazumiSearchForWoofle, MSGBOX_DEFAULT
	closemessage
	msgbox Yogyakarta_Text_KazumiRematch, MSGBOX_YESNO
	call_if_eq VAR_RESULT, NO, Yogyakarta_EventScript_KazumiFairEnough
	msgbox Yogyakarta_Text_KazumiRematchStart, MSGBOX_DEFAULT
	closemessage
	trainerbattle_no_intro TRAINER_KAZUMI, Yogyakarta_Text_KazumiDefeatedRematch
	msgbox Yogyakarta_Text_KazumiRematchEnd, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Yogyakarta_EventScript_KazumiFairEnough::
	msgbox Yogyakarta_Text_KazumiFairEnough, MSGBOX_DEFAULT
	closemessage
	release
	end
	
Yogyakarta_EventScript_ShowPrismCave::
	setmetatile 7, 6, METATILE_General_RockWall_GrassBase_LeftCornerUp, TRUE
	setmetatile 7, 7, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 8, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 9, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 10, METATILE_General_RockWall_GrassBase_LeftWall, TRUE
	setmetatile 7, 11, METATILE_General_RockWall_GrassBase_LeftCornerDown, TRUE
	setmetatile 8, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 8, 7, METATILE_General_RockWall_RockBase_LeftCornerUp, TRUE
	setmetatile 8, 8, METATILE_General_RockWall_RockBase_LeftWall, TRUE
	setmetatile 8, 9, METATILE_General_RockWall_RockBase_LeftWall, TRUE
	setmetatile 8, 10, METATILE_General_RockWall_RockBase_LeftCornerDown, TRUE
	setmetatile 8, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 9, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 9, 7, METATILE_General_RockWall_RockBase_NorthCliff, TRUE
	setmetatile 9, 8, METATILE_General_RockWall_Ground, TRUE
	setmetatile 9, 9, METATILE_General_RockWall_Ground, TRUE
	setmetatile 9, 10, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 9, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 10, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 10, 7, METATILE_General_RockWall_RockBase_NorthCliff, TRUE
	setmetatile 10, 8, METATILE_General_RockWall_Ground, TRUE
	setmetatile 10, 9, METATILE_General_RockWall_Ground, TRUE
	setmetatile 10, 10, METATILE_General_CaveEntrance_Top, TRUE
	setmetatile 10, 11, METATILE_General_CaveEntrance_Bottom, FALSE
	setmetatile 11, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 11, 7, METATILE_General_RockWall_RockBase_NorthCliff, TRUE
	setmetatile 11, 8, METATILE_General_RockWall_Ground, TRUE
	setmetatile 11, 9, METATILE_General_RockWall_Ground, TRUE
	setmetatile 11, 10, METATILE_General_RockWall_RockBase, TRUE
	setmetatile 11, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 12, 6, METATILE_General_RockWall_GrassBase_NorthCliff, TRUE
	setmetatile 12, 7, METATILE_General_RockWall_RockBase_RightCornerUp, TRUE
	setmetatile 12, 8, METATILE_General_RockWall_RockBase_RightWall, TRUE
	setmetatile 12, 9, METATILE_General_RockWall_RockBase_RightWall, TRUE
	setmetatile 12, 10, METATILE_General_RockWall_RockBase_RightCornerDown, TRUE
	setmetatile 12, 11, METATILE_General_RockWall_GrassBase, TRUE
	setmetatile 13, 6, METATILE_General_RockWall_GrassBase_RightCornerUp, TRUE
	setmetatile 13, 7, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 8, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 9, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 10, METATILE_General_RockWall_GrassBase_RightWall, TRUE
	setmetatile 13, 11, METATILE_General_RockWall_GrassBase_RightCornerDown, TRUE
	return
	
Yogyakarta_EventScript_CalmWeather::
	setweather WEATHER_NONE
	doweather
	return
	
	.align 2
Yogyakarta_Mart_Sugiho_Basic:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_MAX_POTION
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	pokemartlistend
	
	.align 2
Yogyakarta_Mart_Sugiho_Omni:
	.2byte ITEM_ULTRA_BALL
	.2byte ITEM_GREAT_BALL
	.2byte ITEM_POKE_BALL
	.2byte ITEM_NET_BALL
	.2byte ITEM_DIVE_BALL
	.2byte ITEM_NEST_BALL
	.2byte ITEM_REPEAT_BALL
	.2byte ITEM_TIMER_BALL
	.2byte ITEM_LUXURY_BALL
	.2byte ITEM_PREMIER_BALL
	.2byte ITEM_POTION
	.2byte ITEM_ANTIDOTE
	.2byte ITEM_BURN_HEAL
	.2byte ITEM_ICE_HEAL
	.2byte ITEM_AWAKENING
	.2byte ITEM_PARALYZE_HEAL
	.2byte ITEM_FULL_RESTORE
	.2byte ITEM_MAX_POTION
	.2byte ITEM_HYPER_POTION
	.2byte ITEM_SUPER_POTION
	.2byte ITEM_FULL_HEAL
	.2byte ITEM_REVIVE
	.2byte ITEM_MAX_REVIVE
	.2byte ITEM_FRESH_WATER
	.2byte ITEM_SODA_POP
	.2byte ITEM_LEMONADE
	.2byte ITEM_BEER
	.2byte ITEM_ENERGY_POWDER
	.2byte ITEM_ENERGY_ROOT
	.2byte ITEM_HEAL_POWDER
	.2byte ITEM_REVIVAL_HERB
	.2byte ITEM_ETHER
	.2byte ITEM_MAX_ETHER
	.2byte ITEM_ELIXIR
	.2byte ITEM_MAX_ELIXIR
	.2byte ITEM_LAVA_COOKIE
	.2byte ITEM_BLUE_FLUTE
	.2byte ITEM_YELLOW_FLUTE
	.2byte ITEM_RED_FLUTE
	.2byte ITEM_BLACK_FLUTE
	.2byte ITEM_WHITE_FLUTE
	.2byte ITEM_BERRY_JUICE
	.2byte ITEM_SACRED_ASH
	.2byte ITEM_SHOAL_SALT
	.2byte ITEM_SHOAL_SHELL
	.2byte ITEM_RED_SHARD
	.2byte ITEM_BLUE_SHARD
	.2byte ITEM_YELLOW_SHARD
	.2byte ITEM_GREEN_SHARD
	.2byte ITEM_HP_UP
	.2byte ITEM_PROTEIN
	.2byte ITEM_IRON
	.2byte ITEM_CARBOS
	.2byte ITEM_CALCIUM
	.2byte ITEM_RARE_CANDY
	.2byte ITEM_PP_UP
	.2byte ITEM_ZINC
	.2byte ITEM_PP_MAX
	.2byte ITEM_GUARD_SPEC
	.2byte ITEM_DIRE_HIT
	.2byte ITEM_X_ATTACK
	.2byte ITEM_X_DEFEND
	.2byte ITEM_X_SPEED
	.2byte ITEM_X_ACCURACY
	.2byte ITEM_X_SPECIAL
	.2byte ITEM_POKE_DOLL
	.2byte ITEM_CURSED_TAG
	.2byte ITEM_SUPER_REPEL
	.2byte ITEM_MAX_REPEL
	.2byte ITEM_ESCAPE_ROPE
	.2byte ITEM_REPEL
	.2byte ITEM_SUN_STONE
	.2byte ITEM_MOON_STONE
	.2byte ITEM_FIRE_STONE
	.2byte ITEM_THUNDER_STONE
	.2byte ITEM_LEAF_STONE
	.2byte ITEM_TINY_MUSHROOM
	.2byte ITEM_BIG_MUSHROOM
	.2byte ITEM_PEARL
	.2byte ITEM_BIG_PEARL
	.2byte ITEM_STARDUST
	.2byte ITEM_STAR_PIECE
	.2byte ITEM_NUGGET
	.2byte ITEM_HEART_SCALE
	.2byte ITEM_POWER_WEIGHT
	.2byte ITEM_POWER_BRACER
	.2byte ITEM_POWER_BELT
	.2byte ITEM_POWER_ANKLET
	.2byte ITEM_POWER_LENS
	.2byte ITEM_POWER_BAND
	.2byte ITEM_SHINY_STONE
	.2byte ITEM_EXPERT_BELT
	.2byte ITEM_POWER_HERB
	.2byte ITEM_WIDE_LENS
	.2byte ITEM_FLAME_ORB
	.2byte ITEM_TOXIC_ORB
	.2byte ITEM_CHERI_BERRY
	.2byte ITEM_CHESTO_BERRY
	.2byte ITEM_PECHA_BERRY
	.2byte ITEM_RAWST_BERRY
	.2byte ITEM_ASPEAR_BERRY
	.2byte ITEM_LEPPA_BERRY
	.2byte ITEM_ORAN_BERRY
	.2byte ITEM_PERSIM_BERRY
	.2byte ITEM_LUM_BERRY
	.2byte ITEM_SITRUS_BERRY
	.2byte ITEM_FIGY_BERRY
	.2byte ITEM_WIKI_BERRY
	.2byte ITEM_CHILAN_BERRY
	.2byte ITEM_OCCA_BERRY
	.2byte ITEM_PASSHO_BERRY
	.2byte ITEM_WACAN_BERRY
	.2byte ITEM_RINDO_BERRY
	.2byte ITEM_YACHE_BERRY
	.2byte ITEM_CHOPLE_BERRY
	.2byte ITEM_KEBIA_BERRY
	.2byte ITEM_POMEG_BERRY
	.2byte ITEM_KELPSY_BERRY
	.2byte ITEM_QUALOT_BERRY
	.2byte ITEM_HONDEW_BERRY
	.2byte ITEM_GREPA_BERRY
	.2byte ITEM_TAMATO_BERRY
	.2byte ITEM_SHUCA_BERRY
	.2byte ITEM_COBA_BERRY
	.2byte ITEM_PAYAPA_BERRY
	.2byte ITEM_TANGA_BERRY
	.2byte ITEM_CHARTI_BERRY
	.2byte ITEM_KASIB_BERRY
	.2byte ITEM_HABAN_BERRY
	.2byte ITEM_COLBUR_BERRY
	.2byte ITEM_BABIRI_BERRY
	.2byte ITEM_LIECHI_BERRY
	.2byte ITEM_GANLON_BERRY
	.2byte ITEM_SALAC_BERRY
	.2byte ITEM_PETAYA_BERRY
	.2byte ITEM_APICOT_BERRY
	.2byte ITEM_LANSAT_BERRY
	.2byte ITEM_STARF_BERRY
	.2byte ITEM_BRIGHT_POWDER
	.2byte ITEM_WHITE_HERB
	.2byte ITEM_MACHO_BRACE
	.2byte ITEM_EXP_SHARE
	.2byte ITEM_QUICK_CLAW
	.2byte ITEM_SOOTHE_BELL
	.2byte ITEM_MENTAL_HERB
	.2byte ITEM_CHOICE_BAND
	.2byte ITEM_KINGS_ROCK
	.2byte ITEM_SILVER_POWDER
	.2byte ITEM_AMULET_COIN
	.2byte ITEM_CLEANSE_TAG
	.2byte ITEM_SOUL_DEW
	.2byte ITEM_KUSANAGI
	.2byte ITEM_YATA_MIRROR
	.2byte ITEM_SMOKE_BALL
	.2byte ITEM_EVERSTONE
	.2byte ITEM_FOCUS_BAND
	.2byte ITEM_LUCKY_EGG
	.2byte ITEM_SCOPE_LENS
	.2byte ITEM_METAL_COAT
	.2byte ITEM_BENTO_BOX
	.2byte ITEM_CHOICE_SCARF
	.2byte ITEM_ICY_BALL
	.2byte ITEM_SOFT_SAND
	.2byte ITEM_HARD_STONE
	.2byte ITEM_MIRACLE_SEED
	.2byte ITEM_BLACK_GLASSES
	.2byte ITEM_BLACK_BELT
	.2byte ITEM_MAGNET
	.2byte ITEM_MYSTIC_WATER
	.2byte ITEM_SHARP_BEAK
	.2byte ITEM_POISON_BARB
	.2byte ITEM_NEVER_MELT_ICE
	.2byte ITEM_SPELL_TAG
	.2byte ITEM_TWISTED_SPOON
	.2byte ITEM_CHARCOAL
	.2byte ITEM_GOHEI
	.2byte ITEM_SILK_SCARF
	.2byte ITEM_CHOICE_SPECS
	.2byte ITEM_SHELL_BELL
	.2byte ITEM_SCARLET_ROCK
	.2byte ITEM_LIGHT_CLAY
	.2byte ITEM_LUCKY_PUNCH
	.2byte ITEM_PARASOL
	.2byte ITEM_ICEBURN_GEM
	.2byte ITEM_LUNAR_VEST
	.2byte ITEM_RED_SCARF
	.2byte ITEM_BLUE_SCARF
	.2byte ITEM_PINK_SCARF
	.2byte ITEM_GREEN_SCARF
	.2byte ITEM_YELLOW_SCARF
	.2byte ITEM_MASTER_BALL
	pokemartlistend

Yogyakarta_Text_CitySign:
	.string "Yogyakarta\p"
	.string "A peaceful village where\n"
	.string "people and Bonéka thrive.$"
	
Yogyakarta_Text_AichiHouse:
	.string "Aichi and Yukai's home\n"
	.string "Placeholder for JP text$"
	
Yogyakarta_Text_OldmanSugiho:
	.string "Oldman Sugiho\n"
	.string "The World Merchant\p"
	.string "Buy all your needs here!$"
	
Yogyakarta_Text_House1:
	.string "Base Camp$"
	
Yogyakarta_Text_House2:
	.string "Eatherna & Sheffyne's house$"

Yogyakarta_Text_BlockingScientist:
	.string "Oh! You shouldn't be here, you know?\n"
	.string "Mt. Merapi has been having some strange\l"
	.string "reactions, recently!\p"
	.string "If I were you, I would steer clear for\n"
	.string "the time being.$"
	
Yogyakarta_Text_BlockingHiker:
	.string "Hah. My friend and I are here to make\n"
	.string "sure other people don't wander up on\l"
	.string "over here.\p"
	.string "No matter how strong you look, don't\n"
	.string "underestimate the power of nature.$"
	
Yogyakarta_Text_AichiHouseLocked:
	.string "It appears this house is locked.$"
	
Yogyakarta_Text_BrahmGivesInfo:
	.string "Brahm: Ah, welcome to Java, kid.\n"
	.string "You look lost, so I'll give you some\l"
	.string "help.\p"
	.string "Java doesn't really have a gym circuit\n"
	.string "like in other regions.\p"
	.string "Instead there's seven gems that were\n"
	.string "claimed by powerful trainers.\p"
	.string "The seven gems are the Ruby, the\n"
	.string "Sapphire, the Emerald, the Diamond,\l"
	.string "the Pearl, the Topaz, and the Amethyst.\p"
	.string "With these seven gems, a secret cave\n"
	.string "will reveal itself to their keeper.\p"
	.string "It seems as though you got your hands\n"
	.string "on the Ruby, but the other six will be\l"
	.string "tough to get.\p"
	.string "They're all held by powerful trainers\n"
	.string "that made their home here. Beat them\l"
	.string "and you will obtain those gems.\p"
	.string "Be careful and good luck.$"	
	
Yogyakarta_Text_BrahmWantsToFight:
	.string "Brahm: I see you have collected all\n"
	.string "seven gems.\p"
	.string "Perhaps with those in hand, you'll find\n"
	.string "the secret cave, wherever it hides.\p"
	.string "However, knowing that you have gathered\n"
	.string "the seven gems…\p"
	.string "I can feel my old blood boiling!\n"
	.string "Would you like to battle with me?$"
	
Yogyakarta_Text_BrahmRejected:
	.string "Brahm: I see… So be it.\p"
	.string "I will be here if you change your mind.$"
	
Yogyakarta_Text_BrahmLetsFight:
	.string "Brahm: Excellent. Come, let us fight!$"
	
Yogyakarta_Text_BrahmDefeated:
	.string "And so it ends…$"
	
Yogyakarta_Text_BrahmWasRight:
	.string "Brahm: I was right, you're a strong\n"
	.string "trainer indeed.\p"
	.string "Come back if you wish to fight me\n"
	.string "again, do you hear me?$"
	
Yogyakarta_Text_SugihoPreShop:
	.string "Oldman Sugiho: Fufufu… are you a\n"
	.string "traveler?\p"
	.string "Welcome!\p"
	.string "How may I serve you?$"
	
Yogyakarta_Text_SugihoPreOmnishop1:
	.string "Oldman Sugiho: Fufufu… are you a\n"
	.string "traveler?$"

Yogyakarta_Text_SugihoPreOmnishop2:
	.string "Hmm…\p"
	.string "I have a strange feeling that we've\n"
	.string "met before, a very long time ago…\p"
	.string "Anyway…\p"
	.string "Welcome!\p"
	.string "How may I serve you?$"
	
Yogyakarta_Text_KazumiNewFace:
	.string "???: Hi there! You're a new face.$"
	
Yogyakarta_Text_KazumiIntroduction:
	.string "Kazumi: I'm Kazumi, a member of\n"
	.string "the AOI Elite SP.\p"
	.string "We're a group of special trainers\n"
	.string "that possess Java's seven gemstones.\p"
	.string "That Ruby you hold… I remember that\n"
	.string "Aichi gave it to Suzakurenzan…\p"
	.string "So the old man must've seen something\n"
	.string "special in you.\p"
	.string "So, gem holder to gem holder…\n"
	.string "Care for a battle?$"
	
Yogyakarta_Text_KazumiComeBackLater:
	.string "Kazumi: It's alright if you're not\n"
	.string "ready yet.\p"
	.string "Come back when you are!$"
	
Yogyakarta_Text_KazumiSearchForWoofle:
	.string "Kazumi: Next, you must search for\n"
	.string "AOI Elite SP Woofle.\p"
	.string "Show that Emerald to him and he will\n"
	.string "battle you.$"
	
Yogyakarta_Text_KazumiDefeated:
	.string "Wow, you're better than I thought!$"
	
Yogyakarta_Text_KazumiLetsBattle:
	.string "Kazumi: Let's see what Renzan sees\n"
	.string "in you!$"
	
Yogyakarta_Text_KazumiTakeEmerald:
	.string "Kazumi: Well done!\n"
	.string "That was a great battle.\p"
	.string "Please, take this Emerald as proof of\n"
	.string "defeating me.$"
	
Yogyakarta_Text_KazumiRematch:
	.string "Kazumi: That being said, if you're\n"
	.string "up for a rematch, I'd be willing to\l"
	.string "fight you again.\p"
	.string "Would you be interested in another\n"
	.string "fight?$"
	
Yogyakarta_Text_KazumiFairEnough:
	.string "Kazumi: Ah! I suppose that's fair\n"
	.string "enough.\p"
	.string "But if you ever want a rematch, I'll\n"
	.string "be waiting here.$"
	
Yogyakarta_Text_KazumiRematchStart:
	.string "Kazumi: Ah, good! Let's see how you've\n"
	.string "improved!$"
	
Yogyakarta_Text_KazumiRematchEnd:
	.string "Kazumi: Don't ever count yourself short,\n"
	.string "you hear me?\p"
	.string "You're way too good for that.$"
	
Yogyakarta_Text_KazumiDefeatedRematch:
	.string "You're just as good as I remembered!$"
