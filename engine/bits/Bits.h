#pragma once
#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cmath>

namespace Bits
{
    std::vector<bool> bitLoad(std::string path);
    void bitSave(std::vector<bool> bits, std::string path);
    int conversionToInt(std::vector<bool>::iterator bits, int size);
    char conversionToChar(std::vector<bool>::iterator bits);
    std::string conversionToChars(std::vector<bool>& bits);
    std::vector<bool> conversionToBits(int number);
    std::vector<bool> conversionToBits(int number, uint16_t sizeArrayBits);
    void conversionToBits(int number, uint16_t sizeArrayBits, std::vector<bool> & toInBits);
}
