#pragma once
#include "GameObject.h"
#include "Image.h"
#include "Enemy.h"


class Bullet :
	public GameObject
{
private:
	Image img;
	
public:
	void Init(int _x, int _y);
	void Draw();
	int GetWidth();
	int GetHeigth();
	void DeleteBullet();
};
