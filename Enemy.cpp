#include "Enemy.h"
#include "Window.h"
#include "Vector2.h"
#include "Bullet.h"
#include <iostream>
#include "Spawner.h"


void Enemy::Init(int x_, int y_)
{
	Bullet bullet;
	position.x = x_;
	position.y = y_;
	enemy.Load("Enemigo.png");
}
void Enemy::Draw()
{
	Window* window = Window::GetPtr();
	window->RenderTexture(&enemy, position.x, position.y);
}

void Enemy::Update(Vector2 playerPosition)
{
	Vector2 direction;
	direction = playerPosition - position;
	direction = direction.Unit() * 0.1;
	position = position + direction;

	

}

int Enemy::GetWidth()
{
	return enemy.GetWidth();
}

int Enemy::GetHeigth()
{
	return enemy.GetHeight();
}

bool Enemy::Colision(int posBulletX, int posBulletY, int bulletWidth, int bulletHeight)
{
	int xEnemyP = position.x + enemy.GetWidth();
	int xBulletP = posBulletX + bulletWidth;
	int yEnemyP = position.y + enemy.GetHeight();
	int yBulletP = posBulletY + bulletHeight;

	if (position.x < xEnemyP && xEnemyP > posBulletX && position.y < yEnemyP && yEnemyP > posBulletY)
	{
		return true;
	}
	return false;
}



bool Enemy::CheckColisions(std::vector <Bullet*> bullets)
{
	for (auto bullet : bullets)
	{
		if (Colision(bullet->position.x, bullet->position.y, bullet->GetWidth(), bullet->GetHeigth()))
		{
			std::cout << "Colision";
			DB = true;
			return true;
			healt--;
			
		}
	DB = false;
	}
	return false;
	
}

void Enemy::DelteEnemy()
{
}

void Enemy::DeleteEnemy()
{
	if (healt == 0)
	{
		delete &enemy;
		
	}
}

