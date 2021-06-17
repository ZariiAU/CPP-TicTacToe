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
	leaderboard.Draw();

}

void PlayerDatabase::Update()
{
}

void PlayerDatabase::displayMenu()
{
}

void PlayerDatabase::parseUserInput()
{
}
