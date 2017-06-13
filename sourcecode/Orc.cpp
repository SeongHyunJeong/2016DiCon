#include "Orc.h"
#include"Scene_Fight.h"


Orc::Orc()
	:IEnemy("img/mob/1/orc/오크.png", "0", 1400, 3)
{
	//isAttackTargetPlayer = true;
	scale = D3DXVECTOR2(2.5f, 2.5f);
}


Orc::~Orc()
{
}

void Orc::Update(float dt)
{
	Scene_Fight * s = (Scene_Fight *)sceneManager->currentScene;
	IEnemy::Update(dt);
	if (hp.first <= 700)
	{
		if (damage == 3)
			s->log->PushLog("전투민족: 오크의 공격력이 +2 증가합니다.");
		damage = 5;

	}
	
}
