#ifndef COUNT_H
#define COUNT_H

#include "State.h"
#include <fstream>
#include <string>

class Count : public State
{
private:
    std::ifstream* in;
    std::string search_word;
public:
    Count(std::string, std::ifstream*);
    virtual void act();
    ~Count();
};

#endif