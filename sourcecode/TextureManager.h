#pragma once
#include <d3dx9.h>
#include <map>

using namespace std;

class TextureManager
{
public:
	TextureManager();
	~TextureManager();

	map<string, LPDIRECT3DTEXTURE9> textureMap;

	LPDIRECT3DTEXTURE9 LoadTextureFromFile(string path);
};

