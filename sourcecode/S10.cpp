#include "S7.h"
#include"Sound.h"
#include"Collisions.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"
#include"bee.h"
#include"s8.h"
#include"S9.h"
#include"Tree.h"
#include"s10.h"
#include"S11.h"
S10::S10(int id, Vec2 pp)
{
	bg = new Sprite("img/map/2Ã©ÅÍ/½Â°­±â/½Â°­±â.png");
	AddObject(bg);

	p = new Sprite("img/black.png");
	AddObject(p);

	player = new Player();
	AddObject(player);
	player->pos = pp;

	playerInfo.currentMap = 10;


}


S10::~S10()
{
}

void S10::Render()
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
}

void S10::Update(float dt)
{
	GScene::Update(dt);
	if (!FadeOut(p))
	{
		FadeIn(bg);
	}
	if (player->pos.x >= 377) player->pos.x = 377;
	if (player->pos.x <= 183) player->pos.x = 183;
	if (player->pos.y >= 404)player->pos.y = 404;
	if (player->pos.y <= 133)player->pos.y = 133;



	if (GetMyKeyState('1')==KEYDOWN)
	{
		sound.Play("click", false);
		sceneManager->ChangeScene(new S9(-2, Vec2(558, 93)));
		return;
	}
	else if (GetMyKeyState('2') == KEYDOWN)
	{
		sound.Play("click", false);
		sceneManager->ChangeScene(new S11(-2, Vec2(374, 468)));
		return;
	}
}
