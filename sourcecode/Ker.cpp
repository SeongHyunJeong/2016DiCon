#include "Ker.h"

#include"PlayerInfo.h"
#include"scene_fight.h"

Ker::Ker()
	:IEnemy("img/mob/2/케로베로스/킬배로스.png", "0", 1000, 5)
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
		fs->log->PushLog("관심 : 공격력의 2배만큼 회복합니다.");
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
		fs->log->PushLog("공포 : 체력이 10000, 공격력이 5가 되고 나머지 능력을 잃습니다.");
	}
	if (dead)
		if (hp.first >= hp.second) hp.first = hp.second;

	if (hp.first < 0 && dead)
		alive = false;

}
