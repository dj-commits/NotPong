//
//
// Game.hpp
// Game Engine Test
// Donald Jones, 2023
//
//
//
//


#ifndef Game_hpp
#define Game_hpp
#define SDL_MAIN_HANDLED
#include "SDL.h"
#include <iostream>

class Game
{
public:
	Game();
	~Game();

	void init(const char* title, int xPos, int yPos, int width, int height, bool fullscreen);
	void handleEvents();
	void update();
	void render();
	void clean();

	bool isRunning() { return running; }

private:
	int cnt;
	bool running;

	SDL_Window* window;
	SDL_Renderer* renderer;
};







#endif /* Game_hpp */

