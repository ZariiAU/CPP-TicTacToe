#pragma once
#include <string>
#include <iostream>

using namespace std;

class Player
{
private:
	char m_name[50];
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


