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

	ballSpeed = 10.0f;
	velocity = new Vec2(ballSpeed, ballSpeed);
}

void Ball::Move(double deltaTime)
{
	
	int screenWidth = 800;
	int screenHeight = 600;

	// If moving right, and going out of the screen bounds
	if(sprite.x + (velocity->x + sprite.w) > screenWidth)
	{
		velocity->x *= -1;
	}
	if(sprite.x + (velocity->x + sprite.w) < 0)
	{
		velocity->x *= -1;
	}
	if (sprite.y + (velocity->y + sprite.h) > screenHeight)
	{
		velocity->y *= -1;
	}
	if (sprite.y + (velocity->y + sprite.h) < 0)
	{
		velocity->y *= -1;
	}
	sprite.x += velocity->x * deltaTime;
	sprite.y += velocity->y * deltaTime;
}