#include "EnemyBullet.h"
#include "Global.h"


EnemyBullet::EnemyBullet(int cnt)
{
	sprite = new Sprite("enemybullet.png");
	AddChild(sprite);

	SetCenter(sprite->width, sprite->height, sprite);
	Cnt = cnt;
	isHit = false;
}


EnemyBullet::~EnemyBullet()
{
}

void EnemyBullet::Render()
{
	IObject::Render();
	sprite->Render();
}

void EnemyBullet::Update(float dTime)
{
	IObject::Update(dTime);
	if (Cnt == 1) {
		if (isHit == false) {
			pos.y += 750 * dTime;
		}
	}
	else if (Cnt == 2) {
		if (isHit == false) {
			pos.y += 750 * dTime;
			pos.x -= 750 * dTime;
		}
	}
	else if (Cnt == 3) {
		if (isHit == false) {
			pos.y += 750 * dTime;
			pos.x += 750 * dTime;
		}
	}
}