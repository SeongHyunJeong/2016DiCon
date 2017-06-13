#pragma once
#include "IObject.h"
#include"Text.h"
#include"Sprite.h"
class Log :
	public IObject
{
public:
	//�α�â ���
	Sprite * bg;
	//���ڿ� ���
	list<string> log;
	//��¿�
	Text * str;
	//�ִ� ���� ����
	int size;
	Log(string bgpath, int size);
	~Log();


	void Render();
	void Update(float dt);

	void PushLog(string str);
};

