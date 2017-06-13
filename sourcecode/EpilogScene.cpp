#include "EpilogScene.h"
#include"MainScene.h"
#include"PlayerInfo.h"

EpilogScene::EpilogScene()
{
	for (int i = 0; i < 5; i++)
	{
		s[i] = new Sprite("img/epilog/" + to_string(i) + ".png");
		AddObject(s[i]);
	}
	cursor = 0;

	timer.first = 0;
	timer.second = 6.f;
	sound.Initialize(g_hWnd);
	sound.Add("sound/epilog.wav", "epilog");
	sound.Play("epilog", true);
}


EpilogScene::~EpilogScene()
{
	//sound.Shutdown();
}

void EpilogScene::Render()
{
	if(cursor<=4)
	s[cursor]->Render();
}

void EpilogScene::Update(float dt)
{
	timer.first += dt;
	if (timer.first >= timer.second)
	{
		timer.first = 0;
		cursor++;
		
	}
	if (cursor >= 5)
	{
		playerInfo.Reset();
		//에필로그를 다봤으면 플레이어정보를 리셋한다.
		sound.Stop("epilog");
		PostQuitMessage(0);
	}
}