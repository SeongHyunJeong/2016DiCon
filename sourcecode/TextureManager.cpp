#include "TextureManager.h"
#include "Global.h"


TextureManager::TextureManager()
{
}


TextureManager::~TextureManager()
{
	for (auto&texture : textureMap)
		texture.second->Release();
}

LPDIRECT3DTEXTURE9 TextureManager::LoadTextureFromFile(string path)
{
	if (textureMap[path] == NULL) {
	D3DXCreateTextureFromFileExA(
		g_pd3dDevice, path.c_str(), D3DX_DEFAULT_NONPOW2, D3DX_DEFAULT_NONPOW2, 1, 0, D3DFMT_UNKNOWN, D3DPOOL_MANAGED,
		D3DX_DEFAULT, D3DX_DEFAULT, NULL, NULL, NULL, &textureMap[path]);

}
	return textureMap[path];
}