#ifndef GUARD_CONSTANTS_FIELD_MUGSHOTS_H
#define GUARD_CONSTANTS_FIELD_MUGSHOTS_H

// don't remove the `+ 32`
// otherwise your sprite will not be placed in the place you desire
#define MUGSHOT_X 168 + 32
#define MUGSHOT_Y 51  + 32

enum Mugshots {
    MUGSHOT_NONE = 0,
    MUGSHOT_TEST,
    MUGSHOT_COUNT,
};

enum MugshotEmotes {
    EMOTE_NORMAL = 0,
    EMOTE_ALT,
    EMOTE_COUNT,
};

#endif // GUARD_CONSTANTS_FIELD_MUGSHOTS_H
