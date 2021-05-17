#include "Game.h"
#include "Board.h"

#define UNDERLINE "\033[4m" // Underline
#define CLOSEUNDERLINE "\033[0m"
#define RSTCLR "\033[37m" // Reset Colour
#define RED "\033[31m" // Red
#define CYN "\033[36m" // Cyan

int input;
bool won = false;

// MAIN GAME LOOP
void Game::Run()
{
	while (!boardFull) {
		// Check for Wins
		CheckWin(Token::cross);
		CheckWin(Token::naught);

		CheckBoardFull(); // Check if board is full

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

	if (!Game::isNaughtTurn) {
		cout << RED << UNDERLINE <<"\Cross's Turn\n" << RSTCLR << CLOSEUNDERLINE << endl;
	}
	else
		cout << CYN << UNDERLINE << "\Naught's Turn\n" << RSTCLR << CLOSEUNDERLINE << endl;

	board.Draw();
}

void Game::CheckWin(char token)
{
	// CHECK ROW WIN CONDITION
	for (int row = 0; row < board.xSize; row++)
	{
		if (checkRow(row, token)) {
			WinCondition(token);
		}
	}

	// CHECK COLUMN WIN CONDITION
	for (int col = 0; col < board.ySize; col++)
	{
		if (checkCol(col, token)) {
			WinCondition(token);
		}
	}

	// CHECK RIGHT DIAGONAL WIN CONDITION
	if (board.boardSlots[0][2].getType() == token &&
		board.boardSlots[1][1].getType() == token &&
		board.boardSlots[2][0].getType() == token) {

		WinCondition(token);
	}

	// CHECK LEFT DIAGONAL WIN CONDITION
	if (board.boardSlots[0][0].getType() == token &&
		board.boardSlots[1][1].getType() == token&&
		board.boardSlots[2][2].getType() == token) {

		WinCondition(token);
	}
}

bool Game::checkCol(int col, char token)
{
	return token == board.boardSlots[col][0].getType() &&
		token == board.boardSlots[col][1].getType() &&
		token == board.boardSlots[col][2].getType();
}

bool Game::checkRow(int row, char token)
{
	return token == board.boardSlots[0][row].getType() &&
		token == board.boardSlots[1][row].getType() &&
		token == board.boardSlots[2][row].getType();
}

void Game::WinCondition(const char winner)
{
	int playAgainInput;
	won = true;

	system("cls");
	cout << winner << " Wins!";
	cout << "Play again? \n 1. Yes \n 2. No \n";

	cin >> playAgainInput;

	switch (playAgainInput) {
	case 1:
		board.Reset();
		Refresh();
		boardFull = false;
		won = false;
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

