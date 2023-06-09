#pragma once
#include <SDL.h>
#include "Vec2.h"

class Ball
{
public:
	Ball(SDL_Renderer* rend);
	~Ball();
	void Move() {};
	SDL_Surface* image;
	SDL_Texture* texture;
	SDL_Rect sprite;
	Vec2 position;
	Vec2 *velocity;
	void Move(double deltaTime);

private:
	float ballSpeed;

};

