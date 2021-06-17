#include "Game.h"

Program::Program()
{
}

void Program::Run()
{
	Init();

	while (isRunning) {
		Update();
		Draw();
	}

	Shutdown();
}

void Program::Init()
{
}

void Program::Shutdown()
{
	cout << "Thanks for playing!";
}

void Program::Draw()
{
}

void Program::Update()
{
}

