#include "texture_manager.h"
SDL_Texture* Texture_manager::load_texture(const char* path)
{
	SDL_Surface* tempSur = IMG_Load(path);
	SDL_Texture* texture = SDL_CreateTextureFromSurface(Game::renderer, tempSur);
	SDL_FreeSurface(tempSur);
	return texture;
}

void Texture_manager::draw(SDL_Texture* texture, SDL_Rect src, SDL_Rect dest)
{
	SDL_RenderCopy(Game::renderer, texture, &src, &dest);
}
