#include <iostream>
#include "Token.h"

#pragma once
class Board
{
public:
	static constexpr int xSize = 3;
	static constexpr int ySize = 3;

	bool hasDrawn = false;

	Token boardSlots[xSize][ySize];

	Board() {}

	void Create();

	void Draw();

	void Reset();

	bool CheckOccupied(int xToCheck, int yToCheck);

	void setToken(int xToCheck, int yToCheck, char type);
	
};