#include "Scene_Fight.h"
#include "Scene_Dungeon1.h"
#include "Scene_Dungeon2.h"
#include"Scene_Dungeon3.h"
#include"BeatmapManager.h"
#include"sound.h"
#include"playerinfo.h"
#include"S7.h"
#include"s8.h"
#include"s9.h"
#include"s11.h"
#include"s12.h"
#include"s13.h"
Scene_Fight::Scene_Fight(char * _songPath, char * _notePath, int prevSceneId, IEnemy * e)
	:isInited(false), initTimer(0.f),currentLine(0),nList(4),lnList(4),combo(0),lnTimer(0),isFreeTime(false)
{
	sound.Stop("bg");
	sound.Add("sound/bg.wav", "bg");
	id = prevSceneId;
	playerHp = playerInfo.maxHp;
	background = new Sprite("img/ui/fight.png");
	AddObject(background);
	bmmgr.Reset();
	bmmgr.ReadBeatmap(_notePath);

	enemy = e;
	AddObject(e);
	enemy->pos = Vec2(615, 296);
	//enemy->scale = Vec2(2.5f, 2.5f);
	songPath = _songPath;

	player = new Sprite(playerInfo.skinPath.c_str());
	AddObject(player);
	player->scale = Vec2(2.5f, 2.5f);
	player->pos = Vec2(55, 296);
	//sprintf(soundPath, "sound/_%s.wav", songName.c_str());
	/**/
	//bmmgr.PrintNotes();'

	playerHpBar = new Sprite("img/ui/hpbar.png");
	AddObject(playerHpBar);
	playerHpBar->pos = Vec2(10, 470);

	enemyHpBar = new Sprite("img/ui/hpbar.png");
	AddObject(enemyHpBar);
	enemyHpBar->pos = Vec2(529, 470);

	
	comboText = new SText();
	AddObject(comboText);
	comboText->pos = Vec2(400, 52);

	hpBarBg = new Sprite("img/ui/hpbarback.png");
	AddObject(hpBarBg);

	
	for (int i = 0; i < 4; i++)
	{
		key[i] = new Key("img/ui/key" + to_string(i) + ".png", "img/ui/key" + to_string(i) + "pr.png", playerInfo.keys[i]);
		key[i]->pos = Vec2(270 + i * 66, 425);
		AddObject(key[i]);
		nList[i].clear();
		lnList[i].clear();
	}

	acc = 1.f;
	perfectCount = 0;
	greatCount = 0;
	badMissCount = 0;

	accText = new Text("Pixel NES");
	AddObject(accText);
	accText->pos = Vec2(630, 20);
	accText->Put("100.00%", DT_LEFT, D3DCOLOR_ARGB(255, 0, 255, 0));

	switch (prevSceneId)
	{
	case 3:result = new Result(new Sprite("img/ui/inventory/items/0_goblinhair.png"), 0); break;
	case 4:result = new Result(new Sprite("img/ui/inventory/items/1_slime.png"), 1); break;
	case 5:result = new Result(new Sprite("img/ui/inventory/items/2_mushroom.png"), 2); break;
	case 7:result = new Result(new Sprite("img/ui/inventory/items/3_sting.png"), 3); break;
	case 8:result = new Result(new Sprite("img/ui/inventory/items/4_orcspear.png"), 4); break;
	case 9:result = new Result(new Sprite("img/ui/inventory/items/5_tree.png"), 5); break;
	case 11:result = new Result(new Sprite("img/ui/inventory/items/6_ogrehorn.png"), 6); break;
	case 14:result = new Result(new Sprite("img/ui/inventory/items/7_scythe.png"), 7); break;
	case 12:result = new Result(new Sprite("img/ui/inventory/items/8_dog.png"), 8); break;
	case 30: result = new Result(new Sprite("img/spot.png"), 9); break;
	case 31: result = new Result(new Sprite("img/spot.png"), 10); break;
	case 32: result = new Result(new Sprite("img/spot.png"), 11); break;
	}
	AddObject(result);
	result->pos = Vec2(267, 50);

	ok = new Button("img/ui/ok.png");
	AddObject(ok);
	ok->pos = Vec2(117 + 277, 375 + 50);

	freeTime = new Text("Pixel NES");
	freeTime->pos = Vec2(310, 0);
	AddObject(freeTime);
	freeTime->Put("FREE TIME!", DT_LEFT, D3DCOLOR_ARGB(255, 0,0, 255));
	
	log = new Log("img/ui/log.png", 5);
	AddObject(log);
	log->pos = Vec2(202, 464);

	potion = new Potion("img/ui/potioncool.png", "img/ui/potionready.png");
	AddObject(potion);
	potion->pos = Vec2(-10, -50);
	potion->scale = Vec2(2.5f, 2.5f);

	bar = new Sprite("img/ui/bar.png");
	bar->pos = Vec2(255, 403);
	AddObject(bar);
	
	for (int i = 0; i < 4; i++)
	{
		hit[i] = new Animation(50);
		AddObject(hit[i]);
		hit[i]->pos = Vec2(key[i]->pos.x, key[i]->pos.y - 80);
		hit[i]->AddFrame("img/ui/Animation1.png");
		hit[i]->AddFrame("img/ui/Animation2.png");
		hit[i]->AddFrame("img/ui/Animation3.png");
		hit[i]->AddFrame("img/ui/Animation4.png");
		hit[i]->loop = false;

	}

	for (int i = 0; i < 4; i++)
	{
		judge[i] = new Animation(40);
		AddObject(judge[i]);
		judge[i]->pos = Vec2(0, 0);
		judge[i]->loop = false;
		for (int j = 0; j < 4; j++)
		{
			judge[i]->AddFrame("img/ui/judge/" + to_string(i) + to_string(j) + ".png");
		}
		//여기부터
		isPressed[i] = false;
	}
	
	

	log->PushLog(" ");

	isFreeTime = false;
}

