#pragma once
#include "IObject.h"
#include"Button.h"
#include"Sprite.h"
class Confirm :
	public IObject
{
public:
	Sprite * bg;
	Button * y;
	Button * n;
	bool isShowing;
	Confirm(string path);
	~Confirm();
	void Render();
	void Update(float dt);
};


