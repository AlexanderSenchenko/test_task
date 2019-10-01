#include "include/Count.h"
#include <iostream>

Count::Count(std::string search_word, std::ifstream* in)
{
    this->in = in;
    this->search_word = search_word;
}

void Count::act()
{
    std::string line;
    std::cout << this->search_word << std::endl;
    while (getline(*this->in, line)) {
        std::cout << line << std::endl;
    }
}

Count::~Count()
{
}