#ifndef ERROR_H
#define ERROR_H

#include "State.h"
#include <string>

using namespace std;

class Error : public State
{
private:
    string err_msg;
public:
    Error(string);
    virtual void act();
    ~Error();
};

#endif
