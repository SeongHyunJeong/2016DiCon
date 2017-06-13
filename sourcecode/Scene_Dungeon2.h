#pragma once
#include "GScene.h"
#include "Sprite.h"
#include "Collisions.h"
#include "Animation.h"
#include"Confirm.h"
class Scene_Dungeon2 :
	public GScene
{
public:
	Scene_Dungeon2(int id, Vec2 pp);
	~Scene_Dungeon2();

	Sprite * Priorbackground;
	Sprite * background;
	Sprite * back;
	Animation * slime;
	Player * player;

	int priorpresentX, priorpresentY;

	RECT slimearea;

	RECT collider[6];

	RECT Dungeon3;


	RECT to3;

	void Render();
	void Update(float dTime);

	Confirm *c;

};

