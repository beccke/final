#include <iostream>
#include "Window.h"
#include "Player.h"
#include <vector>
#include "Bullet.h"
#include "SDL.h"
#include "Enemy.h"
#include <chrono>
#include "Spawner.h"

int main(int argc, char* args[])
{
    Window* window = Window::GetPtr();
    window->Init();
    Player p1;
    Enemy e1;
    Bullet* newBullet;
    p1.Init();
    int dirx;
    int mouseX;
    int mouseY;
    int velx;
    int vely;
    int acex;
    int acey;
    bool click = false;
    int diry;
    float DT = 1.0 / 60.0;
    float seg = 0;
    std::vector<Bullet*> bullets;
    std::chrono::steady_clock clock;
    double deltaTime = 0;
    Spawner spawner(1280, 720);
    bool lastClick = false;

    while (true)
    {     
        auto start = clock.now();
        spawner.EnemySpawner(deltaTime);
        window->Clear();
        lastClick = click;
        window->Input(dirx, diry, click, mouseX, mouseY, velx, vely, acex, acey);
        if (diry > 0 && p1.position.y > -10)
        {
            p1.velocidad.y += p1.aceleracion.y * (1.0 / 60.0);
            p1.position.y -= p1.velocidad.y * (1.0 / 60.0);
            
        }
        else if (diry < 0 && p1.position.y < 630)
        {
            p1.velocidad.y += p1.aceleracion.y * (1.0 / 60.0);
            p1.position.y += p1.velocidad.y * (1.0 / 60.0);
        }
        if (dirx > 0 && p1.position.x < 1180)
        {
            p1.velocidad.x += p1.aceleracion.x * (1.0 / 60.0);
            p1.position.x += p1.velocidad.x * (1.0 / 60.0);
        }
        else if (dirx < 0 && p1.position.x > 0)
        {
            p1.velocidad.x += p1.aceleracion.x * (1.0 / 60.0);
            p1.position.x -= p1.velocidad.x * (1.0 / 60.0);
        }




        if (click && !lastClick)
        {

            Bullet* newBullet = new Bullet();
            newBullet->Init(mouseX, mouseY);
            bullets.push_back(newBullet);
        }     

        for (int i = 0; i < bullets.size(); i++)
        {
            bullets[i]->Draw();
        }

        for (int i = 0; i < spawner.enemies.size(); i++)
        {
            spawner.enemies[i]->Draw();
            spawner.enemies[i]->CheckColisions(bullets);
            spawner.enemies[i]->DeleteEnemy();
        }

        for (int i = 0; i < spawner.enemies.size(); i++)
        {
            spawner.enemies[i]->Update(p1.position);
        }
        p1.CheckColisions(spawner.enemies);
        
        p1.Draw(mouseX, mouseY);
        window->Render();
        auto end = clock.now();  
        auto time_span = static_cast<std::chrono::duration<double>>(end - start);
        p1.acel(10.0,10.0,10.0,10.0);

        deltaTime = time_span.count();


        if (p1.Pegaron == true ) {

            seg += DT/60;
            //std::cout << seg << "\n";

        }
         if (seg >= 5 && p1.Pegaron == true) {
            seg -= DT / 60;
            p1.Pegaron = false;

        }
        
        

    }
    
    return 0;
}

