#pragma once
#include "GScene.h"
#include"Text.h"
#include"button.h"

class Scene_Weaponchange :
	public GScene
{
public:
	Scene_Weaponchange();
	~Scene_Weaponchange();

	Button * back;

	Text * abilities;//�ӽ� �ɷ�ġ ��¿� ����

	
	int moneyset;

	void Render();
	void Update(float dTime);
	


};