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

void PlayerBoard::Draw()
{
	system("cls");
	cout << "###################" << endl;
	cout << "Leaderboards!" << endl;
	cout << "###################" << endl;

	if (!GetPlayersInUse() == 0) {
		for (unsigned int i = 0; i < m_used; i++) {
			playerList[i].Draw();
		}
	}
	else {
		cout << " \n No Players Found." << endl;
	}
	cout << "(Q)uit" << endl;
}

unsigned int PlayerBoard::GetMaxPlayers()
{
	return m_maxPlayers;
}

unsigned int PlayerBoard::GetPlayersInUse()
{
	return m_used;
}

void PlayerBoard::SetPlayersInUse(unsigned int numberOfPlayers)
{
	m_used = numberOfPlayers;
}
