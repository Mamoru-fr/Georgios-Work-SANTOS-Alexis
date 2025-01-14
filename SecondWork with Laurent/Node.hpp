#include <iostream>
#include <string>

using namespace std;

#ifndef Human_H
#define Human_H

struct Human
{
    string name;
    Human *dad;
    Human *mom;
    Human *son;

    Human(string k, Human *s) : name(k), son(nullptr), dad(nullptr), mom(nullptr) {}
};

#endif