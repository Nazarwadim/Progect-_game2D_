#pragma once
#include "Game.h"
class GameObject{
public:
	GameObject(const char * teture_sheet, SDL_Renderer *ren, bool isGravity = false, bool floor = false, bool rigidBody = false);
	~GameObject();
	void render();
	void update();
	bool isGravity = false;
	bool rigidBody = false;
	bool floor = false;
protected:
	float x_pos;
	float y_pos;

	Vector2d speed = { 0, 0 };
	SDL_Texture *object_texture;
	SDL_Rect srcRect, destRect;
	SDL_Renderer * render_obj;
};