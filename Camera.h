#pragma once
#include "SFML/Graphics.hpp"
#include "World.h"

class Camera
{
    int zoom;

private:
    sf::View view;
    World* world = 0;
public:
    Camera(sf::RenderWindow* window, sf::Vector2f pos = sf::Vector2f(0, 0), int zoom = 100);
    void setWorld(World* world);
    void render(uint16_t sizeTexture);

    int getZoom() const;
    void setZoom(int zoom);
    sf::RenderWindow* window;
};
