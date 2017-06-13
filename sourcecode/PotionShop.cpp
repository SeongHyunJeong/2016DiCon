#include "PotionShop.h"

#include"PlayerInfo.h"


PotionShop::PotionShop()
{
	bg = new Sprite("img/ui/potionui/bg.png");
	AddChild(bg);

	potion = new Sprite("img/ui/potionui/potion.png");
	AddChild(potion);
	potion->pos = Vec2(23, 23);
	potion->scale = Vec2(0.8, 0.8);

	p1 = new Button("img/ui/potionui/p1.png");
	AddChild(p1);
	p1->pos = Vec2(45, 183);
	p1->diff = Vec2(249, 116);
	printf("%f\n", p1->diff.x);

	p2 = new Button("img/ui/potionui/p2.png");
	AddChild(p2);
	p2->pos = Vec2(45, 269);
	p2->diff = Vec2(249, 116);

	x = new Button("img/ui/potionui/x.png");
	AddChild(x);
	x->pos = Vec2(280, -10);
	x->diff = Vec2(249, 116);

	potionCount = new Text("Pixel NES");
	AddChild(potionCount);
	potionCount->pos = Vec2(140, 35);

	hp = new Text("Pixel NES");
	AddChild(hp);
	hp->pos = Vec2(100, 75);

	p1Cost = new Text("Pixel NES");
	AddChild(p1Cost);
	p1Cost->pos = Vec2(145, 213);

	p2Cost = new Text("Pixel NES");
	AddChild(p2Cost);
	p2Cost->pos = Vec2(145, 299);

	money = new Text("Pixel NES");
	AddChild(money);
	money->pos = Vec2(21, 126);

	isShowing = false;


}


PotionShop::~PotionShop()
{
}

void PotionShop::Render()
{
	IObject::Render();
	if (isShowing)
	{
		bg->Render();
		potion->Render();
		hp->Render();
		p1->Render();
		p2->Render();
		x->Render();

		potionCount->Render();
		p1Cost->Render();
		p2Cost->Render();
		money->Render();
	}
	
}

void PotionShop::Update(float dt)
{
	IObject::Update(dt);

	potionCount->Put(to_string(playerInfo.potion), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	hp->Put(to_string((int)playerInfo.maxHp), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	p1Cost->Put(" 100", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	p2Cost->Put("1000", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	money->Put(to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));



	if (isShowing)
	{
		if (p1->IsClicked())
		{
			if (playerInfo.money >= 100)
				playerInfo.money -= 100;
			playerInfo.potion += 1;
		}
		if (p2->IsClicked())
		{
			if (playerInfo.money >= 1000)
			{
				playerInfo.money -= 1000;
				playerInfo.maxHp += 10;
			}
				
		}
		if (x->IsClicked())
		{
			isShowing = false;
		}
	}
	
}
