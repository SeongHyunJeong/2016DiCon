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

	//Ȯ�� â
	Sprite * confirm;
	Button * confirmx;
	Button * confirmBuy;
	Text * requiredMoney;
	bool isConfirmShowing;
	int pressedItem;
	//���繫�� �̸�
	Text * currentWeaponText;
	//��ȭ��ġ
	Text * reinCountText;
	//���� ��
	Text * moneyText;
	bool isShowing;
	WeaponShop();
	~WeaponShop();

	void Render();
	void Update(float dt);

};

