#include <iostream>
#include "Type.h"

TypeObject::TypeObject(std::vector<sf::Vector2i> positionTexture, Static _static,
                       TypeObject::Default _default,
                       PowerData (*update)(std::array<uint8_t, 4> powerNeighbors, uint8_t сondition)) :
        _static(_static), _default(_default), update(update), textures(textureGenerator(positionTexture, _static, _default)){}

std::vector<sf::Texture> TypeObject::textureGenerator(std::vector<sf::Vector2i>& positionTexture, Static& _static, Default& _default) {

    std::vector<sf::Texture> textures(_static.сondition ? 1 : positionTexture.size());

    if (_static.сondition) {
        addTextures(textures[0], positionTexture[0]);
    } else {
        for (int i = 0; i < positionTexture.size(); ++i) {
            addTextures(textures[i], positionTexture[i]);
        }
    }
    return textures;
}

void TypeObject::addTextures(sf::Texture &texture, sf::Vector2i positionTexture) {
    texture.loadFromFile(pathMiltiTexture, sf::IntRect(positionTexture,
                                                       sf::Vector2i(generalTexture.sizeTeture,
                                                                    generalTexture.sizeTeture)));
}

const sf::Texture& TypeObject::getTexture(uint16_t i) const {
    return textures[_static.сondition ? _default.сondition : i];
}
