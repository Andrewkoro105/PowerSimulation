#include "World.h"

World::World(std::string path) : map(path) {}
World::World(std::vector<std::vector<Object>> objects, std::string path) : map(objects, path) {}

void World::Update(sf::RenderWindow *window, sf::Vector2i startCameraRender, sf::Vector2i endCameraRender) {
    map.render(window, startCameraRender, endCameraRender);
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

Object World::getObject(sf::Vector2i position) {
    return map.getObject(position);
}

