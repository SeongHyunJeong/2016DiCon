#pragma once
#include <d3dx9.h>
#include "SceneManager.h"
#include "TextureManager.h"
#include <iostream>

#define NAME TEXT("API")
#define Vec2(a,b) D3DXVECTOR2((a),(b))
#define SCREEN_WIDTH 808
#define SCREEN_HEIGHT 630
#define BG_COLOR D3DCOLOR_ARGB(255, 0, 153, 0)

#define KEYON 2
#define KEYDOWN 1
#define KEYUP -1
#define KEYNONE -2
#define for_iter(iter, collection) for(auto iter = collection.begin(); iter != collection.end(); iter++)

typedef D3DXVECTOR2 Vec2;
using namespace std;


extern LPDIRECT3D9 g_pd3d;
extern D3DPRESENT_PARAMETERS d3dpp;
extern LPDIRECT3DDEVICE9 g_pd3dDevice;
extern LPD3DXSPRITE g_pd3dSprite;
extern HWND g_hWnd;

extern SceneManager*sceneManager;
extern TextureManager*textureManager;

void UpdateKeyState();
int GetMyKeyState(int vk);



D3DXVECTOR2 GetMousePos();