#pragma once
#include "IObject.h"
#include"Sprite.h"

//��Ʈ �⺻ Ŭ���� 
//�Ϲݳ�Ʈ
class Note :
	public IObject
{
public:

	//��Ʈ �̹���
	Sprite * sprite;

	//�������� �ӵ�
	float speed;

	//������(�̹��� ��ιޱ�)
	Note(string path, float x, float spped);

	~Note();
	
	
	void Render();
	void Update(float dt);

};

