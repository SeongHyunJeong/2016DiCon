#pragma once
#include "Button.h"
class Key :
	public Button
{
public:
	Key(string _dpath, string _ppath, char _ch);
	~Key();


	char ch;

	int state;

	int State();

	void Render();
	void Update(float dt);

};

