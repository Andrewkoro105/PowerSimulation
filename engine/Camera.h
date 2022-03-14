#pragma once
#include "SFML/Graphics.hpp"
#include "World.h"

class Camera
{
    World* world = 0;
    float zoom;
public:
    float getZoom() const;

public:
    sf::View view;

    Camera(sf::RenderWindow* window, sf::Vector2f pos = sf::Vector2f(0, 0), int zoom = 1);
    void setWorld(World* world);
    void render();

    void editZoom(float zoom);
    void setZoom(float zoom);


    void setPosition(sf::Vector2f pos);
    sf::Vector2f posPosition();
    void move(sf::Vector2f pos);
    sf::RenderWindow* window;
};
