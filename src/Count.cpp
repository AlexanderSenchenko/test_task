#include "include/Count.h"
#include <iostream>
#include <string.h>

Count::Count(std::string search_word, std::ifstream* in)
{
    this->in = in;
    this->search_word = search_word;
}

void Count::act()
{
    std::string line;
    const char* delim = " ";
    char *cstr, *savedptr, *token;
    int count = 0;

    while (getline(*this->in, line)) {
        cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());

        token = strtok_r(cstr, delim, &savedptr);
        if (std::string(token) == this->search_word)
            count++;

        while ((token = strtok_r(NULL, delim, &savedptr)) != nullptr) {
            if (std::string(token) == this->search_word)
                count++;
        }

        delete[] cstr;
    }

    std::cout << count << std::endl;
}

Count::~Count() {}
