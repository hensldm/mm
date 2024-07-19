#include "regs.h"
#include "libc64/malloc.h"
#include "libu64/gfxprint.h"
#include "macros.h"

#include "functions.h"

#include "color.h"
#include "gfx.h"
#include "gfxalloc.h"
#include "z64debug.h"
#include "z64effect_ss.h"
#include "z64math.h"
#include "z64play.h"

RegEditor* gRegEditor;

void Regs_Init(void) {
    s32 i;

    gRegEditor = malloc(sizeof(RegEditor));
    if (1) {}
    gRegEditor->regPage = 0;
    gRegEditor->regGroup = 0;
    gRegEditor->regCur = 0;
    gRegEditor->inputRepeatTimer = 0;
    gRegEditor->dPadInputPrev = 0;

    for (i = 0; i < ARRAY_COUNT(gRegEditor->data); i++) {
        gRegEditor->data[i] = 0;
    }
}

// Added Debug functions

static Color_RGBA8 sDebugColors[] = {
    { 0, 0, 0, 0 },       // DEBUG_COLOR_BLACK
    { 255, 255, 255, 0 }, // DEBUG_COLOR_WHITE
    { 255, 0, 0, 0 },     // DEBUG_COLOR_RED
    { 255, 255, 0, 0 },   // DEBUG_COLOR_YELLOW
    { 255, 0, 255, 0 },   // DEBUG_COLOR_PINK
    { 0, 255, 0, 0 },     // DEBUG_COLOR_GREEN
    { 0, 255, 255, 0 },   // DEBUG_COLOR_CYAN
    { 0, 0, 255, 0 },     // DEBUG_COLOR_BLUE
    { 128, 128, 128, 0 }, // DEBUG_COLOR_GREY
};

void Debug_SpawnDust(PlayState* play, Vec3f* pos, DebugColor color) {
    if ((color < 0) || (color >= DEBUG_COLOR_MAX)) {
        color = DEBUG_COLOR_BLACK;
    }

    func_800B0EB0(play, pos, &gZeroVec3f, &gZeroVec3f, &sDebugColors[color], &sDebugColors[color], 100, 5, 10);
}

void Debug_PrintScreen(PlayState* play, s32 x, s32 y, DebugColor color, const char* fmt, ...) {
    GfxPrint printer;
    Gfx* gfxHead;
    Gfx* gfx;

    va_list args;
    va_start(args, fmt);

    if ((color < 0) || (color >= DEBUG_COLOR_MAX)) {
        color = DEBUG_COLOR_BLACK;
    }

    OPEN_DISPS(play->state.gfxCtx);

    Gfx_SetupDL28_Opa(play->state.gfxCtx);

    GfxPrint_Init(&printer);

    gfxHead = POLY_OPA_DISP;
    gfx = Gfx_Open(gfxHead);
    gSPDisplayList(OVERLAY_DISP++, gfx);

    GfxPrint_Open(&printer, gfx);

    GfxPrint_SetColor(&printer, sDebugColors[color].r, sDebugColors[color].g, sDebugColors[color].b, 255);

    GfxPrint_SetPos(&printer, x, y);
    GfxPrint_VPrintf(&printer, fmt, args);

    gfx = GfxPrint_Close(&printer);

    gSPEndDisplayList(gfx++);
    Gfx_Close(gfxHead, gfx);
    POLY_OPA_DISP = gfx;

    GfxPrint_Destroy(&printer);

    va_end(args);

    CLOSE_DISPS(play->state.gfxCtx);
}
