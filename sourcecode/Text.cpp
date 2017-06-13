#include "Text.h"
Text::Text(string fontName) :width(20), height(45)
{
	D3DXCreateFontA(g_pd3dDevice, 45, 20, 1000, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0,fontName.c_str(), &font);
	str = "";
}
Text::Text(string fontName, int width, int height)
{
	D3DXCreateFontA(g_pd3dDevice, height, width, 1, 1, false, DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY, 0, fontName.c_str(), &font);
	this->width = width;
	this->height = height;
	str = "";
}


Text::~Text()
{
}

void Text::Render()
{
	IObject::Render();
	g_pd3dSprite->SetTransform(&mat);
	font->DrawTextA(g_pd3dSprite, str.c_str(), -1, &rect, attributes, color);
}
void Text::Update(float dTime)
{

}
void Text::Put(string str, int attributes, D3DCOLOR color)
{
	this->str = str;
	SetRect(&rect, 0, 0, width * strlen(str.c_str())+100 , height);
	this->attributes = attributes;
	this->color = color;
}
void Text::Put(char ch, int attributes, D3DCOLOR color)
{
	char tmp[2];
	sprintf(tmp, "%c", ch);
	str = tmp;
	SetRect(&rect, 0, 0, width * strlen(str.c_str()) + 100, height);
	this->attributes = attributes;
	this->color = color;
}