#include <iostream>
#include <fstream>
#include "Player.h"
#include "DynamicArray.h"

int main()
{
    DynamicArray<Player> m_players (10);

    char userInput;
    bool hasCompleted = false;

    string filename = "playerData.dat";

    fstream file(filename, ios::out | ios::binary);
    file.seekg(0, ios::beg);

    Player n;

    m_players.AddToArray(n);

    file.write((char*)m_players.data(), (unsigned int)m_players.size() * sizeof(Player));

    file.close();

    fstream fileIn(filename, ios::in | ios::binary);

    cout << m_players.data();
    //while (!hasCompleted) {
    //    try {
    //        ifstream file(filename, ios::in | ios::binary);
    //        file.seekg(0, ios::beg);

    //        for (int i = 0; i < m_players.used(); i++) {
    //            file.read((char*)m_players.data(), (unsigned int)m_players.size() * sizeof(Player));
    //        }
    //    }
    //    catch(exception e){
    //        cout << "failed to load file";
    //    }

    //    cout << "What would you like to do?" << endl;
    //    cout << "(S)earch" << endl << "(A)dd new player" << "(Q)uit";

    //    try {
    //        cin >> userInput; // Get user input

    //        switch (userInput) {
    //        case 'A':
    //            // ADD PLAYER HERE
    //            break;
    //        case 'S':
    //            // BINARY SEARCH FOR PLAYER
    //            break;
    //        case 'Q':
    //            // QUIT
    //            hasCompleted = true;
    //            break;
    //        }
    //    }
    //    catch (exception e) {
    //        cout << "nope";
    //    }
    //}
}
