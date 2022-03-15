#include "Object.h"
#include <algorithm>

Object::Object(int type, uint8_t rotation, uint8_t condition, std::array<uint8_t, 4> powerStream) :
        type(type),
        rotation(typesObjects[type]._static.rotation ? typesObjects[type]._default.rotation : rotation),
        powerData{typesObjects[type]._static.сondition ? typesObjects[type]._default.defaultActive : powerStream , typesObjects[type]._static.сondition ? typesObjects[type]._default.сondition : condition}{}

void Object::renderSettings(sf::Sprite& sprite){
    sprite.setRotation(rotation * 90);
    sprite.setTexture(typesObjects[type].getTexture(powerData.сondition));
}

void Object::setRotation(uint8_t rotation) {
    if(!typesObjects[type]._static.rotation)
        Object::rotation = rotation;
}

uint8_t Object::getRotation() const {
    return rotation;
}

void Object::setCondition(uint8_t condition) {
    if (!typesObjects[type]._static.сondition)
        powerData.сondition = condition;
}

int Object::getCondition() const {
    return powerData.сondition;
}

TypeObject* Object::getType() const {
    return &typesObjects[type];
}

int Object::getIntType() const {
    return type;
}

bool Object::operator==(Object object) {
    return
            ((object.powerData.сondition == this->powerData.сondition) &&
             (object.rotation == this->rotation)) &&
                    (object.type == this->type);
}

uint8_t Object::getPowerIn(uint8_t side) const {
    return powerData.sreamPower[side];
}

const std::array<uint8_t, 4> Object::getPowerInGivenRotation() const {
    std::array<uint8_t, 4> striamPower = powerData.sreamPower;
    std::rotate(striamPower.rbegin(), striamPower.rbegin() + static_cast<int>(rotation), striamPower.rend());
    return striamPower;
}

PowerData &Object::getPowerData(){
    return powerData;
}

std::array<uint8_t, 4> Object::powerUpdate(std::array<uint8_t, 4> powerStream) {
    powerData = typesObjects[type].update(powerStream, powerData.сondition);
    return powerData.sreamPower;
}