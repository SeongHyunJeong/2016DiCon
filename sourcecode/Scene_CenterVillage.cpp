#include "Scene_CenterVillage.h"
#include "Scene_CenterGate.h"
#include"PlayerInfo.h"

Scene_CenterVillage::Scene_CenterVillage(int id, Vec2 pp)
	:GScene(id, pp)
{

	background = new Sprite("img/map/centervillage.png");
	AddObject(background);

	_1 = new Sprite("img/map/centergate.png");
	AddObject(_1);
	
	SetRect(&qb,291, 32, 435, 122);

	player = new Player();
	player->pos.x = 771;
	player->pos.y = 406;
	AddObject(player);

	//SetRect(&questBoard, 280, 10, 442, 121);
	//rbRectList.push_back(questBoard);

	//이동용
	SetRect(&to1, 800, 324, 801, 489);
	playerInfo.currentMap = 2;

	q = new Quest();
	q->pos = Vec2(200, 30);
	AddObject(q);

	b = new Sprite("img/map/중심가.png");
	AddObject(b);

	SetRect(&r[0], 0, 0, 65, 475);
	SetRect(&r[1], 0, 490, 800, 600);
	SetRect(&r[2], 0, 175, 575, 25);
	SetRect(&r[3], 0, 670, 800, 325);
	for (int i = 0; i < 4; i++)
		rbRectList.push_back(r[i]);

	SetRect(&up, 163, 347, 242, 366);

	cf = new Confirm("img/ui/전직.png");
	AddObject(cf);
	cf->pos = Vec2(220, 160);

}


Scene_CenterVillage::~Scene_CenterVillage()
{
}

void Scene_CenterVillage::Render()
{
	background->Render();
	if(!isFadedOut)
	_1->Render();
	
	if(isFadedOut)
		player->Render();
		

		if (isFadedIn)
		{
			b->Render();
		}
		q->Render();
		cf->Render();
	GScene::Render();
}

void Scene_CenterVillage::Update(float dTime)
{
	GScene::Update(dTime);
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, up))
	{
		player->pos -= Vec2(player->dx, player->dy);
		cf->isShowing = true;
	}
	if (cf->isShowing)
	{
		if (cf->y->IsClicked())
		{
			if (playerInfo.chapter == 1 && playerInfo.lv >= 7)
			{
				int c = 0;
				for (int i = 0; i < 6; i++)
				{
					if (playerInfo.isCleared[i])
						c++;
				}
				if (c >= 6)
				{
				
					playerInfo.job++;
					playerInfo.chapter++;
					playerInfo.skinPath = "img/2player.png";
					player->Reload();
					player->pos = Vec2(333, 323);
				}
			}
			else if (playerInfo.chapter == 2 && playerInfo.lv >= 14)
			{
				int c = 0;
				for (int i = 6; i < 9; i++)
				{
					if (playerInfo.isCleared[i])
					{
						c++;
					}
					if (c >= 3)
					{
						playerInfo.job++;
						playerInfo.chapter++;
						playerInfo.skinPath = "img/3player.png";
						player->Reload();
						player->pos = Vec2(333, 323);
					}
				}
			}
			cf->isShowing = false;
		}
		else if (cf->n->IsClicked())
		{
			player->pos -= Vec2(player->dx, player->dy);
			cf->isShowing = false;
		}
	}



	if (!FadeOut(_1))
	{
		FadeIn(background);
	}

	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to1))
	{
		sceneManager->ChangeScene(new Scene_CenterGate(2, Vec2(32, 216)));
	}
	
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, qb))
	{
		player->pos -= Vec2(player->dx*2, player->dy*2);
		//퀘스트창
		q->isShowing = true;
	}
}