#include "../include/StateInfo.h"
#include <iostream>

using namespace std;

void Info::act()
{
    cout << "test -f FILE -m words -v \"word\"";
    cout << "\tnumber of words \"word\" in the file" << endl;
    
    cout << "test -f FILE -m checksum";
    cout << "\t32 bit checksum" << endl;
    
    cout << "test -h";
    cout << "\t\t\t\tdisplay this help and exit" << endl;
}

Info::~Info() {}
