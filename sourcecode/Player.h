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

	//������ ���� �ִ���
	bool isTop;
	//������ ���� �ִ���
	bool isLeft;

	//�̵��ӵ�
	float ms;
	//�̵���
	float dx, dy;

	
	void Reload();
	void Render();
	void Update(float dTime);


};

