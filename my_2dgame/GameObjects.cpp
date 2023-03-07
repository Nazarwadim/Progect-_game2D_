#include "Game.h"
#include "GameObject.h"

GameObject::~GameObject(){}
GameObject::GameObject(const char* teture_sheet, SDL_Renderer* ren, bool isGravity,bool floor, bool rigidBody) {
	x_pos = 0;
	y_pos = 0;
	srcRect.h = 0;
	srcRect.w = 0;
	srcRect.x = x_pos;
	srcRect.y = y_pos;

	destRect.h = srcRect.h * 0;
	destRect.w = srcRect.w * 0;
	destRect.x = srcRect.x;
	destRect.y = srcRect.y;

	render_obj = ren;
	object_texture = texture_manager::load_texture(render_obj, teture_sheet);
	this->floor = floor;
	this->isGravity = isGravity;
	this->rigidBody = rigidBody;
}
void GameObject::update()
{

	srcRect.h = 78;
	srcRect.w = 78;
	srcRect.x = 0;
	srcRect.y = 0;

	destRect.h = srcRect.h * 2;
	destRect.w = srcRect.w * 2;

	std::cout << speed.y << ' ' << y_pos << '\n';
	x_pos += speed.x;
	y_pos += speed.y;
	if (isGravity && speed.y < 10)
	{
		speed.y += 0.1;
	}
	
	if (floor && y_pos > HEIGHT - destRect.h)
	{
		isGravity = false;
		speed.y = - speed.y * 0;
	}
	else {
		isGravity = true;
	}






	const Uint8* state = SDL_GetKeyboardState(NULL);
	if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_UP]) {
		// рухаємо персонажа вліво-вверх
		speed.x -= 0.1;
		speed.y -= 0.1;
	}
	else if (state[SDL_SCANCODE_LEFT] && state[SDL_SCANCODE_DOWN]) {
		// рухаємо персонажа вліво-вниз
		speed.x -= 0.1;
		speed.y += 0.1;
	}
	else if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_UP]) {
		// рухаємо персонажа вправо-вверх
		speed.x += 0.1;
		speed.y -= 0.1;
	}
	else if (state[SDL_SCANCODE_RIGHT] && state[SDL_SCANCODE_DOWN]) {
		// рухаємо персонажа вправо-вниз
		speed.x += 0.1;
		speed.y += 0.1;
	}
	else if (state[SDL_SCANCODE_LEFT]) {
		// рухаємо персонажа вліво
		speed.x -= 0.1;
	}
	else if (state[SDL_SCANCODE_RIGHT]) {
		// рухаємо персонажа вправо
		speed.x += 0.1;
	}
	else if (state[SDL_SCANCODE_UP]) {
		// рухаємо персонажа вверх
		speed.y -= 0.1;
	}
	else if (state[SDL_SCANCODE_DOWN]) {
		// рухаємо персонажа вниз
		speed.y += 0.1;
	}

	if (state[SDL_SCANCODE_B])
	{
		if(speed.y > -10 && !isGravity) speed.y -= 5;
	}
}
void GameObject::render()
{
	destRect.x = (int)x_pos;
	destRect.y = (int)y_pos;
	SDL_RenderCopy(render_obj, object_texture, &srcRect, &destRect);
}