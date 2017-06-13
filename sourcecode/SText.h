#pragma once
#include "sprite.h"
//보이는 문자인지 검사하기 위한 헤더파일 인클루드
#include<ctype.h>
#include<vector>
#include<map>

class SText :
	public IObject
{
public:
	//출력할 문자열
	string str;
	//이미지 로딩할 맵
	map<char, Sprite *>img;
	//글꼴크기이다. 글꼴이미지를 몇 배로 늘일지 결정한다.
	float fontSize;
	//
	//기본 생성자, Default 글꼴경로로 저장한다.
	SText();
	
	//글꼴 폴더를 경로로 지정한다.
	//글꼴 폴더 안에는 0.png, a.png 등 사용할 문자의 이름.png 파일이 있어야 한다.
	SText(string path, float fontsize=1);
	~SText();
	//글꼴을 렌더링한다.
	void Render();
	//글꼴을 업데이트한다. 게임 중에 문자열이 변하지 않는다면 필요 없다.
	void Update(float dTime);
	//문자열을 집어넣고, 내부적으로 글꼴이미지들의 포지션을 조정한다.
	void Put(string str);
	


	
};

