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
#include"S11.h"
#include"Ogre.h"
#include"got.h"
S11::S11(int id, Vec2 pp)
{
	if (!playerInfo.isCleared[6]) 
	{
		bg = new Sprite("img/map/2챕터/마왕의 성 입구/before.png");

		SetRect(&collider[0], 1, 307, 299, 596);
		SetRect(&collider[1], 521, 308, 799, 598);
		SetRect(&collider[2], 300, 303, 519, 333);
		SetRect(&collider[3], 1, 1, 64, 156);
		SetRect(&collider[4], 118, 5, 265, 154);
		SetRect(&collider[5], 544, 2, 799, 154);
		for (int i = 0; i < 6; i++)
		{
			rbRectList.push_back(collider[i]);
		}
	}
	else 
	{
		bg = new Sprite("img/map/2챕터/마왕의 성 입구/after.png");
		SetRect(&collider[0], 1, 307, 299, 596);
		SetRect(&collider[1], 521, 308, 799, 598);
		SetRect(&collider[2], 1, 1, 64, 156);
		SetRect(&collider[3], 118, 5, 265, 154);
		SetRect(&collider[4], 544, 2, 799, 154);
		for (int i = 0; i < 5; i++)
		{
			rbRectList.push_back(collider[i]);
		}
	}
	AddObject(bg);

	p = new Sprite("img/black.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;

	SetRect(&r1, 48, 169, 150, 254);
	SetRect(&to10, 297, 599, 524, 600);
	SetRect(&to12, 360, 87, 458, 88);
	SetRect(&r2, 0, 306, 287, 585);
	SetRect(&r3, 517, 314, 792, 596);
	rbRectList.push_back(r2);
	rbRectList.push_back(r3);

	playerInfo.currentMap = 11;
	ogre = new Sprite("img/mob/2/오우거/오우거.png");
	AddObject(ogre);
	ogre->pos = Vec2(435, 407);

	got = new Sprite("img/mob/2/고트리퍼/고트리퍼.png");
	AddObject(got);
	got->pos = Vec2(648, 141);

	cf = new Confirm("img/ui/오우거_확인창.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);
	cf2 = new Confirm("img/ui/고트리퍼_확인창.png");
	AddObject(cf2);
	cf2->pos = Vec2(220, 160);
	cf3 = new Confirm("img/ui/확인창 UI/확인.png");
	AddObject(cf3);
	cf3->pos = Vec2(220, 160);

}


S11::~S11()
{
}

void S11::Render()
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
		ogre->Render();
		if (playerInfo.isCleared[6])
			got->Render();
	}
	cf->Render();
	cf2->Render();
	cf3->Render();
	GScene::Render();
}

void S11::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to10))
	{
		sceneManager->ChangeScene(new S10(7, Vec2(200, 200)));
		return;
	}
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to12))
	{
		sceneManager->ChangeScene(new S12(7, Vec2(377, 505)));
		return;
	}

	if (IsCollisionRect(player->pos, ogre->pos, player->rect, ogre->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_ogre.wav", "note/ogre.txt", 11, new Ogre()));
			return;
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}
	if (IsCollisionRect(player->pos, got->pos, player->rect, got->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf2->isShowing = true;
	}
	if (cf2->isShowing)
	{
		if (cf2->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_got.wav", "note/got.txt", 14, new Got()));
			return;
		}
		else if (cf2->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf2->isShowing = false;
		}
	}
	if (IsCollisionRect(player->pos,Vec2(0, 0), player->rect, r1))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf3->isShowing = true;
	}
	if (cf3->isShowing)
	{
		if (cf3->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			playerInfo.Save();
			cf3->isShowing = false;
		}
		else if (cf3->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf3->isShowing = false;
		}
	}

	if (!playerInfo.isCleared[6])
	{
		if (player->pos.y <= 306)player->pos.y = 306;
	}


}
