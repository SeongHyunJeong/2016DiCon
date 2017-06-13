#include"player.h"
#include"Global.h"
#include"GScene.h"
#include"Collisions.h"
#include"PlayerInfo.h"
Player::Player() 
{
	ms = 180;
	fl = new Animation(3);
	fr = new Animation(3);
	bl = new Animation(3);
	br = new Animation(3);
	if (playerInfo.job == 0)
	{
		fl->AddFrame("player/기본/fl/1.png");
		fl->AddFrame("player/기본/fl/2.png");
		fl->AddFrame("player/기본/fl/3.png");
		fl->AddFrame("player/기본/fl/4.png");
		fr->AddFrame("player/기본/fr/1.png");
		fr->AddFrame("player/기본/fr/2.png");
		fr->AddFrame("player/기본/fr/3.png");
		fr->AddFrame("player/기본/fr/4.png");
		bl->AddFrame("player/기본/bl/1.png");
		bl->AddFrame("player/기본/bl/2.png");
		bl->AddFrame("player/기본/bl/3.png");
		bl->AddFrame("player/기본/bl/4.png");
		br->AddFrame("player/기본/br/1.png");
		br->AddFrame("player/기본/br/2.png");
		br->AddFrame("player/기본/br/3.png");
		br->AddFrame("player/기본/br/4.png");
		AddChild(fl);
		AddChild(fr);
		AddChild(bl);
		AddChild(br);
	}
	else if (playerInfo.job == 1)
	{
		fl->AddFrame("player/2/fl/1.png");
		fl->AddFrame("player/2/fl/2.png");
		fl->AddFrame("player/2/fl/3.png");
		fl->AddFrame("player/2/fl/4.png");
		fr->AddFrame("player/2/fr/1.png");
		fr->AddFrame("player/2/fr/2.png");
		fr->AddFrame("player/2/fr/3.png");
		fr->AddFrame("player/2/fr/4.png");
		bl->AddFrame("player/2/bl/1.png");
		bl->AddFrame("player/2/bl/2.png");
		bl->AddFrame("player/2/bl/3.png");
		bl->AddFrame("player/2/bl/4.png");
		br->AddFrame("player/2/br/1.png");
		br->AddFrame("player/2/br/2.png");
		br->AddFrame("player/2/br/3.png");
		br->AddFrame("player/2/br/4.png");
		AddChild(fl);
		AddChild(fr);
		AddChild(bl);
		AddChild(br);
	}
	else if (playerInfo.job == 2)
	{
		fl->AddFrame("player/3/fl/1.png");
		fl->AddFrame("player/3/fl/2.png");
		fl->AddFrame("player/3/fl/3.png");
		fl->AddFrame("player/3/fl/4.png");
		fr->AddFrame("player/3/fr/1.png");
		fr->AddFrame("player/3/fr/2.png");
		fr->AddFrame("player/3/fr/3.png");
		fr->AddFrame("player/3/fr/4.png");
		bl->AddFrame("player/3/bl/1.png");
		bl->AddFrame("player/3/bl/2.png");
		bl->AddFrame("player/3/bl/3.png");
		bl->AddFrame("player/3/bl/4.png");
		br->AddFrame("player/3/br/1.png");
		br->AddFrame("player/3/br/2.png");
		br->AddFrame("player/3/br/3.png");
		br->AddFrame("player/3/br/4.png");
		AddChild(fl);
		AddChild(fr);
		AddChild(bl);
		AddChild(br);
	}
	

	SetCenter(fl->height, fl->width, fl);
	SetCenter(fr->height, fr->width, fr);
	SetCenter(bl->height, bl->width, bl);
	SetCenter(br->height, br->width, br);

	SetRect(&rect, -10, 0, 10, 25);
	printf("%d, %d, %d, %d", rect.left, rect.top, rect.right, rect.bottom);
	dx = 0;
	dy = 0;
	
	
}
Player::~Player()
{
	
}