Scene_Fight::~Scene_Fight()
{
	
}

void Scene_Fight::Init()
{
	sound.Add(songPath, "song");
	sound.Play("song", false);

	timer.second = bmmgr.readInterval;
	isInited = true;
	
}

void Scene_Fight::GenerateNotes(float dt)
{
	if (isInited)
	{
		timer.first += dt;
		if (timer.first >= timer.second)
		{
			if (currentLine < bmmgr.notes[1].size() - 1)
				currentLine++;
			else
			{
				if (enemy->alive)
				{
					result->SetActive(acc, perfectCount, playerHp, 0); return;
				}
				else
				result->SetActive(acc, perfectCount, playerHp, 2); 				return;
			}
			timer.first = 0;
			for (int i = 0; i < 4; i++)
			{
				//일반노트
				if (bmmgr.notes[i][currentLine] == 1)
				{
					//300, 30
					Note * n = new Note("img/note.png", 270 + i * 66, bmmgr.speed);
					nList[i].push_back(n);
					AddObject(n);
				}
				//롱노트
				else if (bmmgr.notes[i][currentLine] >= 2)
				{
					LongNote * ln = new LongNote("img/longnote.png", 270 + i * 66, bmmgr.speed, bmmgr.speed * dt *bmmgr.notes[i][currentLine]);
					lnList[i].push_back(ln);
					AddObject(ln);
				}
			}
			
		}
	}

}

void Scene_Fight::Render()
{
	background->Render();
	enemy->Render();
	player->Render();

	potion->Render();
	if(isInited)
	accText->Render();

	for (int i = 0; i < 4; i++)
	{
		for(auto iter=nList[i].begin(); iter!=nList[i].end();iter++)
		{
			(*iter)->Render();
		}
		for (auto iter = lnList[i].begin(); iter != lnList[i].end(); iter++)
		{
			(*iter)->Render();
		}
		
	}
	bar->Render();
	for (int i = 0; i < 4; i++)
	{
		key[i]->Render();
		hit[i]->Render();
		judge[i]->Render();
		if (isPressed[i])
		{
			judge[i]->currentFrame = 0;
			judge[i]->Play();
			isPressed[i] = false;
		}
	}
	
	log->Render();
	hpBarBg->pos = playerHpBar->pos;
	hpBarBg->Render();
	playerHpBar->Render();
	hpBarBg->pos = enemyHpBar->pos;
	hpBarBg->Render();
	enemyHpBar->Render();
	comboText->Render();
	result->Render();
	if (result->isShowing)
	{
		ok->Render();
	}

	if (isFreeTime)
		freeTime->Render();

	
}

