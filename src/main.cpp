#include <SFML/Graphics.hpp>
#include "../include/Facades/game.h"
#include "../include/Backend/timer.h"


int main() {
    setlocale(LC_ALL, "russian");
    std::unique_ptr<Game>game = std::make_unique<Game>();
    game->gameLoop();
    return 0;
}