#pragma once
#include "IObject.h"
#include"Sprite.h"
class Button :
	public IObject
{
public:
	//버튼 기본 이미지
	Sprite * defaultImage;
	//마우스 올라갔을 때 이미지
	Sprite * onMouseImage;
	//클릭했을 때 이미지
	Sprite * clickImage;

	//생성자(_d 디폴트 _c 클릭 _m 온마우스)
	Button(string _dPath);
	Button(string _dPath, string _cpath);
	Button(string _dPath, string _cpath, string _mPath);
	~Button();

	//클릭됐는지.(버튼안에 마우스좌표가 있으면서, GetMyKeyState에서 -1이 반환되었을때.)
	bool isClk;
	bool IsClicked();

	//높이와 너비

	float width;
	float height;


	//씬에 있는 버튼이 아닌, 다른 오브젝트의 상속을 받은 버튼일경우
	//마우스 좌표는 월드좌표로 계산되는데 버튼의 좌표는 로컬좌표로 계산되어
	//클릭 판정이 제대로 되지 않는데 이를 보완해주는 변수이다.
	D3DXVECTOR2 diff;

	//기본함수재정의
	virtual void Render();
	virtual void Update(float dt);

};

