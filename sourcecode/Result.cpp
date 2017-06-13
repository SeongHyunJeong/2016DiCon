#include "Result.h"
#include"playerinfo.h"

Result::Result(Sprite * rewardImg, int mobId)
{
	bg = new Sprite("img/ui/result.png");
	AddChild(bg);
	reward = rewardImg;
	AddChild(reward);
	reward->pos = Vec2(108, 230);
	rewardText = new Text("Pixel NES");
	AddChild(rewardText);
	rewardText->pos = Vec2(242, 233);
	accText = new Text("Pixel NES");
	AddChild(accText);
	accText->pos = Vec2(143, 175);
	rewardCount = 0;

	expText = new Text("Pixel NES");
	AddChild(expText);
	expText->pos = Vec2(87, 332);

	moneyText = new Text("Pixel NES");
	AddChild(moneyText);
	moneyText->pos = Vec2(87, 277);


	exp = 0;
	money = 0;
	this->mobId = mobId;

	isShowing = false;
	isClosed = false;
}

Result::~Result()
{
}

void Result::SetActive(float acc, int perf, float curHp, int endstate)
{
	
	if (!isShowing)
	{
		if (endstate == 0)
			rank = new Sprite("img/ui/d.png");
		else if (acc >= 0.98)
		{
			rank = new Sprite("img/ui/s.png");
			rewardCount = 2;
			money += 50 * (mobId + 1);
			exp += pow(2, mobId) * 300;
		}
		else if (acc < 0.97 && acc >= 0.90)
		{
			rank = new Sprite("img/ui/a.png");
			rewardCount = 1;
			money += 45 * (mobId + 1);
			exp += pow(2, mobId) * 210;
		}
		else if (acc < 0.90 && acc >= 0.80)
		{
			rank = new Sprite("img/ui/b.png");
			rewardCount = 1;
			money += 33 * (mobId + 1);
			exp += pow(2, mobId) * 50;
		}
		else if (acc < 0.80)
		{
			rank = new Sprite("img/ui/c.png");
			rewardCount = 0;
			money += 22 * (mobId + 1);
			exp += pow(2, mobId) / 3;
		}

		AddChild(rank);
		rank->pos = Vec2(246, 173);
		//프리타임을 끝까지 플레이했을때
		if (endstate == 2)
		{
			rewardCount++;
			money *= 1.2f;
			exp *= 1.1f;
		}


		//체력이 최대체력의 10분의 9 이상일 때
		if (curHp >= 0.9f * playerInfo.maxHp)
		{
			rewardCount++;
			money *= 1.2f;
			exp *= 1.1f;
		}
		if(mobId <= 8)
		playerInfo.itemCount[mobId] += rewardCount;
		playerInfo.exp.first += exp;
		playerInfo.money += money;
		//레벨 업 처리
		while (playerInfo.exp.first >= playerInfo.exp.second)
		{
			playerInfo.lv++;
			playerInfo.exp.first -= playerInfo.exp.second;
			playerInfo.exp.second *= 2;
			playerInfo.damage += 2;
			playerInfo.maxHp += 2;
		}

		rewardText->Put(to_string(rewardCount), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		expText->Put(to_string((int)exp), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		moneyText->Put(to_string((int)money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		accText->Put(to_string((int)(acc * 100))+"%", DT_LEFT, D3DCOLOR_ARGB(255, 0, 255, 0));
		isShowing = true;

		if(mobId>= 9 && curHp > 0)
		playerInfo.isCleared[mobId] = 1;
	}


	
}

void Result::Render()
{
	IObject::Render();
	if (isShowing)
	{
		bg->Render();
		rank->Render();
		reward->Render();
		rewardText->Render();
		accText->Render();
		expText->Render();
		moneyText->Render();
	}
}

void Result::Update(float dt)
{
	IObject::Update(dt);
}
