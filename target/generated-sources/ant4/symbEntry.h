#pragma once

#ifndef SYMBENTRY_H
#define SYMBENRTY_H

#include <iostream>
#include <string>
#include <vector>
#include "typeSpec.h"
using namespace std;

class symbEntry
{
    public:
        symbEntry()
        {
            name = "";
            kind = "";
            type = nullptr;
            nlvl = 0;
        }
        string name;
        string kind;
        typeSpec *type;
        int nlvl;
        union helpful
        {
            symbEntry *array;
            vector<symbEntry*> funct_param;
        };
};

#endif