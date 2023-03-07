#include "Game.h"
#include "GameObject.h"


GameObject *player;
void Game::start()
{	
	player = new GameObject("player.png", renderer, true, true);
}
void Game::update()
{
	player->update();
	if (!isRunning)
	{
		delete player;
	}
}

void Game::render()
{
	SDL_RenderClear(renderer);
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