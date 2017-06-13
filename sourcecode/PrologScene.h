#pragma once
#include "GScene.h"
#include"Sprite.h"
class PrologScene :
	public GScene
{
public:
	//프롤로그 이미지들
	Sprite * s[4];

	PrologScene();
	~PrologScene();
	pair<float, float> timer;
	int cursor;
	void Render();
	void Update(float dt);
};

