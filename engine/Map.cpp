#include "Map.h"
#include <algorithm>

Map::Map(std::vector<std::vector<Object>> objects, std::string path) : cells(objects), pathToMap(path) {
    spriteRender.setOrigin(generalTexture.sizeTeture/2, generalTexture.sizeTeture/2);
    energyInit();
}

Map::Map(std::string path) : pathToMap(path){
    spriteRender.setOrigin(generalTexture.sizeTeture/2, generalTexture.sizeTeture/2);
    if (access(pathToMap.c_str(), 0) != -1) {

        std::vector<bool> bits = Bits::bitLoad(path);
        std::_Bit_iterator cursor = bits.begin();
        activCellsPosition = loadActiveCellsPosition(cursor, bits);
        cells = loadCells(cursor, bits);
    } else
        cells = cellsGenerating();

    energyInit();
}

std::vector<sf::Vector2i> Map::loadActiveCellsPosition(std::_Bit_iterator &cursor, std::vector<bool> &bits) {

    std::vector<sf::Vector2i> rezult;

    int size = Bits::conversionToInt(cursor, 32);
    cursor += 32;

    for (int i = 0; i < size; ++i) {
        rezult.push_back(sf::Vector2i(Bits::conversionToInt(cursor, 32), Bits::conversionToInt(cursor + 32, 32)));
        cursor += 64;
    }
    return rezult;
}

std::vector<std::vector<Object>> Map::loadCells(std::_Bit_iterator &cursor, std::vector<bool> &bits) {


        std::vector<std::vector<Object>> cells;

        cells = convertToObjects(bits, cursor);
        return cells;
}

std::vector <std::vector<Object>> Map::convertToObjects(std::vector<bool>& bits, std::_Bit_iterator &cursor) {

    std::vector<std::vector<Object>> cells;

    sf::Vector2i size(Bits::conversionToInt(cursor, 32), Bits::conversionToInt(cursor + 32, 32));

    cursor += 64;

    for (int x = 0; x < size.x; ++x) {
        cells.push_back({});
        for (int y = 0; y < size.y; ++y) {
            Object object(0, 0, 0, std::array<uint8_t, 4>());
            if (convertToObject(bits, cursor, object)) {
                cells[x].push_back(object);
            } else
                return cells;
        }
    }
    return cells;
}

bool Map::convertToObject(std::vector<bool> &bits, std::_Bit_iterator &cursor, Object &object) {

    if (std::distance(bits.begin(), cursor) + 5 <= bits.size()) {
        int type = Bits::conversionToInt(cursor, 5);
        if (typesObjects.size() > type) {
            int rotation = 0;
            int condition = 0;
            std::array<uint8_t, 4> powerIn{0, 0, 0, 0};
            cursor += 5;
            if (!typesObjects[type]._static.rotation &&
                std::distance(bits.begin(), cursor) + 2 <= bits.size()) {
                rotation = Bits::conversionToInt(cursor, 2);
                cursor += 2;
            }
            if (!typesObjects[type]._static.сondition &&
                std::distance(bits.begin(), cursor) + 4 <= bits.size()) {
                condition = Bits::conversionToInt(cursor, 4);
                cursor += 4;
            }

            for (int i = 0; i < 4; ++i) {
                if (!typesObjects[type]._static.сondition &&
                    std::distance(bits.begin(), cursor) + 2 <= bits.size()) {
                    powerIn[i] = Bits::conversionToInt(cursor, 2);
                    cursor += 2;
                }
            }
            object = Object(type, rotation, condition, powerIn);
        } else
            return false;
    } else
        return false;
    return true;
}

std::vector<std::vector<Object>> Map::cellsGenerating() {
    return std::vector<std::vector<Object>>(32, std::vector<Object>(32, Object{0, 0, 0}));
}

void Map::render(sf::RenderWindow *window, sf::Vector2i startCameraRender, sf::Vector2i endCameraRender) {
    sf::Vector2i startRender = generalTexture.toGamePosition(startCameraRender);
    sf::Vector2i endRender = generalTexture.toGamePosition(endCameraRender) + sf::Vector2i(2, 0);
    if (startRender.x < 0){
        startRender.x = 0;
    }
    if (startRender.y >= cells[0].size()){
        startRender.y = cells[0].size() - 1;
    }
    if (endRender.x > cells.size() ){
        endRender.x = cells.size();
    }
    if (endRender.y < 0){
        endRender.y = 0;
    }
/*
    startRender = {0, static_cast<int>(cells[0].size()) - 1};
    endRender = {static_cast<int>(cells.size()), 0};
*/
    for (int x = startRender.x; x < endRender.x; ++x) {
        for (int y = startRender.y; y > endRender.y; --y) {
            spriteRender.setPosition(
                x * generalTexture.sizeTeture + generalTexture.sizeTeture / 2,
                y * -generalTexture.sizeTeture - generalTexture.sizeTeture / 2);
            cells[x][y].renderSettings(spriteRender);

            window->draw(spriteRender);
        }
    }
    //energyCalculation();
    energyUpdate();
}

void Map::energyCalculation() {
    std::vector<sf::Vector2i> newCellsPosition;

    for (int i = 0; i < activCellsPosition.size(); ++i) {
        sf::Vector2i position = activCellsPosition[i];
        std::array<uint8_t, 4> oldInPut = cells[position.x][position.y].getPowerInGivenRotation();
        std::array<uint8_t, 4> outPut = getOutPower(position, cells[position.x][position.y].getRotation());
        cells[position.x][position.y].powerUpdate(outPut);
        std::array<uint8_t, 4> inPut = cells[position.x][position.y].getPowerInGivenRotation();

        if (oldInPut != inPut) {
            for (int side = 0; side < 4; ++side) {
                if (inPut[side] || oldInPut[side]) {
                    sf::Vector2i willBeActivePosition;
                    if (moveCell(willBeActivePosition, position, side)) {
                        newCellsPosition.push_back(willBeActivePosition);
                    }
                }
            }
        }
    }
    activCellsPosition = newCellsPosition;
}

