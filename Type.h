#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include "SFML/Graphics.hpp"

extern struct TypeObject
{
    std::string pathMiltiTexture = "image/block/air.png";
    std::vector<sf::Texture> textures;
    struct Power
    {
        uint8_t w, d, s, a;
    } powerIN, powerOut;
    struct Static
    {
        bool rotation;
        bool active;
    }_static;
    TypeObject(std::vector<sf::IntRect> rectTexture, Power powerIN, Power powerOut, Static _static);
}typesObjects[];