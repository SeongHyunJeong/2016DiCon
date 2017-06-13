#pragma once
#include "Scene.h"
#include "Player.h"
#include "Enemy.h"
#include "Text.h"
#include "Item.h"

class GameScene :
	public Scene
{
public:
	GameScene();
	~GameScene();

	Player*player;
	Sprite *sprite;
	Enemy * enemy;
	Item*item;

	list<Item*>itemList;

	bool isGameOver;
	bool spawn;
	void Render();
	void Update(float dTime);

	Text * sample;

	void SpawnItem();
	
};

