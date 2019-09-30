#include "include/Info.h"
#include <iostream>

State* Info::getNextState()
{
    return nullptr;
}

void Info::act()
{
    std::cout << "Usage: test [OPTION] [FILE]" << std::endl;
    std::cout << std::endl;
    std::cout << "Mandatory arguments." << std::endl;
    std::cout << "\t-f" << std::endl;
    std::cout << "\t-h" << std::endl;
}

// Info::Info(/* args */)
// {
// }

// Info::~Info()
// {
// }
