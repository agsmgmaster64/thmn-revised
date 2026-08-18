static const u32 sFieldMugshotGfx_TestNormal[] = INCGFX_U32("graphics/field_mugshots/test/normal.png", ".4bpp.smol");
static const u32 sFieldMugshotGfx_TestAlt[] = INCGFX_U32("graphics/field_mugshots/test/alt.png", ".4bpp.smol");
static const u16 sFieldMugshotPal_TestNormal[] = INCGFX_U16("graphics/field_mugshots/test/normal.png", ".gbapal");
static const u16 sFieldMugshotPal_TestAlt[] = INCGFX_U16("graphics/field_mugshots/test/alt.png", ".gbapal");

static const u32 sFieldMugshotGfx_Renko[] = INCGFX_U16("graphics/field_mugshots/player/renko.png", ".4bpp.smol");
static const u16 sFieldMugshotPal_Renko[] = INCGFX_U16("graphics/field_mugshots/player/renko.png", ".gbapal");
static const u32 sFieldMugshotGfx_Maribel[] = INCGFX_U16("graphics/field_mugshots/player/maribel.png", ".4bpp.smol");
static const u16 sFieldMugshotPal_Maribel[] = INCGFX_U16("graphics/field_mugshots/player/maribel.png", ".gbapal");

struct MugshotGfx
{
    const u32 *gfx;
    const u16 *pal;
    u16 x;
    u16 y;
};

static const struct MugshotGfx sFieldMugshots[MUGSHOT_COUNT][EMOTE_COUNT] =
{
    [MUGSHOT_TEST] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_TestNormal,
            .pal = sFieldMugshotPal_TestNormal,
        },

        [EMOTE_ALT] =
        {
            .gfx = sFieldMugshotGfx_TestAlt,
            .pal = sFieldMugshotPal_TestAlt,
        },
    },

    [MUGSHOT_RENKO] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Renko,
            .pal = sFieldMugshotPal_Renko,
        },
    },

    [MUGSHOT_MARIBEL] =
    {
        [EMOTE_NORMAL] =
        {
            .gfx = sFieldMugshotGfx_Maribel,
            .pal = sFieldMugshotPal_Maribel,
        },
    },
};
