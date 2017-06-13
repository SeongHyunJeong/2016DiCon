#include "S7.h"

#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"
#include"bee.h"
#include"s8.h"
#include"S9.h"
#include"S10.h"
#include"ker.h"
#include"s12.h"
#include"S13.h"
#include"S11.h"
S12::S12(int id, Vec2 pp)
{

		bg = new Sprite("img/map/2챕터/마왕의성 정원/a.png");
	
	AddObject(bg);

	p = new Sprite("img/black.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;

	SetRect(&r1, 357, 257, 426, 321);
	SetRect(&to11, 297, 599, 524, 600);
	SetRect(&to13, 360, 87, 458, 88);

	playerInfo.currentMap = 12;
	ker = new Sprite("img/mob/2/케로베로스/킬배로스.png");
	AddObject(ker);
	ker->pos = Vec2(200, 70);

	cf = new Confirm("img/ui/케로베로스_확인창.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);

	SetRect(&collider[0], 1, 1, 301, 597);
	SetRect(&collider[1], 518, 2, 799, 599);
	for (int i = 0; i < 6; i++)
	{
		rbRectList.push_back(collider[i]);
	}


}


S12::~S12()
{
}

void S12::Render()
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
		ker->Render();
	}
	cf->Render();
	GScene::Render();
}

void S12::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to11))
	{
		sceneManager->ChangeScene(new S11(7, Vec2(200, 200)));
		return;
	}
	if (playerInfo.chapter == 3 && IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to13))
	{
		sceneManager->ChangeScene(new S13(7, Vec2(400, 560)));
		return;
	}

	if (IsCollisionRect(player->pos, ker->pos, player->rect, ker->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_ker.wav", "note/ker.txt", 12, new Ker()));
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}
}
