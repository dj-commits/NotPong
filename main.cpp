#include "main.h"
#include "Game.hpp"

Game* game = nullptr;
int main()
{
	game = new Game();
	game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	while (game->isRunning())
	{
		game->handleEvents();
		game->update();
		game->render();
	}

	game->clean();
	return 0;
}