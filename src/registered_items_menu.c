//Credits: TheXaman
#include "global.h"
#include "constants/songs.h"
#include "bg.h"
#include "decoration.h"
#include "event_scripts.h"
#include "event_object_lock.h"
#include "event_object_movement.h"
#include "field_screen_effect.h"
#include "field_weather.h"
#include "gpu_regs.h"
#include "international_string_util.h"
#include "item.h"
#include "item_icon.h"
#include "item_menu.h"
#include "item_menu_icons.h"
#include "constants/items.h"
#include "list_menu.h"
#include "mail.h"
#include "main.h"
#include "malloc.h"
#include "menu.h"
#include "menu_helpers.h"
#include "overworld.h"
#include "palette.h"
#include "party_menu.h"
#include "player_pc.h"
#include "script.h"
#include "sound.h"
#include "sprite.h"
#include "string_util.h"
#include "strings.h"
#include "task.h"
#include "window.h"
#include "menu_specialized.h"
#include "registered_items_menu.h"
#include "graphics.h"

#define REGISTER_MENU_MAX  4

struct TxRegItemsMenu_Struct
{
    struct ListMenuItem listItems[REGISTER_MENU_MAX + 1];
    u8 itemNames[REGISTER_MENU_MAX + 1][ITEM_NAME_LENGTH + 10];
    u8 windowIds[1];
    u8 registerOptions[REGISTER_MENU_MAX];
    u8 itemOriginalLocation;
};

static void TxRegItemsMenu_ClearAndInitData(u8 taskId);
static void TxRegItemsMenu_InitDataAndCreateListMenu(u8 taskId);
static void TxRegItemsMenu_ProcessInput(u8 taskId);
static void TxRegItemsMenu_DoItemAction(u8 taskId);
static void TxRegItemsMenu_RegisterL(u8 taskId);
static void TxRegItemsMenu_RegisterR(u8 taskId);
static void TxRegItemsMenu_CloseMenu(u8 taskId);
//helper
static void TxRegItemsMenu_CalcCursorPos(void);
static void TxRegItemsMenu_AllocateStruct(void);
static u8 TxRegItemsMenu_InitWindow(void);
static void TxRegItemsMenu_RefreshListMenu(void);
static void TxRegItemsMenu_MoveCursor(s32 id, bool8 b, struct ListMenu *thisMenu);
static void TxRegItemsMenu_PrintFunc(u8 windowId, u32 id, u8 yOffset);
static void TxRegItemsMenu_CopyItemName(u8 *string, u32 button);
static void TxRegItemsMenu_PrintMenuCursor(u8 y, u8 b, u8 speed);
static void TxRegItemsMenu_CalcAndSetUsedSlotsCount(void);
static u32 GetRegisteredOptionByPosition(u32 position);
//helper cleanup
static void TxRegItemsMenu_RemoveWindow(void);
static void TxRegItemsMenu_FreeStructs(void);

