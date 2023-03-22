/*
	Custom OSInit for DVD data usage
*/

#include <revolution.h>
#include "customOSInit.h"

void MyCustomOSInit(void)
{
	void* arenaLo;
	void* arenaHi;
	
	OSInit();
	
	arenaLo = OSGetArenaLo();
	arenaHi = OSGetArenaHi();
	
	// OSInitAlloc should only ever be invoked once
	arenaLo = OSInitAlloc(arenaLo, arenaHi, 1); // 1 heap
	OSSetArenaLo(arenaLo);
	
	OSSetCurrentHeap(OSCreateHeap((void*)OSRoundUp32B(arenaLo),
								(void*)OSRoundUp32B(arenaHi)));
	
	OSSetArenaLo(arenaLo=arenaHi);
	
	return;
}