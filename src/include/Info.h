#ifndef INFO_H
#define INFO_H

// #ifndef STATE_H
// #define STATE_H
#include "State.h"
// #endif

class Info : public State
{
public:
    virtual State* getNextState();
    virtual void act();
    // Info(/* args */);
    // ~Info();
};

#endif
