#pragma once
#include "SFML/Graphics.hpp"
#include "Copying.h"
#include "../engine/Game.h"
#include "../engine/Inventory.h"

class Keyboard {
    sf::Event* event;
    Game* game;
    Copying* copyingCells;
    void copying();
    void paste();
public:
    Keyboard(Game* game, sf::Event* event);
    void Check();
};