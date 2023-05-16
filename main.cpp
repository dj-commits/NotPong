#include "main.h"
#include "Game.hpp"

Game* game = nullptr;
Uint64 minimumFPS = (1000 / 6);
Uint64 lastTime = SDL_GetTicks64();
int main()
{
	game = new Game();
	game->init("Title", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 800, 600, false);
	
	game->LoadContent();
	while (game->isRunning())
	{
		Uint64 nowTime = SDL_GetTicks64();
		if(lastTime < nowTime)
		{
			Uint64 deltaTime = nowTime - lastTime;
			if (deltaTime > minimumFPS)
			{
				deltaTime = minimumFPS;
			}

			game->handleEvents(deltaTime);
			game->update(deltaTime);
			lastTime = nowTime;
			game->render(deltaTime);
			
		}
		else
		{
			SDL_Delay(1);
		}
		
	}

	game->clean();
	return 0;
}