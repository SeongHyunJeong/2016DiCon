#pragma once
#include "IObject.h"
#include"Text.h"
#include"Sprite.h"
class Log :
	public IObject
{
public:
	//로그창 배경
	Sprite * bg;
	//문자열 목록
	list<string> log;
	//출력용
	Text * str;
	//최대 보관 개수
	int size;
	Log(string bgpath, int size);
	~Log();


	void Render();
	void Update(float dt);

	void PushLog(string str);
};

