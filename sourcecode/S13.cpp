#include "S7.h"

#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"
#include"bee.h"
#include"s8.h"
#include"S9.h"
#include"Tree.h"
#include"s10.h"
#include"S12.h"
#include"s13.h"
#include"Boss1.h"
#include"Boss2.h"
#include"Boss3.h"
S13::S13(int id, Vec2 pp)
{
	bg = new Sprite("img/map/3Ã©ÅÍ/¸¶¿ÕÀÇ ¼º ³»ºÎ.png");
	AddObject(bg);

	p = new Sprite("img/black.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;

	playerInfo.currentMap = 13;
	SetRect(&to12, 295, 599, 516, 600);
	for (int i = 0; i < 3; i++)
	{
		boss[i] = new Sprite("img/mob/3/¸¶" + to_string(i + 1) + ".png");
		AddObject(boss[i]);
		boss[i]->pos = Vec2(335, 73);
	}

	if (playerInfo.isCleared[10])
	cf = new Confirm("img/ui/¸¶¿Õ3_È®ÀÎÃ¢.png");
	else if(playerInfo.isCleared[9])
	cf = new Confirm("img/ui/¸¶¿Õ2_È®ÀÎÃ¢.png");
	else
	cf = new Confirm("img/ui/¸¶¿Õ1_È®ÀÎÃ¢.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);

}


S13::~S13()
{
}

void S13::Render()
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
	}
	GScene::Render();

	if (playerInfo.isCleared[10])
		boss[2]->Render();
	else if (playerInfo.isCleared[9])
		boss[1]->Render();
	else
		boss[0]->Render();

	cf->Render();
}

void S13::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to12))
	{
		sceneManager->ChangeScene(new S12(-2, Vec2(500, 209))); return;
	}
	else if (IsCollisionRect(player->pos, boss[0]->pos, player->rect, boss[0]->rect))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			if(playerInfo.isCleared[10])
			sceneManager->ChangeScene(new Scene_Fight("sound/_f3.wav", "note/f3.txt", 32, new Boss3()));
			else if(playerInfo.isCleared[9])
			sceneManager->ChangeScene(new Scene_Fight("sound/_f2.wav", "note/f2.txt", 31, new Boss2()));
			else if(playerInfo.isCleared[8])
			sceneManager->ChangeScene(new Scene_Fight("sound/_f1.wav", "note/f1.txt", 30, new Boss1()));
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}


}


//if (playerInfo.isCleared[10])
//sceneManager->ChangeScene(new Scene_Fight("_f3.wav", "f3.txt", 32, new Boss3()));
//else if (playerInfo.isCleared[9])
//sceneManager->ChangeScene(new Scene_Fight("_f2.wav", "f2.txt", 31, new Boss2()));
//else
//boss[0]->Render();