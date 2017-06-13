#pragma once
#include "IObject.h"
#include "Sprite.h"
#include "EnemyBullet.h"

class Enemy :
	public IObject
{
public:
	Enemy();
	~Enemy();

	Sprite*sprite;

	list<EnemyBullet*>enemyBulletList;

	bool isHit;
	int direction;
	int hp;
	int maxHp;
	Sprite*hpBar;

	float attackDelay;
	float attackDelayTimer;


	void Render();
	void Update(float dTime);

	void ShootEnemyBullet();
};

