#pragma once

//페이드인/페이드아웃 실험용
#include "Scene.h"
#include"Sprite.h"
class TestScene :
	public Scene
{
public:
	Sprite * fadein;
	pair<int, int> fade;

	TestScene();
	~TestScene();


	void Render();
	void Update(float dt);
};

