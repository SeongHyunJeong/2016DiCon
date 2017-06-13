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
			fs->log->PushLog("치유 : 세계수가 체력을 100 회복합니다.");
			hp.first += 100;
		}
		if (rand() % 3 ==0)
		{
			fs->log->PushLog("숲의 권능 : 1.5배의 데미지를 입힙니다.");
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
			fs->log->PushLog("자연의 가호: 플레이어의 공격을 무시합니다.");
			hp.first += playerInfo.damage;
		}
		hit = false;
	}
}
