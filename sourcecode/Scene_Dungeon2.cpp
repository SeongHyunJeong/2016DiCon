#include "Scene_Dungeon2.h"
#include"Scene_Dungeon1.h"
#include "Scene_CenterVillage.h"
#include "Scene_Dungeon3.h"
#include "Scene_Fight.h"
#include"Slime.h"
#include"playerinfo.h"
Scene_Dungeon2::Scene_Dungeon2(int id, Vec2 pp)
{

	Priorbackground = new Sprite("img/map/dungeon1.png");
	AddObject(Priorbackground);

	background = new Sprite("img/map/dungeon2.png");
	AddObject(background);

	player = new Player();
	player->pos = pp;
	AddObject(player);

	slime = new Animation(3);
	slime->AddFrame("img/mob/1/slime/1.png");
	slime->AddFrame("img/mob/1/slime/2.png");
	slime->AddFrame("img/mob/1/slime/3.png");
	slime->AddFrame("img/mob/1/slime/4.png");
	slime->AddFrame("img/mob/1/slime/5.png");
	slime->pos.x = 660;
	slime->pos.y = 370;

	//이전씬 위치 저장
	priorpresentX = Priorbackground->pos.x;
	priorpresentY = Priorbackground->pos.y;

	//background->pos.x = 800;
	//background->pos.y = -240;


	SetRect(&slimearea, 680, 385, 720, 395);
	SetRect(&Dungeon3, 552, 18, 639, 33);

	SetRect(&to3, 0, 336, 1, 463);

	c = new Confirm("img/ui/슬라임_확인창.png");
	AddObject(c);
	c->pos = Vec2(220, 160);

	playerInfo.currentMap = 4;

	SetRect(&collider[0], 4, 2, 533, 329);
	SetRect(&collider[1], 5, 330, 455, 367);
	SetRect(&collider[2], 651, 3, 798, 340);
	SetRect(&collider[3], 711, 345, 795, 499);
	SetRect(&collider[4], 482, 499, 797, 598);
	SetRect(&collider[5], 2, 483, 479, 597);
	for (int i = 0; i < 6; i++)
	{
		rbRectList.push_back(collider[i]);
	}



}





Scene_Dungeon2::~Scene_Dungeon2()
{
	//Scene::~Scene();

}

void Scene_Dungeon2::Render()
{
	
	if (!isFadedOut)
	{
		Priorbackground->Render();
	}
	


	if (isFadedOut) {
		background->Render();
		slime->Render();
		player->Render();

	}
	c->Render();
	GScene::Render();
}



void Scene_Dungeon2::Update(float dTime)
{
	GScene::Update(dTime);
	if (!FadeOut(Priorbackground))
	{
		FadeIn(background);
	}
	//화면이 다 움직였으면 움직이기 가능

		if (IsCollisionRect(Vec2(0, 0), player->pos, slimearea, player->rect))
		{
			player->pos -= Vec2(player->dx, player->dy);
			c->isShowing = true;
		}
	if (c->isShowing)
	{
		if (c->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_slime.wav", "note/slime.txt", 4, new Slime()));
			return;
		}
		else if (c->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			c->isShowing = false;
		}
	}
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to3))
	{
		sceneManager->ChangeScene(new Scene_Dungeon1(4, Vec2(744, 146)));
	}

	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, Dungeon3))
		sceneManager->ChangeScene(new Scene_Dungeon3(4, Vec2(380, 478)));
}
