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
	//������ �б���� �ҷ���
	f = fopen(path.c_str(), "rt");
	//����� ����
	fscanf(f, "%f %f %f", &sleepTime, &readInterval, &speed);
	//��Ʈ�� ����
	//EOF�� �ƴҵ���
	while (!feof(f))
	{
		//�ӽù迭
		int t[4] = { 0 };
		
		fscanf(f, "%d %d %d %d", &t[0], &t[1], &t[2], &t[3]);

		for (int i = 0; i < 4; i++)
		{
			//i��° ��Ʈ���Ϳ� i��° ���� ��Ʈ�� ����ִ´�.
			notes[i].push_back(t[i]);
		}
	}
	//������ ����
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