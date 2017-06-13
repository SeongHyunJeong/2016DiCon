#pragma once
#include "iEnemy.h"
class Got :
	public IEnemy
{
public:
	Got();
	~Got();

	void Update(float dt);
};

