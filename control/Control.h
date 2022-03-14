#pragma once
#include "SFML/Graphics.hpp"
#include "Mouse.h"
#include "Keyboard.h"
#include "../engine/Game.h"

class Control {
    Mouse mouse;
    Keyboard keyboard;
public:
    Control(Game* game, sf::Event* event);
    void Check();
};