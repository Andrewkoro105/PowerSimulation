#include <vector>
#include "engine/bloks/Type.h"
#include "engine/GeneralTexture.h"
#include <algorithm>

std::vector<TypeObject> typesObjects{
        {//air
                {sf::Vector2i (0, 0)},
                {true, true}
        },
        {//wire
            {sf::Vector2i(generalTexture.sizeTeture, 0), sf::Vector2i(2 * generalTexture.sizeTeture, 0)},
            {false, false},
            {},
            [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                if (inPut[2] > 0 || inPut[1] > 1 || inPut[3] > 1)
                    return {{2, 1, 0, 1}, 1};
                return {{0, 0, 0, 0}, 0};
            }
        },
        {//generator
            {sf::Vector2i(3*generalTexture.sizeTeture, 0)},
            {true, true},
            {{2, 2, 2, 2}},
            [](std::array<uint8_t, 4> inOut, uint8_t condition) -> PowerData{
                return {{2, 2, 2, 2}, 0};
            }
        },
        {//and
                {sf::Vector2i(4*generalTexture.sizeTeture, 0), sf::Vector2i(5 * generalTexture.sizeTeture, 0)},
                {false, false},
                {},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    if (inPut[1] > 1 && inPut[3] > 1)
                        return {{2, 0, 0, 0}, 1};
                    return {{0, 0, 0, 0}, 0};
                }
        },
        {//xor
                {sf::Vector2i(8*generalTexture.sizeTeture, 0), sf::Vector2i(9 * generalTexture.sizeTeture, 0)},
                {false, false},
                {{2, 0, 0, 0}},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    for (int i = 0; i < 4; ++i) {
                        if (inPut[i] == 1)
                            inPut[i] = 0;
                    }
                    if (inPut[1] != inPut[3])
                        return {{2, 0, 0, 0}, 1};
                    return {{0, 0, 0, 0}, 0};
                }
        },
        {//xand
                {sf::Vector2i(10*generalTexture.sizeTeture, 0), sf::Vector2i(11 * generalTexture.sizeTeture, 0)},
                {false, false},
                {{2, 0, 0, 0}},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    for (int i = 0; i < 4; ++i) {
                        if (inPut[i] == 1)
                            inPut[i] = 0;
                    }
                    if (inPut[1] == inPut[3])
                        return {{2, 0, 0, 0}, 1};
                    return {{0, 0, 0, 0}, 0};
                }
        }
};