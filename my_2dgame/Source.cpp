#include "Game.h"

Game* game = nullptr;

int main(int argc, char* argv[])
{
	game = new Game();
	
	game->init("GameWindow", WIDTH, HEIGHT, false);

	const int fps = 144;
	const int frameDelay = 1000 / fps;
	Uint32 frameStart;
	int frametime;
	game->start();
	while (game->running())
	{
		frameStart = SDL_GetTicks();

		
		game->update();
		game->render();
		game->handleEvents();
		frametime = SDL_GetTicks() - frameStart;
		if (frameDelay > frametime)
		{
			SDL_Delay(frameDelay - frametime); //60 fps duraku on line 11 it is written 144 chorte 
		}
	}

	game->clean();
	
	delete game;
	return 0;
}