#include "S7.h"

#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"
#include"bee.h"
#include"s8.h"
#include"S9.h"
#include"Tree.h"
#include"S10.h"
S9::S9(int id, Vec2 pp)
{
	if (playerInfo.job == 0)
	{
		bg = new Sprite("img/map/1챕터/막다른길/막다른 길 기본.png");

		SetRect(&collider[0], 0, 3, 83, 305);
		SetRect(&collider[1], 2, 306, 62, 595);
		SetRect(&collider[2], 63, 547, 241, 598);
		SetRect(&collider[3], 241, 292, 798, 599);
		SetRect(&collider[4], 200, 3, 795, 283);
		for (int i = 0; i < 5; i++)
		{
		rbRectList.push_back(collider[i]);
		}

	}
	else if (playerInfo.job != 0)
	{
		bg = new Sprite("img/map/1챕터/막다른길/막다른 길.png");

		SetRect(&collider[0], 1, 1, 82, 298);
		SetRect(&collider[1], 195, 3, 466, 288);
		SetRect(&collider[2], 472,81,530,326);
		SetRect(&collider[3], 229, 291, 465, 355);
		SetRect(&collider[4], 2, 298, 57, 598);
		SetRect(&collider[5], 59, 547,799, 598);
		SetRect(&collider[6], 221, 486, 488, 546);
		SetRect(&collider[7], 492, 493, 717, 546);
		SetRect(&collider[8], 719, 2, 795, 545);
		SetRect(&collider[9], 651, 80, 718, 341);
		for (int i = 0; i < 10; i++)
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

	SetRect(&r1, 357, 257, 426, 321);
	SetRect(&to8, 82, 0, 200, 1);
	SetRect(&to10, 530, 43, 647, 45);

	playerInfo.currentMap = 9;
	tree = new Sprite("img/mob/1/tree/최종수정.png");
	AddObject(tree);
	tree->pos = Vec2(125, 392);

	cf = new Confirm("img/ui/세계수_확인창.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);

}


S9::~S9()
{
}

void S9::Render()
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
		tree->Render();
	}
	cf->Render();
	GScene::Render();
}

void S9::Update(float dt)
{
	GScene::Update(dt);
	
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to8))
	{
		sceneManager->ChangeScene(new S8(7, Vec2(496, 513)));
		return;
	}
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to10) && playerInfo.chapter >= 2)
	{
		sceneManager->ChangeScene(new S10(7, Vec2(300, 300)));
		return;
	}

	if (IsCollisionRect(player->pos, tree->pos, player->rect, tree->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			//전투씬 진입 시 음악파일이름(폴더명과 확장자제외) 전씬 아이디, 적 코드 넣어야 한다.
			sceneManager->ChangeScene(new Scene_Fight("sound/_tree.wav", "note/tree.txt", 9, new Tree()));
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}
}
