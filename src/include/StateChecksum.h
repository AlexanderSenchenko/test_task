#ifndef CHECKSUM_H
#define CHECKSUM_H

#include "State.h"
#include <fstream>

using namespace std;

class Checksum : public State
{
private:
    ifstream* in;
public:
    Checksum(ifstream*);
    virtual void act();
    ~Checksum();
};

#endif
