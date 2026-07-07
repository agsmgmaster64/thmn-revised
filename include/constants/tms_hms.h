#ifndef GUARD_CONSTANTS_TMS_HMS_H
#define GUARD_CONSTANTS_TMS_HMS_H

#define FOREACH_TM(F) \
    F(U_TURN) \
    F(HEART_BREAK) \
    F(WATER_PULSE) \
    F(CALM_MIND) \
    F(ROAR) \
    F(TOXIC) \
    F(HAIL) \
    F(BULK_UP) \
    F(BULLET_SEED) \
    F(MULTI_PULSE) \
    F(SUNNY_DAY) \
    F(TAUNT) \
    F(ICE_BEAM) \
    F(BLIZZARD) \
    F(LUNATIC) \
    F(LIGHT_SCREEN) \
    F(PROTECT) \
    F(RAIN_DANCE) \
    F(GIGA_DRAIN) \
    F(SAFEGUARD) \
    F(RAZOR_WIND) \
    F(SOLAR_BEAM) \
    F(STEEL_FIST) \
    F(THUNDERBOLT) \
    F(THUNDER) \
    F(EARTHQUAKE) \
    F(RETURN) \
    F(DIG) \
    F(MANA_BURST) \
    F(SHADOW_BALL) \
    F(BRICK_BREAK) \
    F(SPIKES) \
    F(REFLECT) \
    F(SHOCK_WAVE) \
    F(FLAMETHROWER) \
    F(POISON_BOMB) \
    F(SANDSTORM) \
    F(FIRE_BLAST) \
    F(ROCK_TOMB) \
    F(AERIAL_ACE) \
    F(SIGNAL_BEAM) \
    F(FACADE) \
    F(POISON_JAB) \
    F(REST) \
    F(ENERGY_LIGHT) \
    F(THIEF) \
    F(MANA_PUNCH) \
    F(SUBSTITUTE) \
    F(SOAR) \
    F(MYSTICAL_FIRE)

#define FOREACH_HM(F) \
    F(CUT) \
    F(FLY) \
    F(SURF) \
    F(STRENGTH) \
    F(FLASH) \
    F(ROCK_SMASH) \
    F(WATERFALL) \
    F(SHADOW_DIVE)

#define FOREACH_TMHM(F) \
    FOREACH_TM(F) \
    FOREACH_HM(F)

#endif
