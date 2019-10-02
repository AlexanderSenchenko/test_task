#include "../include/StateRead.h"
#include "../include/StateWord.h"
#include "../include/StateChecksum.h"
#include "../include/StateError.h"
#include <string>

Read::Read(char** opts)
{
    if (*opts == nullptr) {
        state = new Error("test: expects name file");
        return;
    }

    in = new ifstream(*opts);

    if (in->is_open()) {        
        if (*(opts + 1) != nullptr && string(*(++opts)) == "-m") {
            ++opts;
            if (*opts != nullptr && string(*opts) == "words") {
                state =  new Word(++opts, in);
            } else if (*opts != nullptr && string(*opts) == "checksum") {
                state = new Checksum(in);
            } else {
                state = new Error("test: missing command(words or checksum)");
            }
        } else {
            state = new Error("test: missing option(-m)");
        }
    } else {
        state = new Error("test: no such file");
    }
}

void Read::act()
{
    state->act();
}

Read::~Read()
{
    delete state;
    delete in;
}
