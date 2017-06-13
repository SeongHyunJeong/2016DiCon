#include "Scene_Weaponchange.h"
#include"scene_village.h"
#include"PlayerInfo.h"


Scene_Weaponchange::Scene_Weaponchange()
{
	abilities = new Text("Arial", 10, 10);
	AddObject(abilities);
	abilities->Put("데미지:" + std::to_string(playerInfo.damage) + "업그레이드:" + std::to_string(playerInfo.upgrade) + "돈" + std::to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	back = new Button("img/ui/shopback.png");
	AddObject(back);
	back->pos = Vec2(SCREEN_WIDTH / 2 - back->width / 2, 450);

	moneyset = 10;
	

}


Scene_Weaponchange::~Scene_Weaponchange()
{
}

void Scene_Weaponchange::Render()
{
	abilities->Render();
	back->Render();

}

void Scene_Weaponchange::Update(float dTime)
{
	Scene::Update(dTime);
	abilities->Update(dTime);

	for (int i = 1; i < (playerInfo.upgrade / 5); i++)
		moneyset *= 10;

	
		if (GetMyKeyState(VK_RETURN) == KEYDOWN)
		{
			switch (playerInfo.upgrade / 5) {
			case 1: playerInfo.damage = 10; break;
			case 2: playerInfo.damage = 30; break;
			case 3: playerInfo.damage = 50; break;
			case 4: playerInfo.damage = 100; break;
			default: break;
			}
		}


		if (playerInfo.upgrade % 5 == 0 && playerInfo.money >= moneyset) {
			playerInfo.money -= moneyset;
			playerInfo.upgrade++;
		}
	
		
	abilities->Put("데미지:" + std::to_string(playerInfo.damage) + "업그레이드:" + std::to_string(playerInfo.upgrade) + "돈" + std::to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	
	if (back->IsClicked())
	{
		sceneManager->ChangeScene(new Scene_Village());
	
	}
	

}
