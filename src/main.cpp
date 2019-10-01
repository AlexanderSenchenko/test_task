#include <iostream>
#include "include/Context.h"
#include "include/Info.h"

int main(int argc, char** argv)
{
    if (argc < 2) {
        std::cout << "test: missing option operand" << std::endl;
        std::cout << "Try 'test -h' for more information." << std::endl;
        exit(EXIT_FAILURE);
    } else {
        // std::cout << *(argv + 1) << std::endl;
    }

    Context obj(argv + 1);
    obj.StateChanged();

    return 0;
}
