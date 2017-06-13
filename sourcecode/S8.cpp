#include "S7.h"

#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Dungeon3.h"
#include"Scene_Fight.h"
#include"bee.h"
#include"s8.h"
#include"Orc.h"
#include"S9.h"
S8::S8(int id, Vec2 pp)
{
	bg = new Sprite("img/map/1é��/��ũ ����/��ũ ����.png");
	AddObject(bg);

	p = new Sprite("img/black.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;

	SetRect(&r1, 299, 262, 526, 309);
	rbRectList.push_back(r1);
	SetRect(&to7, 89, 0, 195, 1);
	SetRect(&to9, 484, 599, 596, 600);

	playerInfo.currentMap = 8;
	orc = new Sprite("img/mob/1/orc/��ũ.png");
	AddObject(orc);
	orc->pos = Vec2(654, 289);

	cf = new Confirm("img/ui/��ũ_Ȯ��â.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);


	mask = new Sprite("img/map/��ũ ����.png");
	AddObject(mask);

	SetRect(&collider[0], 1, 2,80, 160);
	SetRect(&collider[1], 3, 160, 29, 475);
	SetRect(&collider[2], 3, 476, 484, 598);
	SetRect(&collider[3], 604, 475, 797, 598);
	SetRect(&collider[4], 753, 108, 798, 476);
	SetRect(&collider[5], 536, 109, 753, 146);
	SetRect(&collider[6], 298, 2, 798, 106);
	SetRect(&collider[7], 199, 4, 286, 146);
	for (int i = 0; i < 8; i++)
	{
		rbRectList.push_back(collider[i]);
	}

}


S8::~S8()
{
}

void S8::Render()
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
		mask->Render();
		orc->Render();
	}
	cf->Render();
	GScene::Render();
}

void S8::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to7))
	{
		sceneManager->ChangeScene(new S7(7, Vec2(516, 492)));
		return;
	}
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to9))
	{
		sceneManager->ChangeScene(new S9(7, Vec2(114, 28)));
		return;
	}

	if (IsCollisionRect(player->pos, orc->pos, player->rect, orc->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			//������ ���� �� ���������̸�(������� Ȯ��������) ���� ���̵�, �� �ڵ� �־�� �Ѵ�.
			sceneManager->ChangeScene(new Scene_Fight("sound/_orc.wav", "note/orc.txt", 8, new Orc()));
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}
}
