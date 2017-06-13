#include "Scene_Village.h"
#include "Scene_Weaponchange.h"
#include"Scene_ReinforceShop.h"
#include"Scene_PotionShop.h"
#include"Scene_House.h"
#include "Scene_CenterGate.h"
#include"PlayerInfo.h"

Scene_Village::Scene_Village(int id, Vec2 ppos)
	:GScene(id, ppos)
{
	background = new Sprite("img/map/village.png");
	AddObject(background);

	_1 = new Sprite("img/map/centergate.png");
	AddObject(_1);


	player = new Player();


	player->pos = ppos;

	AddObject(player);

	////집
	//house = Vec2(275, 451+25);
	//SetRect(&houseSide1, 265, 408 + 25, 291, 452);
	//SetRect(&houseSide2, 263, 466+15, 291, 482+15);

	//입구 RECT 설정
	SetRect(&reinforceShop, 239, 222, 269, 279);
	SetRect(&house, 266, 419 , 289, 480 );
	SetRect(&potionShop, 556, 235 , 580, 284 );
	SetRect(&weaponShop, 553, 482, 589, 541);
	SetRect(&to1, 371, 0, 442, 1);
	//물리적 충돌 RECT 설정
	SetRect(&collider[0], 272, 7 , 366, 233 );
	SetRect(&collider[1], 272, 285 , 366, 422 );
	SetRect(&collider[2], 272, 476, 366, 599);
	SetRect(&collider[3], 440, 5 , 548, 228 );
	SetRect(&collider[4], 440, 287 , 548, 472 );
	SetRect(&collider[5], 440, 541, 548, 598 );
	for (int i = 0; i < 6; i++)
	{
		rbRectList.push_back(collider[i]);
	}
	playerInfo.currentMap = 0;

	ps = new PotionShop();
	AddObject(ps);
	ps->pos = Vec2(249, 116);

	ws = new WeaponShop();
	AddObject(ws);
	ws->pos = Vec2(249, 116);

	s = new Confirm("img/ui/확인창 UI/확인.png");
	AddObject(s);
	s->pos = Vec2(220, 160);


//	sound.Add("sound/village.wav", "village");
//	sound.Play("village", true);
}


Scene_Village::~Scene_Village()
{
	//Scene::~Scene();

}

void Scene_Village::Render()
{

	background->Render();

	if (id == 1)
	{
		if (!isFadedOut)
			_1->Render();
	}
	if(isFadedOut)
	player->Render();
	ps->Render();
	ws->Render();
	s->Render();
	GScene::Render();
}

void Scene_Village::Update(float dTime)
{
	GScene::Update(dTime);

	int i;

	if (id == 1)
	{
		if (!FadeOut(_1))
		{
			FadeIn(background);
		}
	}
	if (id == -1)
	{
		isFadedOut = true;
	}
	

	//player->Update(dTime);

	
	if (player->pos.x < 264) player->pos.x = 264;
	if (player->pos.x > 550) player->pos.x = 550;
	if (s->isShowing)
	{
		if (s->y->IsClicked())
		{
			playerInfo.Save();
			s->isShowing = false;
		}
		else if (s->n->IsClicked())
		{
			s->isShowing = false;
		}
	}
	
	//집
	if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, house))
	{
		s->isShowing = true;
		player->pos.x += 180 * dTime;
	}

	//강화상점
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, reinforceShop))
		sceneManager->ChangeScene(new Scene_ReinforceShop());


	//무기교환 상점
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, weaponShop))
	{
		ws->isShowing = true;
		player->pos.x -= 180 * dTime;
	}
		

	//포션 상점
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, potionShop))
	{
		ps->isShowing = true;
		player->pos.x -= 180 * dTime;
	}
	// 번화가입구
	else if (IsCollisionRect(player->pos, Vec2(0, 0), player->rect, to1))
	{
	//	sound.Stop("village");
		sceneManager->ChangeScene(new Scene_CenterGate(0, Vec2(526, 518)));
	}
	
	
	

	
}
