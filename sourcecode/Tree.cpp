#include "Tree.h"
#include"scene_fight.h"
#include"PlayerInfo.h"

Tree::Tree()
	:IEnemy("img/mob/1/tree/tree.png", "0", 2300, 15)
{
	scale = D3DXVECTOR2(2.5f, 2.5f);
}


Tree::~Tree()
{
}

void Tree::Update(float dt)
{
	Scene_Fight * fs = (Scene_Fight*)sceneManager->currentScene;
	IEnemy::Update(dt);

	if (attacked)
	{
		if (rand() % 10 ==0)
		{
			fs->log->PushLog("ġ�� : ������� ü���� 100 ȸ���մϴ�.");
			hp.first += 100;
		}
		if (rand() % 3 ==0)
		{
			fs->log->PushLog("���� �Ǵ� : 1.5���� �������� �����ϴ�.");
			if (fs->player)
			{
				fs->playerHp -= damage / 2;
			}
		}
		attacked = false;
	}
	if (hit)
	{
		if (rand() % 10 ==0)
		{
			fs->log->PushLog("�ڿ��� ��ȣ: �÷��̾��� ������ �����մϴ�.");
			hp.first += playerInfo.damage;
		}
		hit = false;
	}
}
