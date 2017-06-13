#include "Log.h"


Log::Log(string bgpath, int size)
{
	bg = new Sprite(bgpath);
	AddChild(bg);

	str = new Text("둥근모꼴", 12, 17);
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

	//로그 문자열을 순회하며 Text에 집어넣고 렌더한다.
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
	//가득찬 상태에서 푸시백을 하면 가장먼저들어온 요소를 뺀다.
	if (log.size() > size)
		log.pop_front();

	
}
