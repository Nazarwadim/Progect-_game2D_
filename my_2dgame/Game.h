#pragma once
#include "SDL.h"
#include "SDL_image.h"
#include "texture_manager.h"
#include <iostream>
#include <cmath>
#define WIDTH 800
#define HEIGHT 640
struct Vector2d {
	float x;
	float y;
};


class Game
{
public:
	Game();
	~Game();
	void start();
	void update();
	void handleEvents();
	bool running() { return isRunning; }
	void render();
	void init(const char* title, int width, int height, bool fullscreen)
	{
		int flags = 0;

		if (fullscreen)
		{
			flags = SDL_WINDOW_FULLSCREEN;
		}

		if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
		{
			window = SDL_CreateWindow(title, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, width, height, flags);
			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			}

			isRunning = true;
		}
	}
	void clean();

	static SDL_Renderer* renderer;

private:
	bool isRunning = false;
	float cnt = 0;
	SDL_Window *window;
};
