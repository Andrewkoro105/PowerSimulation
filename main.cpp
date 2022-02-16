#include <SFML/Graphics.hpp>
#include <vector>
#include "Game.h"

int main()
{
    Game game{World{""},
              Camera{new sf::RenderWindow{sf::VideoMode(100, 100), "ass", sf::Style::Fullscreen}}};

    while (game.camera.window->isOpen())
    {
        sf::Event event{};
        while (game.camera.window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                game.camera.window->close();
            if (event.type == sf::Event::KeyPressed)
                if (event.key.code == sf::Keyboard::Escape)
                    return 0;
        }
        game.render();
    }

    return 0;
}