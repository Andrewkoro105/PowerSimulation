#pragma once
#include "SFML/Graphics.hpp"
#include "World.h"
#include "Camera.h"
 class Game
{
     World world;
public:
    Game(World world, Camera camera);
    void render();

    Camera camera;
    const uint16_t sizeTexture = 100;
};