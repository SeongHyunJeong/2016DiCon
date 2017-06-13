#include "Mushroom.h"
#include"Global.h"


Mushroom::Mushroom()
	:IEnemy("img/mob/1/mushroom/mushroom.png", "img/ui/inventory/items/0_goblinhair.png", 900, 2)
{
	scale = Vec2(2.5f, 2.5f);
}


Mushroom::~Mushroom()
{
}
