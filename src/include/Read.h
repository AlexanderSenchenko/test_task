#ifndef READ_H
#define READ_H

#include "State.h"
#include <fstream>

class Read : public State
{
private:
    State* state;
    std::ifstream* in;
public:
    Read(char**);
    virtual void act();
    ~Read();
};

#endif
