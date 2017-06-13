#pragma once
#include "Scene.h"
#include "Sprite.h"
#include"SText.h"
#include"Sound.h"
#include"Scene_Village.h"
#include"Button.h"
#include"Inventory.h"
class MainScene :
	public Scene
{
public:
	MainScene();
	~MainScene();

	Button * startButton;
	Button * howButton;
	Button * exitButton;

	//Button * settingButton;
	Sprite * background;
	//Inventory * test;

	void Render();
	void Update(float dTime);
};




	
