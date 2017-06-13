#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S10 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	Player * player;
	S10(int id, Vec2 pp);
	~S10();
	Confirm * cf;

	void Render();
	void Update(float dt);
};
