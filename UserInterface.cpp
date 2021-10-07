#include "UserInterface.h"
#include "BitSwapper.h"
#include "IOUtility.h"
#include <iostream>

void UserInterface::showValueInputInterface()
{
    int choice;
    bool call = true;
    std::cout << "Choose the type:\n 1.float \n 2.unsigned long (When entering a floating point number, the fractional part is discarded)\n 3. Exit programm. \n" << std::endl;

    while (call) {
        std::cout << "Your choice: ";
        std::cin >> choice; std::cout << std::endl;
        switch (choice){
        case 1: {
            showBitSwapInterface(InputValue<float>());
            break;
        }
        case 2: {
            showBitSwapInterface(InputValue<unsigned long>());
            break;
        }
        case 3: {
            std::cout << "\nExiting..." << std::endl; //exit
            call = false;
            break;
        }
        default: {
            std::cin.clear();
            std::cin.ignore(100100, '\n');
            std::cout << "Wrong input!\n" << std::endl;
        }
        }
    }
}
