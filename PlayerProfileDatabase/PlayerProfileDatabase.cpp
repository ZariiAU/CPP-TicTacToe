#include <iostream>
#include <fstream>
#include "PlayerBoard.h"
#include "PlayerDatabase.h"
#include "Player.h"

using namespace std;

int main()
{
    cout << "Database" << endl;

    PlayerDatabase database;
    database.Run();
}
