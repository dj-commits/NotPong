#include "Paddle.h"
#include "Vec2.h"
#include <SDL_image.h>

Paddle::Paddle(SDL_Renderer* rend)
{
	image = IMG_Load("pong_paddle.png");
	texture = SDL_CreateTextureFromSurface(rend, image);
	SDL_FreeSurface(image);
	SDL_QueryTexture(texture, NULL, NULL, &sprite.w, &sprite.h);
	sprite.x = 250;
	sprite.y = 250;
}
