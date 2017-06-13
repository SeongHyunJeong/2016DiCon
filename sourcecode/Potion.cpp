#include "Potion.h"
#include"PlayerInfo.h"
#include"Sound.h"
//#include"Scene_Fight.h"
Potion::Potion(string cpath, string rpath)
{
	cool = new Sprite(cpath);
	AddChild(cool);
	ready = new Sprite(rpath);
	AddChild(ready);

	count = new Text("Pixel NES", 7, 15);
	AddChild(count);
	count->pos = Vec2(51, 33);

	timer.first = 0;
	timer.second = 30;

	isReady = false;
	sound.Add("sound/potion.wav", "potion");
}

Potion::~Potion()
{
}

void Potion::Render()
{
	IObject::Render();
	if (isReady)
		ready->Render();
	else
		cool->Render();

	count->Render();
}

void Potion::Update(float dt)
{
	IObject::Update(dt);

	timer.first += dt;

	if (timer.first >= timer.second && playerInfo.potion >= 1)
	{
		isReady = true;
	}
		
	if (isReady)
	{
		//use potion
		if (GetMyKeyState(VK_SPACE) == KEYDOWN)
		{
			timer.first = 0;
			isReady = false;
			playerInfo.potion--;
			playerInfo.isHpIncreased = true;
			//s->playerHp += 10;
			sound.Play("potion", false);
		}
	}


	count->Put(to_string(playerInfo.potion), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
}
