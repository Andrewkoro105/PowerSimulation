#pragma once

#include <array>
#include <cstdint>

struct PowerData
{
    std::array<uint8_t, 4> sreamPower{0, 0 ,0, 0};
    uint8_t сondition;
};