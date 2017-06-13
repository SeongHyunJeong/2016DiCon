#pragma once
#include "GScene.h"
#include"Player.h"
#include"Confirm.h"
class S13 :
	public GScene
{
public:

	Sprite * bg;
	Sprite * p;
	Player * player;
	Sprite * boss[3];
	RECT to12;
	S13(int id, Vec2 pp);
	~S13();
	Confirm * cf;
	
	void Render();
	void Update(float dt);
};