void Scene_Fight::Update(float dt)
{
	Scene::Update(dt);


	if (playerInfo.isHpIncreased)
	{
		playerHp += 10;
		playerInfo.isHpIncreased = false;
	}
	//노트생성
	if(result->isShowing == false)
	GenerateNotes(dt);


	//초기화부분
	initTimer += dt;
	if (initTimer > 3.f)
	{
		if (!isInited)
		{
			Init();
		}
	}

	//판정
	Judge(dt);
	comboText->Put(to_string(combo));

	//체력바 상태 업데이트

	playerHpBar->visibleRect.right = playerHp / playerInfo.maxHp * 253;
	if (playerHpBar->visibleRect.right <= 0)playerHpBar->visibleRect.right = 0;
	enemyHpBar->visibleRect.right = enemy->hp.first / enemy->hp.second * 253;
	if (enemyHpBar->visibleRect.right <= 0)enemyHpBar->visibleRect.right = 0;
	//프리타임이 아닌데 플레이어가 죽었을 때
	if (playerHp <= 0 && !isFreeTime)
	{
		if (result->isShowing == false)
		{
			log->PushLog("당신은 쓰러졌습니다");
		}
		result->SetActive(acc, perfectCount, 0, 0);
		sound.Stop("song");
	}
	else if (enemy->alive == false)
	{
		if(!isFreeTime)
		{
			log->PushLog("**************프리 타임!****************");
			log->PushLog("ESC를 누르면 전투를 일찍 종료할 수 있습니다.");
			log->PushLog("끝까지 플레이 할 시 추가 보상이 주어집니다.");
		}
		isFreeTime = true;
		
	}

	if (isFreeTime)
	{
		if (GetMyKeyState(VK_ESCAPE) == KEYDOWN)
		{
			//nList.clear();
			//lnList.clear();
			result->SetActive(acc, perfectCount, playerHp, 1);
			sound.Stop("song");
			
		}
	}


	
	if (!enemy->alive)
	{
		isFreeTime = true;
	}

	
	
	//if (GetMyKeyState(VK_SPACE))
		//sceneManager->ChangeScene(new Scene_Dungeon1());
	

	//정확도 업데이트(퍼펙트 100퍼 그레이트 60퍼 배드,미스 0퍼로 평균계산)
	acc = (float)(perfectCount + greatCount*0.6f) / ((float)(perfectCount + greatCount + badMissCount) == 0 ? 1 : (float)(perfectCount + greatCount + badMissCount));
	accText->Put(to_string((int)(acc * 100)) + "." + to_string((int)(acc * 1000) % 10) + "%", DT_LEFT, D3DCOLOR_ARGB(255, 0,255, 0));
	if (playerHp >= playerInfo.maxHp)playerHp = playerInfo.maxHp;
	//결과창에서 확인 누르면 씬 전환
	if (result->isShowing)
	{
		if (ok->IsClicked())
		{
			sound.Play("click", false);
			sound.Play("bg", true);
			if (id == 3)
				sceneManager->ChangeScene(new Scene_Dungeon1(-2, Vec2(273, 176)));
			else if (id == 4)
				sceneManager->ChangeScene(new Scene_Dungeon2(-2, Vec2(541, 388)));
			else if (id == 5)
				sceneManager->ChangeScene(new Scene_Dungeon3(-2, Vec2(402, 375)));
			else if (id == 7)
				sceneManager->ChangeScene(new S7(-2, Vec2(466, 92)));
			else if (id == 8)
				sceneManager->ChangeScene(new S8(-2, Vec2(501, 390)));
			else if (id == 9)
				sceneManager->ChangeScene(new S9(-2, Vec2(118, 165)));
			else if (id == 11)
				sceneManager->ChangeScene(new S11(-2, Vec2(352, 451)));
			else if (id == 14)
				sceneManager->ChangeScene(new S11(-2, Vec2(559, 188)));
			else if (id == 12)
				sceneManager->ChangeScene(new S12(-2, Vec2(385, 406)));
			else if (id == 30 || id == 31)
			{
				sceneManager->ChangeScene(new S13(-2, Vec2(400, 500)));
			}
			else if (id == 32)
			{
				playerInfo.chapter = 4;
				playerInfo.Save();
				PostQuitMessage(0); return;
			}
				
		}
	}
}

