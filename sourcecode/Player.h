#pragma once
#include "IObject.h"
#ifndef _GLOBAL
#define _GLOBAL
#include"Global.h"
#endif
#include "Animation.h"
#include "Sprite.h"

class Player :
	public IObject
{
public:
	Player();
	~Player();
	Animation * fl;
	Animation * fr;
	Animation * bl;
	Animation * br;

	//위쪽을 보고 있는지
	bool isTop;
	//왼쪽을 보고 있는지
	bool isLeft;

	//이동속도
	float ms;
	//이동량
	float dx, dy;

	
	void Reload();
	void Render();
	void Update(float dTime);


};

