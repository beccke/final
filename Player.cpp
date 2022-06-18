#include "Player.h"
#include "Window.h"
#include <iostream>
#include <math.h>


void Player::Init()
{
	position.x = 0;
	position.y = 0;
	player.Load("Jugador.png");
	forward.x = 0.0;
	forward.y = -1.0;
	aceleracion.x = 2.0;
	velocidad.x = 0.3;
	aceleracion.y = 5.0;
	velocidad.y = 0.3;
}

void Player::Draw(int mouseX,int mouseY)
{
	Vector2 mousePosition(mouseX, mouseY);
	mousePosition = mousePosition - position;
	mousePosition.Norm();
	forward.Norm();
	float angle = atan2(mousePosition.y - forward.y, mousePosition.x - forward.x)*180/3.1416;
	angle += 95;
	/*float direction;
	float denominador;
	direction = forward * mousePosition;
	denominador = forward.Norm() * mousePosition.Norm();
	float angle = SDL_acos(direction/denominador)*180; // arcos(A.B/|A||B|)
	std::cout << angle;*/
	Window* window = Window::GetPtr();
	window->RenderTexture(&player, position.x, position.y, angle);
}



void Player::acel(int velocidadx_,int aceleracionx_, int velocidady_, int aceleraciony_)
{
	const Uint8* keys = SDL_GetKeyboardState(NULL);
	aceleracion.x = aceleracionx_;
	aceleracion.y = aceleraciony_;
	velocidad.x = velocidadx_;
	velocidad.y = velocidady_;
	velocidad.x += aceleracion.x * deltaTime;
	velocidad.y += aceleracion.y * deltaTime;

	

	if (keys[SDL_SCANCODE_UP])
	{
		position.y -= velocidad.y * deltaTime;
	}
	else if (keys[SDL_SCANCODE_DOWN])
	{
		position.y += velocidad.y * deltaTime;
	}
	if (keys[SDL_SCANCODE_RIGHT])
	{
		position.x += velocidad.x * deltaTime;

	}
	else if (keys[SDL_SCANCODE_LEFT])
	{
		position.x -= velocidad.x * deltaTime;

	}


}


bool Player::Colision(int posEnemyX, int posEnemyY, int enemyWidth, int enenmyHeight) 
{
	int xPlayerP = position.x + player.GetWidth();
	int xEnemyP = posEnemyX + enemyWidth;
	int yPlayerP = position.y + player.GetHeight();
	int yEnemyP = posEnemyY + enenmyHeight;

	if (position.x < xEnemyP && xPlayerP > posEnemyX && position.y < yEnemyP && yPlayerP > posEnemyY) 
	{	
		return true;
	}
	return false;
}



bool Player::CheckColisions(std::vector <Enemy*> enemies)
{
	for(auto enemy:enemies)
	{
		if (Colision(enemy->position.x, enemy->position.y, enemy->GetWidth(), enemy->GetHeigth())) 
		{
			Pegaron = true;
			energy-=5;
			std::cout << energy << "\n";
			return true;
			//eliminar enemigo
		}
	}
	return false;
	Pegaron = false;
}



