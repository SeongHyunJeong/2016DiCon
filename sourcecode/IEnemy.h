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

	//�� �̹���
	Animation * ani;

	//��� ������ �̹���
	//Sprite * dropItem;

	//�� ü��
	pair<float, float>hp;

	//�� ������
	float damage;

	//hp > 0 ����Ÿ��?
	bool alive;
	
	//�ΰ��ӿ��� �� ��������Ʈ�� �׸���.
	virtual void Render();

	//��ų�� ����ϰ� ü�¼�ġ�� ������Ʈ�Ѵ�.
	virtual void Update(float dt);
	//��ų 1 �ߵ�����
	virtual bool TimeToS1(float dt);
	//��ų 1
	virtual void Skill1(float dt);
	//��ų 2 �ߵ�����
	virtual bool TimeToS2(float dt);
	//��ų 2
	virtual void Skill2(float dt);
	//��ų 3 �ߵ�����
	virtual bool TimeToS3(float dt);
	//��ų 3
	virtual void Skill3(float dt);

	//ü�°�� ����


	virtual void HealthCalc(float dt);

	//�÷��̾ �¾�����
	bool attacked;
	//�ڱⰡ �¾�����
	bool hit;

};

