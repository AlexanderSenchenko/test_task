#include "include/Word.h"
#include "include/Error.h"
#include "include/Count.h"

Word::Word(char** opts, std::ifstream* in)
{
    std::string opt(*opts);
    if (opt == "-v") {
        if (*(opts + 1) != nullptr) {
            state = new Count(std::string(*(++opts)), in);
        } else {
            state = new Error("test: missing option operand(search word)");
        }
    } else {
        state = new Error("test: missing option operand(-v)");
    }
}

void Word::act()
{
    this->state->act();
}

Word::~Word()
{
    delete state;
}
