#include "include/Read.h"
#include "include/Word.h"
#include "include/Checksum.h"
#include "include/Error.h"
#include <string>

#include <stdio.h>
#include <string>
#include <iostream>

Read::Read(char** opts)
{
    in = new std::ifstream(*opts);
    std::string line;

    if (in->is_open()) {
        // std::cout << opts[0] << std::endl;
        if (std::string(*(++opts)) == "-m") {
            // std::cout << opts[0] << std::endl;
            std::string opt(*(++opts));
            // std::cout << opts[0] << std::endl;
            if (opt == "words") {
                this->state =  new Word(opts + 1, in);
            } else if (opt == "checksum") {
                this->state = new Checksum(in);
            } else {
                this->state = new Error("test: missing option operand");
                delete in;
            }
        } else {
            this->state = new Error("test: missing option operand");
            delete in;
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
}
