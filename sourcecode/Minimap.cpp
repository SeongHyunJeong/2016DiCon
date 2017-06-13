#include "Minimap.h"
#include"Global.h"
#include"PlayerInfo.h"

Minimap::Minimap()
{
	for (int i = 0; i < 3; i++)
	{
		bgs[i] = new Sprite("img/ui/minimap/" + to_string(i) + ".png");
		AddChild(bgs[i]);
	}
	location = new Sprite("img/ui/minimap/pos.png");
	AddChild(location);
}


Minimap::~Minimap()
{
}

void Minimap::Render()
{
	IObject::Render();
	bgs[playerInfo.chapter-1]->Render();
	location->Render();
}

void Minimap::Update(float dt)
{
	IObject::Update(dt);

	if (playerInfo.chapter == 1)
	{
		switch(playerInfo.currentMap)
		{
		case 0:location->pos = Vec2(130, 300) - Vec2(15, 50); break;
		case 1:location->pos = Vec2(130, 230) - Vec2(15, 50); break;
		case 2:location->pos = Vec2(45, 230) - Vec2(15, 50); break;
		case 3:location->pos = Vec2(130, 167) - Vec2(15, 50); break;
		case 4:location->pos = Vec2(218, 167) - Vec2(15, 50); break;
		case 5:location->pos = Vec2(218, 105) - Vec2(15, 50); break;
		case 6:location->pos = Vec2(136, 95) - Vec2(15, 50); break;
		case 7:location->pos = Vec2(275, 35) - Vec2(15, 50); break;
		case 8:location->pos = Vec2(331, 105) - Vec2(15, 50); break;
		case 9:location->pos = Vec2(341, 173) - Vec2(15, 50); break;
		}
	}
	else if (playerInfo.chapter == 2)
	{
		switch (playerInfo.currentMap)
		{
		case 0:location->pos = Vec2(132, 340) - Vec2(15, 50); break;
		case 1:location->pos = Vec2(132, 270) - Vec2(15, 50); break;
		case 2:location->pos = Vec2(48, 270) - Vec2(15, 50); break;
		case 3:location->pos = Vec2(132, 210) - Vec2(15, 50); break;
		case 4:location->pos = Vec2(218, 210) - Vec2(15, 50); break;
		case 5:location->pos = Vec2(218, 148) - Vec2(15, 50); break;
		case 6:location->pos = Vec2(136, 136) - Vec2(15, 50); break;
		case 7:location->pos = Vec2(275, 75) - Vec2(15, 50); break;
		case 8:location->pos = Vec2(332, 147) - Vec2(15, 50); break;
		case 9:location->pos = Vec2(341, 215) - Vec2(15, 50); break;
		case 10:location->pos = Vec2(425, 181) - Vec2(15, 50); break;
		case 11:location->pos = Vec2(433, 102) - Vec2(15, 50); break;
		case 12:location->pos = Vec2(433, 35) - Vec2(15, 50); break;
		}
	}
	else if (playerInfo.chapter = 3)
	{
		switch (playerInfo.currentMap)
		{
		case 0:location->pos = Vec2(132, 408) - Vec2(15, 50); break;
		case 1:location->pos = Vec2(132, 340) - Vec2(15, 50); break;
		case 2:location->pos = Vec2(45, 340) - Vec2(15, 50); break;
		case 3:location->pos = Vec2(132, 277) - Vec2(15, 50); break;
		case 4:location->pos = Vec2(218, 277) - Vec2(15, 50); break;
		case 5:location->pos = Vec2(218, 214) - Vec2(15, 50); break;
		case 6:location->pos = Vec2(135, 205) - Vec2(15, 50); break;
		case 7:location->pos = Vec2(273, 143) - Vec2(15, 50); break;
		case 8:location->pos = Vec2(332, 215) - Vec2(15, 50); break;
		case 9:location->pos = Vec2(341, 282) - Vec2(15, 50); break;
		case 10:location->pos = Vec2(424, 247) - Vec2(15, 50); break;
		case 11:location->pos = Vec2(431, 168) - Vec2(15, 50); break;
		case 12:location->pos = Vec2(431, 105) - Vec2(15, 50); break;
		case 13:location->pos = Vec2(431, 33) - Vec2(15, 50); break;
		}
	}
	
}
