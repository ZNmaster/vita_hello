#include <psp2/kernel/processmgr.h>
#include <psp2/display.h>
#include <psp2/kernel/threadmgr.h>

#include <sstream>

#include "debugScreen.h"

//We're gonna fake printf() func
#define printf psvDebugScreenPrintf


int main(int argc, char *argv[]) {

	psvDebugScreenInit();

	//Our printf() accepts nothing but char *
	std::stringstream out;

    int year = 2020;

    // We put everything to our out stream
    out << "Hello, "
        << year
        << ", World!";

    printf (out.str().c_str());
    printf("\r\n\r\n");



    sceKernelDelayThread(20*1000000); // Wait for 20 seconds
	sceKernelExitProcess(0);
    return 0;
}
