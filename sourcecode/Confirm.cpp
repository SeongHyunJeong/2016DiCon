#include "Confirm.h"
#include"PlayerInfo.h"
#include"sound.h"

Confirm::Confirm(string path)
{
	bg = new Sprite(path);
	AddChild(bg);

	y = new Button("img/ui/확인창 UI/예2.png","img/ui/확인창 UI/예1.png" );
	AddChild(y);
	y->pos = Vec2(77, 217);
	y->diff = Vec2(220, 160);
	n = new Button("img/ui/확인창 UI/아니요2.png", "img/ui/확인창 UI/아니요1.png");
	AddChild(n);
	n->pos = Vec2(190, 217);
	n->diff = Vec2(220, 160);
	isShowing = false;
}


Confirm::~Confirm()
{
}

void Confirm::Render()
{
	IObject::Render();
	if (isShowing)
	{
		bg->Render();
		y->Render();
		n->Render();

	}

}

void Confirm::Update(float dt)
{
	IObject::Update(dt);
	if(y->IsClicked())sound.Play("click", false);
	if(n->IsClicked())sound.Play("click", false);
	
}
