#include "global.h"
#include "data.h"
#include "event_data.h"
#include "event_object_movement.h"
#include "event_scripts.h"
#include "field_effect.h"
#include "field_control_avatar.h"
#include "field_move.h"
#include "field_player_avatar.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "fieldmap.h"
#include "fldeff.h"
#include "fldeff_misc.h"
#include "item.h"
#include "item_menu.h"
#include "item_menu_frlg.h"
#include "item_use.h"
#include "map_name_popup.h"
#include "metatile_behavior.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "qol_field_moves.h"
#include "region_map.h"
#include "script.h"
#include "sound.h"
#include "constants/event_objects.h"
#include "constants/field_effects.h"
#include "constants/flags.h"
#include "constants/items.h"
#include "constants/map_types.h"
#include "constants/moves.h"
#include "constants/party_menu.h"
#include "constants/songs.h"
#include "constants/vars.h"

EWRAM_DATA bool8 gFlySource = FLY_SOURCE_MOVE;

static void FieldCallback_UseFlyTool(void);
static void Task_UseFlyTool(void);

static bool32 CanSpeciesLearnMoveLevelUp(enum Species species, enum Move move);
static void SetMonResultVariables(u32 partyIndex, enum Species species);

#define tState      data[0]
#define tFallOffset data[1]
#define tTotalFall  data[2]

static inline u32 GetFieldMoveUsage(enum FieldMove fieldMove, u32 item)
{
    if (PartyCanUseFieldMove(fieldMove, TRUE, FALSE) || CheckBagHasItem(item, 1))
        return TRUE;
    return FALSE;
}

// Fly
void ReturnToFieldFromFlyToolMapSelect(void)
{
    SetMainCallback2(CB2_ReturnToField);
    gFieldCallback = Task_UseFlyTool;
}

static void Task_UseFlyTool(void)
{
    Overworld_ResetStateAfterFly();
    WarpIntoMap();
    SetMainCallback2(CB2_LoadMap);
    gFieldCallback = FieldCallback_UseFlyTool;
}

static void FieldCallback_UseFlyTool(void)
{
    Overworld_PlaySpecialMapMusic();
    FadeInFromBlack();
    if (gPaletteFade.active)
        return;

    UnlockPlayerFieldControls();
    UnfreezeObjectEvents();
    gFieldCallback = NULL;
}

bool32 IsFlyToolUsed(void)
{
    return (gFlySource != FLY_SOURCE_MOVE);
}

void ReturnToFieldOrBagFromFlyTool(void)
{
    if (gFlySource == FLY_SOURCE_BAG)
    {
        if (FRLG_I_USE_FRLG_BAG)
            GoToBagMenuFrlg(ITEMMENULOCATION_LAST, FRLG_POCKET_KEYITEMS, CB2_ReturnToFieldWithOpenMenu);
        else
            GoToBagMenu(ITEMMENULOCATION_LAST, POCKET_KEY_ITEMS, CB2_ReturnToFieldWithOpenMenu);
    }
    else if (gFlySource == FLY_SOURCE_FIELD)
    {
        SetMainCallback2(CB2_ReturnToField);
    }
}

void SetFlySource(enum FlyToolSource flySource)
{
    gFlySource = flySource;
}

void ResetFlyTool(void)
{
    gFlySource = FLY_SOURCE_MOVE;
}

u32 CanUseSurfFromInteractedWater(void)
{
    if (IsPlayerFacingSurfableFishableWater())
    {
        if (GetFieldMoveUsage(FIELD_MOVE_SURF, ITEM_SURFBOARD_PLUS))
            return TRUE;
        return GetFieldMoveUsage(FIELD_MOVE_SURF, ITEM_SURFBOARD);
    }

    return FALSE;
}

// Flash

void FldEff_UseFlashTool(void)
{
    HideMapNamePopUpWindow();
    PlaySE(SE_M_REFLECT);
    FlagSet(FLAG_SYS_USE_FLASH);
    ScriptContext_SetupScript(EventScript_UseLantern);
}

