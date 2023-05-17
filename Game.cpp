#include "Game.hpp"
#include "Paddle.h"
#include "Ball.h"
#include <SDL_image.h>


Paddle* player1;
Paddle* player2;
Ball* ball;
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
				std::cout << "SDL Renderer created successfully..." << std::endl;

				if (IMG_Init(IMG_INIT_PNG) == 2)
				{
					std::cout << "SDL_Image created successfully..." << std::endl;
					
					
					running = true;
				}
				
			}
		}
	}
	else
	{
		running = false;
	}

	
}

void Game::handleEvents(double deltaTime)
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
	player1 = new Paddle(renderer);
	player2 = new Paddle(renderer);
	ball = new Ball(renderer);

	player1->sprite.x = 25;
	player1->sprite.y = 300;
	player2->sprite.x = 750;
	player2->sprite.y = 300;
	ball->sprite.x = 400;
	ball->sprite.y = 300;
}

void Game::update(double deltaTime)
{
	ball->Move(deltaTime);
	//std::cout << deltaTime << std::endl;
}

void Game::render(double deltaTime)
{
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer, 128, 128, 128, 255);
	SDL_RenderCopy(renderer, player1->texture, NULL, &player1->sprite);
	SDL_RenderCopy(renderer, player2->texture, NULL, &player2->sprite);
	SDL_RenderCopy(renderer, ball->texture, NULL, &ball->sprite);
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


