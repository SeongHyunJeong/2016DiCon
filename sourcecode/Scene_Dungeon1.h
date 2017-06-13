#pragma once
#include "GScene.h"
#include "Sprite.h"
#include"Collisions.h"
#include"Confirm.h"
//////////////// ID : 3///////////////////////////
class Scene_Dungeon1 :
	public GScene
{
public:
	Scene_Dungeon1(int id, Vec2 pp);
	~Scene_Dungeon1();

	Sprite * background;
	Sprite * _1;
	Sprite * _4;
	Player * player;
	Animation * goblin; //고블린



	RECT rgoblin; //고블린

	//이동용
	RECT to1;
	RECT to4;

	RECT collider[7];

	Confirm  * c;


	void Render();
	void Update(float dTime);
};

