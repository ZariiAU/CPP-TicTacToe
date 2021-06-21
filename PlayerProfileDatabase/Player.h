#pragma once
#include <string>
#include <iostream>

const unsigned int MAX_NAME_SIZE = 50;

class Player
{
private:
	char m_name[MAX_NAME_SIZE];
	int m_highscore;

public:
	Player();
	Player(const char* name, unsigned int highscore);

	~Player();

	char* GetName();
	unsigned int GetHighscore();
	void SetName(const char* name);
	void SetHighscore(unsigned int highscore);

	void Draw();
};


