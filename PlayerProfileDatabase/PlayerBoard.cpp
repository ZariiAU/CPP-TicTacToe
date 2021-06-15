#include "PlayerBoard.h"

PlayerBoard::PlayerBoard(unsigned int maxPlayers)
	:m_maxPlayers(maxPlayers), m_used(0)
{
	if (m_maxPlayers <= 0)
		m_maxPlayers = 5;
	
	if (m_maxPlayers > 100)
		m_maxPlayers = 100;

	playerList = new Player[m_maxPlayers];
}

PlayerBoard::~PlayerBoard()
{
	delete[] playerList;
}
