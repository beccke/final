#pragma once
#include "GameObject.h"
#include "Image.h"
#include <vector>
#include "Enemy.h"
class Player :public GameObject
{
private:
	Image player;
	float deltaTime;
	int energy = 1000;
	bool Colision(int posEnemyX, int posEnemyY, int enemyWidth, int enenmyHeight);
	

public:
	bool Pegaron;
	void Init();
	void Draw(int mouseX, int mouseY);
	void acel(int velocidadx_, int aceleracionx_, int velocidady_, int aceleraciony_);
	bool CheckColisions(std::vector <Enemy*> enemies);
};