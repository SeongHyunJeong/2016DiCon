#include "Note.h"



Note::Note(string path, float x, float speed)
	:speed(speed)
{
	pos.y = 0;
	pos.x = x;
	sprite = new Sprite(path);
	AddChild(sprite);


}


Note::~Note()
{
}

void Note::Render()
{
	IObject::Render();
	sprite->Render();
}

void Note::Update(float dt)
{
	IObject::Update(dt);
	pos.y += speed * dt;
}
