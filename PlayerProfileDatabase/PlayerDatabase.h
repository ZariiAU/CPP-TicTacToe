#pragma once
#include <fstream>
#include "Game.h"
#include "PlayerBoard.h"

class PlayerDatabase :
    public Program
{
public:

protected:
	virtual void Init() override;
	virtual void Shutdown() override;
	virtual void Draw() override;
	virtual void Update() override;
	void Save();

private:
	PlayerBoard leaderboard;

	void displayMenu();
	void parseUserInput();
};

