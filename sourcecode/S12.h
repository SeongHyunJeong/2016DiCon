#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S12 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	RECT r1;
	RECT to11;
	RECT to13;
	Player * player;
	Sprite * ker;
	S12(int id, Vec2 pp);
	~S12();
	Confirm * cf;

	RECT collider[2];

	void Render();
	void Update(float dt);
};
