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

	Text * abilities;//임시 능력치 출력용 변수

	
	int moneyset;

	void Render();
	void Update(float dTime);
	


};