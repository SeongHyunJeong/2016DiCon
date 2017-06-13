#include "ResultScene.h"
#include "Global.h"
#include "MainScene.h"
#include "GameScene.h"

ResultScene::ResultScene(int score)
{
	mainButton = new Sprite("gotomain.png");
	AddObject(mainButton);
	mainButton->pos = Vec2(SCREEN_WIDTH / 2 - mainButton->width / 2, 400);

	scoreT = new Sprite("score.png");
	AddObject(scoreT);
	scoreT->pos = Vec2(SCREEN_WIDTH / 2 - scoreT->width / 2, 100);

	sample = new Text();

	lastScore = score;

}


ResultScene::~ResultScene()
{
}

void ResultScene::Render()
{
	mainButton->Render();
	scoreT->Render();

	sample->Put(lastScore);
	sample->ShowText(sample->str, 400, 300, DT_LEFT, D3DCOLOR_ARGB(255,0,0,0));
}

void ResultScene::Update(float dTime)
{
	Scene::Update(dTime);

	if (GetMyKeyState(VK_LBUTTON) == 1)
	{
		if (IsPointInRect(mainButton->pos, mainButton->rect, GetMousePos()))
			sceneManager->ChangeScene(new MainScene());
		return;
	}
}