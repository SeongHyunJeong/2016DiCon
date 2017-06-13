#pragma once
#include "IObject.h"
#include"Sprite.h"
#include"Text.h"
#include"Button.h"
class PotionShop :
	public IObject
{
public:

	Sprite * bg;
	Sprite * potion;

	Button * p1;
	Button * p2;
	Button * x;


	Text * potionCount;
	Text * hp;
	Text * p1Cost;
	Text * p2Cost;
	Text * money;

	bool isShowing;


	PotionShop();
	~PotionShop();

	void Render();
	void Update(float dt);
};

