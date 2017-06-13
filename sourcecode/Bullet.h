#pragma once
#include "IObject.h"
#include "Sprite.h"
class Bullet :
	public IObject
{
public:
	Bullet();
	~Bullet();

	Sprite*sprite;

	bool isHit;

	void Render();
	void Update(float dTime);
};

