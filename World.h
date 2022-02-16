#pragma once
#include <string>
#include "Map.h"

class World {
    Map map;
public:
    World(std::string path);
    void Update(sf::RenderWindow* window, int sizeTexture);

};