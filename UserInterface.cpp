#include "UserInterface.h"
#include "BitSwapper.h"
#include "IOUtility.h"
#include <iostream>

void UserInterface::showValueInputInterface()
{
    long double inputValue;
    float floatValue;
    unsigned long ulValue;
    int choice;

    while (true) {
        std::cout << "1.Enter your nubmer: ";
        std::cin >> inputValue; std::cout << std::endl;
        if (!std::cin)
        {
            std::cout << "ERROR! Incorrect input!" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(100100, '\n');
        }
        else break;
    }
    std::cout << "Choose the type:\n 1.float \n 2.unsigned long\n";
    
    while (true) {
        std::cout << "Your choice: ";
        std::cin >> choice;
        if (choice == 1) {
            floatValue = (float)inputValue;
            showBitSwapInterface(floatValue);
            break;
        }
        else if (choice == 2) {
            ulValue = (unsigned long)inputValue;
            showBitSwapInterface(ulValue);
            break;
        }
        else {
            std::cin.clear();
            std::cin.ignore(100100, '\n');
            std::cout << "Wrong input!\n" << std::endl;
        }
    }

}

void UserInterface::showBitSwapInterface(float value)
{
    int Npairs, index;
    while (true) {
        std::cout << std::endl << "2.How many pairs do you want to swap?: ";
        std::cin >> Npairs; std::cout << std::endl;
        if ((!std::cin) || (Npairs < 1) || (Npairs > sizeof(value) * 4)) // check for required type of input and required amount of pairs
        {
            std::cout << "ERROR! The input must be positive integer number (except 0) and must not exceed the number of pairs of bits in the original number!" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(100100, '\n');
        }
        else break;
    }
    while (true) {
        std::cout << "3.Enter the bit index - the beginning of the swap: ";
        std::cin >> index; std::cout << std::endl;
        if ((!std::cin) || (index < 0) || (index > sizeof(value) * 8)) {  // check for required type of input and required begining of swap 

            std::cout << "ERROR! The input must be positive integer number and must not exceed the number of bits in the original number!" << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(100100, '\n');
        }
        else if ((sizeof(value) * 8 - index) <= (Npairs * 2)) {  // check for the required number of bits for swap

            std::cout << "ERROR! Not enough bits to swap " << Npairs << " pairs! Choose a smaller suitable beginning of swap. " << std::endl << std::endl;
            std::cin.clear();
            std::cin.ignore(100100, '\n');
        }
        else break;
    }
    std::cout << "Original value: " << value << std::endl;
    std::cout << "In binary: " << IOUtility::BinaryRepresentation(value) << std::endl; // binary representation of input value

    float res = BitSwapper::SwapNPairsStartingFromBitIndex(value, Npairs, index);  // swap function
    std::cout << "With " << Npairs << " pairs swapped starting from bit[" << index << "]: " << IOUtility::BinaryRepresentation(res) << std::endl; // binary representation of swaped input value
    std::cout << "In decimal: " << res << std::endl;
}
