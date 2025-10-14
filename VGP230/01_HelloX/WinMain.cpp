#include <XEngine.h>
#include "BouncingSprite.h"
BouncingSprite mario = BouncingSprite();
BouncingSprite qBlock = BouncingSprite();

void GameInit()
{
	mario.Init("mario.png",X::GetScreenWidth()/4, X::GetScreenHeight()/4, -2.5f, -1.5f);
	qBlock.Init("qmark.png", X::GetScreenWidth()*3 / 4, X::GetScreenHeight()*3 / 4, 3.0f, 5.0f);
}

bool GameLoop(float deltaTime)
{
	mario.Step();
	mario.Draw();
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