#pragma once
#include "IObject.h"
#include"button.h"
#include"text.h"
class Quest :
	public IObject
{
public:
	


	Sprite * bg[2];
	Button * x;
	bool isShowing;
	Button * b[9];
	Button*  select[2];
	//퀘스트완료 조건들
	//세로 : 아이템종료
	//가로0: 개수, 가로1: 금액
	int req[9][2];
	Text * cur[9];
	Text * able;
	int page;
	Quest();
	~Quest();
	void Render();
	void Update(float dt);
};

