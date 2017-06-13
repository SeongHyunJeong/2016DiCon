#pragma once
#include "IObject.h"
#include "Sprite.h"
#include <vector>

class Animation :
	public IObject
{
public:
	Animation(int fps);
	~Animation(void);

	int maxFrame;
	int currentFrame;
	int fps;
	D3DCOLOR color;
	float timeChecker;

	int width;
	int height;

	vector<Sprite*>spriteVector;

	bool loop;
	bool played;

	void Render();
	void Update(float dTime);

	void AddFrame(string);
	void Play();
};

