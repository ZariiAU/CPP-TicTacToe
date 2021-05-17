#include "Board.h"
#include "Game.h"

//Define Escape Codes for ~fanciness~
#define UNDERLINE "\033[4m" // Underline
#define CLOSEUNDERLINE "\033[0m"
#define RSTCLR "\033[37m" // Reset Colour
#define RED "\033[31m" // Red
#define CYN "\033[36m" // Cyan

using namespace std;

// Create a new board with default values
void Board::Create()
{
	Board board;
}

// Draw the game board
void Board::Draw()
{
	cout << "     |  " << "    |  " << endl;
	cout << "  " << boardSlots[0][0].getType() << "  |   " << boardSlots[1][0].getType() << "  |   " << boardSlots[2][0].getType() << endl;
	cout << " " << UNDERLINE << "    |  " << "    |    " << CLOSEUNDERLINE << endl;
	cout << "     |  " << "    |   " << endl;
	cout << "  " << boardSlots[0][1].getType() << "  |   " << boardSlots[1][1].getType() << "  |   " << boardSlots[2][1].getType() << endl;
	cout << " " << UNDERLINE << "    |  " << "    |    " << CLOSEUNDERLINE << endl;
	cout << "     |  " << "    |   " << endl;
	cout << "  " << boardSlots[0][2].getType() << "  |   " << boardSlots[1][2].getType() << "  |   " << boardSlots[2][2].getType() << endl;
	cout << "     |  " << "    |   " << endl << endl;
}

void Board::Reset()
{
	for (int x = 0; x < this->xSize; x++)
	{
		for (int y = 0; y < this->ySize; y++)
		{
			boardSlots[x][y].setType(Token::empty);
		}
	}
}


// Check if token in position = empty
bool Board::CheckOccupied(int xToCheck, int yToCheck)
{
	if (boardSlots[xToCheck][yToCheck].getType() == Token::empty) {
		return false;
	}
	else
		return true;
}

// Set token in position to type passed in
void Board::setToken(int xToCheck, int yToCheck, char type)
{
	if (type == Token::naught)
		boardSlots[xToCheck][yToCheck].setType(type);

	else if (type == Token::cross)
		boardSlots[xToCheck][yToCheck].setType(type);

	else {
	}
}


