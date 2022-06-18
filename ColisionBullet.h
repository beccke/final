#pragma once
#include <vector>
#include "Enemy.h"
class ColisionBullet
{

private:
	Vector2 position;
	int mouseX;
	int mouseY;
	bool Colision(int posEnemyX, int posEnemyY, int enemyWidth, int enenmyHeight);



public:

	bool CheckColisions(std::vector <Enemy*> enemies);



};

