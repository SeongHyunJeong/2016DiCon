#include "Boss2.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"


Boss2::Boss2()
	:IEnemy("img/mob/3/마2.png", "0", 25000, 20)
{
	scale = Vec2(0.5f, 0.5f);
}


Boss2::~Boss2()
{
}

void Boss2::Update(float dt)
{
	IEnemy::Update(dt);
	Scene_Fight * s = (Scene_Fight *)sceneManager->currentScene;

	if (playerInfo.isHpIncreased)
	{
		s->log->PushLog("광란 : 포션을 사용할 수 없습니다.");
		s->playerHp -= 10;
		playerInfo.isHpIncreased = false;
	}
}
