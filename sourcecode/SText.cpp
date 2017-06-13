#include "SText.h"
#include"Global.h"
#include<String>
using namespace std;


SText::SText()
	:str("")
{
	fontSize = 1;
	for (int i = 0; i <= 9; i++)
	{
		img[i] = new Sprite("font/" +to_string(i) + ".png");
		AddChild(img[i]);
		img[i]->scale = Vec2(fontSize, fontSize);
	}
}

SText::SText(string path, float fontsize)
	:str("")
{
	fontSize = 1;
	for (int i = 0; i <= 9; i++)
	{
		img[i] = new Sprite(path +"/" + to_string(i) + ".png");
		AddChild(img[i]);
		img[i]->scale = Vec2(fontSize, fontSize);
	}
}


SText::~SText()
{
}

void SText::Render()
{
	IObject::Render();
	for (int i = 0; i < str.size(); i++)
	{
		img[str[i] - '0']->pos.x = i * fontSize * img[str[i] - '0']->width - 0.5 * img[str[i] - '0']->width * str.size();
		img[str[i] - '0']->Render();
	}
}
void SText::Update(float dTime)
{


}
void SText::Put(string str)
{
	this->str = str;
}
//	if (!charVector.empty())
//	{
//		for (auto& iter : charVector)
//		{
//			RemoveChild(iter);
//			iter = nullptr;
//		}
//		charVector.clear();
//	}
//	for (int i = 0; i < str.size(); i++)
//	{
//		if (isgraph(str[i]))
//		{
//			charVector.push_back(new Sprite(path + "/" + str[i] + ".png"));
//			AddChild(charVector.back());
//			charVector.back()->scale = D3DXVECTOR2(fontSize, fontSize);
//			charVector.back()->pos.x = i * charVector.back()->width*fontSize;
//		}
//	}
//}