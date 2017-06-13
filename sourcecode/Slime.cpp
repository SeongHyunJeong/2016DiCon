#include "Slime.h"
#include"Scene_Fight.h"


Slime::Slime()
	:IEnemy("img/mob/1/slime/1.png", "img/ui/inventory/items/1_slime.png", 400, 1)
{
	for (int i = 2; i <= 5; i++)
		ani->AddFrame("img/mob/1/slime/" + to_string(i) + ".png");


	scale = D3DXVECTOR2(2.5f, 2.5f);
}


Slime::~Slime()
{
}

void Slime::Render()
{
	IEnemy::Render();

}

void Slime::Update(float dt)
{
	IEnemy::Update(dt);
}

bool Slime::TimeToS1(float dt)
{
	return false;
}

void Slime::Skill1(float dt)
{
}

void Slime::HealthCalc(float dt)
{
	Scene_Fight * fs = (Scene_Fight*)sceneManager->currentScene;
	if (hp.first < 0)
	{
		if (alive)
		{
			if (rand() % 2)
			{
				hp.first = 200;
				fs->log->PushLog("슬라임이 분열되었습니다.");
				fs->log->PushLog("체력을 200 회복합니다.");
			}
			else
			{
				alive = false;
			}
		}
		
	}
}
