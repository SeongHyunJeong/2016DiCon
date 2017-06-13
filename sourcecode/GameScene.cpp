#include "GameScene.h"
#include "Global.h"
#include "ResultScene.h"

GameScene::GameScene()
{
	sprite = new Sprite("Back.png");
	AddObject(sprite);
	enemy = new Enemy();
	enemy->pos = Vec2(SCREEN_WIDTH / 2, 200);
	player = new Player();
	AddObject(player);
	player->pos=Vec2(SCREEN_WIDTH/2,600);
	spawn = false;
	isGameOver = false;
	sample = new Text();
}


GameScene::~GameScene()
{
}

void GameScene::Render()
{
	sprite->Render();
	player->Render();
	enemy->Render();
	sample->Put(player->score);
	sample->ShowText(sample->str, 100, 100, DT_LEFT, D3DCOLOR_ARGB(255, 0, 255, 255));


	for (auto&item : itemList)
	{
		item->Render();
	}
	
}

void GameScene::Update(float dTime)
{
	Scene::Update(dTime);
	enemy->Update(dTime);

	if (rand() % 2500 == 0)
		SpawnItem();

	for (auto&bullet : player->bulletList)
	{
		if (IsCollisionRect(enemy->pos, bullet->pos, enemy->rect, bullet->rect))
		{
			enemy->isHit = true;
			bullet->isHit = true;
		}
	}

	for (auto&enemybullet : enemy->enemyBulletList)
	{
		if (IsCollisionRect(player->pos, enemybullet->pos, player->rect, enemybullet->rect) && player->invincibleTime == 0)
		{
			player->isHit = true;
			enemybullet->isHit = true;
			player->pos = Vec2(SCREEN_WIDTH / 2, 600);
			player->invincibleTime = 3;
		}
	}

	if (IsCollisionRect(enemy->pos, player->pos, enemy->rect, player->rect) && player->invincibleTime == 0)
	{
		player->life--;
		player->pos = Vec2(SCREEN_WIDTH / 2, 600);
		player->invincibleTime = 3;
	}

	if (enemy->hp <= 0 || enemy->pos.x >= SCREEN_WIDTH)
	{
		RemoveObject(enemy);
		spawn = false;

		delete (enemy);
	}


	if (IsPointInRect(player->pos, player->rect, GetMousePos()) && GetMyKeyState(VK_LBUTTON) == 1)
		isGameOver = true;

	if (player->life <= 0)
	{
		sceneManager->ChangeScene(new ResultScene(player->score));
		return;
	}
	if (enemy->hp <= 0)
	{
		player->score += 5000;
		enemy = new Enemy();
		enemy->pos = Vec2(SCREEN_WIDTH / 2, 200);
	}

	if (enemy->isHit)
	{
		player->score += 100;
	}

	for (auto item = itemList.begin(); item != itemList.end(); item++)
	{
		if (IsCollisionRect(player->pos, (*item)->pos, player->rect, (*item)->rect))
		{
			player->itemIsHit = true;
			(*item)->isHit = true;
		}


		if (IsCollisionRect((*item)->pos, player->pos, (*item)->rect, player->rect))
		{
			if(player->life<3)
				player->life++;
			(*item)->hp--;
			cout << (*item)->hp << endl;

			if ((*item)->hp <= 0 || (*item)->pos.x >= SCREEN_WIDTH) {

				RemoveObject((*item));
				delete (*item);
				item = itemList.erase(item);
				if (item == itemList.end())
					break;


			}
		}
	}
}

void GameScene::SpawnItem()
{
	Item*i = new Item();
	AddObject(i);
	i->pos = Vec2((rand() % SCREEN_WIDTH - 120 + 60), -100);

	itemList.push_back(i);
}