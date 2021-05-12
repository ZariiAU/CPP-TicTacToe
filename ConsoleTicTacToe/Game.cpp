#include "Game.h"
#include "Board.h"

/* TO FIX
CheckWin();

*/

int input;

// MAIN GAME LOOP
void Game::Run()
{
	while (!boardFull) {
		CheckWin();
		CheckBoardFull();
		if (CheckBoardFull())
			DrawCondition();
		else {
			Refresh();
			TakeTurn();
			Refresh();
		}
	}
}

void Game::TakeTurn()
{
	// CROSS'S TURN
	while (!isNaughtTurn && !boardFull) {
		cout << "\Cross's Turn \n";
		cout << "Pick a spot \n 1, 2, 3 \n 4, 5, 6 \n 7, 8, 9 \n";

		cin >> input;

		switch (input) {
		case 1:
			while (!board.CheckOccupied(0, 0)) { // Check if board slot 0,0 is occupied
				board.setToken(0, 0, Token::cross); // Set the value of 0,0 to 'X'
			}
			break;
		case 2:
			while (!board.CheckOccupied(1, 0)) {
				board.setToken(1, 0, Token::cross);
			}
			break;
		case 3:
			while (!board.CheckOccupied(2, 0)) {
				board.setToken(2, 0, Token::cross);
			}
			break;
		case 4:
			while (!board.CheckOccupied(0, 1)) {
				board.setToken(0, 1, Token::cross);
			}
			break;
		case 5:
			while (!board.CheckOccupied(1, 1)) {
				board.setToken(1, 1, Token::cross);
			}
			break;
		case 6:
			while (!board.CheckOccupied(2, 1)) {
				board.setToken(2, 1, Token::cross);
			}
			break;
		case 7:
			while (!board.CheckOccupied(0, 2)) {
				board.setToken(0, 2, Token::cross);
			}
			break;
		case 8:
			while (!board.CheckOccupied(1, 2)) {
				board.setToken(1, 2, Token::cross);
			}
			break;
		case 9:
			while (!board.CheckOccupied(2, 2)) {
				board.setToken(2, 2, Token::cross);
			}
			break;
		}
		isNaughtTurn = true; // Switch turns
		return;
	}

	// NAUGHT'S TURN
	while (isNaughtTurn && !boardFull) {
		cout << "\Naught's Turn \n";
		cout << "Pick a spot \n 1, 2, 3 \n 4, 5, 6 \n 7, 8, 9 \n";

		cin >> input;

		switch (input) {
		case 1:
			while (!board.CheckOccupied(0, 0)) {
				board.setToken(0, 0, Token::naught);
			}
			break;
		case 2:
			while (!board.CheckOccupied(1, 0)) {
				board.setToken(1, 0, Token::naught);
			}
			break;
		case 3:
			while (!board.CheckOccupied(2, 0)) {
				board.setToken(2, 0, Token::naught);
			}
			break;
		case 4:
			while (!board.CheckOccupied(0, 1)) {
				board.setToken(0, 1, Token::naught);
			}
			break;
		case 5:
			while (!board.CheckOccupied(1, 1)) {
				board.setToken(1, 1, Token::naught);
			}
			break;
		case 6:
			while (!board.CheckOccupied(2, 1)) {
				board.setToken(2, 1, Token::naught);
			}
			break;
		case 7:
			while (!board.CheckOccupied(0, 2)) {
				board.setToken(0, 2, Token::naught);
			}
			break;
		case 8:
			while (!board.CheckOccupied(1, 2)) {
				board.setToken(1, 2, Token::naught);
			}
			break;
		case 9:
			while (!board.CheckOccupied(2, 2)) {
				board.setToken(2, 2, Token::naught);
			}
			break;
		}
		isNaughtTurn = false; // Switch turns
	}
}

// To run before program ends
void Game::Shutdown()
{
	cout << "Thanks for playing!";
	exit;
}

// Clears screen and redraws the board
void Game::Refresh()
{
	system("cls");
	board.Draw();
}

void Game::CheckWin()
{
	for (int row = 0; row < board.xSize; row++)
	{
		for (int col = 0; col < board.xSize; col++)
		{
			if (board.boardSlots[row][col].getType() == Token::cross) {
				WinCondition(Token::cross);
			}
			else if (board.boardSlots[row][col].getType() == Token::naught) {
				WinCondition(Token::naught);
			}
		}
	}

	
}

void Game::WinCondition(const char winner)
{
	system("cls");
	cout << winner << " Wins!";
	cout << "Play again? \n 1. Yes \n 2. No \n";

	cin >> input;

	switch (input) {
	case 1:
		board.Reset();
		Refresh();
		boardFull = false;
		break;
	case 2:
		Shutdown();
	}
	return;
}

// Runs when the board is full and there are no winners
void Game::DrawCondition()
{
	system("cls");
	cout << "DRAW!" << endl;
	cout << "Play again? \n 1. Yes \n 2. No \n";

	cin >> input;

	switch (input) {
	case 1:
		board.Reset();
		Refresh();
		boardFull = false;
		break;
	case 2:
		Shutdown();
	}
	return;
}

// Iterates through the 2D array of boardslots and checks if they're empty
bool Game::CheckBoardFull()
{
	boardFull = true;
	for (int x = 0; x < board.xSize; x++)
	{
		for (int y = 0; y < board.ySize; y++)
		{
			if (board.boardSlots[x][y].getType() == Token::empty)
			{
				boardFull = false;
				return false;
			}
		}
	}	
}

