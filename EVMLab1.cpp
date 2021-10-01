
#include <iostream>
#include "IOUtility.h"
#include "BitSwapper.h"

int main()
{
    float testVal = 33.08f;
    std::cout << "Example:" << std::endl;
    std::cout << "Original value: " << testVal << std::endl;
    std::cout << "In binary: " << IOUtility::BinaryRepresentation(testVal) << std::endl;

    float res = BitSwapper::SwapNPairsStartingFromBitIndex(testVal, 8, 8);
    std::cout << "With 8 pairs swapped starting from bit[8]: " << IOUtility::BinaryRepresentation(res) << std::endl;
    std::cout << "In decimal: " << res << std::endl;

}
