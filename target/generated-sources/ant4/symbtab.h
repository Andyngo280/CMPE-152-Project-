#pragma once

#ifndef SYMBTAB_H
#define SYMBTAB_H

#include <iostream>
#include <map>
#include <string>
#include <cctype>
#include "symbEntry.h"
using namespace std;

class symbtab
{
    private:
        string name;
        int nlvl;
        map<string, symbEntry *> list;
    public:
        symbtab()
        {
            name = "";
            nlvl = 0;
        }
        void setlvl(int i) {nlvl = i;}
        void setName(string n){name = n;}
        string getName(){return name;}
        int getLvl(){return nlvl;}
        bool checkTab(string name)
        {
            if(list.find(name) != list.end()) return true;

            return false;
        }
        void addEntry(string name, symbEntry * entry)
        {
            list.insert(pair<string,symbEntry *>(name, entry));

            return;
        }
        void printEntries()
        {
            for(auto& x: list)
            {
                cout << "Name: " << x.first << endl;
                cout << "Kind: " << x.second->kind << " Level: " << x.second->nlvl << endl;
                if(x.second->type != nullptr)
                {
                    cout << "Type: ";
                    x.second->type->printType();
                }
                cout << endl;
            }
        }
        symbEntry* getEntry(string name)
        {
            for(auto &x: list)
            {
                if(x.second->name == name) return x.second;
            }

            return nullptr;
        }
};

#endif