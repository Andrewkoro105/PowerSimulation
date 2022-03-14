#pragma once
#include "SFML/Graphics.hpp"
#include "World.h"
#include "Camera.h"
extern class Game
{
public:
    Game(World* world, Camera camera);
    ~Game();
    void render();

    World* world;
    Camera camera;
}game;