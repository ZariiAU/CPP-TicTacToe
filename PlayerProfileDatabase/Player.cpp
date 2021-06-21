#include "Player.h"

using namespace std;

Player::Player()
{
	SetName("Default");
	SetHighscore(0);
}

Player::Player(const char* name, unsigned int highscore)
{
	SetName(name);
	SetHighscore(highscore);
}

Player::~Player() {

}

char* Player::GetName()
{
	return this->m_name;
}

unsigned int Player::GetHighscore()
{
	return this->m_highscore;
}

void Player::SetName(const char* name)
{
	strcpy_s(this->m_name, 50, name);
}

void Player::SetHighscore(const unsigned int highscore)
{
	this->m_highscore = highscore;
}

void Player::Draw()
{
	cout << GetName() << " : " << GetHighscore() << endl;
}
