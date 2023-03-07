#include "Game.h"
#include "GameObject.h"

GameObject::~GameObject(){}
GameObject::GameObject(const char* teture_sheet, bool isGravity,bool floor, bool rigidBody) {
	x_pos = 0;
	y_pos = 0;
	srcRect.h = 78;
	srcRect.w = 78;
	srcRect.x = 0;
	srcRect.y = 0;
	destRect.h = srcRect.h * 0;
	destRect.w = srcRect.w * 0;
	destRect.x = srcRect.x;
	destRect.y = srcRect.y;
	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;
	object_texture = Texture_manager::load_texture(teture_sheet);
	this->floor = floor;
	this->isGravity = isGravity;
	this->rigidBody = rigidBody;
}
void GameObject::update()
{
	
}
void GameObject::render()
{
	destRect.x = (int)x_pos;
	destRect.y = (int)y_pos;
	SDL_RenderCopy(Game::renderer, object_texture, &srcRect, &destRect);
}