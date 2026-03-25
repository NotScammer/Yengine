#include "../include/Game.hpp"

int main() {
    Game game;

    if (game.Initialize()) {
        game.Run();
    }

    //Any type of multiplayer (tcp-udp-websockets) communication should be on the main.cpp

    return 0;
}
