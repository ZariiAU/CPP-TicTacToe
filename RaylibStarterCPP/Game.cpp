#include "Game.h"
#include "raylib.h"

namespace TicTacToe {
	Game::Game() {

	}

	void Game::Run()
	{
		InitWindow(1280, 720, "Tic Tac Toe");
		Init();

		while (!WindowShouldClose())    // Detect window close button or ESC key
		{
		    Update();
		    Draw();
		}

		Shutdown();

		CloseWindow();
	}

	void Game::Init()
	{
	}

	void Game::Update()
	{
	}

	void Game::Draw()
	{
	}

	void Game::Shutdown()
	{
	}

}