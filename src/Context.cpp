#include "include/Context.h"
#include "include/Info.h"
#include "include/Read.h"
#include "include/Error.h"

Context::Context(char** opts)
{
    if (*opts == nullptr) {
        this->state = new Error("test: missing option operand");
        return;
    }

    std::string opt(*opts);
    if (opt == "-h") {
        this->state = new Info;
    } else if (opt == "-f") {
        this->state = new Read(opts + 1);
    } else {
        this->state = new Error("test: missing option operand(-f or -h)");
    }
}

void Context::StateChanged() { this->state->act(); }

Context::~Context() {
    if (state != nullptr)
        delete state;
}
