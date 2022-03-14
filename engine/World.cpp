#include "World.h"

World::World(std::string path) : map(path) {}
World::World(std::vector<std::vector<Object>> objects, std::string path) : map(objects, path) {}

void World::Update(sf::RenderWindow* window) {
    map.render(window);
}

sf::Vector2i World::getSizeMap() {
    return map.getSize();
}

void World::setObject(Object object, sf::Vector2i position) {
    map.setObject(object, position);
}

bool World::objectInMap(sf::Vector2i position) {
    return map.objectInMap(position);
}

