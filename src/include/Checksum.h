#ifndef CHECKSUM_H
#define CHECKSUM_H

#include "State.h"
#include <fstream>

class Checksum : public State
{
private:
    std::ifstream* in;
public:
    Checksum(std::ifstream*);
    virtual void act();
    ~Checksum();
};

#endif
