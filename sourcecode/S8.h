#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S8 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * mask;
	Sprite * p;
	RECT r1;
	RECT to7;
	RECT to9;
	Player * player;
	Sprite * orc;
	S8(int id, Vec2 pp);
	~S8();
	Confirm * cf;

	RECT collider[8];

	void Render();
	void Update(float dt);
};
