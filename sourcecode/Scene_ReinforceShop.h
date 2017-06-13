#pragma once
#include "GScene.h"
#include"Sprite.h"
#include"Global.h"
#include"Text.h"
#include"button.h"

class Scene_ReinforceShop :
	public GScene
{
public:
	Scene_ReinforceShop();
	~Scene_ReinforceShop();

	Sprite * bg;
	Button * rfButton;
	//Button * back;
	//Sprite * anvil;
	Text * luck;
	//Text * abilities;//임시 능력치 출력용 변수

	Button * x;
	Sprite * weapon;
	Text * money;
	Text * upgrade;
	Text * damage;

	int moneyset;
	
	void Render();
	void Update(float dTime);
	void Reinforce();


};

