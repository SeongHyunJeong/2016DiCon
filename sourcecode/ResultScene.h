#pragma once
#include "Scene.h"
#include "Sprite.h"
#include "Text.h"

class ResultScene :
	public Scene
{
public:
	ResultScene(int score);
	~ResultScene();

	Sprite*mainButton;
	Sprite*scoreT;

	int lastScore;

	void Render();
	void Update(float dTime);

	Text * sample;
};