void Map::setObject(Object object, sf::Vector2i position) {
    if (objectInMap(position)) {

        std::array<uint8_t, 4> inPut = cells[position.x][position.y].getPowerInGivenRotation();

        activCellsPosition.push_back(position);
        for (int side = 0; side < 4; ++side) {
            sf::Vector2i willBeActivePosition;
            if (moveCell(willBeActivePosition, position, side)) {
                activCellsPosition.push_back(willBeActivePosition);
            }
        }

        cells[position.x][position.y] = object;
    }
}

sf::Vector2i Map::getSize() {
    return sf::Vector2i(cells.size(), cells[0].size());
}

bool Map::operator==(Map map) {
    if (map.cells.size() == this->cells.size() && map.cells[0].size() == this->cells[0].size()) {
        for (int x = 0; x < this->cells.size(); ++x) {
            for (int y = 0; y < this->cells[x].size(); ++y) {
                if (!(map.cells[x][y] == this->cells[x][y]))
                    return false;
            }
        }
    }
    return true;
}

bool Map::objectInMap(sf::Vector2i position, sf::Vector2i move) {
    position += move;
    if (cells.size()){
        if (cells.size() > position.x){
            if (cells[0].size() > position.y){
                return true;
            }
        }
    }
    return false;
}

std::array<uint8_t, 4> Map::getOutPower(sf::Vector2i position, uint8_t rotation) {
    std::array<uint8_t, 4> rezult{
            (objectInMap(position, {0, 1}) ?
             cells[position.x][position.y + 1].getPowerInGivenRotation()[2] : uint8_t(0)),

            (objectInMap(position, {1, 0}) ?
             cells[position.x + 1][position.y].getPowerInGivenRotation()[3] : uint8_t(0)),


            (objectInMap(position, {0, -1}) ?
             cells[position.x][position.y - 1].getPowerInGivenRotation()[0] : uint8_t(0)),

            (objectInMap(position, {-1, 0}) ?
             cells[position.x - 1][position.y].getPowerInGivenRotation()[1] : uint8_t(0))
    };

    std::rotate(rezult.begin(), rezult.begin() + rotation, rezult.end());

    return rezult;
}

bool Map::moveCell(sf::Vector2i &willBeActivePosition, sf::Vector2i position, uint8_t side, uint16_t distance) {

    willBeActivePosition = position;

    if (side == 0)
        willBeActivePosition += sf::Vector2i(0, distance);
    else if (side == 1)
        willBeActivePosition += sf::Vector2i(distance, 0);
    else if (side == 2)
        willBeActivePosition += sf::Vector2i(0, -distance);
    else if (side == 3)
        willBeActivePosition += sf::Vector2i(-distance, 0);

    if (willBeActivePosition.x >= 0 && willBeActivePosition.x < cells.size() &&
        willBeActivePosition.y >= 0 && willBeActivePosition.y < cells[0].size())
        return true;
    return false;
}

Object Map::getObject(sf::Vector2i position) {
    return cells[position.x][position.y];
}

void Map::energyUpdate() {

    clock_t clock = std::clock();
    if (clock - lastUpdateTime > updateTime) {
        energyCalculation();
        lastUpdateTime = std::clock();
    }
}

void Map::energyInit() {
    lastUpdateTime = std::clock();
}

Map::~Map() {
    save(pathToMap);
}

void Map::save(std::string pathToMap) {
    if (pathToMap != "") {
        std::vector<bool> bits;

        std::vector<bool> bitsActiveCellsPosition = saveActiveCellsPosition();
        bits.insert(bits.end(), bitsActiveCellsPosition.begin(), bitsActiveCellsPosition.end());

        std::vector<bool> bitsObjects = saveObjects();
        bits.insert(bits.end(), bitsObjects.begin(), bitsObjects.end());

        Bits::bitSave(bits, pathToMap);
    }
}

std::vector<bool> Map::saveObjects() {
    std::vector<bool> bits;


    Bits::conversionToBits(cells.size(), 32, bits);

    Bits::conversionToBits(cells[0].size(), 32, bits);

    for (int x = 0; x < cells.size(); ++x) {
        for (int y = 0; y < cells[x].size(); ++y) {
            std::vector<bool> bitsObject = saveObject(cells[x][y]);
            bits.insert(bits.end(), bitsObject.begin(), bitsObject.end());
        }
    }


    return bits;
}

std::vector<bool> Map::saveObject(Object &object) {
    std::vector<bool> bits;

    Bits::conversionToBits(object.getIntType(), 5, bits);

    if (!object.getType()->_static.rotation) {
        Bits::conversionToBits(object.getRotation(), 2, bits);
    }
    if (!object.getType()->_static.сondition) {
        Bits::conversionToBits(object.getCondition(), 4, bits);
    }
    if (!object.getType()->_static.сondition){
        for (int i = 0; i < 4; ++i) {
            Bits::conversionToBits(object.getPowerIn(i), 2, bits);
        }
    }
    return bits;
}

std::vector<bool> Map::saveActiveCellsPosition() {

    std::vector<bool> bits;

    Bits::conversionToBits(activCellsPosition.size(), 32, bits);

    for (int i = 0; i < activCellsPosition.size(); ++i) {
        Bits::conversionToBits(activCellsPosition[i].x, 32, bits);
        Bits::conversionToBits(activCellsPosition[i].y, 32, bits);
    }

    return bits;
}
