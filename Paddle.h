#pragma once
#include <SDL.h>
class Paddle
{
public:
	Paddle(SDL_Renderer* rend);
	~Paddle();
	void Move() {};
	SDL_Surface* image;
	SDL_Texture* texture;
	SDL_Rect sprite;
private:
	bool isHuman;
	


};

