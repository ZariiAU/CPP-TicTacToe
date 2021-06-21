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

// Draw function for the leaderboard
void PlayerBoard::Draw(bool drawTitleCard, bool clearScreenBeforeDraw)
{
	if(clearScreenBeforeDraw)
		system("cls");

	if (drawTitleCard) {
		cout << "###################" << endl;
		cout << "## Leaderboards! ##" << endl;
		cout << "###################\n" << endl;
	}

	// Loop through players in use and draw their info for the screen
	if (!GetPlayersInUse() == 0) {
		for (unsigned int i = 0; i < m_used; i++) {
			cout << i+1 << "] ";
			playerList[i].Draw();
		}
	}
	// If there are no players, do this.
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

// Create a player
void PlayerBoard::AddPlayer()
{ 
	char playerNameTemp[50]; // Set a temporary variable to hold the data until Player class is created
	unsigned int playerScoreTemp = 0; // ..

	system("cls");

	cout << "#####################" << endl;
	cout << "## Player Creation ##" << endl;
	cout << "#####################" << endl;

	cout << "\nEnter Player Name:" << endl;

	cin >> (char*)playerNameTemp; // Ask for name input 

	system("cls");

	cout << "\nEnter Player Score:" << endl;

	cin >> playerScoreTemp; // Ask for score input

	// Check if stream is good.
	while(!cin.good()){
		// Clear the console-in buffer
		cin.clear();
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		
		system("cls");
		cout << "\nEnter Player Score:" << endl;
		cin >> playerScoreTemp;
	}

	// Add a new player to the array with values from above
	playerList[GetPlayersInUse()] = Player(playerNameTemp, playerScoreTemp);

	// Increment Players in Use by 1
	SetPlayersInUse(GetPlayersInUse() + 1);
}
