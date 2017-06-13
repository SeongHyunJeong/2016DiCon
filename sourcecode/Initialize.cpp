#include "Initialize.h"
#include "Global.h"
#include "GameScene.h"
#include"MainScene.h"
//#include"Scene_Dungeon4.h"
#include"Scene_Dungeon2.h"
#include"TestScene.h"
#include"Scene_Fight.h"
#include"Scene_ReinforceShop.h"

LARGE_INTEGER LInterval, Frequency, RInterval;

void InitD3D(HWND hWnd) {
	g_pd3d = Direct3DCreate9(D3D_SDK_VERSION);
	ZeroMemory(&d3dpp, sizeof(d3dpp));

	d3dpp.Windowed = true;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;

	g_pd3d->CreateDevice(D3DADAPTER_DEFAULT, D3DDEVTYPE_HAL, hWnd, D3DCREATE_SOFTWARE_VERTEXPROCESSING, &d3dpp, &g_pd3dDevice);

	D3DXCreateSprite(g_pd3dDevice, &g_pd3dSprite);
}

void ReleaseD3D()
{
	g_pd3dSprite->Release();
	g_pd3dDevice->Release();
	g_pd3d->Release();

}

void InitWindow(HINSTANCE hInst) {
	WNDCLASS WndClass;

	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);

	WndClass.hInstance = hInst;
	WndClass.lpfnWndProc = WndProc;
	WndClass.lpszClassName = NAME;
	WndClass.lpszMenuName = NULL;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	RegisterClass(&WndClass);
}
HWND FloatWindow(HINSTANCE hInst,int nCmdShow)
{
	g_hWnd = CreateWindow(NAME, L"非Fantastic Music", WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, SCREEN_WIDTH, SCREEN_HEIGHT, NULL, (HMENU)NULL, hInst, NULL);
	ShowWindow(g_hWnd, nCmdShow);
	return g_hWnd;
}

int DoMainLoop() {
	InitDeltaTime();
	InitManager();

	sceneManager->ChangeScene(new MainScene());
	
	MSG msg = {};

	while (msg.message != WM_QUIT) {
		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

		
		
		//버퍼 클리어
		g_pd3dDevice->Clear(0, NULL, D3DCLEAR_TARGET, BG_COLOR, 1.0f, 0);

		g_pd3dDevice->BeginScene();

		g_pd3dSprite->Begin(D3DXSPRITE_ALPHABLEND);

		sceneManager->Render();

		g_pd3dSprite->End();

		g_pd3dDevice->EndScene();

		g_pd3dDevice->Present(NULL, NULL, NULL, NULL);


		UpdateKeyState();
		sceneManager->Update(GetDeltaTime());
	}

	DeleteManager();
	ReleaseD3D();
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT iMessage, WPARAM wParam, LPARAM IParam)
{
	switch (iMessage)
	{
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;
	}
	return(DefWindowProc(hWnd, iMessage, wParam, IParam));
}

void InitDeltaTime()
{
	QueryPerformanceCounter(&LInterval);
	QueryPerformanceFrequency(&Frequency);
}

float GetDeltaTime()
{
	QueryPerformanceCounter(&RInterval);
	LONGLONG interval = (RInterval.QuadPart - LInterval.QuadPart);
	float dTime = (float)interval / (float)Frequency.QuadPart;
	LInterval = RInterval;
	return dTime;
}

void InitManager()
{
	sceneManager = new SceneManager;
	textureManager = new TextureManager;

}

void DeleteManager()
{
	delete sceneManager;
	delete textureManager;
}