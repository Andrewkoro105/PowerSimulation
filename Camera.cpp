#include "Camera.h"

Camera::Camera(sf::RenderWindow* window, sf::Vector2f pos, int zoom) : window(window), zoom(zoom)
{
    view = sf::View(pos, sf::Vector2f(sf::VideoMode::getFullscreenModes()[0].width * zoom / 100, sf::VideoMode::getFullscreenModes()[0].height * zoom / 100));
    window->setView(view);
}

void Camera::setWorld(World* world) {
    this->world = world;
}

void Camera::render(uint16_t sizeTexture)
{
    window->clear(sf::Color(41, 51, 50));
    world->Update(window, sizeTexture);
    window->display();
}

void Camera::setZoom(int zoom) {
    Camera::zoom = zoom;
}

int Camera::getZoom() const {
    return zoom;
}
