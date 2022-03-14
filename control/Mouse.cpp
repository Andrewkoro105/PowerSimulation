#include "Mouse.h"

Mouse::Mouse(Game* game, sf::Event* event) : event(event), game(game) {}

void Mouse::Check() {
    if (sf::Mouse::isButtonPressed(sf::Mouse::Left)) {
        sf::Vector2i positionRelativeWorld(toWorldPosition(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap(generalTexture.toGamePosition(positionRelativeWorld));

        game->world->setObject(inventory.getBloc(), positionRelativeMap);

    } else if (sf::Mouse::isButtonPressed(sf::Mouse::Right)) {
        sf::Vector2i positionRelativeWorld(toWorldPosition(sf::Mouse::getPosition(*game->camera.window)));
        sf::Vector2i positionRelativeMap = generalTexture.toGamePosition(positionRelativeWorld);

        game->world->setObject(Object(0, 0, 0, std::array<uint8_t, 4>()), positionRelativeMap);

    } else if (event->type == sf::Event::MouseWheelMoved){
        game->camera.editZoom(event->mouseWheel.delta * -0.1 + 1);
    }
}


sf::Vector2i Mouse::toWorldPosition(sf::Vector2i posMouse) {
    sf::Vector2i positionRelativeCamera(game->camera.window->getSize() / 2U - (sf::Vector2u)posMouse);
    return sf::Vector2i(((sf::Vector2f)-positionRelativeCamera * game->camera.getZoom() + game->camera.view.getCenter()));
}
