#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"

class Context
{
private:
    State* state;
public:
    Context(State*);
    void StateChanged();
    ~Context();
};

#endif