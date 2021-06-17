#include "Player.h"
#pragma once
class PlayerBoard
{
public:
	PlayerBoard(unsigned int maxPlayers = 5);

	~PlayerBoard();

	void Draw();

	unsigned int GetMaxPlayers();
	unsigned int GetPlayersInUse();

	void SetPlayersInUse(unsigned int numberOfPlayers);

	Player* playerList = nullptr;

private:
	unsigned int m_maxPlayers = 0;
	unsigned int m_used = 0;
};