#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S9 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	RECT r1;
	RECT to8;
	RECT to10;
	Player * player;
	Sprite * tree;
	S9(int id, Vec2 pp);
	~S9();
	Confirm * cf;

	RECT collider[10];

	void Render();
	void Update(float dt);
};
