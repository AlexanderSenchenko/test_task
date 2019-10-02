#include "../include/StateError.h"
#include <iostream>

Error::Error(string err_msg)
{
    this->err_msg = err_msg;
}

void Error::act()
{
    cout << err_msg << endl;
}

Error::~Error() {}
