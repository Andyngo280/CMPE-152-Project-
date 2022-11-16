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
    private:
        struct helpful
        {
            typeSpec* array;
            vector<symbEntry*> funct_param;
        };
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
        string value;
        typeSpec *type;
        int nlvl;
        helpful extras;
};

#endif