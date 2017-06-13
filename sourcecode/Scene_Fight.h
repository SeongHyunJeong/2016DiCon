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

	//체력바 배경
	Sprite * hpBarBg;

	//로그
	Log * log;


	//노트 판정선 이하로 내려갈때 가리기
	Sprite * bar;


	//타격 애니메이션
	Animation * hit[4];
	//판정 애니메이션
	Animation* judge[4];
	bool isPressed[4];
	//적
	IEnemy * enemy;
	//노트 리스트
	vector<list<Note *> > nList;
	//롱노트 리스트
	vector<list<LongNote *> > lnList;
	//키
	Key * key[4];
	//현재 읽고있는 줄


	int currentLine;



	//플레이어 hp
	float playerHp;

	//콤보
	int combo;

	//콤보텍스트
	SText * comboText;

	//프리타임텍스트
	Text * freeTime;
	//전투씬에 진입후 대기처리
	float initTimer;

	//초기화 되었는지 확인하는변수
	bool isInited;

	char * songPath;

	//노트재생할때 쓸 타이머
	pair<float, float>timer;

	//롱노트 콤보계산타이며
	float lnTimer;
	
	//프리타임
	bool isFreeTime;
	//보상
	int rewardItemCount;
	int rewardMoney;
	int rewardExp;

	//정확도
	Text * accText;
	float acc;
	int perfectCount;
	int greatCount;
	int badMissCount;
	
	//곡과 노트를 재생한다.
	void Init();

	//비트맵 매니저를 읽어 일정시간마다 노트를 생성한다.
	void GenerateNotes(float dt);
	void Render();
	void Update(float dtime);


	//키 입력에 따라 판정을 한다.
	void Judge(float dt);

	//포션

	Potion * potion;



	////////////////

	//결과창
	Result * result;
	//확인버튼(누르면 전씬으로 나감)
	Button * ok;


	bool isFinished;
};