void Player::Reload()
{
	RemoveChild(fl);
	RemoveChild(fr);
	RemoveChild(bl);
	RemoveChild(br);
	fl = new Animation(3);
	fr = new Animation(3);
	bl = new Animation(3);
	br = new Animation(3);
	if (playerInfo.job == 0)
	{
		fl->AddFrame("player/기본/fl/1.png");
		fl->AddFrame("player/기본/fl/2.png");
		fl->AddFrame("player/기본/fl/3.png");
		fl->AddFrame("player/기본/fl/4.png");
		fr->AddFrame("player/기본/fr/1.png");
		fr->AddFrame("player/기본/fr/2.png");
		fr->AddFrame("player/기본/fr/3.png");
		fr->AddFrame("player/기본/fr/4.png");
		bl->AddFrame("player/기본/bl/1.png");
		bl->AddFrame("player/기본/bl/2.png");
		bl->AddFrame("player/기본/bl/3.png");
		bl->AddFrame("player/기본/bl/4.png");
		br->AddFrame("player/기본/br/1.png");
		br->AddFrame("player/기본/br/2.png");
		br->AddFrame("player/기본/br/3.png");
		br->AddFrame("player/기본/br/4.png");
		AddChild(fl);
		AddChild(fr);
		AddChild(bl);
		AddChild(br);
	}
	else if (playerInfo.job == 1)
	{
		fl->AddFrame("player/2/fl/1.png");
		fl->AddFrame("player/2/fl/2.png");
		fl->AddFrame("player/2/fl/3.png");
		fl->AddFrame("player/2/fl/4.png");
		fr->AddFrame("player/2/fr/1.png");
		fr->AddFrame("player/2/fr/2.png");
		fr->AddFrame("player/2/fr/3.png");
		fr->AddFrame("player/2/fr/4.png");
		bl->AddFrame("player/2/bl/1.png");
		bl->AddFrame("player/2/bl/2.png");
		bl->AddFrame("player/2/bl/3.png");
		bl->AddFrame("player/2/bl/4.png");
		br->AddFrame("player/2/br/1.png");
		br->AddFrame("player/2/br/2.png");
		br->AddFrame("player/2/br/3.png");
		br->AddFrame("player/2/br/4.png");
		AddChild(fl);
		AddChild(fr);
		AddChild(bl);
		AddChild(br);
	}
	else if (playerInfo.job == 2)
	{
		fl->AddFrame("player/3/fl/1.png");
		fl->AddFrame("player/3/fl/2.png");
		fl->AddFrame("player/3/fl/3.png");
		fl->AddFrame("player/3/fl/4.png");
		fr->AddFrame("player/3/fr/1.png");
		fr->AddFrame("player/3/fr/2.png");
		fr->AddFrame("player/3/fr/3.png");
		fr->AddFrame("player/3/fr/4.png");
		bl->AddFrame("player/3/bl/1.png");
		bl->AddFrame("player/3/bl/2.png");
		bl->AddFrame("player/3/bl/3.png");
		bl->AddFrame("player/3/bl/4.png");
		br->AddFrame("player/3/br/1.png");
		br->AddFrame("player/3/br/2.png");
		br->AddFrame("player/3/br/3.png");
		br->AddFrame("player/3/br/4.png");
		AddChild(fl);
		AddChild(fr);
		AddChild(bl);
		AddChild(br);
	}


	SetCenter(fl->height, fl->width, fl);
	SetCenter(fr->height, fr->width, fr);
	SetCenter(bl->height, bl->width, bl);
	SetCenter(br->height, br->width, br);
}

void Player::Render()
{
	IObject::Render();
	if (!isTop)
	{
		if (isLeft)
		{
			fl->Render();
		}
		else
		{
			fr->Render();
		}
	}
	else
	{
		if (isLeft)
		{
			bl->Render();
		}
		else
		{
			br->Render();
		}
	}
}
void Player::Update(float dTime)
{
	IObject::Update(dTime);

	if (GetMyKeyState(VK_F6) == KEYDOWN)
	{
		if (ms == 180)
			ms = 360;
		else
			ms = 180;
	}

	//아래, 위 애니메이션 처리
	if (GetMyKeyState(VK_UP) == KEYDOWN)
		isTop = true;
	if (GetMyKeyState(VK_DOWN) == KEYDOWN)
		isTop = false;
	//왼쪽, 오른쪽 애니메이션 처리
	if (GetMyKeyState(VK_LEFT) == KEYDOWN)
		isLeft = true;
	if (GetMyKeyState(VK_RIGHT) == KEYDOWN)
		isLeft = false;


	//printf("%f, %f\n", pos.x, pos.y);

	//이동량 처리
	if (GetMyKeyState(VK_UP) >0)
		dy = -ms * dTime;
	else if (GetMyKeyState(VK_DOWN)>0)
		dy = ms * dTime;
	else
		dy = 0;
	if (GetMyKeyState(VK_LEFT) >0)
		dx = -ms * dTime;
	else if (GetMyKeyState(VK_RIGHT) >0)
		dx = ms * dTime;
	else
		dx = 0;

	//이동처리

	pos.x += dx;
	

	//충돌처리
	
	GScene * s = (GScene *)sceneManager->currentScene;
	for_iter(iter, s->rbList)
	{
		if (IsCollisionRect(pos, (*iter)->pos, rect, (*iter)->rect))
		{
			pos.x -= dx;
			
		}
	}
	for_iter(iter, s->rbRectList)
	{
		if (IsCollisionRect(pos, Vec2(0, 0), rect, (*iter)))
		{
			pos.x -= dx;
			
		}
	}
	pos.y += dy;
	for_iter(iter, s->rbList)
	{
		if (IsCollisionRect(pos, (*iter)->pos, rect, (*iter)->rect))
		{
			pos.y -= dy;

		}
	}
	for_iter(iter, s->rbRectList)
	{
		if (IsCollisionRect(pos, Vec2(0, 0), rect, (*iter)))
		{
			pos.y -= dy;

		}
	}
	//맵 밖으로 못나가게 하기

	

	if (pos.x < 0) pos.x = 0;
	if (pos.x > 800) pos.x = 800;
	if (pos.y < 0) pos.y = 0;
	if (pos.y > 600) pos.y = 600;


	//

}