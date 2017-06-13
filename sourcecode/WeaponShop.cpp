#include "WeaponShop.h"
#include"PlayerInfo.h"


WeaponShop::WeaponShop()
{
	bg = new Sprite("img/ui/weaponui/bg.png");
	AddChild(bg);
	for (int i = 0; i < 5; i++)
	{
		weapons[i] = new Sprite("img/ui/weaponui/" + to_string(i) + ".png");
		weapons[i]->pos = Vec2(31, 44);
		weapons[i]->scale = Vec2(0.6f, 0.6f);
		AddChild(weapons[i]);
	}

	for (int i = 0; i < 4; i++)
	{
		buy[i] = new Button("img/ui/weaponui/buy.png", "img/ui/weaponui/buy2.png", "img/ui/weaponui/buy2.png");
		buy[i]->pos = Vec2(163, 175 + i * 55);
		buy[i]->diff = Vec2(249, 116);
		AddChild(buy[i]);
	}

	x = new Button("img/ui/weaponui/x.png");
	x->pos = Vec2(270, -5);
	x->diff = Vec2(249, 116);
	AddChild(x);

	isShowing = false;

	currentWeaponText= new Text("둥근모꼴", 10, 22);
	AddChild(currentWeaponText);
	currentWeaponText->pos = Vec2(18, 36);

	reinCountText = new Text("Pixel NES");
	AddChild(reinCountText);
	reinCountText->pos = Vec2(161, 57);

	moneyText = new Text("Pixel NES");
	AddChild(moneyText);
	moneyText->pos = Vec2(25, 123);

	confirm = new Sprite("img/ui/weaponui/confirm.png");
	AddChild(confirm);
	confirm->pos = Vec2(0, 160);
	isConfirmShowing = false;

	confirmx = new Button("img/ui/weaponui/x.png");
	AddChild(confirmx);
	confirmx->pos = Vec2(200, 150);
	confirmx->diff = Vec2(249, 116);

	confirmBuy = new Button("img/ui/weaponui/buy.png");
	AddChild(confirmBuy);
	confirmBuy->pos = Vec2(92, 280);
	confirmBuy->diff = Vec2(249, 116);

	requiredMoney = new Text("Pixel NES");
	AddChild(requiredMoney);
	requiredMoney->pos = Vec2(55, 237);

	pressedItem = 0;
}


WeaponShop::~WeaponShop()
{
}

void WeaponShop::Render()
{
	if (isShowing)
	{
		IObject::Render();
		bg->Render();
		weapons[(playerInfo.upgrade-1) / 5]->Render();
		for (int i = (playerInfo.upgrade - 1)/5; i < 4; i++)
		{
			buy[i]->Render();
		}
		x->Render();
		currentWeaponText->Render();
		reinCountText->Render();
		moneyText->Render();

		if (isConfirmShowing)
		{
			
			confirm->Render();
			confirmx->Render();
			if(playerInfo.money >= (int)pow(10, pressedItem + 1) && (playerInfo.upgrade) % 5 == 0)
			confirmBuy->Render();
			requiredMoney->Render();
			weapons[pressedItem]->pos = Vec2(58, 187);
			weapons[pressedItem]->Render();
			weapons[pressedItem]->pos = Vec2(31, 44);
		}
	}
}

void WeaponShop::Update(float dt)
{
	IObject::Update(dt);

	if (isShowing)
	{
		if (x->IsClicked())
		{
			isShowing = false;
		}
		if (isConfirmShowing)
		{
			if (confirmx->IsClicked())
			{
				isConfirmShowing = false;
			}
			if(playerInfo.money >= (int)pow(10, pressedItem + 1) && (playerInfo.upgrade ) % 5 == 0)
			{
				if (confirmBuy->IsClicked())
				{
					playerInfo.money -= (int)pow(10, pressedItem + 1);
					playerInfo.upgrade++;
					isConfirmShowing = false;
				}
			}
		}
	}
	switch ((playerInfo.upgrade-1) / 5)
	{
	case 0:currentWeaponText->Put("         낡은", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0)); break;
	case 1:currentWeaponText->Put("         중고", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0)); break;
	case 2:currentWeaponText->Put("    새틀라이트", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0)); break;
	case 3:currentWeaponText->Put("       북셀프", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0)); break;
		//timeGetTime 사용한이유 : 글자 무지개 효과
	default:currentWeaponText->Put("플로어 스탠딩", DT_LEFT, D3DCOLOR_ARGB(255, timeGetTime()%255, 255-timeGetTime() % 255, timeGetTime() % 55)); break;
	}
	
	for (int i = (playerInfo.upgrade-1) / 5; i < 4; i++)
	{
		if (buy[i]->IsClicked())
		{
			pressedItem = i;
			isConfirmShowing = true;
		}
	}


	reinCountText->Put(to_string((playerInfo.upgrade-1) % 5+1), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	moneyText->Put(to_string(playerInfo.money), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
	requiredMoney->Put(to_string((int)pow(10, pressedItem + 1)), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));



}
