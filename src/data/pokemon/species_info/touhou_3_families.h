#ifdef __INTELLISENSE__
const struct SpeciesInfo gSpeciesInfoTouhou3[] =
{
#endif

    [SPECIES_KEDAMA] =
    {
        .baseHP        = 100,
        .baseAttack    = 100,
        .baseDefense   = 100,
        .baseSpeed     = 100,
        .baseSpAttack  = 100,
        .baseSpDefense = 100,
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
        .speciesName = _("Kedama"),
        .cryId = CRY_KEDAMA,
        .natDexNum = NATIONAL_DEX_PARAS,
        .categoryName = _("Dummy"),
        .height = 1,
        .weight = 100,
        .description = COMPOUND_STRING(
            "Placeholder."),
        .pokemonScale = 256,
        .pokemonOffset = 1,
        .trainerScale = 302,
        .trainerOffset = 3,
        .frontPic = gMonFrontPic_Kedama,
        .frontPicSize = MON_COORDS_SIZE(64, 64),
        .frontPicYOffset = 0,
        .frontAnimFrames = sAnims_GenericBlinkingAnim,
        .frontAnimId = ANIM_V_SQUISH_AND_BOUNCE,
        .enemyMonElevation = 0,
        .backPic = gMonBackPic_Kedama,
        .backPicSize = MON_COORDS_SIZE(64, 64),
        .backPicYOffset = 0,
        .backAnimId = BACK_ANIM_NONE,
        .palette = gMonPalette_Kedama,
        .shinyPalette = gMonShinyPalette_Kedama,
        .iconSprite = gMonIcon_Kedama,
        .iconPalIndex = 0,
        .levelUpLearnset = sKedamaLevelUpLearnset,
        .teachableLearnset = sKedamaTeachableLearnset,
    },

#ifdef __INTELLISENSE__
};
#endif
