#include "GeneralTexture.h"


GeneralTexture generalTexture(100);

GeneralTexture::GeneralTexture(uint16_t sizeTeture) : sizeTeture(sizeTeture){}

sf::Vector2i GeneralTexture::toGamePosition(sf::Vector2i pixelPosition) {
    return pixelPosition / static_cast<int>(sizeTeture);
}
