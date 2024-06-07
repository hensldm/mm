#ifndef LIBC64_APRINTF_H
#define LIBC64_APRINTF_H

#include "ultra64.h"

#include "stdarg.h"

#include "lib/ultralib/src/libc/xstdio.h"

int vaprintf(outfun* pfn, const char* fmt, va_list args);
int aprintf(outfun* pfn, const char* fmt, ...);

#endif
