#pragma once
#include "Scene.h"
#include"GScene.h"
#include"button.h"
#include"Inventory.h"
#include"Setting.h"
#include"Minimap.h"
//�� ���ӿ��� ���Ǵ� ��� ���� �⺻ Ŭ����
//Scene Ŭ������ id�� �÷��̾������ǥ, ��潺ũ���� �߰���
//�� ������ �ʿ� ������ ��� �� �ϸ� ��

//��뿹
//�÷��̾ ���� �Ѿ �� id���� �Ѱ��༭ ��𿡼� �Ѿ�������� �Ǵ��Ѵ�.
//���������� �Ѿ�� id���� �Ѱ��༭ � ���� �������� �Ǵ��ϰ�
//�ٽ� ������ ���ư��� ���� ���ư��� �Ǵ��Ѵ�.

class GScene :
	public Scene
{
public:

	//�÷��̾� ������ǥ
	//����Ʈ:0, 0
	D3DXVECTOR2 spawnPlayerCoord;

	//������ȣ
	//����Ʈ:0
	//�ʿ��Ҷ� �̰� ����ġ���̽��� �ְ� �б�ó���ϸ� �ȴ�.
	int id;

	//��ü����Ʈ
	//������ �浹ó���� �� ������Ʈ�� ��� �� ����Ʈ�� �����Ѵ�.
	list<IObject * > rbList;
	//��ü����Ʈ2
	//������Ʈ��� ��Ʈ�� �ְ� ������ ����.
	//��Ʈ�� �������� �������� ���ϵ�������.
	list<RECT> rbRectList;

	//������. id�� ������ Default���� 0���� �ش�.
	//�Ϲ� �� �����ϵ��� �� ���� �ִ� 
	GScene(int _id=0, D3DXVECTOR2 _spc=D3DXVECTOR2(0, 0));
	virtual ~GScene();

	virtual void Render();
	virtual void Update(float dt);

	Button * inventoryButton;
	Button * x;
	bool isInvenShowing;
	Inventory * inven;

	Button * settingButton;
	Setting * setting;
	bool isSettingShowing;
	bool isMapShowing;
	//����ġ�� ����
	Sprite * exps[5];
	Text * level;
	Text * exp;
	//�̴ϸ�
	Minimap * minimap;
	Button * map;
	//���̵���/�ƿ��� ����
	int fade;
	int fade2;
	bool isFadedOut;
	bool isFadedIn;
	//��� �̵�
	void MoveBackground(int x, int y, Sprite* prevBackgroundSprite, Sprite* nextBackgroundSprite);
	//��� ���̵���/�ƿ�
	bool FadeIn(Sprite * s);
	bool FadeOut(Sprite * s);

};

