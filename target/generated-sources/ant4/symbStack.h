#pragma once

#ifndef SYMBSTACK_H
#define SYMBSTACK_H

#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include "symbtab.h"
#include "symbEntry.h"

using namespace std;

class symbStack
{
    private:
        string name;
        vector<symbtab *> stack;
        symbtab *current_table;
    public:
        symbStack()
        {
            current_table = new symbtab;
            current_table->setName("Predefined");
            current_table->setlvl(0);

            symbEntry *entry = new symbEntry;
            entry->name = "integer";
            entry->kind = "PREDEF_CONST";
            entry->type = nullptr;
            entry->nlvl = 0;
            current_table->addEntry("integer", entry);

            //cout << entry->name << endl;

            entry = new symbEntry;
            entry->name = "real";
            entry->kind = "PREDEF_CONST";
            entry->type = nullptr;
            entry->nlvl = 0;
            current_table->addEntry("real", entry);

            //cout << entry->name << endl;

            entry = new symbEntry;
            entry->name = "boolean";
            entry->kind = "PREDEF_CONST";
            entry->type = nullptr;
            entry->nlvl = 0;
            current_table->addEntry("boolean", entry);

            //cout << entry->name << endl;

            entry = new symbEntry;
            entry->name = "char";
            entry->kind = "PREDEF_CONST";
            entry->type = nullptr;
            entry->nlvl = 0;
            current_table->addEntry("char", entry);

            //cout << entry->name << endl;

            stack.push_back(current_table);
        }
        void push(symbtab * table)
        {
            current_table = table;
            stack.push_back(current_table);
        }
        void pop()
        {
            stack.pop_back();
            current_table = stack.back();
        }
        symbtab* getLocal()
        {
            return current_table;
        }
        bool checkStack(string name)
        {
            for(int i = stack.size()-1; i >= 0; i--)
            {
                if(stack[i]->checkTab(name)) return true;
            }

            return false;
        }
        symbEntry *getEntry(string name)
        {
            for(int i = stack.size()-1; i >= 0; i--)
            {
                return stack[i]->getEntry(name);
            }

            return nullptr;
        }
        void printTables()
        {
            for(int i = 0; i < stack.size(); i++)
            {
                cout << "Table: " << stack[i]->getName() << " level: " << stack[i]->getLvl() << endl << endl;
                stack[i]->printEntries();
                cout << "-----------------------------------------------------" << endl;
            }
        }        
        
};

#endif