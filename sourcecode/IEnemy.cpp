#include "IEnemy.h"
#include"global.h"


IEnemy::IEnemy(string path, string itempath,float _hp, float damage)
	:ani(new Animation(20)),damage(damage)
{
	ani->AddFrame(path);
	AddChild(ani);

	hp.first = _hp;
	hp.second = _hp;

	attacked = false;
	hit = false;
	alive = true;
}


IEnemy::~IEnemy()
{
	scale = Vec2(2.5f, 2.5f);
}

void IEnemy::Render()
{
	IObject::Render();
	ani->Render();
}

void IEnemy::Update(float dt)
{
	IObject::Update(dt);
	if(TimeToS1(dt))
	Skill1(dt);
	if(TimeToS2(dt))
	Skill2(dt);
	if(TimeToS3(dt))
	Skill3(dt);
	HealthCalc(dt);
}

bool IEnemy::TimeToS1(float dt)

{
	return false;
	
}

void IEnemy::Skill1(float dt)
{

}

bool IEnemy::TimeToS2(float dt)
{
	return false;
}

void IEnemy::Skill2(float dt)
{

}

bool IEnemy::TimeToS3(float dt)
{
	return false;
}

void IEnemy::Skill3(float dt)
{

}

void IEnemy::HealthCalc(float dt)
{

	//hp.first -= 2;
	if (hp.first >= hp.second)hp.first = hp.second;
	if (hp.first < 0) alive = false;
}
