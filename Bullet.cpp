#include "Bullet.h"
#include "Window.h"
#include "Enemy.h"

Enemy *enemy;

void Bullet::Init(int _x, int _y)
{
	position.x = _x;
	position.y = _y;
	img.Load("Bala.png");
}

void Bullet::Draw()
{
	Window* window = Window::GetPtr();
	window->RenderTexture(&img, position.x, position.y);
}

int Bullet::GetWidth()
{
	return img.GetWidth();
}

int Bullet::GetHeigth()
{
	return img.GetHeight();
}


void Bullet::DeleteBullet()
{
	if (enemy->DB == true)
	{
		delete &img;

	}
}