#ifndef WORD_H
#define WORD_H

#include "State.h"
#include <fstream>
#include <string>

class Word : public State
{
private:
    State *state;
public:
    Word(char**, std::ifstream*);
    virtual void act();
    ~Word();
};

#endif
