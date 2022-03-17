#include "Mouse.h"

Mouse::Mouse(Game* game, sf::Event* event) : event(event), game(game), oldMousePosition(sf::Mouse::getPosition(*game->camera.window)) {}

void Mouse::Check() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Button::Middle)) {
        sf::Vector2f mouseToWorldPosition(game->camera.toWorldPosition(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2f oldMouseToWorldPosition(game->camera.toWorldPosition(oldMousePosition));

        game->camera.move(oldMouseToWorldPosition - mouseToWorldPosition);
    }
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i positionRelativeWorld(game->camera.toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap(generalTexture.toGamePosition(positionRelativeWorld));

        game->world->setObject(inventory.getBloc(), positionRelativeMap);

    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i positionRelativeWorld(game->camera.toWorldPositionNotInventoryY(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap = generalTexture.toGamePosition(positionRelativeWorld);

        game->world->setObject(Object(0, 0, 0), positionRelativeMap);

    } else if (event->type == sf::Event::MouseWheelMoved){
        game->camera.editZoom(event->mouseWheel.delta * -0.1 + 1);
    }

    oldMousePosition = sf::Mouse::getPosition(*game->camera.window);
}
