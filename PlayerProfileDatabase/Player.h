#pragma once

#include <string>
#include <iostream>

using namespace std;

class Player
{
private:
	char name[10];
	int highscore;

public:
	char* GetName();
	int GetHighscore();
	void SetName(const char* name);
	void SetHighscore(int highscore);

};


