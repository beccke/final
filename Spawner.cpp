#include "Spawner.h"
#include "Enemy.h"

	Enemy* enemy = new Enemy;

Spawner::Spawner(int widthScreen, int heightScreen)
{
	this->widthScreen = widthScreen;
	this->heightScreen = heightScreen;
}

void Spawner::CreateEnemy()
{
	enemy->Init(rand()%widthScreen, rand()%heightScreen);
	enemies.push_back(enemy);
}

void Spawner::EnemySpawner(double deltaTime)
{
	time += deltaTime;
	if (time >= 3) 
	{
		CreateEnemy();
		time = 0;
	}
}



