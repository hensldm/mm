#ifndef Z64DEBUG_H
#define Z64DEBUG_H

#include "z64math.h"

struct PlayState;

typedef enum DebugColor {
    /* 0 */ DEBUG_COLOR_BLACK,
    /* 1 */ DEBUG_COLOR_WHITE,
    /* 2 */ DEBUG_COLOR_RED,
    /* 3 */ DEBUG_COLOR_YELLOW,
    /* 4 */ DEBUG_COLOR_PINK,
    /* 5 */ DEBUG_COLOR_GREEN,
    /* 6 */ DEBUG_COLOR_CYAN,
    /* 7 */ DEBUG_COLOR_BLUE,
    /* 8 */ DEBUG_COLOR_GREY,
    /* 9 */ DEBUG_COLOR_MAX
} DebugColor;

void Debug_SpawnDust(struct PlayState* play, Vec3f* pos, DebugColor color);

#endif
