#include "include/Error.h"
#include <iostream>

Error::Error(std::string err_msg)
{
    this->err_msg = err_msg;
}

void Error::act()
{
    std::cout << err_msg << std::endl;
}

Error::~Error() {}
