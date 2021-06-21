#include "PlayerDatabase.h"

void PlayerDatabase::Init()
{
	Load("PlayerData.dat");
	BubbleSort();
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

// Save database to file
void PlayerDatabase::Save(const char* file)
{
	ofstream fileOut;
	fileOut.open(file, ios::out | ios::binary); // Open file 

	if (fileOut.good()) { // Check if the stream is good
		unsigned int temp = leaderboard.GetPlayersInUse();

		fileOut.write((char*)&temp, sizeof(unsigned int));

		fileOut.write((char*)leaderboard.playerList, sizeof(Player) * leaderboard.GetPlayersInUse());
	}

	fileOut.close();
}

// Load database from file
void PlayerDatabase::Load(const char* file)
{
	ifstream fileIn;
	fileIn.open(file, ios::in | ios::binary); // Open file

	if (fileIn.good()) { // Check if the stream is good
		unsigned int temp = 0;

		fileIn.read((char*)&temp, sizeof(unsigned int));
		leaderboard.SetPlayersInUse(temp);

		fileIn.read((char*)leaderboard.playerList, sizeof(Player) * leaderboard.GetPlayersInUse());
	}
	
	else
		cout << "Failed to Load File.";

	fileIn.close();
}

void PlayerDatabase::BubbleSort()
{
	if (leaderboard.GetPlayersInUse() <= 1) return;

	Player temp;

	bool sorted = false;
	while (!sorted) {
		sorted = true;
		for (int i = 0; i < leaderboard.GetPlayersInUse() - 1; i++) {
			if (strcmp(leaderboard.playerList[i].GetName(), leaderboard.playerList[i+1].GetName()) > 0) {
				temp = leaderboard.playerList[i];
				leaderboard.playerList[i] = leaderboard.playerList[i + 1];
				leaderboard.playerList[i + 1] = temp;
				sorted = false;
			}
			
		}
	}
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
			BubbleSort();
			Save("PlayerData.dat");
			
			break;
		case 'D':
		case 'd':
			leaderboard.Draw(true, true);

			cin >> input;
			if (input == 'Q' || input == 'q') {
				return;
			}
			break;
		case 'U':
		case 'u':
			system("cls");
			cout << "Enter the name of the player you wish to edit: \n" << endl;
			leaderboard.Draw(false, false);
			
			int newScore;
			char newName[MAX_NAME_SIZE];

			char nameToEdit[MAX_NAME_SIZE];
			cin >> nameToEdit;

			for (unsigned int i = 0; i < leaderboard.GetPlayersInUse(); i++) {
				if (strcmp(nameToEdit, leaderboard.playerList[i].GetName()) == 0) {
					system("cls");
					cout << "Enter new name:" << endl;
					cin >> newName;
					leaderboard.playerList[i].SetName(newName);

					system("cls");
					cout << "Enter new score:" << endl;
					cin >> newScore;
					leaderboard.playerList[i].SetHighscore(newScore);
					Save("PlayerData.dat");
				}
			}
			if (input == 'Q' || input == 'q') {
				return;
			}
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
