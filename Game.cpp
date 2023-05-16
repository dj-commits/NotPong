#include "Game.hpp"
#include "Paddle.h"
Paddle* player1;
Game::Game()
{}
Game::~Game()
{}

void Game::init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen)
{
	int flags = 0;
	if(fullscreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}
	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "SDL Initialized correctly..." << std::endl;

		window = SDL_CreateWindow(title, xPos, yPos, width, height, flags | SDL_WINDOW_RESIZABLE);
		if(window)
		{
			std::cout << "SDL Window created successfully..." << std::endl;

			renderer = SDL_CreateRenderer(window, -1, 0);
			if (renderer)
			{
				SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
				std::cout << "SDL Renderer created successfully..." << std::endl;

				running = true;
			}
		}
	}
	else
	{
		running = false;
	}

	player1 = new Paddle(renderer);
}

void Game::handleEvents(Uint64 deltaTime)
{
	SDL_Event evnt;
	SDL_PollEvent(&evnt);
	switch (evnt.type)
	{
	case SDL_QUIT:
		running = false;
		break;
	default:
		break;
	}
}

void Game::LoadContent()
{
	
}

void Game::update(Uint64 deltaTime)
{
	
	std::cout << deltaTime << std::endl;
}

void Game::render(Uint64 deltaTime)
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
	SDL_RenderCopy(renderer, player1->texture, NULL, &player1->sprite);
	// add stuff to render
	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Game cleaned successfully..." << std::endl;
}


