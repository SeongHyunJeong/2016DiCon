#include "Setting.h"
#include"Sound.h"
#include"playerinfo.h"
#include<ctype.h>

Setting::Setting()
	:cursor(0)
{
	bg = new Sprite("img/ui/ingameui/setting.png");
	AddChild(bg);
	key = new Text("Pixel NES");
	key->str = "";
	AddChild(key);
	isShowing = false;
}


Setting::~Setting()
{
}

void Setting::Render()
{
	IObject::Render();
	bg->Render();
	for (int i = 0; i <4; i++)
	{
		key->pos = Vec2(310 + (i*90) , 235);
		key->Put(playerInfo.keys[i], DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		//printf("%d\n", playerInfo.keys[i]);
		key->Render();
	}
	
}

void Setting::Update(float dt)
{
	IObject::Update(dt);
	if (isShowing)
	{
		for (int i = 0; i <128; i++)
		{
			if(isgraph(i))
			if (GetMyKeyState(i) == KEYDOWN)
			{
				playerInfo.keys[cursor] = i;
				cursor++;
				if (cursor >= 4)
					cursor = 0;
				sound.Play("click", false);
			}
		}
	}
	
}
