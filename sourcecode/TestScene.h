#pragma once

//���̵���/���̵�ƿ� �����
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

