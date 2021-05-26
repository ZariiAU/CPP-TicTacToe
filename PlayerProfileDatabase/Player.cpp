#include "Player.h"

char* Player::GetName()
{
	return this->name;
}

int Player::GetHighscore()
{
	return this->highscore;
}

void Player::SetName(const char* name)
{
	strcpy_s(this->name, 10, name);
}

void Player::SetHighscore(const int highscore)
{
	this->highscore = highscore;
}