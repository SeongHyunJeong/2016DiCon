#include "Button.h"
#include"collisions.h"
#include"Sound.h"
//�����ڿ����� �Ʒ��� ���� �ʱ�ȭ ����Ʈ�� ������ �սô�.
//d ������
Button::Button(string _dpath)
	:defaultImage(new Sprite(_dpath)),
	clickImage(new Sprite(_dpath)),
	onMouseImage(new Sprite(_dpath)),
	isClk(false),
	diff(0, 0)
{
	AddChild(defaultImage);
	AddChild(clickImage);
	AddChild(onMouseImage);
	rect = defaultImage->visibleRect;
	width = defaultImage->width;
	height = defaultImage->height;
}

//d c ������
Button::Button(string _dpath, string _cpath)
	:defaultImage(new Sprite(_dpath)),
	clickImage(new Sprite(_cpath)),
	onMouseImage(new Sprite(_dpath)),
	isClk(false),
	diff(0, 0)
{
	AddChild(defaultImage);
	AddChild(clickImage);
	AddChild(onMouseImage);
	rect = defaultImage->visibleRect;
	width = defaultImage->width;
	height = defaultImage->height;
}
// d c m ������
Button::Button(string _dpath, string _cpath, string _mpath)
	:defaultImage(new Sprite(_dpath)),
	clickImage(new Sprite(_cpath)),
	onMouseImage(new Sprite(_mpath)),
	isClk(false),
	diff(0, 0)
{
	AddChild(defaultImage);
	AddChild(clickImage);
	AddChild(onMouseImage);
	rect = defaultImage->visibleRect;
	width = defaultImage->width;
	height = defaultImage->height;
}


Button::~Button()
{
}

void Button::Render()
{
	IObject::Render();
	
	if (IsPointInRect(pos, rect, GetMousePos() + diff))
	{
		if (isClk)
		{
			
			clickImage->Render();
		}
		else
		{
			onMouseImage->Render();
		}
	}
	else
	{
		defaultImage->Render();
	}

}

bool Button::IsClicked()
{
	return isClk;
}
void Button::Update(float dt)
{
	IObject::Update(dt);
	
	if (IsPointInRect(pos + diff, rect, GetMousePos()))
	{
		if (GetMyKeyState(VK_LBUTTON) == -1)
			isClk = true;
		else
			isClk = false;
	}
	else
		isClk = false;

}

