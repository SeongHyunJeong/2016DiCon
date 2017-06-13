#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S11 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	RECT r1;
	RECT to10;
	RECT to12;
	RECT r2, r3;
	Player * player;
	Sprite * got;
	Sprite * ogre;
	S11(int id, Vec2 pp);
	~S11();
	Confirm * cf;
	Confirm * cf2;
	Confirm * cf3;

	RECT collider[6];

	void Render();
	void Update(float dt);
};
