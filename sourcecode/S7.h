#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S7 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	RECT r1;
	RECT to5;
	RECT to8;
	Player * player;
	Sprite * bee;
	S7(int id, Vec2 pp);
	~S7();
	Confirm * cf;

	RECT collider[9];

	void Render();
	void Update(float dt);
};

