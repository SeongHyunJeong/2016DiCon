#include "Ogre.h"

#include"Scene_Fight.h"

Ogre::Ogre()
	:IEnemy("img/mob/2/오우거/오우거.png", "0", 10000, 15)
{
	target = false;
	scale = Vec2(1, 1);
}


Ogre::~Ogre()
{
}

void Ogre::Update(float dt)
{
	Scene_Fight * fs = (Scene_Fight*)sceneManager->currentScene;
	IEnemy::Update(dt);

	if (attacked)
	{
		if (rand() % 2)
		{
			target = true;
			fs->log->PushLog("멍청함: 자기 자신을 공격합니다.");
			fs->playerHp += damage;
		}
		if (rand() % 2)
		{
			fs->log->PushLog("파괴력: 두 배의 대미지로 공격합니다.");
			if (target)
			{
				hp.first -= damage * 2;
			}
			else
				fs->playerHp -= damage;
		}
		attacked = false;
	}
}
