#pragma once
#include <string>
#include "Map.h"

class World {
    Map map;
public:
    World(std::string path);
    World(std::vector<std::vector<Object>> objects, std::string path = "");
    void Update(sf::RenderWindow *window, sf::Vector2i startCameraRender, sf::Vector2i endCameraRender);
    sf::Vector2i getSizeMap();
    void setObject(Object object, sf::Vector2i position);
    bool  objectInMap(sf::Vector2i position);
};