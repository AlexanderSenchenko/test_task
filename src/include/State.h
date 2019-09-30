#ifndef STATE_H
#define STATE_H

class State
{
public:
    virtual State* getNextState() = 0;
    virtual void act() = 0;
};

#endif
