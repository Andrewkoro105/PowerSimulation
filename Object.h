#pragma once
#include <cstdint>
#include "SFML/Graphics.hpp"
#include "Type.h"

class Object
{
    TypeObject* type;
    uint8_t rotation;
    bool active;
public:
    Object(uint8_t type, uint8_t rotation, bool active);
    void render(sf::Sprite& sprite);

    void setRotation(uint8_t rotation);
    uint8_t getRotation() const;

    void setActive(bool active);
    bool getActive() const;
};