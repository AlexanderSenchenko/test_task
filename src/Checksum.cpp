#include "include/Checksum.h"
#include <string>

#include <iostream>

Checksum::Checksum(std::ifstream* in)
{
    this->in = in;
}

void Checksum::act()
{
    std::string line;
    while (getline(*this->in, line)) {
        std::cout << line << std::endl;
    }
}

Checksum::~Checksum() {
    if (in != NULL)
        delete in;
}
