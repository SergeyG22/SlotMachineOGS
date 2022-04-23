#include <SFML/Graphics.hpp>
#include "../include/Facades/game.h"

int main() {
    std::unique_ptr<Game>game = std::make_unique<Game>();
    game->gameLoop();
    return 0;
}