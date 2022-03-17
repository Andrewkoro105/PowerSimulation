#include "Mouse.h"

Mouse::Mouse(Game* game, sf::Event* event) : event(event), game(game), oldMousePosition(sf::Mouse::getPosition(*game->camera.window)) {}

void Mouse::Check() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)) {
        sf::Vector2f mouseToWorldPosition(toWorldPosition(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2f oldMouseToWorldPosition(toWorldPosition(oldMousePosition));

        game->camera.move(oldMouseToWorldPosition - mouseToWorldPosition);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i positionRelativeWorld(toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap(generalTexture.toGamePosition(positionRelativeWorld));

        game->world->setObject(inventory.getBloc(), positionRelativeMap);

    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i positionRelativeWorld(toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap = generalTexture.toGamePosition(positionRelativeWorld);

        game->world->setObject(Object(0, 0, 0), positionRelativeMap);

    } else if (event->type == sf::Event::MouseWheelMoved){
        game->camera.editZoom(event->mouseWheel.delta * -0.1 + 1);
    }

    oldMousePosition = sf::Mouse::getPosition(*game->camera.window);
}


sf::Vector2i Mouse::toWorldPositionNotInventoryY(sf::Vector2i posMouse) {
    sf::Vector2i positionRelativeCamera(game->camera.window->getSize() / 2U - static_cast<sf::Vector2u>(posMouse));
    return sf::Vector2i((sf::Vector2f(positionRelativeCamera.x * -1, positionRelativeCamera.y) * game->camera.getZoom() + sf::Vector2f(game->camera.view.getCenter().x, -game->camera.view.getCenter().y)));
}

sf::Vector2i Mouse::toWorldPosition(sf::Vector2i posMouse) {
    sf::Vector2i positionRelativeCamera(game->camera.window->getSize() / 2U - static_cast<sf::Vector2u>(posMouse));
    return sf::Vector2i((sf::Vector2f(positionRelativeCamera.x * -1, positionRelativeCamera.y * -1) * game->camera.getZoom() + sf::Vector2f(game->camera.view.getCenter().x, -game->camera.view.getCenter().y)));
}