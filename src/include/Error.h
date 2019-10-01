#ifndef ERROR_H
#define ERROR_H

#include "State.h"
#include <string>

class Error : public State
{
private:
    std::string err_msg;
public:
    Error(std::string);
    virtual void act();
    ~Error();
};

#endif
