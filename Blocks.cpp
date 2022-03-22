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
                    if (inPut[1] + inPut[2] + inPut[3] >= 4)
                        return {{2, 0, 0, 0}, 1};
                    return {{0, 0, 0, 0}, 0};
                }
        },
        {//not
                {sf::Vector2i(6*generalTexture.sizeTeture, 0), sf::Vector2i(7 * generalTexture.sizeTeture, 0)},
                {false, false},
                {},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    if (inPut[2] > 0 || inPut[1] > 1 || inPut[3] > 1)
                        return {{0, 0, 0, 0}, 1};
                    return {{2, 1, 0, 1}, 0};
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
        },
        {//intersection
                {sf::Vector2i(12 * generalTexture.sizeTeture, 0), sf::Vector2i(13 * generalTexture.sizeTeture, 0),
                 sf::Vector2i(14 * generalTexture.sizeTeture, 0), sf::Vector2i(15 * generalTexture.sizeTeture, 0)},
                {false, false},
                {},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    if (inPut[2] > 0 && inPut[3] == 0)
                        return {{2, 0, 0, 0}, 1};
                    else if (inPut[3] > 0 && inPut[2] == 0)
                        return {{0, 2, 0, 0}, 2};
                    else if (inPut[2] > 0 && inPut[3] > 0)
                        return {{2, 2, 0, 0}, 3};
                    return {{0, 0, 0, 0}, 0};
                }
        },
        {//lamp
                {sf::Vector2i(16 * generalTexture.sizeTeture, 0), sf::Vector2i(17 * generalTexture.sizeTeture, 0)},
                {false, false},
                {},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    if (inPut[0] > 0 || inPut[1] > 0 || inPut[2] > 0 || inPut[3] > 0)
                        return {{0, 0, 0, 0}, 1};
                    return {{0, 0, 0, 0}, 0};
                }
        },
        {//valve
                {sf::Vector2i(18 * generalTexture.sizeTeture, 0), sf::Vector2i(19 * generalTexture.sizeTeture, 0),
                        sf::Vector2i(20 * generalTexture.sizeTeture, 0), sf::Vector2i(21 * generalTexture.sizeTeture,0)},
                {false, false},
                {},
                [](std::array<uint8_t, 4> inPut, uint8_t condition) -> PowerData {
                    if (inPut[2] > 0 && inPut[3] == 0)
                        return {{2, 0, 0, 0}, 1};
                    else if (inPut[3] > 0 && inPut[2] == 0)
                        return {{0, 2, 0, 0}, 2};
                    else if (inPut[2] > 0 && inPut[3] > 0)
                        return {{0, 2, 0, 0}, 3};
                    return {{0, 0, 0, 0}, 0};
                }
        }
};