#include "World.h"

World::World(std::string path) : map(path) {}

void World::Update(sf::RenderWindow* window, int sizeTexture) {

    map.render(window, sizeTexture);
}
