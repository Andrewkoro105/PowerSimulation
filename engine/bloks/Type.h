#pragma once
#include <cstdint>
#include <string>
#include <vector>
#include <array>
#include "SFML/Graphics.hpp"
#include "../GeneralTexture.h"
#include "PowerData.h"

class TypeObject {
    struct Static {
        bool rotation;
        bool сondition;
    };
    struct Default {
        uint8_t rotation = 0;
        uint8_t сondition = 0;
        std::array<uint8_t, 4> defaultActive {0, 0, 0, 0};

        Default(){}

        Default(uint8_t rotation, uint8_t сondition, std::array<uint8_t, 4> defaultActive) :
                rotation(rotation), сondition(сondition), defaultActive(defaultActive){};

        Default(uint8_t сondition, std::array<uint8_t, 4> defaultActive) :
                сondition(сondition), defaultActive(defaultActive){};

        Default(std::array<uint8_t, 4> defaultActive) :
                defaultActive(defaultActive){};
    };
    const std::string pathMiltiTexture = "image/block/BlocksTexture-ai-2color.png";
    const std::vector<sf::Texture> textures;

    std::vector<sf::Texture> textureGenerator(std::vector<sf::Vector2i>& positionTexture, Static& _static, Default& _default);
    void addTextures(sf::Texture& texture, sf::Vector2i positionTexture);

public:
    PowerData (*update)(std::array<uint8_t, 4> powerNeighbors, uint8_t сondition);
    const Static _static;
    const Default _default;

    const sf::Texture& getTexture(uint16_t i) const;
    TypeObject(std::vector<sf::Vector2i> positionTexture, Static _static,
               Default _default = {},
               PowerData (*update)(std::array<uint8_t, 4> powerNeighbors, uint8_t сondition) =
               [](std::array<uint8_t, 4> powerNeighbors, uint8_t сondition) -> PowerData { return {0, 0, 0, 0}; });
};

extern std::vector<TypeObject> typesObjects;