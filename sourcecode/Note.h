#pragma once
#include "IObject.h"
#include"Sprite.h"

//노트 기본 클래스 
//일반노트
class Note :
	public IObject
{
public:

	//노트 이미지
	Sprite * sprite;

	//떨어지는 속도
	float speed;

	//생성자(이미지 경로받기)
	Note(string path, float x, float spped);

	~Note();
	
	
	void Render();
	void Update(float dt);

};

