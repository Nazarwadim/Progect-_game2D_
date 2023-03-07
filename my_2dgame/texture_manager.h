#pragma once
#include "Game.h"
class Texture_manager {
public:
	static SDL_Texture* load_texture(const char* path);
	static void draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest);
};
