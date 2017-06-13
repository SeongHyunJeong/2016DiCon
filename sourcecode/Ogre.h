#pragma once
#include "IEnemy.h"
class Ogre :
	public IEnemy
{
public:
	Ogre();
	~Ogre();
	bool target;
	void Update(float dt);
};

