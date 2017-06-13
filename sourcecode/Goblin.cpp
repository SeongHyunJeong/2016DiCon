#include "Goblin.h"
#include"Global.h"


Goblin::Goblin()
	:IEnemy("img/mob/1/goblin/goblin.png", "img/ui/inventory/items/0_goblinhair.png", 1000, 1)
{
	scale = Vec2(2.5f, 2.5f);
}


Goblin::~Goblin()
{
}
