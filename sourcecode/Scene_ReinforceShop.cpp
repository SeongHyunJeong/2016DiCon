#include "Scene_ReinforceShop.h"
#include "Scene_Village.h"
#include"playerinfo.h"

Scene_ReinforceShop::Scene_ReinforceShop()
{
	bg = new Sprite("img/ui/reinui/bg.png");
	AddObject(bg);
	rfButton = new Button("img/ui/reinui/rein.png");
	AddObject(rfButton);
	rfButton->pos = Vec2(338, 314);

	//abilities = new Text("Arial", 10, 10);
	//AddObject(abilities);
	//abilities->Put("데미지:" + std::to_string(playerInfo.damage) + "업그레이드:" + std::to_string(playerInfo.upgrade) + "돈" + std::to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	//back = new Button("img/ui/shopback.png");
	//AddObject(back);
	//back->pos = Vec2(SCREEN_WIDTH / 2 - back->width / 2, 450);

	//anvil = new Sprite("img/ui/reinui/anvil.png");
	//AddObject(anvil);
	//anvil->pos = Vec2(285, 343);

	luck = new Text("Pixel NES");
	luck->pos = Vec2(340, 428);
	AddObject(luck);

	x = new Button("img/ui/reinui/x.png");
	AddObject(x);
	x->pos = Vec2(725,  0);

	weapon = new Sprite("img/ui/reinui/" + to_string((playerInfo.upgrade - 1) / 5) + ".png");
	AddObject(weapon);
	weapon->pos = Vec2(238, 19);
	weapon->scale = Vec2(1.5f, 1.5f);
	

	money = new Text("Pixel NES");
	AddObject(money);
	money->pos = Vec2(608, 520);

	upgrade = new Text("Pixel NES");
	AddObject(upgrade);

	damage = new Text("Pixel NES", 14, 30);
	AddObject(damage);

	sound.Add("sound/rein.wav", "rein");
}


Scene_ReinforceShop::~Scene_ReinforceShop()
{
}

void Scene_ReinforceShop::Render()
{
	Scene::Render();
	bg->Render();
	rfButton->onMouseImage->color = D3DCOLOR_ARGB(255, timeGetTime(), 50 + timeGetTime(), 100 + timeGetTime());
	rfButton->Render();
	//abilities->Render();
//	back->Render();

//	anvil->Render();
	luck->Render();
	x->Render();
	weapon->Render();
	money->Render();

	if ((playerInfo.upgrade - 1) % 5 + 1 < 5)
	{
		upgrade->pos = Vec2(483, 119);
		upgrade->Put(to_string((playerInfo.upgrade - 1) % 5 + 1), DT_LEFT, D3DCOLOR_ARGB(255,5, 5, 5));
		upgrade->Render();
		upgrade->pos = Vec2(719, 119);
		upgrade->Put(to_string((playerInfo.upgrade - 1) % 5 + 2), DT_LEFT, D3DCOLOR_ARGB(255, 5, 5, 5));
		upgrade->Render();

		damage->pos = Vec2(482 , 187);
		damage->Put(to_string((playerInfo.damage)), DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));
		damage->Render();
		damage->pos = Vec2(709, 187);
		damage->Put(to_string((playerInfo.damage) + (playerInfo.upgrade / 5 + 1)), DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));
		damage->Render();
	}
	else
	{
		upgrade->pos = Vec2(483, 119);
		upgrade->Put("5", DT_LEFT, D3DCOLOR_ARGB(255, timeGetTime()%255, 255, 255-timeGetTime()%255));
		upgrade->Render();
		damage->pos = Vec2(482, 182);
		damage->Put(to_string((playerInfo.damage)), DT_LEFT, D3DCOLOR_ARGB(255, timeGetTime() % 255, 255, 255 - timeGetTime() % 255));
		damage->Render();
	}

}

void Scene_ReinforceShop::Update(float dTime)
{
	
	Scene::Update(dTime);
	
	luck->Put(to_string(100 - ((playerInfo.upgrade % 5 - 1) * 5) - (playerInfo.upgrade / 5 * 5))+"%", DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));
	if (playerInfo.upgrade % 5 == 0) luck->Put("MAX", DT_LEFT, D3DCOLOR_ARGB(255, 255, 255, 255));
	//버튼으로 교체할것
	if (rfButton->IsClicked())
	{
		sound.Play("rein", false);
		if (playerInfo.upgrade % 5 == 0)
		{
			//강화 불가 처리
		}
		else
		{
			Reinforce();
		}
		
	}

	money->Put(to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	//마을로 돌아가기

	if (x->IsClicked())
	{
		sound.Play("click", false);
		sceneManager->ChangeScene(new Scene_Village(-1, Vec2(310, 241)));
	}
			

	
}

void Scene_ReinforceShop::Reinforce()
{
	moneyset = 10;
	for (int i = 1; i<(playerInfo.upgrade / 5); i++) {
		moneyset *= 10;
	}




	if (playerInfo.money >= moneyset) {






		playerInfo.money -= moneyset;
		int random = rand() % 100 + 1;
		int percent = 100 - ((playerInfo.upgrade % 5 - 1) * 5) - (playerInfo.upgrade / 5 * 5);
		if (random <= percent) {
			
			playerInfo.damage += (playerInfo.upgrade / 5 + 1);
			playerInfo.upgrade++;
		}
		else {
			//강화실패
		}
		//abilities->Put("데미지:" + std::to_string(playerInfo.damage) + "업그레이드:" + std::to_string(playerInfo.upgrade) + "돈" + std::to_string(playerInfo.money) + "moneyset:" + std::to_string(moneyset), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	}
	else
	{
		//돈부족
	}


	
}