#include "Keyboard.h"

Keyboard::Keyboard(Game* game, sf::Event* event) : event(event), game(game) {}

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
    }
}