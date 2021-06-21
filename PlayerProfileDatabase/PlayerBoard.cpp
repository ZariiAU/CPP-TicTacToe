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

void PlayerBoard::Draw(bool drawTitleCard, bool clearScreenBeforeDraw)
{
	if(clearScreenBeforeDraw)
		system("cls");

	if (drawTitleCard) {
		cout << "###################" << endl;
		cout << "## Leaderboards! ##" << endl;
		cout << "###################\n" << endl;
	}

	if (!GetPlayersInUse() == 0) {
		for (unsigned int i = 0; i < m_used; i++) {
			cout << i+1 << "] ";
			playerList[i].Draw();
		}
	}
	else {
		cout << " \n No Players Found." << endl;
	}
	cout << "\n(Q)uit" << endl;
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

void PlayerBoard::AddPlayer()
{
	char playerNameTemp[50];
	unsigned int playerScoreTemp = 0;

	system("cls");

	cout << "#####################" << endl;
	cout << "## Player Creation ##" << endl;
	cout << "#####################" << endl;

	cout << "\nEnter Player Name:" << endl;

	cin >> (char*)playerNameTemp; // Ask for name input and set a temp variable to hold it until Player class is created

	system("cls");

	cout << "\nEnter Player Score:" << endl;

	cin >> playerScoreTemp;

	while(!cin.good()){
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		system("cls");
		cout << "\nEnter Player Score:" << endl;
		cin >> playerScoreTemp;
	}

	playerList[GetPlayersInUse()] = Player(playerNameTemp, playerScoreTemp);

	SetPlayersInUse(GetPlayersInUse() + 1);
}
