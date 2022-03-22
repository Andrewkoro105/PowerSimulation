#include "Keyboard.h"

Keyboard::Keyboard(Game* game, sf::Event* event) : event(event), game(game), copyingCells(nullptr){}

void Keyboard::Check() {
    if (event->type == sf::Event::KeyPressed) {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape)) {
            game->camera.window->close();
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
            game->camera.move(sf::Vector2f(0, -80));
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)) {
            game->camera.move(sf::Vector2f(80, 0));
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
            game->camera.move(sf::Vector2f(0, 80));
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::A)) {
            game->camera.move(sf::Vector2f(-80, 0));
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::R)) {
            inventory.upRotation();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) {
            inventory.downType();
        } else if (sf::Keyboard::isKeyPressed(sf::Keyboard::E)) {
            inventory.upType();
        }

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::C)){
            copying();
        } if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
            paste();
        }
    }
}

void Keyboard::copying() {
    sf::Vector2i startPositionRelativeWorld(game->camera.toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
    sf::Vector2i startPositionRelativeMap(generalTexture.toGamePosition(startPositionRelativeWorld));
    std::cout << startPositionRelativeMap.x << ' ' << startPositionRelativeMap.y << std::endl;

    while (!sf::Mouse::isButtonPressed(sf::Mouse::Left)){}

    sf::Vector2i endPositionRelativeWorld(game->camera.toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
    sf::Vector2i endPositionRelativeMap(generalTexture.toGamePosition(endPositionRelativeWorld));

    copyingCells = new Copying(startPositionRelativeMap, endPositionRelativeMap, *game->world);
}

void Keyboard::paste() {
    if (copyingCells != nullptr) {
        sf::Vector2i positionRelativeWorld(
                game->camera.toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap(generalTexture.toGamePosition(positionRelativeWorld));

        copyingCells->paste(positionRelativeMap);
    }
}