u32 CanUseLantern(void)
{
    bool32 playerIsInCave = (gMapHeader.cave == TRUE);
    bool32 mapIsNotLit = (GetFlashLevel() == (gMaxFlashLevel - 1));
    bool32 playerHasUsedFlash = FlagGet(FLAG_SYS_USE_FLASH);

    if (playerIsInCave && mapIsNotLit && !playerHasUsedFlash)
    {
        return TRUE;
    }
    return FALSE;
}

//Waterfall

u32 CanUseWaterfallFromInteractedWater(void)
{
    if (IsPlayerSurfingNorth())
    {
        return GetFieldMoveUsage(FIELD_MOVE_WATERFALL, ITEM_SURFBOARD_PLUS);
    }

    return FALSE;
}

u32 CanUseWaterfallSurfboardPlus(void)
{
    struct ObjectEvent *playerObjEvent = &gObjectEvents[gPlayerAvatar.objectEventId];
    s16 x = playerObjEvent->currentCoords.x;
    s16 y = playerObjEvent->currentCoords.y;

    MoveCoords(playerObjEvent->facingDirection, &x, &y);
    if (GetCollisionAtCoords(playerObjEvent, x, y, playerObjEvent->facingDirection) == COLLISION_NONE
     && MetatileBehavior_IsWaterfall(MapGridGetMetatileBehaviorAt(x, y))
     && IsPlayerSurfingNorth())
    {
        return TRUE;
    }

    return FALSE;
}

// Dive

u32 CanUseDiveDown(void)
{
    if (TrySetDiveWarp() == 2)
    {
        return GetFieldMoveUsage(FIELD_MOVE_DIVE, ITEM_SCUBA_GEAR);
    }

    return FALSE;
}

u32 CanUseDiveEmerge(void)
{
    if (TrySetDiveWarp() == 1 && gMapHeader.mapType == MAP_TYPE_UNDERWATER)
    {
        return GetFieldMoveUsage(FIELD_MOVE_DIVE, ITEM_SCUBA_GEAR);
    }

    return FALSE;
}


u32 CanUseClmibingGear(void)
{
    s16 x, y;

    GetXYCoordsOneStepInFrontOfPlayer(&x, &y);

    if (MetatileBehavior_IsRockClimbable(MapGridGetMetatileBehaviorAt(x, y)))
    {
        return TRUE;
    }

    return FALSE;
}

static bool32 CanSpeciesLearnMoveLevelUp(enum Species species, enum Move move)
{
    const struct LevelUpMove *learnset = GetSpeciesLevelUpLearnset(species);
    u32 i = 0;

    for (i = 0; learnset[i].move != LEVEL_UP_MOVE_END; i++)
    {
        if (learnset[i].move == move)
            return TRUE;
    }
    return FALSE;
}

bool32 PartyCanUseFieldMove(u32 fieldMove, bool32 doUnlockedCheck, bool32 setVariables)
{
    struct Pokemon *mon;
    u32 i, monCanLearn, canUseMove;
    gSpecialVar_Result = PARTY_SIZE;
    gSpecialVar_0x8004 = 0;
    enum Move move = FieldMove_GetMoveId(fieldMove);

    if (doUnlockedCheck && !IsFieldMoveUnlocked(fieldMove))
        return FALSE;

    for (i = 0; i < PARTY_SIZE; i++)
    {
        mon = &gParties[B_TRAINER_PLAYER][i];
        enum Species species = GetMonData(mon, MON_DATA_SPECIES);

        if (species == SPECIES_NONE)
            break;

        monCanLearn = CanTeachMove(mon, move);

        if (monCanLearn == ALREADY_KNOWS_MOVE)
        {
            if (setVariables)
                SetMonResultVariables(i, species);
            return TRUE;
        }

        if (CanSpeciesLearnMoveLevelUp(species, move) || monCanLearn == CAN_LEARN_MOVE)
        {
            if (setVariables)
                SetMonResultVariables(i, species);
            return TRUE;
        }
    }

    return FALSE;
}

static void SetMonResultVariables(u32 partyIndex, enum Species species)
{
    gSpecialVar_Result = partyIndex;
    gSpecialVar_0x8004 = species;
}

#undef tState
#undef tFallOffset
#undef tTotalFall
