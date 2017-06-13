#pragma once
#include "IEnemy.h"
class Orc :
	public IEnemy
{
public:
	Orc();
	~Orc();
	//bool isOnRage;
	void Update(float dt);
	
};

