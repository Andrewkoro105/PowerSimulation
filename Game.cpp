#include "Game.h"



Game::Game(World world, Camera camera) : world(world), camera(camera){
    this->camera.setWorld(&this->world);
}

void Game::render() {
    camera.render(sizeTexture);
}

