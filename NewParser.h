#ifndef NEWPARSER_H_
#define NEWPARSER_H_

#include <iostream>
#include "symbtab.h"
#include "leaf.h"
#include "target/generated-sources/ant4/ExprBaseVisitor.h"
#include "antlr4/antlr4-runtime.h"

using namespace antlr4;
using namespace std;

class newparser : public ExprBaseVisitor
{
    
};

#endif