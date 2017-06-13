#pragma once
#include "IObject.h"
#include "Sprite.h"

class Item :
	public IObject
{
public:
	Item();
	~Item();

	Sprite* sprite;
	bool isHit;

	list<Item*>itemList;

	int hp;

	void Render();
	void Update(float dTime);

};