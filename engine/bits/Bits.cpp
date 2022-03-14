#include "Bits.h"

namespace Bits {
    std::vector<bool> bitLoad(std::string path) {
        std::vector<bool> bits;

        std::ifstream fileMap(path);
        if (fileMap.is_open()) {
            char ch;
            while (fileMap.get(ch)) {
                for (int i = 0; i < 8; ++i) {
                    bool bit = (ch & 128 >> i) ? 1 : 0;
                    bits.push_back(bit);
                }
            }
        } else

        fileMap.close();
        return bits;
    }

    void bitSave(std::vector<bool> bits, std::string path) {
        std::ofstream file(path);
        if (file.is_open()) {
            std::string Byts = conversionToChars(bits);
            for (char &ch: Byts) {
                file << ch;
            }
        } else

        file.close();
    }


    int conversionToInt(std::vector<bool>::iterator bits, int size) {
        int rezult = 0;

        for (int i = 0; i < size; ++i) {
            rezult += *(bits + i) * pow(2, size - 1 - i);
        }

        return rezult;
    }

    char conversionToChar(std::vector<bool>::iterator bits) {
        return conversionToInt(bits, 8);
    }

    std::string conversionToChars(std::vector<bool> &bits) {
        std::string result;

        int residue = bits.size() % 8;
        residue = residue == 0 ? 0 : 8 - residue;

        int countByt = (int)(bits.size() / 8) * 8;

        for (int i = 0; i < residue; ++i) {
            bits.insert(bits.begin() + countByt, 0);
        }

        for (int i = 0; i < bits.size(); i += 8) {
            result.push_back(conversionToChar(bits.begin() + i));
        }
        return result;
    }

    std::vector<bool> conversionToBits(int number) {
        std::vector<bool> buffer;
        do {
            buffer.insert(buffer.begin(), number % 2);
            number = number / 2;
        } while (number > 0);
        return buffer;
    }

    std::vector<bool> conversionToBits(int number, uint16_t sizeArrayBits) {
        std::vector<bool> bits = conversionToBits(number);
        int countAdditionalZero = sizeArrayBits - bits.size();
        for (int i = 0; i < countAdditionalZero; ++i) {
            bits.insert(bits.begin(), 0);
        }

        return bits;
    }

    void conversionToBits(int number, uint16_t sizeArrayBits, std::vector<bool> &toInBits) {
        std::vector<bool> Bits = conversionToBits(number, sizeArrayBits);

        toInBits.insert(toInBits.end(), Bits.begin(), Bits.end());
    }
}