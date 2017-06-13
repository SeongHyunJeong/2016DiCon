#include "Scene_PotionShop.h"
#include "Scene_Village.h"
#include"PlayerInfo.h"

Scene_PotionShop::Scene_PotionShop()
{
	back = new Button("img/ui/shopback.png");
	AddObject(back);
	back->pos = Vec2(SCREEN_WIDTH / 2 - back->width / 2, 450);

	abilities = new Text("Arial", 10, 10);
	AddObject(abilities);


	PotionPrice = 100;
}


Scene_PotionShop::~Scene_PotionShop()
{
	
}

void Scene_PotionShop::Render()
{
	abilities->Render();
	back->Render();

}

void Scene_PotionShop::Update(float dTime)
{

	Scene::Update(dTime);

	if (GetMyKeyState(VK_RETURN) == KEYDOWN)
	{
		if (playerInfo.money >= PotionPrice)
		{
			playerInfo.potion++;
			playerInfo.money -= PotionPrice;
		}
	}
	
		

	
	abilities->Put("¼ÒÀ¯Æ÷¼Ç:" + std::to_string(playerInfo.potion) + "µ·:" + std::to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));

	if (back->IsClicked())
		sceneManager->ChangeScene(new Scene_Village());
}