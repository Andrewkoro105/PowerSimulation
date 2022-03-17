#include <SFML/Graphics.hpp>
#include <vector>
#include <string>
#include "Game.h"
#include "../control/Control.h"
//../maps/test.map

int main(int argc, char *argv[]) {
    sf::Event event{};

    World *world;

    if (argc == 2){
        world = new World(std::string(argv[1]));
    }else if (argc == 4) {
        world = new World(std::vector<std::vector<Object>>(atoi(argv[2]), std::vector<Object>(atoi(argv[3]), Object(0, 0, 0))) , std::string(argv[1]));
    }else{
        world = new World("test.mps");
    }


    Game game{world,
                  Camera{new sf::RenderWindow{sf::VideoMode(), "ass", sf::Style::Fullscreen}, sf::Vector2f(), 1}};
    Control control(&game, &event);

    while (game.camera.window->isOpen()) {
        while (game.camera.window->pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                game.camera.window->close();
            control.Check();
        }
        game.render();
    }

    return 0;
}