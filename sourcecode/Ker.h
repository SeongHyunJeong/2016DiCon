#pragma once
#include "IEnemy.h"
class Ker :
	public IEnemy
{
public:
	Ker();
	~Ker();
	bool dead;
	void Update(float dt);
	void HealthCalc(float dt);
};

