#include "Ball.h"
#include <stdio.h>
#include <SDL_image.h>

Ball::Ball(SDL_Renderer* rend)
{
	image = IMG_Load("pong_ball.png");
	if (!image)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	texture = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(texture, NULL, NULL, &sprite.w, &sprite.h);
}

void Ball::Move(Uint64 deltaTime)
{
	Vec2 *velocity = new Vec2(1, 1);
	sprite.x += velocity->x;
	sprite.y += velocity->y;
}