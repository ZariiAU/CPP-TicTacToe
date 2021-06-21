#include "PlayerDatabase.h"

void PlayerDatabase::Init()
{
	// Load database from file
	ifstream fileIn;
	fileIn.open("PlayerData.dat", ios::in | ios::binary); // Open file

	if (fileIn.good()) { // Check if the stream is good
		unsigned int temp = 0;

		fileIn.read((char*)&temp, sizeof(unsigned int));
		leaderboard.SetPlayersInUse(temp);

		fileIn.read((char*)leaderboard.playerList, sizeof(Player) * leaderboard.GetPlayersInUse());

	}
	else
		cout << "Failed to Load File.";
		return;

	fileIn.close();

}

void PlayerDatabase::Shutdown()
{
	cout << "Yo." << endl;
}

void PlayerDatabase::Draw()
{
	system("cls");
	displayMenu();
	parseUserInput();

}

void PlayerDatabase::Update()
{
}

void PlayerDatabase::Save()
{
	// Save database to file
	ofstream fileOut;
	fileOut.open("PlayerData.dat", ios::out | ios::binary); // Open file 

	if (fileOut.good()) { // Check if the stream is good
		unsigned int temp = leaderboard.GetPlayersInUse();

		fileOut.write((char*)&temp, sizeof(unsigned int));

		fileOut.write((char*)leaderboard.playerList, sizeof(Player) * leaderboard.GetPlayersInUse());
	}

	fileOut.close();
}

void PlayerDatabase::displayMenu()
{
	cout << "(C)reate New Player" << endl;
	cout << "(D)isplay Leaderboard" << endl;
	cout << "(S)earch Player" << endl;
	cout << "(U)pdate Player Data" << endl;
	cout << "(Q)uit" << endl;
}

void PlayerDatabase::parseUserInput()
{
	char input;

	cin >> input;

	if (cin.good()) {
		switch (input)
		{
		case 'Q':
		case 'q':
			PlayerDatabase::Shutdown();
			break;
		case 'C':
		case 'c':
			leaderboard.AddPlayer();
			Save();
			break;
		case 'D':
		case 'd':
			leaderboard.Draw();

			cin >> input;
			if (input == 'Q' || input == 'q') {
				return;
			}
			break;
		case 'U':
		case 'u':
			// Display all players
			// Select a player to modify
			// Modify data
			// Save data to file
			cout << "Updated";
			break;
		case 'S':
		case 's':
			// Binary search
			cout << "Searched";
			break;
		default:
			break;
			// Unknown
		}
	}
}
