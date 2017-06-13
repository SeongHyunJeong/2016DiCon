#include "Scene_CenterGate.h"
#include "Scene_Village.h"
#include "Scene_Dungeon1.h"
#include"PlayerInfo.h"

Scene_CenterGate::Scene_CenterGate(int id, Vec2 pp)
	:GScene(id, pp)
{
	background = new Sprite("img/map/centergate.png");
	AddObject(background);
	//background->pos.y = -600;
	prev_village = new Sprite("img/map/village.png");
	AddObject(prev_village);
	
	_2 = new Sprite("img/map/centervillage.png");
	AddObject(_2);

	_3 = new Sprite("img/map/dungeon1.png");
	AddObject(_3);
	/*spot = new Sprite("spot.png");
	AddObject(spot);
	spot->pos.x = SCREEN_WIDTH / 2;
	spot->pos.y = SCREEN_HEIGHT / 2;*/

	player = new Player();
	player->pos = pp;
	AddObject(player);

	SetRect(&garden, 557, 0, 800, 600);
	rbRectList.push_back(garden);
	//dungeon1 = Vec2(526, 30);
	centervillage = Vec2(20, 267);

	//이동용
	SetRect(&to0, 420, 600, 560, 700);
	SetRect(&to2, -1, 152, 2, 380);
	SetRect(&to3, 413, 0, 559, 1);

	SetRect(&r1, 2, 373, 428, 546);
	rbRectList.push_back(r1);
	SetRect(&r2, 0, 0, 401, 154);
	rbRectList.push_back(r2);

	//map 이동 관련 함수들
	playerInfo.currentMap = 1;

	b = new Sprite("img/map/번화가.png");
	AddObject(b);
	

}


Scene_CenterGate::~Scene_CenterGate()
{
}


void Scene_CenterGate::Render()
{
	if (id == 0)
	{
		if (isFadedOut)
			background->Render();
		if (!isFadedOut)
			prev_village->Render();
	}
	else if (id == 2)
	{
		if (isFadedOut)
			background->Render();
		if (!isFadedOut)
			_2->Render();
	}
	else if (id == 3)
	{
		if (isFadedOut)
			background->Render();
		if (!isFadedOut)
			_3->Render();
	}
	if (isFadedOut)
	{
		player->Render();
	}


	if (isFadedIn)
	{
		b->Render();
	}
		//spot->Render();
	GScene::Render();
}

void Scene_CenterGate::Update(float dTime)
{
	GScene::Update(dTime);
	if (id == 0)
	{
		if (!FadeOut(prev_village))
		{
			FadeIn(background);
		}
	}
	else if (id == 2)
	{
		if (!FadeOut(_2))
		{
			FadeIn(background);
		}
	}
	else if (id == 3)
	{
		if (!FadeOut(_3))
		{
			FadeIn(background);
		}
	}
	

	//to 3 던전1로
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to3)) {
		sceneManager->ChangeScene(new Scene_Dungeon1(1, Vec2(194, 534)));

	}

	

	////중심가로
	//else if (IsPointInRect(player->pos, player->rect, centervillage))
	//	sceneManager->ChangeScene(new Scene_CenterVillage());

	
	//to 0 Village
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to0))
	{
		
		sceneManager->ChangeScene(new Scene_Village(1, Vec2(385, 20)));

		
	}
	//to 2 번화가
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to2))
	{
	
		sceneManager->ChangeScene(new Scene_CenterVillage(1, Vec2(717, 366)));
	}

}