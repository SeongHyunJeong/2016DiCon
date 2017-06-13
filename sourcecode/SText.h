#pragma once
#include "sprite.h"
//���̴� �������� �˻��ϱ� ���� ������� ��Ŭ���
#include<ctype.h>
#include<vector>
#include<map>

class SText :
	public IObject
{
public:
	//����� ���ڿ�
	string str;
	//�̹��� �ε��� ��
	map<char, Sprite *>img;
	//�۲�ũ���̴�. �۲��̹����� �� ��� ������ �����Ѵ�.
	float fontSize;
	//
	//�⺻ ������, Default �۲ð�η� �����Ѵ�.
	SText();
	
	//�۲� ������ ��η� �����Ѵ�.
	//�۲� ���� �ȿ��� 0.png, a.png �� ����� ������ �̸�.png ������ �־�� �Ѵ�.
	SText(string path, float fontsize=1);
	~SText();
	//�۲��� �������Ѵ�.
	void Render();
	//�۲��� ������Ʈ�Ѵ�. ���� �߿� ���ڿ��� ������ �ʴ´ٸ� �ʿ� ����.
	void Update(float dTime);
	//���ڿ��� ����ְ�, ���������� �۲��̹������� �������� �����Ѵ�.
	void Put(string str);
	


	
};

