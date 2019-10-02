#include "../include/StateCount.h"
#include <iostream>
#include <string.h>

Count::Count(string search_word, ifstream* in)
{
    this->in = in;
    this->search_word = search_word;
}

void Count::act()
{
    string line;
    const char* delim = " ";
    char *cstr, *savedptr, *token;
    int count = 0;

    while (getline(*in, line)) {
        cstr = new char[line.length() + 1];
        strcpy(cstr, line.c_str());

        token = strtok_r(cstr, delim, &savedptr);
        if (string(token) == search_word)
            count++;

        while ((token = strtok_r(NULL, delim, &savedptr)) != nullptr) {
            if (string(token) == search_word)
                count++;
        }

        delete[] cstr;
    }

    cout << "Number of words \"" + search_word + "\" in a file: " << count << endl;
}

Count::~Count() {}
