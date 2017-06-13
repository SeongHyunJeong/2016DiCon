#include "LongNote.h"

#include"Global.h"

LongNote::LongNote(string path, float x, float speed, float _l)
	:Note(path, x, speed), state(0)
{
	sprite->scalingCenter = Vec2(sprite->width / 2, sprite->height);
	sprite->scale = Vec2(1, _l);
	SetRect(&rect, 0, -_l, sprite->visibleRect.right, 0);
	
}

LongNote::~LongNote()
{
}
