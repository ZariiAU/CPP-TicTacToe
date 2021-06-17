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

		if (temp == 0) {
			cout << "No Players in Database." << endl;
		}

		for (unsigned int i = 0; i < leaderboard.GetPlayersInUse(); i++) { // For each used player slot, read their data

			fileIn.read((char*)leaderboard.playerList->GetHighscore(), sizeof(unsigned int));
			fileIn.read((char*)leaderboard.playerList->GetName(), sizeof(char*));
		}
	}

	fileIn.close();

}

void PlayerDatabase::Shutdown()
{
	// Save database to file
	ofstream fileOut;
	fileOut.open("PlayerData.dat", ios::out | ios::binary); // Open file 

	if (fileOut.good()) { // Check if the stream is good
		fileOut.write((char*)leaderboard.GetPlayersInUse(), sizeof(unsigned int));

		for (unsigned int i = 0; i < leaderboard.GetPlayersInUse(); i++) { // For each used player slot, read their data
			fileOut.write((char*)leaderboard.playerList[i].GetHighscore(), sizeof(unsigned int));
			fileOut.write((char*)leaderboard.playerList[i].GetName(), sizeof(char*));
		}
	}

	fileOut.close();
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

	switch (input) {
	case 'Q':
		PlayerDatabase::Shutdown();

	case 'C':
		char playerNameTemp[50];
		unsigned int playerScoreTemp;
		
		cout << "#####################" << endl;
		cout << "## Player Creation ##" << endl;
		cout << "#####################" << endl;

		cout << "\nEnter Player Name:" << endl; 

		cin >> (char*)playerNameTemp; // Ask for name input and set a temp variable to hold it until Player class is created

		system("cls");

		//if (cin.good()) {
		//	cout << "Enter Player Score:" << endl;
		//	cin >> playerScoreTemp; // Ask for score input and set a temp variable to hold it until Player class is created

		//	system("cls");

		//}
		
		return;

	case 'D':
		// Display leaderboard
		leaderboard.Draw();

		cin >> input;
		if (input == 'Q') {
			return;
		}

	case 'U':
		// Display all players
		// Select a player to modify
		// Modify data
		// Save data to file
		cout << "Updated";

	case 'S':
		// Binary search
		cout << "Searched";
	}
}
