#include "include/Read.h"
#include "include/Word.h"
#include "include/Checksum.h"
#include "include/Error.h"
#include <string>

Read::Read(char** opts)
{
    if (*opts == nullptr) {
        this->state = new Error("test: expected name file");
        return;
    }

    in = new std::ifstream(*opts);

    if (in->is_open()) {        
        if (*(opts + 1) != nullptr && std::string(*(++opts)) == "-m") {
            ++opts;
            if (*opts != nullptr && std::string(*opts) == "words") {
                this->state =  new Word(++opts, in);
            } else if (*opts != nullptr && std::string(*opts) == "checksum") {
                this->state = new Checksum(in);
            } else {
                this->state = new Error("test: missing option command(words or checksum)");
            }
        } else {
            this->state = new Error("test: missing option operand(-m)");
        }
    } else {
        this->state = new Error("File not found");
    }
}

void Read::act()
{
    this->state->act();
}

Read::~Read()
{
    delete state;
    delete in;
}
