#include <iostream>
#include "Player.h"

int main()
{
    Player p;

    p.SetName("Jorgeanon");
    p.SetHighscore(4903874);

    cout << p.GetName() << endl;
    cout << p.GetHighscore();
}
