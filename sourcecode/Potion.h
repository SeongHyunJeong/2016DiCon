
#include "IObject.h"
#include"Sprite.h"
#include"Text.h"
//#include"Scene_Fight.h"
class Potion :
	public IObject
{
public:
	//쿨일때 이미지
	Sprite * cool;
	//사용가능할때 이미지
	Sprite * ready;

	Text * count;
	
	bool isReady;

	pair<float, float>timer;

	Potion(string cpath, string rpath);
	~Potion();

	void Render();
	void Update(float dt);
};
