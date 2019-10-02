#ifndef READ_H
#define READ_H

#include "State.h"
#include <fstream>

using namespace std;

class Read : public State
{
private:
    State* state;
    ifstream* in;
public:
    Read(char**);
    virtual void act();
    ~Read();
};

#endif
