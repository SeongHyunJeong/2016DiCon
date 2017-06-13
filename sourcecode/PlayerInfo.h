#pragma once
#include "IObject.h"
#include"Inventory.h"
//���̺�/�ε� �ؾ��� ������ �����Ѵ�.
class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();

	//�ʱ� ��������(���ѷα׸� �Ⱥô���)
	//��������� ����ȭ, ���� ����� ���� int�� ��
	int prologWatched;
	//������
	int damage;
	//��
	int money;
	//����
	int potion;
	//���׷��̵� ��ġ
	int upgrade;
	//����ġ
	pair<float, float>exp;
	//�����۰���
	int itemCount[9];
	//����
	int lv;
	//����
	int job;
	//Ŭ���� ����
	//��������� ����ȭ, ���� ����� ���� int�� ��
	int isCleared[12];
	//é��
	int chapter;
	//��Ų ���
	string skinPath;
	//������ Ű �����迭
	char keys[4];
	//���� ��ġ
	int currentMap;
	//�ִ� ü��
	float maxHp;

	bool isHpIncreased;

	bool inGame;
	//���̺� / �ε� �Լ���

	

	//����
	void Save();
	//�ҷ�����
	void Load();
	//�ʱ�ȭ
	void Reset();

	void Play(char * alias, bool loop);
	void Stop(char * alias);
	
};

extern PlayerInfo playerInfo;