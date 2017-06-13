#pragma once
#include "GScene.h"
#include"Sprite.h"
#include"Player.h"
#include"button.h"
class Scene_HowPlay :
	public GScene
{
public:
	Scene_HowPlay();
	~Scene_HowPlay();

	Sprite * howmain;
	Button * startButton;
	Sprite * explain1;
	Sprite * explain2;
	Sprite * explain3;
	Sprite * explain4;
	Button * nextButton;
	Button * prevButton;
	int cursor;

	void Render();
	void Update(float dTime);
};

