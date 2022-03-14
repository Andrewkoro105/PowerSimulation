#include "gtest/gtest.h"
#include "../../engine/bits/Bits.h"
#include <vector>

TEST(BitTest, ConversionToBits) {
    std::vector<bool> vector{1, 0, 1};
    EXPECT_TRUE(Bits::conversionToBits(5) == vector);

    vector = {0};
    EXPECT_TRUE(Bits::conversionToBits(0) == vector);

    vector = {0, 0, 0, 1, 0, 1};
    EXPECT_TRUE(Bits::conversionToBits(5, 6) == vector);

    vector = {1, 0, 1};
    EXPECT_TRUE(Bits::conversionToBits(5, 3) == vector);
}

TEST(BitTest, ConversionToInt) {
    std::vector<bool> vector{1, 0, 1};
    EXPECT_TRUE(Bits::conversionToInt(vector.begin(), 3) == 5);

    vector = {0};
    EXPECT_TRUE(Bits::conversionToInt(vector.begin(), 1) == 0);

    vector = {};
    EXPECT_TRUE(Bits::conversionToInt(vector.begin(), 0) == 0);
}

TEST(BitTest, conversionToChar) {
    std::vector<bool> vector{0, 0, 1, 1, 0, 0, 0, 0};
    EXPECT_TRUE(Bits::conversionToChar(vector.begin()) == '0');
}
TEST(BitTest, conversionToChars) {
    std::vector<bool> vector{0, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    EXPECT_TRUE(Bits::conversionToChars(vector) == "00");

    vector = {0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0};
    EXPECT_TRUE(Bits::conversionToChars(vector) == "00");
}

TEST(BitTest, BitLoadSave) {
    std::vector<bool> vector{0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 0, 0, 0, 0, 0, 0,
                             0, 0, 1, 1, 0, 1, 0, 1};
    Bits::bitSave(vector, "../../UnitTest/BitsTest/test.bit");
    EXPECT_TRUE(Bits::bitLoad("../../UnitTest/BitsTest/test.bit") == vector);
}