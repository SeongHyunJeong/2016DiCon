#pragma once
#include "IObject.h"
class Sprite :
	public IObject
{
public:
	Sprite(string path);
	~Sprite();

	LPDIRECT3DTEXTURE9 texture;
	D3DCOLOR color;
	RECT visibleRect;

	int width;
	int height;

	void Render();
};

