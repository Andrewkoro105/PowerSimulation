#include "Map.h"

Map::Map(std::string path) : map(load(path)) {}

std::vector <std::vector<Object>> Map::load(std::string path) {
    return {{Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)},
            {Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0), Object(0, 0, 0)}};
}

void Map::render(sf::RenderWindow* window, int sizeTexture) {
    for (int x = 0; x < map.size(); ++x)
        for (int y = 0; y < map[x].size(); ++y) {
            spriteRender.setPosition((int)((x - map.size() / 2) * sizeTexture), (int)((y - map[0].size() / 2) * sizeTexture));
            map[x][y].render(spriteRender);
            window->draw(spriteRender);
        }
}
void Map::energyCalculation()
{

}

Map::~Map() {
    Save();
}

void Map::Save() {
}
