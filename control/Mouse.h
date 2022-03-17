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
    Mouse(Game* game, sf::Event* event);
    void Check();
};