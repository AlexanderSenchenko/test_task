#include "include/Context.h"
#include "include/Info.h"
#include "include/Read.h"

Context::Context(char** opts)
{
    std::string opt(*opts);
    if (opt == "-h") {
        this->state = new Info;
    } else if (opt == "-f") {
        this->state = new Read(opts + 1);
    }
}

void Context::StateChanged()
{
    this->state->act();
}

Context::~Context()
{
}
