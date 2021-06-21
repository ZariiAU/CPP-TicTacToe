#include "Player.h"
#pragma once
class PlayerBoard
{
public:
	PlayerBoard(unsigned int maxPlayers = 5);

	~PlayerBoard();

	void Draw(bool drawTitleCard, bool clearScreenBeforeDraw); // Booleans control title card existence and if it clears the screen

	unsigned int GetMaxPlayers();
	unsigned int GetPlayersInUse();
	void SetPlayersInUse(unsigned int numberOfPlayers);

	void AddPlayer();

	Player* playerList = nullptr;

private:
	unsigned int m_maxPlayers = 0;
	unsigned int m_used = 0;
};