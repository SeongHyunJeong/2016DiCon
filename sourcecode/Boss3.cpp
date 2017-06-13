#include "Boss3.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"



Boss3::Boss3()
	:IEnemy("img/mob/3/��3.png", "0", 100000, 20)
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
		s->log->PushLog("���� : ������ ü���� 1000���� �����˴ϴ�.");
		init = true;
	}
	if (playerInfo.isHpIncreased)
	{
		s->log->PushLog("���� : ������ ����� �� �����ϴ�.");
		s->playerHp -= 10;
		playerInfo.isHpIncreased = false;
	}
}
