#pragma once
#include "IEnemy.h"
class Boss3 :
	public IEnemy
{
public:
	Boss3();
	~Boss3();
	bool init;
	void Update(float dt);
};

