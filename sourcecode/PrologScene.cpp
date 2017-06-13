#include "PrologScene.h"

#include"MainScene.h"
#include"PlayerInfo.h"
PrologScene::PrologScene()
{
	for (int i = 0; i < 4; i++)
	{
		s[i] = new Sprite("img/prolog/" + to_string(i) + ".png");
		AddObject(s[i]);
	}

	timer.first = 0;
	timer.second = 4.0f;
	cursor = 0;
	sound.Add("sound/prolog.wav", "prolog");
	sound.Play("prolog", false);
	
}


PrologScene::~PrologScene()
{
}

void PrologScene::Render()
{
	
		s[cursor]->Render();


}

void PrologScene::Update(float dt)
{
	Scene::Update(dt);
	timer.first += dt;

	if (timer.first >= timer.second)
	{
		timer.first = 0;
		cursor++;
	}
	if (cursor >= 4)
	{
		sound.Stop("prolog");
		playerInfo.prologWatched = true;
		sceneManager->ChangeScene(new MainScene());
	}

}
