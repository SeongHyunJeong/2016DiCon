#pragma once
#include "IObject.h"
#include"Button.h"
#include"Text.h"
class WeaponShop :
	public IObject
{
public:
	Sprite * bg;
	Sprite * weapons[5];
	Button * buy[4];
	Button * x;

	//확인 창
	Sprite * confirm;
	Button * confirmx;
	Button * confirmBuy;
	Text * requiredMoney;
	bool isConfirmShowing;
	int pressedItem;
	//현재무기 이름
	Text * currentWeaponText;
	//강화수치
	Text * reinCountText;
	//현재 돈
	Text * moneyText;
	bool isShowing;
	WeaponShop();
	~WeaponShop();

	void Render();
	void Update(float dt);

};