void Scene_Fight::Judge(float dt)
{
	//롱노트 콤보계산 타이머 작동
	lnTimer += dt;
	//일반노트 판정
	for (int i = 0; i < 4; i++)
	{
		//키가눌렸을때
		
			//리스트가 비어있지 않을때만
			if (!nList[i].empty())
			{
				//리스트상의 첫번째노트(화면상의 가장아래노트)에 대해서만 판정을 수행한다.
				//모든 노트에 대해 판정을 수행할 경우 폭타부분에서 판정이 겹쳐버린다.
				auto iter = nList[i].begin();

				if (key[i]->State() == KEYDOWN)
				{
					//판정선 : y좌표 402
					//퍼펙트 판정
					if ((*iter)->pos.y >= 347 && (*iter)->pos.y <= 456)
					{
						//printf("Perfect\n");
						RemoveObject(*iter);
						iter = nList[i].erase(iter);
						combo++;
						perfectCount++;
						//적 공격 전직 대미지 배수 처리
						if (playerInfo.job == 0)
						{
							enemy->hp.first -= playerInfo.damage;
						}else if (playerInfo.job==1)
						{
							enemy->hp.first -= (playerInfo.damage*1.3);
						}
						else if (playerInfo.job == 2)
						{
							enemy->hp.first -= (playerInfo.damage*1.5);
						}
						hit[i]->Play();
						isPressed[0] = true;
						enemy->hit = true;

					}
					//그레이트 판정(else if 안하면 안됨)
					else if ((*iter)->pos.y >= 296 && (*iter)->pos.y <= 490)
					{
						//printf("Great\n");
						RemoveObject(*iter);
						iter = nList[i].erase(iter);
						greatCount++;
						combo++;
						//적 공격
						enemy->hp.first -= playerInfo.damage;
						hit[i]->Play();
						isPressed[1] = true;
						enemy->hit = true;
					}
					//배드 판정(너무 일찍 칠경우)
					else if ((*iter)->pos.y >= 254 && (*iter)->pos.y <= 510)
					{
						//printf(" Bad..\n");
						RemoveObject(*iter);
						iter = nList[i].erase(iter);
						combo = 0;
						badMissCount++;
						if(!isFreeTime)
						playerHp -= enemy->damage;
						isPressed[2] = true;
						if (!isFreeTime)
						enemy->attacked = true;
					}
				}
				//미스 판정(안칠경우)

				else if ((*iter)->pos.y > 510)
				{
					//printf(" Miss..\n");
					RemoveObject(*iter);
					iter = nList[i].erase(iter);
					combo = 0;
					badMissCount++;
					if (!isFreeTime)
					playerHp -= enemy->damage;
					isPressed[3] = true;
					if (!isFreeTime)
					enemy->attacked = true;
				}
			}
	}
	//롱노트 판정
	for (int i = 0; i < 4; i++)
	{
		//첫 부분(일반노트랑 똑같다. 안누를시 콤보끊김)
		
			if (!lnList[i].empty())
			{

				auto iter = lnList[i].begin();
				if (key[i]->State() == KEYDOWN && (*iter)->state == 0)
				{
					//퍼펙트 판정

					if ((*iter)->pos.y >= 347 && (*iter)->pos.y <= 456)
					{
						//printf("Perfectlf\n");
						(*iter)->state = 1;
						//RemoveObject(*iter);
						//iter = nList[i].erase(iter);
						combo++;
						perfectCount++;
						//적 공격
						enemy->hp.first -= playerInfo.damage;
						hit[i]->Play();
						isPressed[0] = true;
						enemy->hit = true;
					}
					//그레이트 판정(else if 안하면 안됨)
					else if ((*iter)->pos.y >= 296 && (*iter)->pos.y  <= 490)
					{
						//printf("Greatlf\n");
						(*iter)->state = 1;
						//RemoveObject(*iter);
						//iter = nList[i].erase(iter);
						combo++;
						greatCount++;
						//적 공격
						enemy->hp.first -= playerInfo.damage;
						hit[i]->Play();
						isPressed[1] = true;
						enemy->hit = true;
					}
					//배드 판정(너무 일찍 칠경우)
					else if ((*iter)->pos.y >= 254 && (*iter)->pos.y <= 510)
					{
						//printf(" Bad..\n");
						(*iter)->state = 2;
						badMissCount++;
						combo = 0;
						if (!isFreeTime)
						playerHp -= enemy->damage;
						isPressed[2] = true;
						if (!isFreeTime)
						enemy->attacked = true;
					}
				}
				//아직 입력 안했는데 놓친경우(첫부분 미스)
				else if ((*iter)->pos.y  > 480 && (*iter)->state == 0)
				{
				//	printf("longfMiss..\n");
					(*iter)->state = 2;
					combo = 0;
					badMissCount++;
					if (!isFreeTime)
					playerHp -= enemy->damage;
					isPressed[3] = true;
					if (!isFreeTime)
					enemy->attacked = true;
				}

				//중간부분이후 판정(일단 무조건 퍼펙트, 수정 가능)
				if (key[i]->State() == KEYON && (*iter)->state == 1)
				{
					
					if (lnTimer >= 0.2f)
					{
					//	printf("ppp\n");
						lnTimer = 0;
						combo++;
						enemy->hp.first -= playerInfo.damage;
						hit[i]->Play();
						enemy->hit = true;
					}
				}
				//롱노트누르다가 실수로 땠을때
				else if (key[i]->State() == KEYUP && (*iter)->state == 1&& (*iter)->pos.y +(*iter)->rect.top >360)
				{
					//printf("mistake\n");
					combo = 0;
					if (!isFreeTime)
					playerHp -= enemy->damage;
					badMissCount++;
					isPressed[3] = true;
					if (!isFreeTime)
					enemy->attacked = true;
				}


				//삭제처리
				if ((*iter)->pos.y +(*iter)->rect.top> 420)
				{
					RemoveObject(*iter);
					iter = lnList[i].erase(iter);
				}
			}
		
		
		
	}

	if (GetMyKeyState(VK_F1)==KEYDOWN) //적 체력 0으로 f1
	{
		enemy->hp.first = 0;
	}







}
