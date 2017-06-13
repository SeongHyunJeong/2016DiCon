#include "Got.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"

Got::Got()
	:IEnemy("img/mob/2/고트리퍼/고트리퍼.png", "0", 15000, 20)
{
	scale = Vec2(1, 1);
}


Got::~Got()
{
}

void Got::Update(float dt)
{
	Scene_Fight * fs = (Scene_Fight*)sceneManager->currentScene;
IEnemy::Update(dt);
	if (hit)
	{
		if (rand() % 10 ==0)
		{
			fs->log->PushLog("유령 : 공격을 회피합니다.");
			hp.first += playerInfo.damage;
		}

		hit = false;
	}
	if (attacked)
	{
		if (rand() % 100 ==0)
		{
			fs->log->PushLog("사신 : 5배의 대미지를 입힙니다.");
			fs->playerHp -= damage * 4;
		}

		attacked = false;
	}
	if (playerInfo.isHpIncreased)
	{
		if (rand() % 100 <= 40)
		{
			fs->log->PushLog("지혜 : 포션 사용이 취소됩니다.");
			fs->playerHp -= 10;
		}
	}
}
