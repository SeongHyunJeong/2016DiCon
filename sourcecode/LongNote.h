
#include "Note.h"
class LongNote :
	public Note
{
public:
	

	//판정용 변수
	//0 : 아직 판정범위에 오지 않은 상태
	//1 : 노트의 첫부분이 판정범위 밑이고, 성공적으로 키를 입력하여 퍼펙트나 그레이트 판정을 얻어낸 상태
	//2 : 노트의 첫부분이 판정범위 밑이고, 배드판정으로 입력했거나 미스해서 첫부분을 놓친 상태
	//0의 경우에 대해서는 첫부분 판정을 수행하면 되고, 1, 2 경우에 대해서는 중간부분 판정을 수행하면 된다.

	int state;


	LongNote(string path, float x, float speed,float length);
	~LongNote();
};
