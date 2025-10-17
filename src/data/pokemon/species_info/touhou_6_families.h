#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoTouhou6[] =
{
#endif

    [SPECIES_CHIBI_REIMU] =
    {
        .baseHP        = 10,
        .baseAttack    = 10,
        .baseDefense   = 10,
        .baseSpeed     = 10,
        .baseSpAttack  = 10,
        .baseSpDefense = 10,
        .types = MON_TYPES(TYPE_NORMAL),
        .catchRate = 255,
        .evYield_HP = 1,
        .evYield_Attack = 1,
        .evYield_Defense = 1,
        .evYield_SpAttack = 1,
        .evYield_SpDefense = 1,
        .evYield_Speed = 1,
        .genderRatio = PERCENT_FEMALE(50),
        .eggCycles = 20,
        .friendship = STANDARD_FRIENDSHIP,
        .growthRate = GROWTH_MEDIUM_FAST,
        .eggGroups = MON_EGG_GROUPS(EGG_GROUP_HUMAN_LIKE),
        .abilities = { ABILITY_ILLUMINATE, ABILITY_NONE, ABILITY_NONE },
        .bodyColor = BODY_COLOR_RED,
        .speciesName = _("CReimu"),
        .cryId = CRY_REIMU,
        .natDexNum = NATIONAL_DEX_BULBASAUR,
        .categoryName = _("Dummy"),
        .height = 1,
        .weight = 100,
        .description = COMPOUND_STRING(
            "Placeholder."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_CircledQuestionMark,
        .frontPicSize = MON_COORDS_SIZE(40, 40),
        .frontPicYOffset = 12,
        .frontAnimFrames = sAnims_TwoFramePlaceHolder,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .backPic = gMonBackPic_CircledQuestionMark,
        .backPicSize = MON_COORDS_SIZE(40, 40),
        .backPicYOffset = 12,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_CircledQuestionMark,
        .shinyPalette = gMonShinyPalette_CircledQuestionMark,
        .iconSprite = gMonIcon_QuestionMark,
        .iconPalIndex = 0,
        FOOTPRINT(QuestionMark)
        .levelUpLearnset = sNoneLevelUpLearnset,
        .teachableLearnset = sNoneTeachableLearnset,
    },

#ifdef __INTELLISENSE__
};
#endif