static const struct WindowTemplate sTxRegItemsMenu_WindowTemplates[] =
{
    {
        .bg = 0,
        .tilemapLeft = 1, //0
        .tilemapTop = 1,
        .width = 14, //30
        .height = 2, //7
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 1, //0
        .tilemapTop = 1,
        .width = 14, //30
        .height = 4, //7
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 1, //0
        .tilemapTop = 1,
        .width = 14, //30
        .height = 6, //7
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
    {
        .bg = 0,
        .tilemapLeft = 1, //0
        .tilemapTop = 1,
        .width = 14, //30
        .height = 8, //7
        .paletteNum = 15,
        .baseBlock = 0x0001
    },
};

static const struct ListMenuTemplate gTxRegItemsMenu_List = //item storage list
{
    .items = NULL,
    .moveCursorFunc = TxRegItemsMenu_MoveCursor,
    .itemPrintFunc = TxRegItemsMenu_PrintFunc,
    .totalItems = 0,
    .maxShowed = 0,
    .windowId = 0,
    .header_X = 0,
    .item_X = 8,
    .cursor_X = 0,
    .upText_Y = 1,
    .cursorPal = 2,
    .fillValue = 1,
    .cursorShadowPal = 3,
    .lettersSpacing = FALSE,
    .itemVerticalPadding = 0,
    .scrollMultiple = FALSE,
    .fontId = FONT_NARROW,
};

// EWRAM
static EWRAM_DATA struct TxRegItemsMenu_Struct *gTxRegItemsMenu = NULL;
static EWRAM_DATA struct TxRegItemsMenu_ItemPageStruct sTxRegItemsMenuItemPageInfo = {0, 0, 0, 0};

static const u8 sListItem_SelectButton[] = _("{SELECT_BUTTON} ");
static const u8 sListItem_LButton[] = _("{L_BUTTON} ");
static const u8 sListItem_RButton[] = _("{R_BUTTON} ");


// functions

static u32 GetRegisteredItemCount(void)
{
    u32 i, count = 0;
    for (i = 0; i < 3; i++)
    {
        if (CheckRegisteredKeyItem(i))
        {
            count++;
        }
    }
    return count;
}

void TxRegItemsMenu_OpenMenu(void)
{
    u8 taskId = CreateTask(TaskDummy, 0);
    FreezeObjects_WaitForPlayer();
    gTasks[taskId].func = TxRegItemsMenu_ClearAndInitData;
}

static void TxRegItemsMenu_ClearAndInitData(u8 taskId)
{
    u8 offset = 0;
    u8 cursorStart = 0;

    sTxRegItemsMenuItemPageInfo.cursorPos = cursorStart;
    sTxRegItemsMenuItemPageInfo.itemsAbove = offset;
    sTxRegItemsMenuItemPageInfo.pageItems = REGISTER_MENU_MAX; //ItemStorage_SetItemAndMailCount(taskId);
    TxRegItemsMenu_AllocateStruct(); //sub_816BC14(); //allocate struct
    gTasks[taskId].func = TxRegItemsMenu_InitDataAndCreateListMenu;
}

static void TxRegItemsMenu_InitDataAndCreateListMenu(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    TxRegItemsMenu_CalcAndSetUsedSlotsCount(); //calculate used slots
    TxRegItemsMenu_CalcCursorPos(); //calc cursor pos
    TxRegItemsMenu_RefreshListMenu();
    data[5] = ListMenuInit(&gMultiuseListMenuTemplate, sTxRegItemsMenuItemPageInfo.itemsAbove, sTxRegItemsMenuItemPageInfo.cursorPos);
    ScheduleBgCopyTilemapToVram(0);
    gTasks[taskId].func = TxRegItemsMenu_ProcessInput;
}

static void TxRegItemsMenu_ProcessInput(u8 taskId)
{
    s16 *data;
    s32 id;

    data = gTasks[taskId].data;
    if (JOY_NEW(L_BUTTON) && CheckRegisteredKeyItem(1))
    {
        TxRegItemsMenu_RegisterL(taskId);
    }
    else if (JOY_NEW(R_BUTTON) && CheckRegisteredKeyItem(2))
    {
        TxRegItemsMenu_RegisterR(taskId);
    }
    else
    {
        id = ListMenu_ProcessInput(data[5]); //fine
        ListMenuGetScrollAndRow(data[5], &(sTxRegItemsMenuItemPageInfo.itemsAbove), &(sTxRegItemsMenuItemPageInfo.cursorPos)); //fine
        switch(id)
        {
        case LIST_NOTHING_CHOSEN:
            break;
        case LIST_CANCEL:
            PlaySE(SE_SELECT);
            ScriptContext_Enable();
            TxRegItemsMenu_CloseMenu(taskId);
            break;
        default:
            PlaySE(SE_SELECT);
            TxRegItemsMenu_DoItemAction(taskId);
            break;
        }
    }
}

static void TxRegItemsMenu_DoItemAction(u8 taskId)
{
    u16 option;

    option = GetRegisteredOptionByPosition(sTxRegItemsMenuItemPageInfo.cursorPos + sTxRegItemsMenuItemPageInfo.itemsAbove);

    TxRegItemsMenu_CloseMenu(taskId);
    UseRegisteredKeyItemOnField(option);
}

static void TxRegItemsMenu_RegisterL(u8 taskId)
{
    PlaySE(SE_SELECT);
    TxRegItemsMenu_CloseMenu(taskId);
    UseRegisteredKeyItemOnField(1);
}

static void TxRegItemsMenu_RegisterR(u8 taskId)
{
    PlaySE(SE_SELECT);
    TxRegItemsMenu_CloseMenu(taskId);
    UseRegisteredKeyItemOnField(2);
}

static void TxRegItemsMenu_CloseMenu(u8 taskId)
{
    s16 *data;

    data = gTasks[taskId].data;
    DestroyListMenuTask(data[5], NULL, NULL);
    TxRegItemsMenu_RemoveWindow();
    TxRegItemsMenu_FreeStructs();
    ScriptUnfreezeObjectEvents();
    DestroyTask(taskId);
}


//helper functions
static void TxRegItemsMenu_AllocateStruct(void)
{
    gTxRegItemsMenu = AllocZeroed(sizeof(struct TxRegItemsMenu_Struct));
    memset(gTxRegItemsMenu->windowIds, 0xFF, 0x1);
    gTxRegItemsMenu->itemOriginalLocation = 0xFF;
}

static u8 TxRegItemsMenu_InitWindow(void)
{
    u8 *windowIdLoc = &(gTxRegItemsMenu->windowIds[0]);
    if (*windowIdLoc == WINDOW_NONE)
    {
        *windowIdLoc = AddWindow(&sTxRegItemsMenu_WindowTemplates[GetRegisteredItemCount()]);
        DrawStdFrameWithCustomTileAndPalette(*windowIdLoc, FALSE, 0x214, 0xE);
        ScheduleBgCopyTilemapToVram(0);
    }
    return *windowIdLoc;
}

static void TxRegItemsMenu_CalcCursorPos(void) //calc cursor pos
{
    SetCursorWithinListBounds(&(sTxRegItemsMenuItemPageInfo.itemsAbove), &(sTxRegItemsMenuItemPageInfo.cursorPos), sTxRegItemsMenuItemPageInfo.pageItems, sTxRegItemsMenuItemPageInfo.count); //fine
}

static void TxRegItemsMenu_RefreshListMenu(void)
{
    u16 i;
    u8 windowId = TxRegItemsMenu_InitWindow();
    LoadMessageBoxAndBorderGfx();
    SetStandardWindowBorderStyle(windowId , 0);

    for(i = 0; i < sTxRegItemsMenuItemPageInfo.count - 1; i++)
    {
        TxRegItemsMenu_CopyItemName(&(gTxRegItemsMenu->itemNames[i][0]), gTxRegItemsMenu->registerOptions[i]);
        gTxRegItemsMenu->listItems[i].name = &(gTxRegItemsMenu->itemNames[i][0]);
        gTxRegItemsMenu->listItems[i].id = i;
    }
    StringCopy(&(gTxRegItemsMenu->itemNames[i][0]) ,gText_Cancel2);
    gTxRegItemsMenu->listItems[i].name = &(gTxRegItemsMenu->itemNames[i][0]);
    gTxRegItemsMenu->listItems[i].id = LIST_CANCEL;
    gMultiuseListMenuTemplate = gTxRegItemsMenu_List;
    gMultiuseListMenuTemplate.windowId = windowId;
    gMultiuseListMenuTemplate.totalItems = sTxRegItemsMenuItemPageInfo.count;
    gMultiuseListMenuTemplate.items = gTxRegItemsMenu->listItems;
    gMultiuseListMenuTemplate.maxShowed = REGISTER_MENU_MAX;//sTxRegItemsMenuItemPageInfo.pageItems;
}

static void TxRegItemsMenu_MoveCursor(s32 id, bool8 b, struct ListMenu *thisMenu)
{
    if (b != TRUE)
        PlaySE(SE_SELECT);
}

static void TxRegItemsMenu_PrintFunc(u8 windowId, u32 id, u8 yOffset)
{
    if (id != MENU_NOTHING_CHOSEN)
    {
        if (gTxRegItemsMenu->itemOriginalLocation != 0xFF)
        {
            if (gTxRegItemsMenu->itemOriginalLocation == (u8)id)
                TxRegItemsMenu_PrintMenuCursor(yOffset, 0, 0xFF);
            else
                TxRegItemsMenu_PrintMenuCursor(yOffset, 0xFF, 0xFF);
        }
    }
}

static void TxRegItemsMenu_CopyItemName(u8 *string, u32 button)
{
    u8 *end;
    switch (button)
    {
    default:
    case 0:
        StringCopy(string, sListItem_SelectButton);
        end = StringAppend(string, GetItemName(gSaveBlock1Ptr->registeredItemSelect));
        break;
    case 1:
        StringCopy(string, sListItem_LButton);
        end = StringAppend(string, GetItemName(gSaveBlock3Ptr->registeredItemL));
        break;
    case 2:
        StringCopy(string, sListItem_RButton);
        end = StringAppend(string, GetItemName(gSaveBlock3Ptr->registeredItemR));
        break;
    }
}

static const u8 gColor_gray[] = {0x01, 0x03, 0x02, 0x00};
static void TxRegItemsMenu_PrintMenuCursor(u8 y, u8 b, u8 speed)
{
    u8 x = 40;
    u8 windowId = gTxRegItemsMenu->windowIds[0];
    if (b == 0xFF)
        FillWindowPixelRect(windowId, PIXEL_FILL(1), x, y, GetMenuCursorDimensionByFont(1, 0), GetMenuCursorDimensionByFont(1, 1));
    else
        AddTextPrinterParameterized4(windowId, 1, x, y, 0, 0, gColor_gray, speed, gText_SelectorArrow2);
}

//registeredItems struct helper functions
static void TxRegItemsMenu_CalcAndSetUsedSlotsCount(void)
{
    u16 i;
    sTxRegItemsMenuItemPageInfo.count = 0;
    for (i = 0; i < 3; i++)
    {
        if (CheckRegisteredKeyItem(i))
        {
            gTxRegItemsMenu->registerOptions[sTxRegItemsMenuItemPageInfo.count] = i;
            sTxRegItemsMenuItemPageInfo.count++;
        }
    }

    sTxRegItemsMenuItemPageInfo.count++;
    if (sTxRegItemsMenuItemPageInfo.count > REGISTER_MENU_MAX)
        sTxRegItemsMenuItemPageInfo.pageItems = REGISTER_MENU_MAX;
    else
        sTxRegItemsMenuItemPageInfo.pageItems = sTxRegItemsMenuItemPageInfo.count;
}

static u32 GetRegisteredOptionByPosition(u32 position)
{
    return gTxRegItemsMenu->registerOptions[position];
}


//helper cleanup
static void TxRegItemsMenu_RemoveWindow(void) //remove window
{
    u8 *windowIdLoc = &(gTxRegItemsMenu->windowIds[0]);
    if (*windowIdLoc != WINDOW_NONE)
    {
        ClearStdWindowAndFrameToTransparent(*windowIdLoc, FALSE);
        ClearWindowTilemap(*windowIdLoc);
        ScheduleBgCopyTilemapToVram(0);
        RemoveWindow(*windowIdLoc);
        *windowIdLoc = WINDOW_NONE;
    }
}

static void TxRegItemsMenu_FreeStructs(void)
{
    Free(gTxRegItemsMenu);
}