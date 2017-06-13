#pragma once
#include "GScene.h"
#include  "Global.h"
#include "Sprite.h"
#include "Collisions.h"
#include"Quest.h"
#include"Confirm.h"
class Scene_CenterVillage :
	public GScene
{
public:
	Scene_CenterVillage(int id, Vec2 pp);
	~Scene_CenterVillage();
	
	Player * player;

	Sprite * background;
	Sprite * _1;
	Sprite * b;
	RECT qb;
	RECT to1;
	RECT up;
	RECT r[4];

	Quest * q;

	Confirm * cf;
	void Render();
	void Update(float dTime);
};

