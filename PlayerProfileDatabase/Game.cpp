#include "Game.h"

void Game::Run()
{
	Init();

	while (isRunning) {
		Update();
		Draw();
	}

	Shutdown();
}

void Game::Shutdown()
{
	cout << "Thanks for playing!";
}

