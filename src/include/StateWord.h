#ifndef WORD_H
#define WORD_H

#include "State.h"
#include <fstream>
#include <string>

using namespace std;

class Word : public State
{
private:
    State *state;
public:
    Word(char**, ifstream*);
    virtual void act();
    ~Word();
};

#endif
