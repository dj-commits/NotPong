#pragma once
#include <SDL.h>
#include "Vec2.h"
class Paddle
{
public:
	Paddle(SDL_Renderer* rend);
	~Paddle();
	void Move() {};
	SDL_Surface* image;
	SDL_Texture* texture;
	SDL_Rect sprite;
	Vec2 position;
private:
	bool isHuman;
	


};

