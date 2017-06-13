#pragma once
#include<filesystem>
#include"Note.h"
class BeatmapManager
{
public:
	
	//��Ʈ TXT ���� ������
	FILE * f;

	//��Ʈ������ ������ ����
	
	vector < vector < int > > notes;

	//��Ʈ�� ����� ������ ����
	float sleepTime;
	float readInterval;
	float speed;

	//������
	//���� 1��°�ε��� ũ�⸦ 4�� �����ϰ� ������ 0���� �ʱ�ȭ�Ѵ�.
	BeatmapManager();
	~BeatmapManager();

	//��Ʈ���� �о�� ���Ϳ� �����Ѵ�.
	void ReadBeatmap(string path);
	//��Ʈ���͸� �ʱ���·� �����.
	void Reset();

	//����׿� �Լ�
	//��Ʈ���� ��ü�� ����Ѵ�.
	void PrintNotes();

};

extern BeatmapManager bmmgr;