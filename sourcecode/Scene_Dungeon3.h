#pragma once
#include "GScene.h"
#include "Sprite.h"
#include "Player.h"
#include"Collisions.h"
#include"Confirm.h"
class Scene_Dungeon3 :
	public GScene
{
public:
	Scene_Dungeon3(int id, Vec2 pp);
	~Scene_Dungeon3();

	Sprite * Priorbackground;
	Sprite * background;
	Sprite * back;
	Sprite * mushroom;
	Player * player;

	Sprite * mushroom1;

	int priorpresentX, priorpresentY;

	//D3DXVECTOR2 Dungeon4;

	RECT Mush;
	RECT to4;
	RECT to6;
	RECT to7;

	RECT collider[13];

	void Render();
	void Update(float dTime);

	Confirm * c;
};

