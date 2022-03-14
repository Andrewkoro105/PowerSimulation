#include "Game.h"

Game::Game(World* world, Camera camera) : world(world), camera(camera){
    this->camera.setWorld(this->world);

    this->camera.move(
            sf::Vector2f(
                    static_cast<float>(this->world->getSizeMap().x / 2 * static_cast<int>(generalTexture.sizeTeture)),
                    static_cast<float>(this->world->getSizeMap().y / -2 * static_cast<int>(generalTexture.sizeTeture))));
}

void Game::render() {
    camera.render();
}

Game::~Game() {
    delete world;
}

