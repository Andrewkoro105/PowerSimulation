#pragma once
#include "SFML/Graphics.hpp"
#include "../engine/Game.h"
#include "../engine/Inventory.h"

class Keyboard {
    sf::Event* event;
    Game* game;
public:
    Keyboard(Game* game, sf::Event* event);
    void Check();
};