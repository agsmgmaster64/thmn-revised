#ifndef GUARD_REGISTERED_ITEMS_MENU
#define GUARD_REGISTERED_ITEMS_MENU

struct TxRegItemsMenu_ItemPageStruct
{
    u16 cursorPos;
    u16 itemsAbove;
    u8 pageItems;
    u8 count;
};

void TxRegItemsMenu_OpenMenu(void);

#endif // GUARD_REGISTERED_ITEMS_MENU