#include <iostream>
#include "include/StateContext.h"

int main(int argc, char** argv)
{
    Context obj(argv + 1);
    obj.StateChanged();

    return 0;
}
