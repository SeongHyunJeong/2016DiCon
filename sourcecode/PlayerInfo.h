#pragma once
#include "IObject.h"
#include"Inventory.h"
//세이브/로드 해야할 정보를 저장한다.
class PlayerInfo
{
public:
	PlayerInfo();
	~PlayerInfo();

	//초기 상태인지(프롤로그를 안봤는지)
	//파일입출력 간편화, 정보 숨기기 위해 int로 함
	int prologWatched;
	//데미지
	int damage;
	//돈
	int money;
	//포션
	int potion;
	//업그레이드 수치
	int upgrade;
	//경험치
	pair<float, float>exp;
	//아이템갯수
	int itemCount[9];
	//레벨
	int lv;
	//전직
	int job;
	//클리어 여부
	//파일입출력 간편화, 정보 숨기기 위해 int로 함
	int isCleared[12];
	//챕터
	int chapter;
	//스킨 경로
	string skinPath;
	//전투씬 키 설정배열
	char keys[4];
	//현재 위치
	int currentMap;
	//최대 체력
	float maxHp;

	bool isHpIncreased;

	bool inGame;
	//세이브 / 로드 함수들

	

	//저장
	void Save();
	//불러오기
	void Load();
	//초기화
	void Reset();

	void Play(char * alias, bool loop);
	void Stop(char * alias);
	
};

extern PlayerInfo playerInfo;