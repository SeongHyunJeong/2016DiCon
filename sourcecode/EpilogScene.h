#pragma once
#include "GScene.h"
class EpilogScene :
	public GScene
{
public:
	//���ʷα� �̹����� 
	Sprite * s[5];
	EpilogScene();
	~EpilogScene();
	int cursor;
	pair<float, float> timer;
	void Render();
	void Update(float dt);

	
	
};

