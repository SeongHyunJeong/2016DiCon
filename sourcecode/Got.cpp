#include "Got.h"
#include"PlayerInfo.h"
#include"Scene_Fight.h"

Got::Got()
	:IEnemy("img/mob/2/��Ʈ����/��Ʈ����.png", "0", 15000, 20)
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
			fs->log->PushLog("���� : ������ ȸ���մϴ�.");
			hp.first += playerInfo.damage;
		}

		hit = false;
	}
	if (attacked)
	{
		if (rand() % 100 ==0)
		{
			fs->log->PushLog("��� : 5���� ������� �����ϴ�.");
			fs->playerHp -= damage * 4;
		}

		attacked = false;
	}
	if (playerInfo.isHpIncreased)
	{
		if (rand() % 100 <= 40)
		{
			fs->log->PushLog("���� : ���� ����� ��ҵ˴ϴ�.");
			fs->playerHp -= 10;
		}
	}
}
