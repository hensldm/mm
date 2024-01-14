#include "global.h"

OSPiHandle* sISVHandle; // official name : is_Handle

#define gISVDbgPrnAdrs 0xB3FF0000

#define ISV_BASE gISVDbgPrnAdrs
#define ISV_MAGIC_ADDR (ISV_BASE + 0x00)
#define ISV_GET_ADDR (ISV_BASE + 0x04)
#define ISV_PUT_ADDR (ISV_BASE + 0x14)
#define ISV_BUFFER (ISV_BASE + 0x20)

#define ISV_BUFFER_LEN (0x10000 - 0x20)

#define IS64_MAGIC 0x49533634 // 'IS64'

void isPrintfInit(void) {
    sISVHandle = osCartRomInit();
    osEPiWriteIo(sISVHandle, ISV_PUT_ADDR, 0);
    osEPiWriteIo(sISVHandle, ISV_GET_ADDR, 0);
    osEPiWriteIo(sISVHandle, ISV_MAGIC_ADDR, IS64_MAGIC);
}

void* is_proutSyncPrintf(void* arg, const char* str, size_t count);

void osSyncPrintfUnused(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(is_proutSyncPrintf, NULL, fmt, args);

    va_end(args);
}

void osSyncPrintf(const char* fmt, ...) {
    u32 prevInt;
    va_list args;
    va_start(args, fmt);

    prevInt = __osDisableInt();

    _Printf(is_proutSyncPrintf, NULL, fmt, args);

    __osRestoreInt(prevInt);

    va_end(args);
}

void rmonPrintf(const char* fmt, ...) {
    va_list args;
    va_start(args, fmt);

    _Printf(is_proutSyncPrintf, NULL, fmt, args);

    va_end(args);
}

void* is_proutSyncPrintf(void* arg, const char* str, size_t count) {
    u32 data;
    s32 pos;
    s32 start;
    s32 end;

    osEPiReadIo(sISVHandle, ISV_MAGIC_ADDR, &data);
    if (data != IS64_MAGIC) {
        return (void*)1;
    }
    osEPiReadIo(sISVHandle, ISV_GET_ADDR, &data);
    pos = data;
    osEPiReadIo(sISVHandle, ISV_PUT_ADDR, &data);
    start = data;
    end = start + count;
    if (end >= ISV_BUFFER_LEN) {
        end -= ISV_BUFFER_LEN;
        if (pos < end || start < pos) {
            return (void*)1;
        }
    } else {
        if (start < pos && pos < end) {
            return (void*)1;
        }
    }
    while (count) {
        u32 addr = ISV_BUFFER + (start & 0xFFFFFFC);
        s32 shift = ((3 - (start & 3)) * 8);

        if (*str) {
            osEPiReadIo(sISVHandle, addr, &data);
            osEPiWriteIo(sISVHandle, addr, (*str << shift) | (data & ~(0xFF << shift)));

            start++;
            if (start >= ISV_BUFFER_LEN) {
                start -= ISV_BUFFER_LEN;
            }
        }
        count--;
        str++;
    }
    osEPiWriteIo(sISVHandle, ISV_PUT_ADDR, start);

    return (void*)1;
}

void func_80002384(const char* exp, const char* file, u32 line) {
    osSyncPrintf("File:%s Line:%d  %s \n", file, line, exp);
    while (true) {}
}
