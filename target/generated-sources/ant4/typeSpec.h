#pragma once

#ifndef TYPESPEC_H
#define TYPESPEC_H

#include <iostream>
#include <string>
using namespace std;

class typeSpec
{
    private:
        string kind;
        struct array 
        {
            typeSpec *indexType;
            typeSpec *elementType;
            int max;
            int min;
            int amount;
        };
        array info;
    public:
        typeSpec(){}
        void setKind(string n){kind = n;}
        string getKind(){return kind;}
        typeSpec* getIndex(){return info.indexType;}
        void setIndex(typeSpec* index_type)
        {
            info.indexType = index_type;
        }
        void setMax(int x)
        {
            info.max = x;
        }
        void setMin(int x)
        {
            info.min = x;
        }
        int getMax() {return info.max;}
        int getMin() {return info.min;}
        void setElement(typeSpec *element_type)
        {
            info.elementType = element_type;
        }
        void setAmount(int amt)
        {
            info.amount = amt;
        }
        void printType()
        {
            cout << kind << endl;
            if(kind == "ARRAY")
            {
                cout << "Element Count: " << info.amount << endl;
                cout << "Index Range: " << info.min << " to " << info.max << endl;
                cout << "IndexType: ";
                info.indexType->printType();
                cout << "ElementType: ";
                info.elementType->printType();
            }
        }
        string getElemType()
        {
            if(kind == "ARRAY")
            {
                return info.elementType->getElemType();
            }

            return kind;
        }
        typeSpec* getType()
        {
            return info.elementType;
        }
    
};

#endif