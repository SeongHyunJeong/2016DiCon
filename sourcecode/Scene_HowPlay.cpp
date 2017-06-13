#include "Scene_HowPlay.h"
#include "Global.h"
#include "Scene_Village.h"

Scene_HowPlay::Scene_HowPlay()
{
	howmain = new Sprite("img/ui/howmain.png");
	AddObject(howmain);

	startButton = new Button("img/ui/start.png");
	AddObject(startButton);
	startButton->pos = Vec2(SCREEN_WIDTH / 2 - startButton->width / 2, 450);

	explain1 = new Sprite("img/ui/explain1.png");
	AddObject(explain1);

	explain2 = new Sprite("img/ui/explain2.png");
	AddObject(explain2);

	explain3 = new Sprite("img/ui/explain3.png");
	AddObject(explain3);

	explain4 = new Sprite("img/ui/explain4.png");
	AddObject(explain4);

	nextButton = new Button("img/ui/next.png");
	AddObject(nextButton);
	nextButton->pos = Vec2(SCREEN_WIDTH - nextButton->width - 20, 220);
	nextButton->defaultImage->color = D3DCOLOR_ARGB(100, 0,0 , 0);
	prevButton = new Button("img/ui/prev.png");
	AddObject(prevButton);
	prevButton->pos = Vec2(SCREEN_WIDTH - prevButton->width - 750, 220);
		prevButton->defaultImage->color = D3DCOLOR_ARGB(100, 0, 0, 0);

	cursor = 1;

}


Scene_HowPlay::~Scene_HowPlay()
{
}

void Scene_HowPlay::Render()
{
	howmain->Render();
	
	

	if (cursor == 1)
		explain1->Render();
	else if (cursor == 2)
		explain2->Render();
	else if (cursor == 3) 
	{
		explain3->Render();
		
	}
	else if (cursor == 4)
	{
		explain4->Render();
		startButton->Render();
	}
	nextButton->Render();
	prevButton->Render();

}

void Scene_HowPlay::Update(float dTime)
{


	Scene::Update(dTime);
		if(nextButton->IsClicked())
			if (cursor < 4)
				cursor++;
			
		

		if (prevButton->IsClicked()) 
			if (cursor >1)
				cursor--;

		
	
		if (startButton->IsClicked()) 
			sceneManager->ChangeScene(new MainScene());
		


}
