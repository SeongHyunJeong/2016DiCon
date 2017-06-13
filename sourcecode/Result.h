#pragma once
#include "IObject.h"
#include"Sprite.h"
#include"Text.h"
//��Ȯ���� ����Ʈ����, �÷��̾��� ����ü���� �־��ָ� ������ ����ؼ� ǥ��
class Result :
	public IObject
{
public:
	
	Result(Sprite * rewardImg,int mobId);
	~Result();

	Sprite * bg;

	int mobId;

	bool isShowing;

	bool isClosed;

	void SetActive(float acc, int perf, float curHp, int endstate);
	
	int rewardCount;
	Sprite * rank;
	Sprite * reward;

	Text * rewardText;
	Text * accText;

	Text * expText;
	float exp;
	Text * moneyText;
	float money;

	void Render();
	void Update(float dt);
	
};

