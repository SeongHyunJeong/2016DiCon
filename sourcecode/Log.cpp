#include "Log.h"


Log::Log(string bgpath, int size)
{
	bg = new Sprite(bgpath);
	AddChild(bg);

	str = new Text("�ձٸ��", 12, 17);
	AddChild(str);
	str->pos = Vec2(50, 10);

	this->size = size;
}

Log::~Log()
{
}

void Log::Render()
{
	IObject::Render();
	bg->Render();

	//�α� ���ڿ��� ��ȸ�ϸ� Text�� ����ְ� �����Ѵ�.
	str->pos.y = -10;
	for_iter(iter, log)
	{
		str->Put((*iter), DT_LEFT, D3DCOLOR_ARGB(255, 0, 0, 0));
		str->pos.y += 20;
		str->Render();
	}
}

void Log::Update(float dt)
{
	IObject::Update(dt);
}

void Log::PushLog(string str)
{
	log.push_back(str);
	//������ ���¿��� Ǫ�ù��� �ϸ� ����������� ��Ҹ� ����.
	if (log.size() > size)
		log.pop_front();

	
}
