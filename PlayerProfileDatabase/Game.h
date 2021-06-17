#pragma once
#include "PlayerBoard.h"
class Program
{
public:
	bool isRunning = true;
	Program();

	void Run();

protected:
	virtual void Init();
	virtual void Shutdown();
	virtual void Draw();
	virtual void Update();

private:
	PlayerBoard leaderboard;
};

