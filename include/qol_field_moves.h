#ifndef GUARD_QOL_FIELD_MOVES_H
#define GUARD_QOL_FIELD_MOVES_H

enum FlyToolSource
{
    FLY_SOURCE_MOVE,
    FLY_SOURCE_FIELD,
    FLY_SOURCE_BAG
};

void ReturnToFieldFromFlyToolMapSelect(void);
bool32 IsFlyToolUsed(void);
void ReturnToFieldOrBagFromFlyTool(void);
void SetFlySource(enum FlyToolSource flySource);
void ResetFlyTool(void);

u32 CanUseSurfFromInteractedWater(void);

void FldEff_UseFlashTool(void);
u32 CanUseLantern(void);

bool32 CanUseWaterfallSurfboardPlus(void);
u32 CanUseWaterfallFromInteractedWater(void);

u32 CanUseDiveDown(void);
u32 CanUseDiveEmerge(void);

bool32 CanUseClmibingGear(void);

bool32 PartyCanUseFieldMove(u32 fieldMove, bool32 doUnlockedCheck, bool32 setVariables);

// https://github.com/PokemonSanFran/pokeemerald/wiki/QoL-Field-Moves#developer-options

#endif // GUARD_QOL_FIELD_MOVES_H
