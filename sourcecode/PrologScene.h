#pragma once
#include "GScene.h"
#include"Sprite.h"
class PrologScene :
	public GScene
{
public:
	//���ѷα� �̹�����
	Sprite * s[4];

	PrologScene();
	~PrologScene();
	pair<float, float> timer;
	int cursor;
	void Render();
	void Update(float dt);
};

