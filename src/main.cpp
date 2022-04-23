#include <SFML/Graphics.hpp>
#include "../include/Facades/game.h"

int main() {
    std::unique_ptr<Game>game = std::make_unique<Game>();
    game->gameLoop();
    /*
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        window.display();
    }
    */


    return 0;
}