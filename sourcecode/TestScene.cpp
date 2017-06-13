#include "TestScene.h"



TestScene::TestScene()
	:fadein(new Sprite("img/fadetest.png"))
{
	AddObject(fadein);
	fade.first = 255;
	fade.second = 0;
}


TestScene::~TestScene()
{
}


void TestScene::Render()
{
	fadein->Render();
}

void TestScene::Update(float dt)
{
	fade.first -= 5;
	if (fade.first <= fade.second) fade.first = 255;
	fadein->color = D3DCOLOR_ARGB(255, fade.first, fade.first, fade.first);
	


}