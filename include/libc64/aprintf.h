#ifndef LIBC64_APRINTF_H
#define LIBC64_APRINTF_H

#include "ultra64.h"

#include "stdarg.h"

#include "lib/ultralib/src/libc/xstdio.h"

typedef void* (*PrintCallback)(void*, const char*, size_t);

int vaprintf(PrintCallback* pfn, const char* fmt, va_list args);
int aprintf(PrintCallback* pfn, const char* fmt, ...);

#endif
