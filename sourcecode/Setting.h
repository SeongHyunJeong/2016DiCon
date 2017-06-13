#pragma once
#include "IObject.h"
#include"Sprite.h"
#include"text.h"
class Setting :
	public IObject
{
public:
	Sprite * bg;
	Text * key;
	int cursor;

	bool isShowing;
	Setting();
	~Setting();

	void Render();
	void Update(float dt);
};

