#include "S7.h"

#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Dungeon3.h"
#include"Scene_Fight.h"
#include"bee.h"
#include"s8.h"
S7::S7(int id, Vec2 pp)
{
	bg = new Sprite("img/map/1챕터/벌이 쉬어가는 곳/벌이 쉬어가는 곳.png");
	AddObject(bg);

	p = new Sprite("img/black.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;

	SetRect(&r1, 357, 257, 426, 321);
	SetRect(&to5, 103, 599, 261, 600);
	SetRect(&to8, 495, 599, 634, 600);

	playerInfo.currentMap = 7;
	bee = new Sprite("img/mob/1/bee/호넷1.png");
	AddObject(bee);
	bee->pos = Vec2(343, 77);

	cf = new Confirm("img/ui/호넷_확인창.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);

	SetRect(&collider[0], 2, 3, 77, 290);
	SetRect(&collider[1], 3, 292, 102, 598);
	SetRect(&collider[2], 78, 5, 675, 28);
	SetRect(&collider[3], 678, 1, 798, 396);
	SetRect(&collider[4], 638, 307, 799, 599);
	SetRect(&collider[5], 250, 309, 490, 598);
	SetRect(&collider[6], 284, 240, 469, 301);
	SetRect(&collider[7], 80, 29, 175, 53);
	SetRect(&collider[8], 570, 32, 674, 52);
	for (int i = 0; i < 9; i++)
	{
		rbRectList.push_back(collider[i]);
	}
	
}


S7::~S7()
{
}

void S7::Render()
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
	if (isFadedIn)
	{
		bee->Render();
	}
	cf->Render();
	GScene::Render();
}

void S7::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to5))
	{
		sceneManager->ChangeScene(new Scene_Dungeon3(7, Vec2(349, 31)));
		return;
	}
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to8))
	{
		sceneManager->ChangeScene(new S8(7, Vec2(102, 43)));
		return;
	}

	if (IsCollisionRect(player->pos, bee->pos, player->rect, bee->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_bee.wav", "note/bee.txt", 7, new Bee()));
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}
}
