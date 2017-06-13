#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"

class S6 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	RECT r1;
	RECT to5;
	Player * player;
	S6(int id, Vec2 pp);
	~S6();

	Confirm * s;

	RECT collider[10];

	void Render();
	void Update(float dt);
};

