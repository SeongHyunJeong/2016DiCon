#pragma once
#include "IEnemy.h"
class Boss2 :
	public IEnemy
{
public:
	Boss2();
	~Boss2();

	void Update(float dt);
};

