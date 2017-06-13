#pragma once
#include "IEnemy.h"
class Slime :
	public IEnemy
{
public:

	Slime();
	~Slime();

	void Render();
	void Update(float dt);
	bool TimeToS1(float dt);
	void Skill1(float dt);

	void HealthCalc(float dt);
};

