
#include <iostream>
#include "IOUtility.h"
#include "BitSwapper.h"

int main()
{
    std::cout << IOUtility::BinaryRepresentation(0b00000101000111010100101001010010) << std::endl;
    std::cout << IOUtility::BinaryRepresentation(BitSwapper::SwapNPairsStartingFromBitIndex(0b00000101000111010100101001010010, 8, 16)) << std::endl;

}
