#include "include/Checksum.h"
#include <string>

#include <iostream>
#include <stdio.h>

// #define MAX_NUMBER 0x100000000
#define MAX_NUMBER 0xFFFFFFFF

Checksum::Checksum(std::ifstream* in)
{
    this->in = in;
}

void Checksum::act()
{
    uint64_t buf = 0;
    uint32_t csum = 0;
    int length;
    int count_byte = sizeof(csum);

    in->seekg (0, in->end);
    length = in->tellg();
    in->seekg (0, in->beg);

    while (in->read(reinterpret_cast<char*>(&csum), count_byte)) {
        buf = buf + csum;
        while ((buf >> 32) != 0)
            buf = (buf & MAX_NUMBER) + (buf >> 32);

        if (length - in->tellg() < count_byte && length - in->tellg() > 0)
            count_byte = length - in->tellg();

        csum = 0;
    }

    printf("Checksum = %x\n", (uint32_t) buf);
}

Checksum::~Checksum() {
    if (in != NULL) {
        in->close();
        delete in;
    }
}
