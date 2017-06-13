#pragma once
#include "IObject.h"
#include"Sprite.h"
class Scene
{
public:
	Scene();

	virtual ~Scene();

	list<IObject*>objectList;

	virtual void Render();
	virtual void Update(float dTime);

	void AddObject(IObject*object);
	void RemoveObject(IObject*object);
	//배경 이동
	

};

