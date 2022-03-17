#pragma once
#include "SFML/Graphics.hpp"
#include "../engine/Game.h"
#include "cmath"
#include "../engine/Inventory.h"
#include "../engine/GeneralTexture.h"

class Mouse {
    sf::Event* event;
    Game* game;

    sf::Vector2i oldMousePosition;
public:
    sf::Vector2i toWorldPositionNotInventoryY(sf::Vector2i posMouse);
    sf::Vector2i toWorldPosition(sf::Vector2i posMouse);
    Mouse(Game* game, sf::Event* event);
    void Check();
};