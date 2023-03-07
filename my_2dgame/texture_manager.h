#pragma once
#include "Game.h"
class texture_manager {
public:
	static SDL_Texture* load_texture(SDL_Renderer* renderer, const char* path)
	{
		SDL_Surface* tempSur = IMG_Load(path);
		SDL_Texture* texture = SDL_CreateTextureFromSurface(renderer, tempSur);
		SDL_FreeSurface(tempSur);
		return texture;
	}
};