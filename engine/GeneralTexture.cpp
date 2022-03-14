#include "GeneralTexture.h"


GeneralTexture generalTexture(100);

GeneralTexture::GeneralTexture(uint16_t sizeTeture) : sizeTeture(sizeTeture){}

sf::Vector2i GeneralTexture::toGamePosition(sf::Vector2i pixelPosition) {
    return sf::Vector2i(abs(pixelPosition.x) / sizeTeture, abs(pixelPosition.y) / sizeTeture);
}
