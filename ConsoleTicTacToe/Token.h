#pragma once
class Token
{
public:
	char type;

	// Store possible token condition
	static constexpr char empty = ' ';
	static constexpr char naught = 'O';
	static constexpr char cross = 'X';

	Token(){
		this->type = empty;
	}

	~Token() {}

	char getType();
	void setType(char type);
	
};

