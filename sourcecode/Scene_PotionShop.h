#pragma once
#include "GScene.h"
#include "Text.h"
#include "Sprite.h"
#include"Button.h"

class Scene_PotionShop :
	public GScene
{
public:
	Scene_PotionShop();
	~Scene_PotionShop();

	Button * back;

	Text * abilities;//�ӽ� �ɷ�ġ ��¿� ����

	int PotionPrice;
	

	void Render();
	void Update(float dTime);
};

