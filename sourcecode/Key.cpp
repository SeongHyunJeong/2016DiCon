#include "Key.h"
#include"Global.h"


Key::Key(string _dpath, string _ppath, char _ch):Button(_dpath, _ppath), ch(_ch), state(KEYNONE)
{

}


Key::~Key()
{
}

int Key::State()
{
	return state;
}

void Key::Render()
{
	IObject::Render();
	if (isClk)
	{
		clickImage->Render();
	}
	else
	{
		defaultImage->Render();
	}
}

void Key::Update(float dt)
{
	IObject::Update(dt);

	if (GetMyKeyState(ch) == KEYDOWN)
	{
		isClk = true;
		state = KEYDOWN;
		//printf("Å¬¸¯");
	}
		
	else if (GetMyKeyState(ch) == KEYUP)
	{
		isClk = false;
		state = KEYUP;
		//printf("¶À");
	}
		
	else if (GetMyKeyState(ch) == KEYON)
	{
		state = KEYON;

	}
		

}



