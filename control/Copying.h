#pragma once
#include <vector>
#include "SFML/Graphics.hpp"
#include "../engine/World.h"


class Copying {
public:
    enum CornerVertical{
        Down = true,
        Top = false
    };
    enum CornerHorizon{
        Left = true,
        Right = false
    };
private:
    World& world;
    std::vector<std::vector<Object>> cells;
    CornerVertical cornerV;
    CornerHorizon cornerH;
public:
    Copying(sf::Vector2i startPosition, sf::Vector2i endPosition, World& world);
    void paste(sf::Vector2i position);
};