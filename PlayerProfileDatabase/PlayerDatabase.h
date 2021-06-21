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
	void Save(const char* file);
	void Load(const char* file);
	void BubbleSort();

private:
	PlayerBoard leaderboard;

	void displayMenu();
	void parseUserInput();
};

