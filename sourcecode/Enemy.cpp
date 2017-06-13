#include "Enemy.h"
#include "Global.h"


Enemy::Enemy()
{

	sprite = new Sprite("enemy.png");
	AddChild(sprite);

	SetCenter(sprite->width, sprite->height, sprite);
	direction = 1;
	hpBar = new Sprite("hpBar.png");
	AddChild(hpBar);
	hpBar->pos = sprite->pos + Vec2(0, -40);

	isHit = false;

	maxHp = 100;
	hp = maxHp;

	attackDelay = 1;
	attackDelayTimer = 0;

}


Enemy::~Enemy()
{
	for (auto&enemyBullet : enemyBulletList)
		delete enemyBullet;
}

void Enemy::Render()
{
	IObject::Render();
	sprite->Render();
	hpBar->Render();

	for (auto&enemyBullet : enemyBulletList)
		enemyBullet->Render();

}

void Enemy::Update(float dTime)
{
	IObject::Update(dTime);
	if (direction == 1) {
		pos.x += 200 * dTime;
	}
	else if (direction == -1) {
		pos.x -= 200 * dTime;
	}
	if (pos.x >= SCREEN_WIDTH - 60 || pos.x <= 60) {
		direction *= -1;
	}

	for (auto&enemyBullet : enemyBulletList)
		enemyBullet->Update(dTime);

	attackDelayTimer += dTime;
	if (attackDelayTimer > attackDelay)
	{
		attackDelayTimer = 0;
		ShootEnemyBullet();
	}

	for (auto iter = enemyBulletList.begin(); iter != enemyBulletList.end(); iter++)
	{
		if ((*iter)->pos.y < 0 || (*iter)->isHit)
		{
			delete (*iter);
			iter = enemyBulletList.erase(iter);
			if (iter == enemyBulletList.end())
				break;
		}
	}

	if (isHit)
	{
		hp--;
		isHit = false;
	}

	hpBar->visibleRect.right = hpBar->width*hp / (float)maxHp;
}

void Enemy::ShootEnemyBullet()
{
	EnemyBullet*b = new EnemyBullet(1);
	EnemyBullet*b2 = new EnemyBullet(2);
	EnemyBullet*b3 = new EnemyBullet(3);

	b->pos = pos;
	b->pos.y = pos.y + 50;
	enemyBulletList.push_back(b);

	b2->pos = pos;
	b2->pos.y = pos.y + 50;
	enemyBulletList.push_back(b2);

	b3->pos = pos;
	b3->pos.y = pos.y + 50;
	enemyBulletList.push_back(b3);
}