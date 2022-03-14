#include "Control.h"

Control::Control(Game* game, sf::Event *event) : mouse(game, event), keyboard(game, event) {

}

void Control::Check() {
    mouse.Check();
    keyboard.Check();
}
