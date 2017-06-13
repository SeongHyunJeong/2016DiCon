#include <Windows.h>
#include <d3dx9.h>
#include <iostream>

using namespace std;

void InitD3D(HWND hWnd);
void ReleaseD3D();

LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void InitWindow(HINSTANCE hInst);
HWND FloatWindow(HINSTANCE hInst,int nCmdShow);
int DoMainLoop();

void InitDeltaTime();
float GetDeltaTime();

void InitManager();
void DeleteManager();