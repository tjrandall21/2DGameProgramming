#include <XEngine.h>
#include "BouncingSprite.h"
BouncingSprite spriteCan = BouncingSprite();
BouncingSprite qBlock = BouncingSprite();

void GameInit()
{
	spriteCan.Init("sprite_can.png",X::GetScreenWidth()/4, X::GetScreenHeight()/4, -4.5f, -2.5f);
	qBlock.Init("qmark.png", X::GetScreenWidth()*3 / 4, X::GetScreenHeight()*3 / 4, 3.0f, 5.0f);
}

bool GameLoop(float deltaTime)
{
	spriteCan.Step();
	spriteCan.Draw();
	qBlock.Step();
	qBlock.Draw();
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