#include "Ker.h"

#include"PlayerInfo.h"
#include"scene_fight.h"

Ker::Ker()
	:IEnemy("img/mob/2/�ɷκ��ν�/ų��ν�.png", "0", 1000, 5)
{
	dead = false;
	scale = Vec2(0.5f, 0.5f);
}


Ker::~Ker()
{
}

void Ker::Update(float dt)
{
	Scene_Fight * fs = (Scene_Fight*)sceneManager->currentScene;
	IEnemy::Update(dt);
	if(!dead)
	damage = rand() % 15 + 6;
	if(!dead)
	if (attacked)
	{
		fs->log->PushLog("���� : ���ݷ��� 2�踸ŭ ȸ���մϴ�.");
		hp.first += damage * 2;
		attacked = false;
	}

}

void Ker::HealthCalc(float dt)
{
	Scene_Fight * fs = (Scene_Fight*)sceneManager->currentScene;
	if (hp.first < 0 && !dead)
	{
		dead = true;
		hp.first = hp.second = 10000;
		damage = 5;
		fs->log->PushLog("���� : ü���� 10000, ���ݷ��� 5�� �ǰ� ������ �ɷ��� �ҽ��ϴ�.");
	}
	if (dead)
		if (hp.first >= hp.second) hp.first = hp.second;

	if (hp.first < 0 && dead)
		alive = false;

}
