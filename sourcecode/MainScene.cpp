#include "MainScene.h"
#include "Global.h"
#include "GameScene.h"
#include "Scene_HowPlay.h"
#include"PlayerInfo.h"
#include"S6.h"
#include"S11.h"
#include"PrologScene.h"
#include"EpilogScene.h"
MainScene::MainScene()
{
	if (playerInfo.chapter == 1)
		background = new Sprite("img/ui/main.png");
	else if (playerInfo.chapter == 2)
		background = new Sprite("img/ui/main2.png");
	else if (playerInfo.chapter >= 3)
		background = new Sprite("img/ui/main3.png");
	AddObject(background);

	startButton = new Button("img/ui/start.png");
	AddObject(startButton);
	startButton->pos = Vec2(SCREEN_WIDTH -startButton->width-50, 190);

	howButton = new Button("img/ui/how.png");
	AddObject(howButton);
	howButton->pos = Vec2(SCREEN_WIDTH -howButton->width-50 , 330);

	exitButton = new Button("img/ui/end.png");
	AddObject(exitButton);
	exitButton->pos = Vec2(SCREEN_WIDTH -exitButton->width-50, 450);

	//settingButton = new Button("img/ui/settingsbutton.png");
	//AddObject(settingButton);
	//settingButton->pos = Vec2(50, 50);
	
	//test = new Inventory();
	//AddObject(test);
	/*sound = new Sound();
	sound->Initialize(g_hWnd);
	sound->Add("b.wav", "alias"); sound->Add("d.wav", "alias2");
	sound->Play("alias2", false); */
	sound.Initialize(g_hWnd);
	//sound.Add("sound/1.wav", "bgm");
	//sound.Play("bgm", true);
	sound.Add("sound/main.wav", "main");
	sound.Add("sound/click.wav", "click");
	sound.Add("sound/bg.wav", "bg");
	if(playerInfo.currentMap != 13 && playerInfo.prologWatched)
	sound.Play("main", true);
}


MainScene::~MainScene()
{

}

void MainScene::Render()
{
	Scene::Render();
	background->Render();
	startButton->Render();
	howButton->Render();
	exitButton->Render();
	//settingButton->Render();
	//test->Render();
	//playerInfo.inven->Render();

	
}

void MainScene::Update(float dTime)
{
	Scene::Update(dTime);
	if (!playerInfo.prologWatched)
	{
		sceneManager->ChangeScene(new PrologScene()); return;
	}
	if (playerInfo.currentMap == 13)
	{
		sceneManager->ChangeScene(new EpilogScene());  return;
	}
	if (startButton->IsClicked())
	{
		sound.Stop("main");
		sound.Play("bg", true);

		if (playerInfo.currentMap == 0)
		{
			sceneManager->ChangeScene(new Scene_Village(-1,Vec2(378, 500))); return;
			
		}
		else if (playerInfo.currentMap == 6)
		{
			sceneManager->ChangeScene(new S6(5, Vec2(723, 289))); return;
		}
			
		else if (playerInfo.currentMap == 11)
		{
			sceneManager->ChangeScene(new S11(5, Vec2(374, 468))); return;
		}
		
		
	}
	else if (howButton->IsClicked())
	{
		sound.Stop("main");
		sceneManager->ChangeScene(new Scene_HowPlay());
	}
		
	else if (exitButton->IsClicked())
	{
		
		PostQuitMessage(0);
	}
		//	else if (settingButton->IsClicked())
	//	printf("¼¼ÆÃ");
	return;
}

