#include "Game.h"

SDL_Texture* player_texure;
SDL_Rect srcR = {100,100,100,100}, destR;
float y_pos = 0;
Vector2d speed(4, 4);
bool buffer_Rwas[HEIGHT][WIDTH];
bool gravity = true;
Game::Game()
{}

Game::~Game()
{}




void Game::start()
{
	for (int y = 0; y < 600; y++)
		for (int x = 0; x < 800; x++)
			buffer_Rwas[y][x] = 0;


	SDL_Surface* tmp_surfase = IMG_Load("player.png");
	player_texure = SDL_CreateTextureFromSurface(renderer, tmp_surfase);
	SDL_FreeSurface(tmp_surfase);
}
void Game::update()
{
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

	
	//colision
	float k_of_elastic_reflection = 0.8;
	if (y_pos < 0)
	{
		if(speed.y < 0)speed.y *= -k_of_elastic_reflection;
	}
	if (y_pos > HEIGHT - destR.h)
	{
		if(speed.y > 0)
			speed.y *= -k_of_elastic_reflection;
	}
	if (cnt > WIDTH - destR.w)
	{
		if (speed.x > 0)speed.x *= -k_of_elastic_reflection;
	}
	if (cnt < 0)
	{
		if(speed.x < 0)speed.x *= -k_of_elastic_reflection;
	}
	if(y_pos > 0 && y_pos < HEIGHT && cnt > 0 && cnt < WIDTH)
		buffer_Rwas[(int)y_pos][(int)cnt] = 1;

	if (speed.x > 0.1) speed.x -= 0.01; if (speed.x > 0) speed.x -= 0.001;
	if (speed.x < -0.1) speed.x += 0.01; if (speed.x < 0) speed.x += 0.001; //x_vec of friction force

	if (speed.y > 0.1) speed.y -= 0.01; if (speed.y > 0) speed.y -= 0.001;//y_vec of friction force
	if (speed.y < -0.1) speed.y += 0.01; if (speed.y < 0) speed.y += 0.001;
	
	if (speed.x > max_speed) speed.x = max_speed - 0.1;
	if (speed.y > max_speed) speed.y = max_speed - 0.1;
	if (-speed.x > max_speed) speed.x = -(max_speed - 0.1);
	if (-speed.y > max_speed) speed.y = -(max_speed - 0.1);

	//gravity

	if (gravity && destR.y < HEIGHT - 100)
	{
		speed.y += 0.05;
	}
	cnt += speed.x;
	y_pos += speed.y;
	destR.h = 100;
	destR.w = 100;
	destR.x = cnt;
	destR.y = y_pos;
}

void Game::render()
{
	SDL_RenderClear(renderer);
	
	SDL_RenderCopy(renderer, player_texure, NULL, &destR);
	
	for(int y = 0; y < 600;y++)
		for(int x = 0; x < 800;x++)
		if (buffer_Rwas[y][x])
		{
			SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
			SDL_RenderDrawPoint(renderer, x, y);
		}
	SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
	SDL_RenderPresent(renderer);
}





void Game::init(const char* title, int width, int height, bool fullscreen)
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
void Game::handleEvents()
{
	SDL_Event event;

	SDL_PollEvent(&event);
	switch (event.type)
	{
	case SDL_QUIT:
		isRunning = false;
		break;
	default:
		break;
	}
}
void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
}