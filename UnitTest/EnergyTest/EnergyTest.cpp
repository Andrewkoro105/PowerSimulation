#include "gtest/gtest.h"
#include "../../engine/bloks/Object.h"
#include "../../engine/Map.h"
#include <array>

TEST(BlockEnegi, oneStepUp) {
    Map map({{Object(0, 0, 0, std::array<uint8_t, 4>()),
              Object(1, 0, 0, std::array<uint8_t, 4>())}});
    map.setObject(Object(2, 0, 0, std::array<uint8_t, 4>()), {0, 0});
    map.energyCalculation();
    map.energyCalculation();
    ASSERT_EQ(static_cast<int>(map.getObject({0, 1}).getPowerData().сondition), 1);
}

TEST(BlockEnegi, oneStepRight) {
    Map map({{Object(0, 0, 0, std::array<uint8_t, 4>())},
             {Object(1, 1, 0, std::array<uint8_t, 4>())}});
    map.setObject(Object(2, 0, 0, std::array<uint8_t, 4>()), {0, 0});
    map.energyCalculation();
    map.energyCalculation();
    ASSERT_EQ(static_cast<int>(map.getObject({1, 0}).getPowerData().сondition), 1);
}

TEST(BlockEnegi, twoStepRight ) {
    Map map({{Object(0, 0, 0, std::array<uint8_t, 4>())},
             {Object(1, 1, 0, std::array<uint8_t, 4>())},
             {Object(1, 1, 0, std::array<uint8_t, 4>())}});
    map.setObject(Object(2, 0, 0, std::array<uint8_t, 4>()), {0, 0});
    map.energyCalculation();
    map.energyCalculation();
    map.energyCalculation();
    ASSERT_EQ(static_cast<int>(map.getObject({2, 0}).getPowerData().сondition), 1);
}

TEST(BlockEnegi, twoStepUp) {
    Map map({{Object(0, 0, 0, std::array<uint8_t, 4>()),
              Object(1, 0, 0, std::array<uint8_t, 4>()),
              Object(1, 0, 0, std::array<uint8_t, 4>())}});
    map.setObject(Object(2, 0, 0, std::array<uint8_t, 4>()), {0, 0});
    map.energyCalculation();
    map.energyCalculation();
    map.energyCalculation();
    ASSERT_EQ(static_cast<int>(map.getObject({0, 2}).getPowerData().сondition), 1);
}

TEST(BlockEnegi_Wire, UpOne) {
    Map map({{
                     Object(2, 0, 0, std::array<uint8_t, 4>()),
                     Object(0, 0, 0, std::array<uint8_t, 4>())
             }});
    map.setObject(Object(1, 0, 0, std::array<uint8_t, 4>()), {0, 1});
    map.energyCalculation();
    ASSERT_EQ(map.getObject({0, 1}).getPowerData().сondition, 1);
}
