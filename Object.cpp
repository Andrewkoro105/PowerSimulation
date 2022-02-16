#include "Object.h"


Object::Object(uint8_t type, uint8_t rotation, bool active) :
        type(&typesObjects[type]), rotation(rotation), active(active) {}

void Object::render(sf::Sprite& sprite)
{
    sprite.setRotation(rotation * 90);
    sprite.setTexture(type->textures[active]);
}

void Object::setRotation(uint8_t rotation) {
    if(!type->_static.rotation)
        Object::rotation = rotation;
}

uint8_t Object::getRotation() const {
    return rotation;
}

void Object::setActive(bool active) {
    if (!type->_static.active)
        Object::active = active;
}

bool Object::getActive() const {
    return active;
}