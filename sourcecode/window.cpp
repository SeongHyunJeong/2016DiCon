#pragma comment(linker, "/entry:WinMainCRTStartup /subsystem:console")
#include <Windows.h>
#include "Initialize.h"
#include <time.h>


int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE, LPSTR , int nCmdShow) {
	srand(time(NULL));
	InitWindow(hInstance);
	InitD3D(FloatWindow(hInstance, nCmdShow));
	return DoMainLoop();
}
