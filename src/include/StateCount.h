#ifndef COUNT_H
#define COUNT_H

#include "State.h"
#include <fstream>
#include <string>

using namespace std;

class Count : public State
{
private:
    ifstream* in;
    string search_word;
public:
    Count(string, ifstream*);
    virtual void act();
    ~Count();
};

#endif