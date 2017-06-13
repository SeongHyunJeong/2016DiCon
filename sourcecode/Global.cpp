#include "Global.h"


LPDIRECT3D9 g_pd3d;
D3DPRESENT_PARAMETERS d3dpp;
LPDIRECT3DDEVICE9 g_pd3dDevice;
LPD3DXSPRITE g_pd3dSprite;
HWND g_hWnd;

SceneManager*sceneManager;
TextureManager*textureManager;


bool lkey[256], rkey[256];

void UpdateKeyState()
{
	for (int i = 0; i < 256; i++)
	{
		lkey[i] = rkey[i];
		rkey[i] = GetAsyncKeyState(i) & 0x8000;
	}
}
int GetMyKeyState(int vk)
{
	if (lkey[vk] && rkey[vk]) return 2;//KEYON
	if (!lkey[vk] && rkey[vk]) return 1;//KEYDOWN
	if (lkey[vk] && !rkey[vk]) return -1;//KEYUP
	return 0;
}





D3DXVECTOR2 GetMousePos()
{
	POINT pt;
	GetCursorPos(&pt);
	ScreenToClient(g_hWnd, &pt);
	return Vec2(pt.x,pt.y);
}