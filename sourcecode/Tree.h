#pragma once
#include "IEnemy.h"
class Tree :
	public IEnemy
{
public:
	Tree();
	~Tree();
	void Update(float dt);
};

