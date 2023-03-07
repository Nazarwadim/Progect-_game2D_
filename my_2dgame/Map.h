#pragma once
#include "Game.h"
#define ROW 20
#define COLUMN 25
class Map {
public:
	Map();
	~Map();
	void load_map(int arr[ROW][COLUMN]);
	void draw_map();

private:
	SDL_Rect src, dest;
	SDL_Texture* dirt;
	SDL_Texture* grass;
	SDL_Texture* water;
	int map[ROW][COLUMN];
};