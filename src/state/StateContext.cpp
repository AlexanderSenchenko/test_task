#include "../include/StateContext.h"
#include "../include/StateInfo.h"
#include "../include/StateRead.h"
#include "../include/StateError.h"

using namespace std;

Context::Context(char** opts)
{
    if (*opts == nullptr) {
        state = new Error("test: missing option");
        return;
    }

    string opt(*opts);
    if (opt == "-h") {
        state = new Info;
    } else if (opt == "-f") {
        state = new Read(opts + 1);
    } else {
        state = new Error("test: missing option(-f or -h)");
    }
}

void Context::StateChanged() { state->act(); }

Context::~Context() {
    if (state != nullptr)
        delete state;
}
