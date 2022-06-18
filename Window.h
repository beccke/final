#pragma once
#include "SDL.h"
#include "Image.h"


class Window
{
private:
	SDL_Window* window;
	SDL_Renderer* canvas;
	Window();
	static Window* ptr;

public:
	static Window* GetPtr();
	void Init();
	void Clear();
	void Render();
	void Input(int& directionX, int& directionY, bool& click, int& mouseX, int& mouseY, int& velocidadx, int& velocidady, int& aceleracionx, int & aceleraciony);
	SDL_Renderer* GetCanvas();
	void RenderTexture(Image* image, int x, int y, float angle = 0);

};


