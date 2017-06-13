#pragma once
#include "IObject.h"
#include"Sprite.h"
class Button :
	public IObject
{
public:
	//��ư �⺻ �̹���
	Sprite * defaultImage;
	//���콺 �ö��� �� �̹���
	Sprite * onMouseImage;
	//Ŭ������ �� �̹���
	Sprite * clickImage;

	//������(_d ����Ʈ _c Ŭ�� _m �¸��콺)
	Button(string _dPath);
	Button(string _dPath, string _cpath);
	Button(string _dPath, string _cpath, string _mPath);
	~Button();

	//Ŭ���ƴ���.(��ư�ȿ� ���콺��ǥ�� �����鼭, GetMyKeyState���� -1�� ��ȯ�Ǿ�����.)
	bool isClk;
	bool IsClicked();

	//���̿� �ʺ�

	float width;
	float height;


	//���� �ִ� ��ư�� �ƴ�, �ٸ� ������Ʈ�� ����� ���� ��ư�ϰ��
	//���콺 ��ǥ�� ������ǥ�� ���Ǵµ� ��ư�� ��ǥ�� ������ǥ�� ���Ǿ�
	//Ŭ�� ������ ����� ���� �ʴµ� �̸� �������ִ� �����̴�.
	D3DXVECTOR2 diff;

	//�⺻�Լ�������
	virtual void Render();
	virtual void Update(float dt);

};

