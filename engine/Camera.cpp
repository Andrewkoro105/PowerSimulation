#include "Camera.h"

Camera::Camera(sf::RenderWindow* window, sf::Vector2f pos, int zoom) : window(window), zoom(zoom)
{
    window->setVerticalSyncEnabled(true);
    view = sf::View(pos, sf::Vector2f(window->getSize().x * zoom, window->getSize().y * zoom));
    window->setView(view);
}

void Camera::setWorld(World* world) {
    this->world = world;
}

void Camera::render()
{

    sf::Vector2i startCameraRender(view.getCenter() + (sf::Vector2f(view.getSize().x * -1, view.getSize().y) / 2.f));
    sf::Vector2i endCameraRender(view.getCenter() + (sf::Vector2f(view.getSize().x, view.getSize().y * -1) / 2.f));

    window->clear(sf::Color(41, 51, 50));
    world->Update(window,startCameraRender, endCameraRender);
    window->display();
}

void Camera::editZoom(float zoom) {
    setZoom(this->zoom * zoom);
}

void Camera::setZoom(float zoom) {
    this->zoom = zoom;
    view.setSize((sf::Vector2f)window->getSize() * zoom);
    window->setView(view);
}


void Camera::setPosition(sf::Vector2f pos) {
    view.setCenter(pos);
    window->setView(view);
}

sf::Vector2f Camera::posPosition() {
    return view.getCenter();
    window->setView(view);
}

void Camera::move(sf::Vector2f pos) {
    view.move(pos);
    window->setView(view);
}

float Camera::getZoom() const {
    return zoom;
}

sf::Vector2i Camera::toWorldPositionNotInventoryY(sf::Vector2i posMouse) {
    sf::Vector2i positionRelativeCamera(window->getSize() / 2U - static_cast<sf::Vector2u>(posMouse));
    return sf::Vector2i((sf::Vector2f(positionRelativeCamera.x * -1, positionRelativeCamera.y) * getZoom() + sf::Vector2f(view.getCenter().x, -view.getCenter().y)));
}

sf::Vector2i Camera::toWorldPosition(sf::Vector2i posMouse) {
    sf::Vector2i positionRelativeCamera(window->getSize() / 2U - static_cast<sf::Vector2u>(posMouse));
    return sf::Vector2i((sf::Vector2f(positionRelativeCamera.x * -1, positionRelativeCamera.y * -1) * getZoom() + sf::Vector2f(view.getCenter().x, -view.getCenter().y)));
}