#pragma once
#include <cmath>
#include "SFML/Graphics.hpp"

extern class GeneralTexture {
public:
    const uint16_t sizeTeture;
    GeneralTexture(uint16_t sizeTeture);

    sf::Vector2i toGamePosition(sf::Vector2i pixelPosition);


}generalTexture;