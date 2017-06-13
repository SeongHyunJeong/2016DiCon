#include "Bullet.h"
#include "Global.h"
#include "Enemy.h"

Bullet::Bullet()
{
	sprite = new Sprite("heart.png");
	//sprite = new Sprite("bullet.png");

	AddChild(sprite);

	SetCenter(sprite->width, sprite->height, sprite);

	isHit = false;
}


Bullet::~Bullet()
{
}

void Bullet::Render()
{
	IObject::Render();
	sprite->Render();
}

void Bullet::Update(float dTime)
{
	IObject::Update(dTime);
	if (isHit == false)
		pos.y -= 1000 * dTime;
}