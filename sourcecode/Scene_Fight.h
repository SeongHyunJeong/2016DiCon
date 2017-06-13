#pragma once
#include "GScene.h"
#include "sprite.h"
#include "Collisions.h"
#include "Global.h"
#include "IObject.h"
#include"iEnemy.h"
#include"LongNote.h"
#include"Key.h"
#include"SText.h"
#include"Result.h"
#include"Log.h"
#include"potion.h"
class Scene_Fight :
	public GScene
{
public:

	Scene_Fight(char * songPath,char * notePath, int prevSceneId, IEnemy * e );
	~Scene_Fight();

	Sprite * background;
	Sprite * player;
	Sprite * playerHpBar;
	Sprite * enemyHpBar;

	//ü�¹� ���
	Sprite * hpBarBg;

	//�α�
	Log * log;


	//��Ʈ ������ ���Ϸ� �������� ������
	Sprite * bar;


	//Ÿ�� �ִϸ��̼�
	Animation * hit[4];
	//���� �ִϸ��̼�
	Animation* judge[4];
	bool isPressed[4];
	//��
	IEnemy * enemy;
	//��Ʈ ����Ʈ
	vector<list<Note *> > nList;
	//�ճ�Ʈ ����Ʈ
	vector<list<LongNote *> > lnList;
	//Ű
	Key * key[4];
	//���� �а��ִ� ��


	int currentLine;



	//�÷��̾� hp
	float playerHp;

	//�޺�
	int combo;

	//�޺��ؽ�Ʈ
	SText * comboText;

	//����Ÿ���ؽ�Ʈ
	Text * freeTime;
	//�������� ������ ���ó��
	float initTimer;

	//�ʱ�ȭ �Ǿ����� Ȯ���ϴº���
	bool isInited;

	char * songPath;

	//��Ʈ����Ҷ� �� Ÿ�̸�
	pair<float, float>timer;

	//�ճ�Ʈ �޺����Ÿ�̸�
	float lnTimer;
	
	//����Ÿ��
	bool isFreeTime;
	//����
	int rewardItemCount;
	int rewardMoney;
	int rewardExp;

	//��Ȯ��
	Text * accText;
	float acc;
	int perfectCount;
	int greatCount;
	int badMissCount;
	
	//��� ��Ʈ�� ����Ѵ�.
	void Init();

	//��Ʈ�� �Ŵ����� �о� �����ð����� ��Ʈ�� �����Ѵ�.
	void GenerateNotes(float dt);
	void Render();
	void Update(float dtime);


	//Ű �Է¿� ���� ������ �Ѵ�.
	void Judge(float dt);

	//����

	Potion * potion;



	////////////////

	//���â
	Result * result;
	//Ȯ�ι�ư(������ �������� ����)
	Button * ok;


	bool isFinished;
};