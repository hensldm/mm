// Force the inclusion of unused archive files

// setcause.o
EXTERN(__osSetCause);
ASSERT(DEFINED(__osSetCause), "Error: __osSetCause was not linked");

// pfsfreeblocks.o
EXTERN(osPfsFreeBlocks);
ASSERT(DEFINED(osPfsFreeBlocks), "Error: osPfsFreeBlocks was not linked");

// stopthread.o
EXTERN(osStopThread);
ASSERT(DEFINED(osStopThread), "Error: osStopThread was not linked");

// getintmask.o
EXTERN(osGetIntMask);
ASSERT(DEFINED(osGetIntMask), "Error: osGetIntMask was not linked");

// pfsreadwritefile.o
EXTERN(osPfsReadWriteFile);
ASSERT(DEFINED(osPfsReadWriteFile), "Error: osPfsReadWriteFile was not linked");

// getconfig.o
EXTERN(__osGetConfig);
ASSERT(DEFINED(__osGetConfig), "Error: __osGetConfig was not linked");

// setconfig.o
EXTERN(__osSetConfig);
ASSERT(DEFINED(__osSetConfig), "Error: __osSetConfig was not linked");

// pfsallocatefile.o
EXTERN(osPfsAllocateFile);
ASSERT(DEFINED(osPfsAllocateFile), "Error: osPfsAllocateFile was not linked");

// position.o
EXTERN(guPositionF);
ASSERT(DEFINED(guPositionF), "Error: guPositionF was not linked");

// getcompare.o
EXTERN(__osGetCompare);
ASSERT(DEFINED(__osGetCompare), "Error: __osGetCompare was not linked");

// pfsdeletefile.o
EXTERN(osPfsDeleteFile);
ASSERT(DEFINED(osPfsDeleteFile), "Error: osPfsDeleteFile was not linked");

// settime.o
EXTERN(osSetTime);
ASSERT(DEFINED(osSetTime), "Error: osSetTime was not linked");

// pfsfilestate.o
EXTERN(osPfsFileState);
ASSERT(DEFINED(osPfsFileState), "Error: osPfsFileState was not linked");

// pfsinitpak.o
EXTERN(osPfsInitPak);
ASSERT(DEFINED(osPfsInitPak), "Error: osPfsInitPak was not linked");

// pfschecker.o
EXTERN(osPfsChecker);
ASSERT(DEFINED(osPfsChecker), "Error: osPfsChecker was not linked");

// gethwinterrupt.o
EXTERN(__osGetHWIntrRoutine);
ASSERT(DEFINED(__osGetHWIntrRoutine), "Error: __osGetHWIntrRoutine was not linked");

// sethwinterrupt.o
EXTERN(__osSetHWIntrRoutine);
ASSERT(DEFINED(__osSetHWIntrRoutine), "Error: __osSetHWIntrRoutine was not linked");

// getwatchlo.o
EXTERN(__osGetWatchLo);
ASSERT(DEFINED(__osGetWatchLo), "Error: __osGetWatchLo was not linked");
