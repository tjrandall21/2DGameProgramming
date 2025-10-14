#pragma once
#include <XEngine.h>
class BouncingSprite
{
private:
	X::TextureId id;
	X::Math::Vector2 position;
	float rotation;
	float xSpeed;
	float ySpeed;
	float width;
	float height;
public:
	BouncingSprite();
	void Init(const char * fileName,float xCoord,float yCoord,float speedX,float speedY);
	void Step();
	void Draw();
};