#include "ColisionBullet.h"


bool ColisionBullet::Colision(int posEnemyX, int posEnemyY, int enemyWidth, int enenmyHeight)
{
	int xMouseP = mouseX;
	int xEnemyP = posEnemyX + enemyWidth;
	int yMouseP = mouseY;
	int yEnemyP = posEnemyY + enenmyHeight;

	if (position.x < xEnemyP && mouseX > posEnemyX && position.y < yEnemyP && mouseY > posEnemyY)
	{
		return true;
	}
	return false;
}



bool ColisionBullet::CheckColisions(std::vector <Enemy*> enemies)
{
	for (auto enemy : enemies)
	{
		if (Colision(enemy->position.x, enemy->position.y, enemy->GetWidth(), enemy->GetHeigth()))
		{
			
			return true;
			//eliminar enemigo
		}
	}
	return false;
	
}
