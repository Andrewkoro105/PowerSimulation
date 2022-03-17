#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <io.h>
#include <ctime>
#include "bits/Bits.h"
#include "bloks/Type.h"
#include "bloks/Object.h"
#include "GeneralTexture.h"

class Map
{
    const int updateTime = 10;
    clock_t lastUpdateTime = 0;
    std::string pathToMap;
    std::vector <sf::Vector2i> activCellsPosition;
    std::vector <std::vector<Object>> cells;
    sf::Sprite spriteRender;

    void energyInit(); 
    bool moveCell(sf::Vector2i &willBeActivePosition, sf::Vector2i position, uint8_t side, uint16_t distance = 1);
    std::array<uint8_t, 4> getOutPower(sf::Vector2i position, uint8_t rotation);
    std::vector<sf::Vector2i> loadActiveCellsPosition(std::_Bit_iterator &cursor, std::vector<bool> &bits);
    std::vector<std::vector<Object>> loadCells(std::_Bit_iterator &cursor, std::vector<bool> &bits);
    std::vector <std::vector<Object>> cellsGenerating();
    std::vector <std::vector<Object>> convertToObjects(std::vector<bool>& bits, std::_Bit_iterator &cursor);
    bool convertToObject(std::vector<bool> &bits, std::_Bit_iterator &cursor, Object &object);

    std::vector<bool> saveObjects();
    std::vector<bool> saveObject(Object& object);
    std::vector<bool> saveActiveCellsPosition();
public:
    Map(std::string path);
    Map(std::vector<std::vector<Object>> objects, std::string path = "");
    ~Map();
    void render(sf::RenderWindow *window, sf::Vector2i startCameraRender, sf::Vector2i endCameraRender);
    void energyUpdate();
    void energyCalculation();
    void setObject(Object object, sf::Vector2i position);
    Object getObject(sf::Vector2i position);
    sf::Vector2i getSize();
    void save(std::string pathToMap);
    bool objectInMap(sf::Vector2i position, sf::Vector2i move = {0, 0});

    bool operator==(Map map);
};