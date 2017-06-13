#pragma once
#include<d3dx9.h>
#include"Global.h"
#include<list>
#include<string>
class Text : public IObject
{
public:
	LPD3DXFONT font;
	string str; 
	int width;
	int height;
	int attributes;
	D3DCOLOR color;
	Text(string fontName);
	Text(string fontName, int width, int height);

	void Render();
	void Update(float dTime);
	void Put(string str, int attributes, D3DCOLOR color);
	void Put(char ch, int attributes, D3DCOLOR color);
	~Text();
};

