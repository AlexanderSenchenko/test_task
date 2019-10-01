#include <iostream>
#include "include/Context.h"

int main(int argc, char** argv)
{
    Context obj(argv + 1);
    obj.StateChanged();

    return 0;
}
