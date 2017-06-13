#pragma once
#include "IObject.h"
#include"Sprite.h"
#include"Animation.h"
class IEnemy :
	public IObject
{
public:
	IEnemy(string path, string itempath, float hp, float damage);
	~IEnemy();

	//적 이미지
	Animation * ani;

	//드랍 아이템 이미지
	//Sprite * dropItem;

	//적 체력
	pair<float, float>hp;

	//적 데미지
	float damage;

	//hp > 0 프리타임?
	bool alive;
	
	//인게임에서 적 스프라이트를 그린다.
	virtual void Render();

	//스킬을 사용하고 체력수치를 업데이트한다.
	virtual void Update(float dt);
	//스킬 1 발동조건
	virtual bool TimeToS1(float dt);
	//스킬 1
	virtual void Skill1(float dt);
	//스킬 2 발동조건
	virtual bool TimeToS2(float dt);
	//스킬 2
	virtual void Skill2(float dt);
	//스킬 3 발동조건
	virtual bool TimeToS3(float dt);
	//스킬 3
	virtual void Skill3(float dt);

	//체력계산 기준


	virtual void HealthCalc(float dt);

	//플레이어가 맞았을시
	bool attacked;
	//자기가 맞았을시
	bool hit;

};

