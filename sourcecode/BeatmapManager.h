#pragma once
#include<filesystem>
#include"Note.h"
class BeatmapManager
{
public:
	
	//노트 TXT 파일 포인터
	FILE * f;

	//노트정보를 저장할 벡터
	
	vector < vector < int > > notes;

	//비트맵 헤더를 저장할 변수
	float sleepTime;
	float readInterval;
	float speed;

	//생성자
	//벡터 1번째인덱스 크기를 4로 지정하고 변수를 0으로 초기화한다.
	BeatmapManager();
	~BeatmapManager();

	//비트맵을 읽어와 벡터에 저장한다.
	void ReadBeatmap(string path);
	//노트벡터를 초기상태로 만든다.
	void Reset();

	//디버그용 함수
	//노트벡터 전체를 출력한다.
	void PrintNotes();

};

extern BeatmapManager bmmgr;