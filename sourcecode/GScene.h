#pragma once
#include "Scene.h"
#include"GScene.h"
#include"button.h"
#include"Inventory.h"
#include"Setting.h"
#include"Minimap.h"
//이 게임에서 사용되는 모든 씬의 기본 클래스
//Scene 클래스에 id와 플레이어생성좌표, 배경스크롤이 추가됨
//이 값들은 필요 없을시 사용 안 하면 됨

//사용예
//플레이어가 씬을 넘어갈 때 id값을 넘겨줘서 어디에서 넘어오는지를 판단한다.
//전투씬으로 넘어갈때 id값을 넘겨줘서 어떤 몹이 생성될지 판단하고
//다시 맵으로 돌아갈때 어디로 돌아갈지 판단한다.

class GScene :
	public Scene
{
public:

	//플레이어 생성좌표
	//디폴트:0, 0
	D3DXVECTOR2 spawnPlayerCoord;

	//고유번호
	//디폴트:0
	//필요할때 이걸 스위치케이스에 넣고 분기처리하면 된다.
	int id;

	//강체리스트
	//물리적 충돌처리를 할 오브젝트는 모두 이 리스트에 들어가야한다.
	list<IObject * > rbList;
	//강체리스트2
	//오브젝트대신 렉트를 넣고 싶을때 쓴다.
	//렉트를 넣을때는 포지션을 더하도록하자.
	list<RECT> rbRectList;

	//생성자. id와 포지션 Default값을 0으로 준다.
	//일반 씬 생성하듯이 할 수도 있다 
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
	//경험치와 레벨
	Sprite * exps[5];
	Text * level;
	Text * exp;
	//미니맵
	Minimap * minimap;
	Button * map;
	//페이드인/아웃용 변수
	int fade;
	int fade2;
	bool isFadedOut;
	bool isFadedIn;
	//배경 이동
	void MoveBackground(int x, int y, Sprite* prevBackgroundSprite, Sprite* nextBackgroundSprite);
	//배경 페이드인/아웃
	bool FadeIn(Sprite * s);
	bool FadeOut(Sprite * s);

};

