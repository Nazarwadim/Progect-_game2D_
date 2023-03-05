#pragma once
#include "Game.h"
class Phisics {
private:
	const float G = 9.67;
	float k_of_elastic_reflection = 0;
public:
	Phisics() {}
	~Phisics(){}
	Phisics(Vector2d speed);
	Phisics(SDL_Point O);
	Phisics(Vector2d speed, SDL_Point O);
	Vector2d speed = {0, 0};
	SDL_Point O = {0, 0};
	bool gravity = false;
	void set_kof_of_el_reflection(float k_of_elastic_reflection)
	{
		this->k_of_elastic_reflection = k_of_elastic_reflection;
	}
	inline float get_kof_of_el_reflection()
	{
		return k_of_elastic_reflection;
	}
	void setgravity()
	{
		if (gravity)
		{
			speed.y += G;
		}
	}
};
Phisics::Phisics(Vector2d speed)
{
	this->speed = speed;
}
Phisics::Phisics(SDL_Point O)
{
	this->O = O;
}
Phisics::Phisics(Vector2d speed, SDL_Point O)
{
	this->speed = speed;
	this->O = O;
}

namespace Texure_manager {
	SDL_Texture* import_player_textue(SDL_Renderer *renderer, char *path_to_png_texture)
	{
		SDL_Surface* tmp_surfase = IMG_Load(path_to_png_texture);
		SDL_Texture *player_texure = SDL_CreateTextureFromSurface(renderer, tmp_surfase);
		SDL_FreeSurface(tmp_surfase);
		return player_texure;
	}
};