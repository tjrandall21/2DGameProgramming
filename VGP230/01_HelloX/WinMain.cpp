#include <XEngine.h>

X::TextureId imageId = 0;
X::Math::Vector2 imagePosition = { 0.0f, 0.0f };
float imageRotation = 0.0f;
float moveSpeed = 3.0f;
float xDirection = 1.0f;
float yDirection = 1.0f;
float spriteWidth = 111.0f;
float spriteHeight = 213.0f;
void GameInit()
{
	imageId = X::LoadTexture("sprite_can.png");
	imagePosition.x = X::GetScreenWidth() / 2;
	imagePosition.y = X::GetScreenHeight() / 2;

}

void MoveSprite()
{
	imagePosition.x += moveSpeed * xDirection;
	imagePosition.y += moveSpeed * yDirection;
}

void CheckWallBounce()
{
	if ((xDirection > 0 && imagePosition.x + (spriteWidth / 2) >= X::GetScreenWidth()) || (xDirection < 0 && imagePosition.x - (spriteWidth / 2) <= 0))
	{
		xDirection *= -1;
	}
	if ((yDirection > 0 && imagePosition.y + (spriteHeight / 2) >= X::GetScreenHeight()) || (yDirection < 0 && imagePosition.y - (spriteHeight / 2) <= 0))
	{
		yDirection *= -1;
	}
}

bool GameLoop(float deltaTime)
{
	X::DrawSprite(imageId, imagePosition,imageRotation);
	CheckWallBounce();
	MoveSprite();
	return X::IsKeyPressed(X::Keys::ESCAPE);
}

void GameCleanup()
{
	XLOG("Game cleanup");
}

int CALLBACK WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	X::Start("config.json");
	GameInit();
	X::Run(GameLoop);
	GameCleanup();
	X::Stop();
	return 0;
}