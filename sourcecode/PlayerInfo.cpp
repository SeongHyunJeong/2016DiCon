#include "PlayerInfo.h"
#include"Sound.h"


PlayerInfo::PlayerInfo()
{
	Load();
	isHpIncreased = false;
	//sound.Add("sound/center.wav", "center");
	//sound.Add("sound/village.wav", "village");
	//sound.Add("sound/final.wav", "final");
	//sound.Add("sound/lava.wav", "lava");
	//sound.Add("sound/bird.wav", "bird");
	//sound.Add("sound/forest.wav", "forest");
}


PlayerInfo::~PlayerInfo()
{

}

void PlayerInfo::Save()
{
	FILE *f = fopen("save.txt", "wt");
	fprintf(f, "%d\n", prologWatched);
	fprintf(f, "%d\n", damage);
	fprintf(f, "%d\n", money);
	fprintf(f, "%d\n", potion);
	fprintf(f, "%d\n", upgrade);
	fprintf(f, "%f\n", exp.first);
	fprintf(f, "%f\n", exp.second);
	for (int i = 0; i<9; i++)
		fprintf(f, "%d\n", itemCount[i]);
	fprintf(f, "%d\n", lv);
	fprintf(f, "%d\n", job);
	for (int i = 0; i<12; i++)
		fprintf(f, "%d\n", isCleared[i]);
	fprintf(f, "%d\n", chapter);
	fprintf(f, "%d\n", currentMap);
	fprintf(f, "%f\n", maxHp);
	fprintf(f, "%c %c %c %c", keys[0], keys[1], keys[2], keys[3]);
	fclose(f);
}

void PlayerInfo::Load()
{
	FILE *f = fopen("save.txt", "rt");
	
	fscanf(f, "%d", &prologWatched);
	fscanf(f, "%d", &damage);
	fscanf(f, "%d", &money);
	fscanf(f, "%d", &potion);
	fscanf(f, "%d", &upgrade);
	fscanf(f, "%f", &exp.first);
	fscanf(f, "%f", &exp.second);
	for (int i = 0; i < 9; i++)
		fscanf(f, "%d", &itemCount[i]);
	fscanf(f, "%d", &lv);
	fscanf(f, "%d", &job);
	for (int i = 0; i < 12; i++)
		fscanf(f, "%d", &isCleared[i]);
	fscanf(f, "%d", &chapter);
	fscanf(f, "%d", &currentMap);
	fscanf(f, "%f", &maxHp);
	fscanf(f, "%*c%c %c %c %c", &keys[0], &keys[1], &keys[2], &keys[3]);
	fclose(f);
	//free(f);
	//printf("%p", f);
	switch (chapter)
	{
		case 1:skinPath = "img/defaultplayer.png"; break;
		case 2:skinPath = "img/2player.png"; break;
		case 3:skinPath = "img/3player.png"; break;
	}
}

void PlayerInfo::Reset()
{
	prologWatched = 0;
	damage = 1;
	money = 10;
	potion = 5;
	upgrade = 1;
	exp.first = 0;
	exp.second = 40;
	for (int i = 0; i < 9; i++)
		itemCount[i] = 0;
	lv = 1;
	job = 0;
	for (int i = 0; i < 12; i++)
		isCleared[i] = 0;
	chapter = 1;
	skinPath = "img/defaultplayer.png";
	currentMap = 0;
	maxHp = 100;


	keys[0] = 'D';
	keys[1] = 'F';
	keys[2] = 'J';
	keys[3] = 'K';
	Save();
}

void PlayerInfo::Play(char * alias, bool loop)
{

	int i;

	sound.Play(alias, loop);


}

void PlayerInfo::Stop(char * alias)
{
	sound.Stop(alias);
}

PlayerInfo playerInfo;