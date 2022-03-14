#pragma once
#include <cstdint>
#include <array>
#include "SFML/Graphics.hpp"
#include "Type.h"
#include "PowerData.h"

class Object
{
    int type;
    uint8_t rotation;
    PowerData powerData;

public:

    Object(int type, uint8_t rotation, uint8_t condition, std::array<uint8_t, 4> powerStream = {0, 0, 0, 0});

    std::array<uint8_t, 4> powerUpdate(std::array<uint8_t, 4> powerStream);

    void renderSettings(sf::Sprite& sprite);

    PowerData &getPowerData();
    uint8_t getPowerIn(uint8_t side) const;
    const std::array<uint8_t, 4> getPowerInGivenRotation() const;

    void setRotation(uint8_t rotation);
    uint8_t getRotation() const;

    void setCondition(uint8_t condition);
    bool getCondition() const;

    TypeObject* getType() const;
    int getIntType() const;

    bool operator== (Object object);
};