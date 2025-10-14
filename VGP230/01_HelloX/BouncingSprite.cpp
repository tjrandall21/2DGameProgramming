#include "BouncingSprite.h"

BouncingSprite::BouncingSprite()
{
	id = 0;
	position = { 0.0f,0.0f };
	rotation = 0.0f;
	xSpeed = 0.0f;
	ySpeed = 0.0f;
	width = 0.0f;
	height = 0.0f;
}
void BouncingSprite::Init(const char * fileName, float xCoord,float yCoord, float speedX = 3.0f, float speedY = 3.0f)
{
	id = X::LoadTexture(fileName);
	position = {xCoord,yCoord};
	xSpeed = speedX;
	ySpeed = speedY;
	height = X::GetSpriteHeight(id);
	width = X::GetSpriteWidth(id);
}
void BouncingSprite::Step()
{
	if ((xSpeed > 0 && position.x + (width / 2) >= X::GetScreenWidth()) || (xSpeed < 0 && position.x - (width / 2) <= 0))
	{
		xSpeed *= -1;
	}
	if ((ySpeed > 0 && position.y + (height / 2) >= X::GetScreenHeight()) || (ySpeed < 0 && position.y - (height / 2) <= 0))
	{
		ySpeed *= -1;
	}
	position.x += xSpeed;
	position.y += ySpeed;
}
void BouncingSprite::Draw()
{
	X::DrawSprite(id, position, rotation);
}