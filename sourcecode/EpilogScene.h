#pragma once
#include "GScene.h"
class EpilogScene :
	public GScene
{
public:
	//에필로그 이미지들 
	Sprite * s[5];
	EpilogScene();
	~EpilogScene();
	int cursor;
	pair<float, float> timer;
	void Render();
	void Update(float dt);

	
	
};

