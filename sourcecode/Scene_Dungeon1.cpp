#include "Scene_Dungeon1.h"
#include "Scene_Centergate.h"
#include "Scene_Dungeon2.h"
#include "Sprite.h"
#include "Scene_Fight.h"
#include"iEnemy.h"
#include"PlayerInfo.h"
#include"Goblin.h"
Scene_Dungeon1::Scene_Dungeon1(int id, Vec2 pp)
	:GScene(id, pp)
{
	background = new Sprite("img/map/dungeon1.png");
	AddObject(background);

	_1 = new Sprite("img/map/centergate.png");
	AddObject(_1);

	player = new Player();
	player->pos = pp;
	AddObject(player);

	goblin = new Animation(3);
	goblin->AddFrame("img/mob/1/goblin/goblin.png");
	goblin->pos.x = 87;
	goblin->pos.y = 165;
	AddObject(goblin);
/*
	presentX = background->pos.x;
	presentY = background->pos.y;*/

	SetRect(&rgoblin, 96, 170, 114, 200);
	SetRect(&to4 ,799, 127, 800, 227);

	SetRect(&to1, 122, 590, 320, 600);

	playerInfo.currentMap = 3;


	SetRect(&collider[0], 4, 6, 799, 103);
	SetRect(&collider[1], 4, 114, 82, 596);
	SetRect(&collider[2], 317, 264, 799, 595);
	SetRect(&collider[3], 84, 247, 143, 543);
	SetRect(&collider[4], 303, 107, 799, 123);
	SetRect(&collider[5], 269, 277, 310, 536);
	SetRect(&collider[6], 363, 237, 796, 261);
	for (int i = 0; i < 7; i++)
	{
		rbRectList.push_back(collider[i]);
	}

	c = new Confirm("img/ui/고블린_확인창.png");
	AddObject(c);
	c->pos = Vec2(220, 160);
}





Scene_Dungeon1::~Scene_Dungeon1()
{
	//Scene::~Scene();

}

void Scene_Dungeon1::Render()
{
	
	if (!isFadedOut)
	{
		_1->Render();
	}
	
	if (isFadedOut)
	{
		background->Render();
		goblin->Render();
		player->Render();

	}
	c->Render();
	GScene::Render();
}



void Scene_Dungeon1::Update(float dTime)
{
	GScene::Update(dTime);
		if (!FadeOut(_1))
		{
			FadeIn(background);
		}
		


	if (IsCollisionRect(Vec2(0, 0), player->pos, rgoblin, player->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		c->isShowing = true;		
	}
	if (c->isShowing)
	{
		if (c->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_goblin.wav", "note/goblin.txt", 3, new Goblin()));
		}
		else if (c->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			c->isShowing = false;
		}
	}


	else if (IsCollisionRect(player->pos,Vec2(0, 0),  player->rect, to4)) {
		sceneManager->ChangeScene(new Scene_Dungeon2(3, Vec2(30, 392)));
	}
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to1))
	{
		sceneManager->ChangeScene(new Scene_CenterGate(3, Vec2(450, 34)));
	}
}
