#include <iostream>
#include <string>
#include "Player.h"
#pragma once
class PlayerBoard
{
public:
	PlayerBoard(unsigned int maxPlayers = 5);

	~PlayerBoard();

private:
	Player* playerList = nullptr;

	unsigned int m_maxPlayers = 0;
	unsigned int m_used = 0;
};