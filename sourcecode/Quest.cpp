#include "Quest.h"
#include"PlayerInfo.h"

#include"Sound.h"
Quest::Quest()
{
	for (int i = 0; i < 2; i++)
	{
		bg[i] = new Sprite("img/ui/퀘스트 UI/" + to_string(i) + ".png");
		AddChild(bg[i]);
	}
	
	x = new Button("img/ui/퀘스트 UI/x.png");
	AddChild(x);
	x->pos = Vec2(473, 120);
	x->diff = Vec2(200, 30);

	for (int i = 0; i < 9; i++)
	{
		b[i] = new Button("img/ui/퀘스트 UI/b" + to_string(i) + ".png");
		AddChild(b[i]);
		b[i]->diff = Vec2(200, 30);
	}

	for (int i = 0; i < 3; i++)
	{
		b[i]->pos = Vec2(167, 182 + 80 * i);
		b[i + 3]->pos = Vec2(385, 182 + 80 * i);
		b[i + 6]->pos = Vec2(330, 182 + 80 * i);

		cur[i] = new Text("Pixel NES", 11, 34);
		cur[i]->pos = Vec2(104, 182 + 80 * i);
			AddChild(cur[i]);

		cur[i+3] = new Text("Pixel NES", 11, 34);
		cur[i + 3]->pos = Vec2(316, 182 + 80 * i);
				AddChild(cur[i+3]);

				cur[i + 6] = new Text("Pixel NES", 11, 34);
				cur[i + 6]->pos = Vec2(180, 182 + 80 * i);
				AddChild(cur[i+6]);
	}

	req[0][0] = 10;
	req[0][1] = 20;
	req[1][0] = 8;
	req[1][1] = 25;
	req[2][0] = 5;
	req[2][1] = 30;
	req[3][0] = 3;
	req[3][1] = 40;
	req[4][0] = 1;
	req[4][1] = 50;
	req[5][0] = 1;
	req[5][1] = 100;

	req[6][0] = 1;
	req[6][1] = 200;
	req[7][0] = 1;
	req[7][1] = 500;
	req[8][0] = 1;
	req[8][1] = 1000;

	isShowing = false;

	able = new Text("둥근모꼴");
	
	AddChild(able);
	able->pos = Vec2(13, 400);
	page = 0;

	for (int i = 0; i < 2; i++)
	{
		select[i] = new Button("img/ui/퀘스트 UI/b.png");
		select[i]->pos = Vec2(160 * i, 65);
		AddChild(select[i]);
		select[i]->diff = Vec2(200, 30);
	}



	sound.Add("sound/click2.wav", "click2");
	
}


Quest::~Quest()
{
}

void Quest::Render()
{
	IObject::Render();
	if (isShowing)
	{
		if (page == 0)
		{
			bg[0]->Render();
			x->Render();
			for (int i = 0; i < 6; i++)
			{
			//if (!playerInfo.isCleared[i])
			//	{
					b[i]->Render();
					cur[i]->Render();
					
			//	}
				
			}
		}
		else if (page == 1)
		{
			bg[1]->Render();
			x->Render();
			for (int i = 6; i < 9; i++)
			{
				//if (!playerInfo.isCleared[i])
			//	{
					b[i]->Render();
					
				//}
				cur[i]->Render();
			}
		}

		//챕터1 퀘스트 완료시 렌더
		int count1 = 0;
		for (int i = 0; i < 6; i++)
		{
			if (playerInfo.chapter == 1 && playerInfo.isCleared[i] == 1)
			{
				count1++;
			}
		}
		if (playerInfo.chapter == 1 && count1 >= 6)
		{
			if (playerInfo.lv >= 7)
			{
				able->Put("1차 전직 가능! 단상으로 가세요", DT_LEFT, D3DCOLOR_ARGB(255, timeGetTime() % 256, 255, 255 - timeGetTime() % 256));
			}
			else
			{
				able->Put("레벨 :"+to_string(playerInfo.lv)+"/7", DT_LEFT, D3DCOLOR_ARGB(255,0, 0, 0));
			}
			able->Render();
		}
		
		if (playerInfo.chapter == 1 && playerInfo.lv <= 6)
		{
			able->Put("레벨 :" + to_string(playerInfo.lv) + "/7", DT_LEFT , D3DCOLOR_ARGB(255, 0, 0, 0));
			able->Render();
		}
		if (playerInfo.chapter == 2 && playerInfo.lv <= 13)
		{
			able->Put("레벨 :" + to_string(playerInfo.lv) + "/14", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
			able->Render();
		}

		//챕터2 퀘스트 완료시 렌더
		int count2 = 0;
		for (int i = 6; i < 9; i++)
		{
			if (playerInfo.chapter == 2 && playerInfo.isCleared[i] == 1)
			{
				count2++;
			}
		}
		if (playerInfo.chapter == 2 && count2 >= 3)
		{
			if (playerInfo.lv >= 14)
			{
				able->Put("전직 가능! 단상으로 가세요", DT_LEFT, D3DCOLOR_ARGB(255, timeGetTime() % 256, 255, 255 - timeGetTime() % 256));
			}
			else
			{
				able->Put("레벨 :" + to_string(playerInfo.lv) + "/14", DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
			}
			able->Render();
		}
	}
	


	
}

void Quest::Update(float dt)
{
	IObject::Update(dt);
	if (isShowing)
	{
		for (int i = 0; i < 9; i++)
		{
				cur[i]->Put(to_string(playerInfo.itemCount[i]) + "/" + to_string(req[i][0]), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
			
			if (playerInfo.itemCount[i] >= req[i][0])
			{
				if (b[i]->IsClicked())
				{
					playerInfo.itemCount[i] -= req[i][0];
					playerInfo.money += req[i][1];
					playerInfo.isCleared[i] = 1;
					sound.Play("click2", false);
				}
			}
		}
		if (x->IsClicked())
		{
			isShowing = false;
		}
		if (select[0]->IsClicked())
		{
			page = 0;
		}
		else if (select[1]->IsClicked() && playerInfo.chapter == 2)
		{
			page = 1;
		}
	}
	


	
}
