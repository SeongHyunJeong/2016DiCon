#pragma once
#include "IObject.h"
#include"sprite.h"
class Minimap :
	public IObject
{
public:
	Sprite * bgs[3];
	Sprite * location;
	Minimap();
	~Minimap();
	void Render();
	void Update(float dt);
};

