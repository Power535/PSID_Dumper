#include <psp2/display.h>
#include <psp2/kernel/processmgr.h>

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <string.h>

#include "graphics.h"

#define printf psvDebugScreenPrintf

typedef struct SceKernelOpenPsId {
	char id[16];
} SceKernelOpenPsId;

int sceKernelGetOpenPsId(SceKernelOpenPsId *id);

int main() {
	psvDebugScreenInit();

	// Use users PSID here
	SceKernelOpenPsId my_psid = {{0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00}};
	SceKernelOpenPsId id;
	sceKernelGetOpenPsId(&id);

	if (memcmp(&id, &my_psid, 0x10) == 0){
		printf("Success! PSID matches!\n");
		printf("\nAuto-exiting in 5 seconds...");
		sceKernelDelayThread(5 * 1000 * 1000);
	}
	else {
		printf("PSID does NOT match!\n");
		printf("\nAuto-exiting in 5 seconds...");
		sceKernelDelayThread(5 * 1000 * 1000);
	}

	sceKernelExitProcess(0);
	return 0;
}
