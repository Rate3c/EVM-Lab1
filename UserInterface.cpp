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