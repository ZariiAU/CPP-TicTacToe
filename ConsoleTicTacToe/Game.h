#pragma once
#include <iostream>
#include <stdlib.h>
#include "Board.h"

using namespace std;

class Game
{
	
public:
	Board board;
	bool isRunning = true;
	bool boardFull = false;

	bool isNaughtTurn = true; // false = X // true = O

	void Run(); 

	void TakeTurn();

	void Shutdown();

	void DrawCondition(); // Runs when game ends in stalemate

	void Refresh();

	void CheckWin();

	bool checkRow(int row, char token);
	
	bool checkCol(int row, char token);

	void WinCondition(const char winner);

	bool CheckBoardFull();
};

