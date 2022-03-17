#include <iostream>
#include "gtest/gtest.h"
#include "SFML/Graphics.hpp"
#include "../../engine/Map.h"

TEST(MapTest, SaveTesting) {
    std::string pathToMap = "../../UnitTest/MapSaveTest/test.psm";

    Map map(std::vector<std::vector<Object>>(16, std::vector<Object>(16, Object{1, 1, 1})), pathToMap);
    map.save(pathToMap);
    Map map1(pathToMap);
    EXPECT_TRUE(map == map1);
}

TEST(MapTest, ChangeRetention) {
    std::string pathToMap = "../../UnitTest/MapSaveTest/test2.psm";

    Map map(std::vector<std::vector<Object>>(1, std::vector<Object>(2, Object{0, 0, 0})), pathToMap);
    //world.setObject(Object(3, 0, 0), {5, 8});
    map.setObject(Object(1, 2, 0, std::array<uint8_t, 4>()), {0, 0});
    map.save(pathToMap);
    Map map1(pathToMap);
    EXPECT_TRUE(map == map1);
}
TEST(MapTest, fourCondition) {
    std::string pathToMap = "../../UnitTest/MapSaveTest/test3.psm";

    Map map(std::vector<std::vector<Object>>(1, std::vector<Object>(1, Object{8, 0, 3})), pathToMap);
    map.save(pathToMap);
    Map map1(pathToMap);
    EXPECT_TRUE(map == map1);
}