#pragma once
#include "IObject.h"
#include"Sprite.h"
#include"Text.h"
#include"Button.h"
class Inventory :
	public IObject
{
public:
	Inventory();
	~Inventory();
	Sprite * bg;
	Sprite * items[9];
	Sprite * weapons[5];
	Sprite * noItem;
	Text * lv;
	Text * exp;
	Text * money;

	Text * upgrade;

	Text * job;

	Text * chapter;

	Text * itemCount;

	Text * damage;

	//Button * x;

	void Render();
	void Update(float dt);

};

