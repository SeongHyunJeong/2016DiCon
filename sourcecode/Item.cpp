#include "Item.h"
#include "Global.h"


Item::Item(void)
{
	sprite = new Sprite("hpItem.png");
	AddChild(sprite);
	SetCenter(sprite->width, sprite->height, sprite);

	isHit = false;
	hp = 1;

}


Item::~Item()
{
}

void Item::Render()
{
	IObject::Render();
	sprite->Render();

}

void Item::Update(float dTime) {

	IObject::Update(dTime);

	if (isHit)
	{
		isHit = false;
	}
	pos.y += 150 * dTime;

}