#include "Animation.h"
#include "Global.h"

Animation::Animation(int fps)
{
	this->fps = fps;
	maxFrame = 0;
	currentFrame = 0;
	timeChecker = 0;

	width = 0;
	height = 0;

	color = D3DCOLOR_ARGB(255, 255, 255, 255);
	loop = true;
	played = false;
}


Animation::~Animation()
{
}

void Animation::Render()
{
	IObject::Render();
	if (loop)
	{
		if (maxFrame > 0)
		{
			spriteVector[currentFrame]->color = color;
			spriteVector[currentFrame]->Render();
		}
	}
	else
	{
		if(!played)
			if (maxFrame > 0)
			{
				spriteVector[currentFrame]->color = color;
				spriteVector[currentFrame]->Render();
			}
	}
}

void Animation::Update(float dTime)
{
	timeChecker += dTime;
	if (loop)
	{
		if (timeChecker > 1.f / fps)
		{
			timeChecker = 0;
			currentFrame++;
			if (currentFrame == maxFrame)
				currentFrame = 0;
		}
	}
	else
	{
		if (timeChecker > 1.f / fps)
		{
			timeChecker = 0;
			currentFrame++;
			if (currentFrame == maxFrame)
			{
				currentFrame = 0;
				played = true;
			}
				
		}
	}

}

void Animation::AddFrame(string path)
{
	spriteVector.push_back(new Sprite(path));
	AddChild(spriteVector[maxFrame]);
	if (maxFrame == 0)
	{
		width = spriteVector[maxFrame]->width;
		height = spriteVector[maxFrame]->height;
	}
	maxFrame ++ ;
}

void Animation::Play()
{
	played = false;
}
