#pragma once

#include "SDL.h"
#include "SDL_image.h"
#include <iostream>
#include <cmath>
#define WIDTH 800
#define HEIGHT 600
struct Vector2d {
	float x;
	float y;
	Vector2d(float xValue, float yValue) : x(xValue), y(yValue) {}
};


class Game
{
public:
	Game();
	~Game();
	void init(const char* title, int width, int height, bool fullscreen);
	void handleEvents();
	void start();
	void update();
	bool running() { return isRunning; }
	void render();
	void clean();

private:
	bool isRunning = false;
	float cnt = 0;
	SDL_Window *window;
	SDL_Renderer* renderer;
	// Write our variables
	
	float max_speed = 3;


};
