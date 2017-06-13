#pragma once
#include "GScene.h"
#include"Sprite.h"
#include "Global.h"
#include"MainScene.h"
#include"Scene_CenterVillage.h"
#include"collisions.h"
#include"PotionShop.h"
#include"WeaponShop.h"
#include"Confirm.h"
class Scene_Village :
	public GScene
{
public:
	Scene_Village(int id=-1, Vec2 ppos=Vec2(0, 0));
	~Scene_Village();
	


	Sprite * background;
	Sprite *_1;
	Player * player;

	PotionShop * ps;
	WeaponShop * ws;
	
	//트리거
	RECT reinforceShop;
	RECT house;
	RECT weaponShop;
	RECT potionShop;
	RECT to1;

	//콜라이더(벽)
	RECT collider[6];

	//세이브용 컨펌창
	Confirm * s;


	void Render();
	void Update(float dTime);
};

