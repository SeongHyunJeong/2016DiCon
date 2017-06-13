#pragma once
#include "GScene.h"
#include "Global.h"
#include "Sprite.h"
#include "Collisions.h"

class Scene_CenterGate :
	public GScene
{
public:
	Scene_CenterGate(int id, Vec2 pp);
	~Scene_CenterGate();

	Sprite * spot;
	Sprite * prev_village;
	Sprite * background;
	Sprite *_2;
	Sprite *_3;
	Sprite * b;
	Player * player;

	RECT garden;

	RECT to0;
	RECT to2;
	RECT to3;
	RECT r1;
	RECT r2;

	D3DXVECTOR2 centervillage;

	void Render();
	void Update(float dTime);
};

