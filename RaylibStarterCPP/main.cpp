#include "raylib.h"
#include <iostream>

#define RAYGUI_IMPLEMENTATION
#define RAYGUI_SUPPORT_ICONS
#include "raygui.h"
#include "Game.h"

namespace TicTacToe {

    int main(int argc, char* argv[])
    {
        Game game;

        game.Run();

        std::cout << "Game Over" << std::endl;

        return 0;

    };
}