
#include "IObject.h"
#include"Sprite.h"
#include"Text.h"
//#include"Scene_Fight.h"
class Potion :
	public IObject
{
public:
	//���϶� �̹���
	Sprite * cool;
	//��밡���Ҷ� �̹���
	Sprite * ready;

	Text * count;
	
	bool isReady;

	pair<float, float>timer;

	Potion(string cpath, string rpath);
	~Potion();

	void Render();
	void Update(float dt);
};
