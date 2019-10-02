#ifndef CONTEXT_H
#define CONTEXT_H

#include "State.h"

class Context
{
private:
    State* state;
public:
    Context(char**);
    void StateChanged();
    ~Context();
};

#endif
