#pragma once
#include "IObject.h"
#include "Sprite.h"
class EnemyBullet :
	public IObject
{
public:
	EnemyBullet(int cnt);
	~EnemyBullet();

	Sprite*sprite;

	bool isHit;
	int Cnt;
	void Render();
	void Update(float dTime);

};

