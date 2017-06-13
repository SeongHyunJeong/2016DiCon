#include "BeatmapManager.h"



BeatmapManager::BeatmapManager():notes(4, vector<int>(0, 0)), 
sleepTime(0),
readInterval(0),
speed(0)
{
	
}


BeatmapManager::~BeatmapManager()
{
}

void BeatmapManager::ReadBeatmap(string path)
{
	//파일을 읽기모드로 불러옴
	f = fopen(path.c_str(), "rt");
	//헤더를 읽음
	fscanf(f, "%f %f %f", &sleepTime, &readInterval, &speed);
	//노트를 읽음
	//EOF가 아닐동안
	while (!feof(f))
	{
		//임시배열
		int t[4] = { 0 };
		
		fscanf(f, "%d %d %d %d", &t[0], &t[1], &t[2], &t[3]);

		for (int i = 0; i < 4; i++)
		{
			//i번째 노트벡터에 i번째 라인 노트를 집어넣는다.
			notes[i].push_back(t[i]);
		}
	}
	//파일을 닫음
	fclose(f);
}

void BeatmapManager::Reset()
{
	for (int i = 0; i < 4; i++)
	{
		notes[i].clear();
	}
}

void BeatmapManager::PrintNotes()
{
	for (int i = 0; i < notes[0].size(); i++)
	{
		for (int j = 0; j < 4; j++)
		{
			printf("%d ", notes[j][i]);
		}
		printf("\n");
	}
}

BeatmapManager bmmgr;