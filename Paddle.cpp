#include "Paddle.h"
#include "Vec2.h"
#include <SDL_image.h>
#include <stdio.h>

Paddle::Paddle(SDL_Renderer* rend)
{
	image = IMG_Load("pong_paddle.png");
	if (!image)
	{
		printf("IMG_Load: %s\n", IMG_GetError());
	}
	texture = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(texture, NULL, NULL, &sprite.w, &sprite.h);
	
}
