#include "Boss3.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"



Boss3::Boss3()
	:IEnemy("img/mob/3/마3.png", "0", 100000, 20)
{
	playerInfo.maxHp = 1000;
	init = false;
	scale = Vec2(0.5f, 0.5f);
}


Boss3::~Boss3()
{
}

void Boss3::Update(float dt)
{
	IEnemy::Update(dt);
	Scene_Fight * s = (Scene_Fight *)sceneManager->currentScene;

	if (!init)
	{
		s->log->PushLog("유희 : 유저의 체력이 1000으로 고정됩니다.");
		init = true;
	}
	if (playerInfo.isHpIncreased)
	{
		s->log->PushLog("광란 : 포션을 사용할 수 없습니다.");
		s->playerHp -= 10;
		playerInfo.isHpIncreased = false;
	}
}
