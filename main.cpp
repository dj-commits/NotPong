#include "main.h"
#include "Game.hpp"

Game* game = nullptr;
double minimumFPS = (1.0 / 60.0);
double nowTime = 0.0;
double lastTime = 0.0;
double deltaTime = 0.0;
int main()
{
	game = new Game();
	game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	game->LoadContent();
	while (game->isRunning())
	{
		
		nowTime = (double)SDL_GetTicks64();
		deltaTime = (nowTime - lastTime) / 1000;

		game->handleEvents(deltaTime);
		game->update(deltaTime);
		game->render(deltaTime);

		lastTime = nowTime;
	}

	game->clean();
	return 0;
}