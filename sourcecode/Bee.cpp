#include "Bee.h"



Bee::Bee()
	:IEnemy("img/mob/1/bee/ȣ��1.png", "0", 700, 1)
{
	ani->AddFrame("img/mob/1/bee/ȣ��2.png");
	ani->AddFrame("img/mob/1/bee/ȣ��3.png");
	ani->AddFrame("img/mob/1/bee/ȣ��4.png");
	scale = D3DXVECTOR2(2.5f, 2.5f);
}


Bee::~Bee()
{
}
