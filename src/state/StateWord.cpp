#include "../include/StateWord.h"
#include "../include/StateError.h"
#include "../include/StateCount.h"

Word::Word(char** opts, ifstream* in)
{
    if (*opts != nullptr && string(*opts) == "-v") {
        if (*(opts + 1) != nullptr) {
            state = new Count(string(*(++opts)), in);
        } else {
            state = new Error("test: missing search word");
        }
    } else {
        state = new Error("test: missing option(-v)");
    }
}

void Word::act()
{
    state->act();
}

Word::~Word()
{
    delete state;
}
