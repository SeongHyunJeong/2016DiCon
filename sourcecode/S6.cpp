#include "S6.h"

#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Dungeon3.h"
S6::S6(int id, Vec2 pp)
{
	bg = new Sprite("img/map/1Ã©ÅÍ/savezone/sz.png");
	AddObject(bg);
	
	p = new Sprite("img/map/1Ã©ÅÍ/savezone/sz.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;
	
	SetRect(&r1, 357, 257, 426, 321);
	SetRect(&to5, 799, 266, 800, 366);
	s = new Confirm("img/ui/È®ÀÎÃ¢ UI/È®ÀÎ.png");
	AddObject(s);
	s->pos = Vec2(220, 160);

	playerInfo.currentMap = 6;

	SetRect(&collider[0], 1, 1, 799, 121);
	SetRect(&collider[1], 1, 123, 158, 597);
	SetRect(&collider[2], 158,523, 799, 599);
	SetRect(&collider[3], 599, 375, 799, 522);
	SetRect(&collider[4], 599, 123, 798, 260);
	SetRect(&collider[5], 560, 125, 598, 174);
	SetRect(&collider[6], 160, 123, 202, 195);
	SetRect(&collider[7], 160, 447, 209, 522);
	SetRect(&collider[8], 554, 460, 597, 523);
	SetRect(&collider[9], 254, 240, 296, 395);
	for (int i = 0; i < 10; i++)
	{
		rbRectList.push_back(collider[i]);
	}

}


S6::~S6()
{
}

void S6::Render()
{
	if (!isFadedOut)
	{
		p->Render();
	}

	
	if (isFadedOut) {
		bg->Render();
		//slime->Render();
		player->Render();

	}
	s->Render();

	GScene::Render();
}

void S6::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (s->isShowing)
	{
		if (s->y->IsClicked())
		{
			playerInfo.Save();
			s->isShowing = false;
		}
		else if (s->n->IsClicked())
		{
			s->isShowing = false;
		}
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, r1))
	{
		s->isShowing = true;
		player->pos -= Vec2(player->dx, player->dy);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to5))
	{
		sceneManager->ChangeScene(new Scene_Dungeon3(6, Vec2(25, 267)));
	}
}
