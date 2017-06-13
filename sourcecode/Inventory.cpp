#include "Inventory.h"
#include"PlayerInfo.h"


Inventory::Inventory()
{
	bg = new Sprite("img/ui/inventory/bg.png");
	AddChild(bg);
	items[0] = new Sprite("img/ui/inventory/items/0_goblinhair.png");
	AddChild(items[0]);
	items[0]->pos = Vec2( 37, 185);
	items[0]->scale = Vec2(0.9f, 0.9f);

	items[1] = new Sprite("img/ui/inventory/items/1_slime.png");
	AddChild(items[1]); 
	items[1]->pos = Vec2(127, 185);

	items[2] = new Sprite("img/ui/inventory/items/2_mushroom.png");
	AddChild(items[2]);
	items[2]->pos = Vec2(217, 185);

	items[3] = new Sprite("img/ui/inventory/items/3_sting.png");
	AddChild(items[3]);
	items[3]->pos = Vec2(37, 255);

	items[4] = new Sprite("img/ui/inventory/items/4_orcspear.png");
	AddChild(items[4]);
	items[4]->pos = Vec2(127, 255);

	items[5] = new Sprite("img/ui/inventory/items/5_tree.png");
	AddChild(items[5]);
	items[5]->pos = Vec2(217, 255);

	items[6] = new Sprite("img/ui/inventory/items/6_ogrehorn.png");
	AddChild(items[6]);
	items[6]->pos = Vec2(37, 317);
	items[6]->scale = Vec2(0.5f, 0.5f);

	items[7] = new Sprite("img/ui/inventory/items/7_scythe.png");
	AddChild(items[7]);
	items[7]->pos = Vec2(127, 317);
	items[7]->scale = Vec2(0.5f, 0.5f);

	items[8] = new Sprite("img/ui/inventory/items/8_dog.png");
	AddChild(items[8]);
	items[8]->pos = Vec2(217, 317);
	items[8]->scale = Vec2(0.5f, 0.5f);
	noItem = new Sprite("img/ui/inventory/noitem.png");
	AddChild(noItem);


	//수정필요
	for (int i = 0; i < 5; i++)
	{
		weapons[i] = new Sprite("img/ui/weaponui/" + to_string(i) + ".png");
		AddChild(weapons[i]);
		weapons[i]->pos = Vec2(186, 36);
		weapons[i]->scale = Vec2(0.6f, 0.6f);
	}

	lv = new Text("Pixel NES",10,30);
	lv->str = "";
	AddChild(lv);
	lv->pos = Vec2(110, 20);

	exp = new Text("Pixel NES",10,20);
	exp->str = "";
	AddChild(exp);
	exp->pos = Vec2(80, 50);

	money = new Text("Pixel NES",10,20);
	money->str = "";
	AddChild(money);
	money->pos = Vec2(65, 74);

	upgrade = new Text("Pixel NES",7,20);
	upgrade->str = "";
	AddChild(upgrade);
	upgrade->pos = Vec2(270, 93);

	job = new Text("Pixel NES",7,20);
	job->str = "";
	AddChild(job);
	job->pos = Vec2(16, 126);

	chapter = new Text("Pixel NES",7,20);
	chapter->str = "";
	AddChild(chapter);
	chapter->pos = Vec2(61, 146);

	damage = new Text("Pixel NES",7,20);
	damage->str = "";
	AddChild(damage);
	damage->pos = Vec2(197, 125);

	itemCount = new Text("Pixel NES", 6, 15);
	itemCount->str = "";
	AddChild(itemCount);


	/*itemCount = new Text("Pixel NES");
	itemCount->str = "";
	AddChild(itemCount);
	itemCount->pos = Vec2()*/



}


Inventory::~Inventory()
{
}

void Inventory::Render()
{
	IObject::Render();
	bg->Render();
	for (int i = 0; i < 9; i++)
	{
		items[i]->Render();
		//챕터가 1일때 6, 7, 8번째 아이템 가리기
		if (playerInfo.chapter == 1 && i >= 6)
		{
			noItem->pos = items[i]->pos;
			noItem->Render();
		}
	}
		
	//noItem->Render();
	lv->Render();
	exp->Render();
	money->Render();
	upgrade->Render();
	job->Render();
	chapter->Render();
	//itemCount->Render();
	damage->Render();
	//x->Render();

	for (int i = 0; i < 9; i++)
	{
		itemCount->Put(to_string(playerInfo.itemCount[i]), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		if(i<6)
		itemCount->pos = items[i]->pos + Vec2(57, 34);
		else if(i>=6)
		itemCount->pos = items[i]->pos + Vec2(57, 37);
		itemCount->Render();
	}
	

	weapons[(playerInfo.upgrade-1) / 5]->Render();
}	

void Inventory::Update(float dt)
{
	IObject::Update(dt);

	lv->Put(to_string(playerInfo.lv), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	exp->Put(to_string((int)playerInfo.exp.first) + "/" + to_string((int)playerInfo.exp.second), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	money->Put(to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	upgrade->Put(to_string((playerInfo.upgrade-1)%5+1), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	job->Put(to_string(playerInfo.job), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	chapter->Put(to_string(playerInfo.chapter), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	/*exp->str = to_string(playerInfo.exp.first) + "/" + to_string(playerInfo.exp.second);
	money->str = to_string(playerInfo.money);
	upgrade->str = to_string(playerInfo.upgrade);
	job->str = to_string(playerInfo.job);
	chapter->str = to_string(playerInfo.chapter);*/
	damage->Put(to_string(playerInfo.damage), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
}
