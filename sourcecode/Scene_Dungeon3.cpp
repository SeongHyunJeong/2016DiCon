#include "Scene_Dungeon3.h"

#include "Scene_CenterVillage.h"
//#include "Scene_Dungeon4.h"
#include"PlayerInfo.h"
#include"Scene_Dungeon2.h"
#include"Scene_Fight.h"
#include"Mushroom.h"
#include"Slime.h"
#include"S6.h"
#include"s7.h"
Scene_Dungeon3::Scene_Dungeon3(int id, Vec2 pp)
{

	Priorbackground = new Sprite("img/map/dungeon2.png");
	AddObject(Priorbackground);

	if (!playerInfo.isCleared[2])
	{
		background = new Sprite("img/map/dungeon3.png");

		SetRect(&collider[0], 508, 1, 700, 120);
		SetRect(&collider[1], 640, 118, 799, 522);
		SetRect(&collider[2], 486, 520, 799, 599);
		SetRect(&collider[3], 571, 123, 640, 166);
		SetRect(&collider[4], 555, 480, 641, 522);
		SetRect(&collider[5], 1, 1, 319, 120);
		SetRect(&collider[6], 1, 518, 340, 599);
		SetRect(&collider[7], 1, 120, 190, 518);
		SetRect(&collider[8], 190, 121, 260, 168);
		SetRect(&collider[9], 194, 477, 270, 514);
		for (int i = 0; i < 10; i++)
		{
			rbRectList.push_back(collider[i]);
		}
	}
	else {
		background = new Sprite("img/map/1챕터/버섯 나무/버섯나무 After.png");

		SetRect(&collider[0], 508, 1, 700, 120);
		SetRect(&collider[1], 640, 118, 799, 522);
		SetRect(&collider[2], 486, 520, 799, 599);
		SetRect(&collider[3], 571, 123, 640, 166);
		SetRect(&collider[4], 555, 480, 641, 522);
		SetRect(&collider[5], 1, 1, 319, 120);
		SetRect(&collider[6], 1, 518, 340, 599);
		SetRect(&collider[7], 1, 1, 320, 120);
		SetRect(&collider[8], 1, 125, 204, 253);
		SetRect(&collider[9], 207, 124, 263, 162);
		SetRect(&collider[10], 1, 365, 202, 527);
		SetRect(&collider[11], 1, 519, 339, 598);
		SetRect(&collider[12], 201, 478, 273, 522);

		for (int i = 0; i < 13; i++)
		{
			rbRectList.push_back(collider[i]);
		}
	}
	AddObject(background);

	mushroom = new Sprite("img/map/mushroom.png");
	AddObject(mushroom);
	mushroom->pos.x = 282;
	mushroom->pos.y = 122;

	
	SetRect(&Mush, 373, 280, 466, 339);
	
	player = new Player();
	player->pos = pp;
	AddObject(player);

	//이전씬 위치 저장
	priorpresentX = Priorbackground->pos.x;
	priorpresentY = Priorbackground->pos.y;

	
	//background->pos.y = -800;

	SetRect(&to4, 339, 599, 491, 600);
	SetRect(&to6, 0, 116, 1, 374);
	SetRect(&to7, 339, 0, 491, 1);

	playerInfo.currentMap = 5;


	mushroom1 = new Sprite("img/mob/1/mushroom/mushroom.png");
	AddObject(mushroom1);
	mushroom1->pos = Vec2(458, 234);

	c = new Confirm("img/ui/머쉬룸_확인창.png");
	AddObject(c);
	c->pos = Vec2(220, 160);



}





Scene_Dungeon3::~Scene_Dungeon3()
{
	//Scene::~Scene();

}

void Scene_Dungeon3::Render()
{
	//Priorbackground->Render();
	//background->Render();

	////화면이 다 움직이면 플레이어 렌더
	//if (background->pos.x == 0 && background->pos.y == 0)
	//	player->Render();

	////화면이 다 움직이면 버섯 렌더(버섯 움직이기 힘들어서)
	//if (background->pos.x == 0 && background->pos.y == 0)
	//mushroom->Render();

	if (!isFadedOut)
	{
		Priorbackground->Render();
	}
	if (isFadedOut) {
		background->Render();
	
		player->Render();
		if (isFadedIn)
		mushroom->Render();
		mushroom1->Render();
	}
	c->Render();
	GScene::Render();
	
}



void Scene_Dungeon3::Update(float dTime)
{
	GScene::Update(dTime);
	if (!FadeOut(Priorbackground))
	{
		FadeIn(background);
	}


	Collision(Vec2(0, 0), Mush, player);

	//씬 움직이기
	
	//MoveBackground(0,800, Priorbackground, background);


	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to4))
	{
		sceneManager->ChangeScene(new Scene_Dungeon2(5, Vec2(564, 55)));
		return;
	}
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to6) && playerInfo.isCleared[2])
	{
		sceneManager->ChangeScene(new S6(5, Vec2(723, 289)));
		return;
	}
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to7))
	{
		sceneManager->ChangeScene(new S7(5, Vec2(129, 502)));
		return;
	}
	if (IsCollisionRect(player->pos, mushroom1->pos, player->rect, mushroom1->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		c->isShowing = true;
	}
	if (c->isShowing)
	{
		if (c->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_mushroom.wav", "note/mushroom.txt", 5, new Mushroom()));
			
		}
		else if (c->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			c->isShowing = false;
		}
	}
}
