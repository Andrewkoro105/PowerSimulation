#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

class Map
{
    std::vector <std::vector<Object>> load(std::string path);
    void Save();

    std::vector <Object*> activBloc;
    std::vector <std::vector<Object>> map;
    sf::Sprite spriteRender;

public:
    Map(std::string path);
    ~Map();
    void render(sf::RenderWindow* window, int sizeTexture);
    void energyCalculation();

};