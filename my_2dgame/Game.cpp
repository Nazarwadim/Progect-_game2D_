#include "Game.h"
#include "GameObject.h"
#include "Map.h"
SDL_Renderer * Game::renderer = nullptr;
GameObject* player;
Map *map;
Game::Game()
{}
Game::~Game()
{
	delete player;
	delete map;
}
void Game::start()
{	
	player = new GameObject("assets/player.png", true, true);
	map = new Map();
}
void Game::update()
{
	player->update();
}

void Game::render()
{
	SDL_RenderClear(renderer);
	map->draw_map();
	player->render();
	SDL_RenderPresent(renderer);
}





void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
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