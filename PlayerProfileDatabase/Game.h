#pragma once
#include "PlayerBoard.h"
class Game
{
public:
	bool isRunning = true;
	Game();

	void Run();

protected:
	virtual void Init();
	virtual void Shutdown();
	virtual void Draw();
	virtual void Update();

private:
	PlayerBoard leaderboard;
};

