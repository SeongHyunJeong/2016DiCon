#include "GScene.h"
#include"PlayerInfo.h"
#include"Collisions.h"
#include"Sound.h"

GScene::GScene(int _id, D3DXVECTOR2 _spc):
	id(_id),
	spawnPlayerCoord(_spc),
	fade(255),
	fade2(0),
	isFadedOut(false),
	isInvenShowing(false),
	isSettingShowing(false)
{
	inventoryButton = new Button("img/ui/ingameui/inventory.png");
	AddObject(inventoryButton);
	inventoryButton->pos = Vec2(699, 511);

	settingButton = new Button("img/ui/ingameui/settingbutton.png");
	settingButton->pos = Vec2(689, 0);
	AddObject(settingButton);



	inven = new Inventory();
	AddObject(inven);
	inven->pos = Vec2(220, 100);
	x = new Button("img/ui/inventory/x.png");
	AddObject(x);
	x->pos = Vec2(495, 85);

	setting = new Setting();
	AddObject(setting);

	for (int i = 0; i < 5; i++)
	{
		exps[i] = new Sprite("img/ui/ingameui/"+to_string(i)+".png");
		AddObject(exps[i]);
	}

	minimap = new Minimap();
	AddObject(minimap);
	//minimap->SetCenter(minimap->bgs[1]->width, minimap->bgs[1]->height, minimap->bgs[1]);
	minimap->pos = Vec2(200, 100);

	level = new Text("Pixel NES", 7, 20);
	AddObject(level);
	level->pos = Vec2(26, 23);
	level->Put(to_string(playerInfo.lv), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	exp = new Text("Pixel NES", 5, 15);
	AddObject(exp);
	exp->pos = Vec2(56, 10);
	exp->Put(to_string((int)playerInfo.exp.first) + "/" + to_string((int)playerInfo.exp.second), DT_LEFT, D3DCOLOR_ARGB(125, 0, 0, 0));
	isFadedIn = false;

	map = new Button("img/ui/ingameui/map.png");
	AddObject(map);
	map->pos = Vec2(14, 511);


	isMapShowing = false;
	

}


GScene::~GScene()
{
}

void GScene::Render()
{
	Scene::Render();

	if (isFadedOut)
	{
		inventoryButton->Render();
		// setting->Render();
		settingButton->Render();
		map->Render();
		exps[(int)(playerInfo.exp.first / playerInfo.exp.second * 5)]->Render();
	}
	if (inventoryButton->IsClicked()||GetMyKeyState('I') == KEYDOWN)
	{
		sound.Play("click", false);
		isInvenShowing = true;
	}
	if (isInvenShowing)
	{
		inven->Render();
		x->pos = Vec2(495, 85);
		x->Render();
	}
	if (x->IsClicked())
	{
		isInvenShowing = false;
		isSettingShowing = false;
		isMapShowing = false;
		setting->isShowing = false;
		sound.Play("click", false);
	}

	if (settingButton->IsClicked())
	{
		isSettingShowing = true;
		setting->isShowing = true;
		sound.Play("click", false);
	}
	if (isSettingShowing)
	{
		x->pos = Vec2(653, 127);
		x->Render();
		setting->Render();
	}
	if (map->IsClicked()||GetMyKeyState('M') == KEYDOWN)
	{
		if (!isMapShowing)
			isMapShowing = true;
		else
			isMapShowing = false;
		//minimap->Render();
		sound.Play("click", false);
	}
	if (IsPointInRect(exps[1]->pos, exps[1]->rect, GetMousePos()))
	{
		exp->Render();
	}
	level->Render();
	if (isMapShowing)
	{
		minimap->Render();
	}

}

void GScene::Update(float dt)
{
	//f1키의 버그는 전투씬에서 적 체력을 0으로 만들어줌
	//버그
	if (GetMyKeyState(VK_F2) == KEYDOWN)//돈 증가 f2
	{
		playerInfo.money = 99999;
	}

	else if (GetMyKeyState(VK_F3) == KEYDOWN)//1챕터 아이템 50객 증가 f3
	{
		for (int i = 0; i < 6; i++)
			playerInfo.itemCount[i] += 50;
	}
	else if (GetMyKeyState(VK_F4) == KEYDOWN)//2챕터 아이템 50개 증가 f4
	{
		for (int j = 6; j < 9; j++)
			playerInfo.itemCount[j] += 50;
	}
	else if (GetMyKeyState(VK_F5) == KEYDOWN)//레벨 1씪 증가 f5
	{
		playerInfo.lv += 1;
		playerInfo.exp.second *= 2;
		exp->Put(to_string((int)playerInfo.exp.first) + "/" + to_string((int)playerInfo.exp.second), DT_LEFT, D3DCOLOR_ARGB(125, 0, 0, 0));
		level->Put(to_string(playerInfo.lv), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		playerInfo.damage += 2;
		playerInfo.maxHp += 2;
	}
	

	
	Scene::Update(dt);
	}

void GScene::MoveBackground(int x, int y, Sprite* prevBackgroundSprite, Sprite* nextBackgroundSprite)
{
	//x가 양수일 경우
	if (x != (*prevBackgroundSprite).pos.x)
		if (x > 0)
		{
			if (x >= (*prevBackgroundSprite).pos.x)
			{
				(*prevBackgroundSprite).pos.x += 10;
				(*nextBackgroundSprite).pos.x += 10;
			}
			else
			{
				(*prevBackgroundSprite).pos.x = x;
			}

		}//아닐경우
		else
		{
			if (x <= (*prevBackgroundSprite).pos.x)
			{
				(*prevBackgroundSprite).pos.x -= 10;
				(*nextBackgroundSprite).pos.x -= 10;
			}
			else
			{
				(*prevBackgroundSprite).pos.x = x;
			}
		}

	//y가 양수일 경우
	if (y != (*prevBackgroundSprite).pos.y)
		if (y > 0)
		{
			if (y >= (*prevBackgroundSprite).pos.y)
			{
				(*prevBackgroundSprite).pos.y += 10;
				(*nextBackgroundSprite).pos.y += 10;
			}
			else
			{
				(*prevBackgroundSprite).pos.y = y;
			}
		}//아닐경우
		else
		{
			if (y <= (*prevBackgroundSprite).pos.y)
			{
				(*prevBackgroundSprite).pos.y -= 10;
				(*nextBackgroundSprite).pos.y -= 10;
			}
			else
			{
				(*prevBackgroundSprite).pos.y = y;
			}
		}


}

bool GScene::FadeIn(Sprite * s)
{
	
	if (fade2 >= 255) {
		isFadedIn = true; return false;
	}
	fade2 += 5;
//	printf("%d", fade2);
	s->color = D3DCOLOR_ARGB(255, fade2, fade2, fade2);
	return true;
}

bool GScene::FadeOut(Sprite * s)
{
	
	if (fade <= 0) { isFadedOut = true; return false; }
	fade -= 5;
	//printf("asdf\n");
	s->color = D3DCOLOR_ARGB(255, 0, 0, 0);
	return true;
}
