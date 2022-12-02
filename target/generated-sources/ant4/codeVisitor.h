
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"
#include "typeSpec.h"
#include <iostream>
#include <string>
#include <map>
#include <vector>


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */

 /* for many purposes like returning a constant and its value for the optimizations
 *  or to hold the variable name and its index
 */

struct node
{
    string name;
    string value;
    int max;
};

/* Will act like a mini runtime stack frame holding the index of each variable
*/

vector<node> rtFrame;


class  codeVisitor : public ExprBaseVisitor
{
private:
    int labels = 0;
    int size = 0;
    struct values {

        string val;
        //will declare these to store values
        //for arithmetic, use stoi() to convert strings to integer
    };

    string instructTabs = "\t\t\t\t";

public:

    virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext* ctx) override
    {
        labels = 1;
        cout << "test\t\t\tSTART\t0" << endl;
        visitChildren(ctx);
        cout << endl;

        //checking if a variable holds the correct value
        cout << instructTabs << "CLEAR X" << endl;
        cout << instructTabs << "CLEAR T" << endl;
        cout << instructTabs << "LDA #1747" << endl;    //finding beta: stackindex-offset => 1762-15
        cout << instructTabs << "ADDR A,X" << endl;
        cout << instructTabs << "LDT stack,X" << endl;

        cout << "stack\t\t\tRESB 10000" << endl;
        cout << "stackindex\t\tWORD 0" << endl;
        cout << "stackmax\t\tWORD 10000" << endl;
        cout << "returnvalue\t\tRESB 500" << endl;
        cout << "returnmax\t\tWORD 500" << endl;
        cout << instructTabs << "END  0" << endl;
        return 0;
        //return visitChildren(ctx);

    }

    virtual antlrcpp::Any visitProgram_header(ExprParser::Program_headerContext* ctx) override
    {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDeclarations(ExprParser::DeclarationsContext* ctx) override {

        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitConstants(ExprParser::ConstantsContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitConstant_list(ExprParser::Constant_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitConstant_declaration(ExprParser::Constant_declarationContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitConst_identifier(ExprParser::Const_identifierContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitTypes(ExprParser::TypesContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitType_list(ExprParser::Type_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitType_declaration(ExprParser::Type_declarationContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitType_identifier_list(ExprParser::Type_identifier_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitType_identifier(ExprParser::Type_identifierContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitType_specification(ExprParser::Type_specificationContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitSimpletype(ExprParser::SimpletypeContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitArraytype(ExprParser::ArraytypeContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitArray_start(ExprParser::Array_startContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitDimensions(ExprParser::DimensionsContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitScalar(ExprParser::ScalarContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitRange(ExprParser::RangeContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVariables(ExprParser::VariablesContext* ctx) override
    {
        //   do not know how to declare variables yet
        //   need to know how to access them later on
        //   will change 'return visitChild...'
        //   will manually visit variable identifier list
        //   after, declare a stack frame/increment stack index by size amount

        visitChildren(ctx);

        /*for (int i = 0; i < rtFrame.size(); i++)
        {
          cout << rtFrame[i].name << " " << rtFrame[i].value << endl;
        }*/

        size += 9;
        cout << instructTabs << "LDA stackindex" << endl;     //  load stack index to A
        cout << instructTabs << "ADD #" << size << endl;      //  add (max stack frame size) to A
        cout << instructTabs << "STA stackindex" << endl;     //  store ^^ into stack index
        cout << instructTabs << "CLEAR X" << endl;            //  empty X
        cout << instructTabs << "LDA #" << size - 3 << endl;  //  load (address of prev frame index) to A
        cout << instructTabs << "ADDR A,X" << endl;           //  X = X + A
        cout << instructTabs << "LDA #0" << endl;             //  load previous frame index to A
        cout << instructTabs << "STA stack,X" << endl;        //  store ^^ to stack
        cout << instructTabs << "CLEAR X" << endl;
        cout << instructTabs << "LDA #" << size - 6 << endl;  //load address of frames scope
        cout << instructTabs << "ADDR A,X" << endl;
        cout << instructTabs << "LDA #1" << endl;
        cout << instructTabs << "STA stack,X" << endl;        //store scope
        cout << endl;
        size = 0;

        return 0;
    }

    virtual antlrcpp::Any visitVariable_list(ExprParser::Variable_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVariable_declarations(ExprParser::Variable_declarationsContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVar_identifier_list(ExprParser::Var_identifier_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitVar_identifier(ExprParser::Var_identifierContext* ctx) override
    {

        //cout << ctx->entry->name << endl;

        //  check each entry type
        //  depending on type, we increment size by an amount
        //  we also create a node to hold the name and size value
        //  then we add the struct to the vector called rtFrame;

        int x = 1;
        //cout << ctx->entry->name << " " << ctx->entry->type->getKind() << endl;

        node entry;

        if (ctx->entry->type->getKind() == "integer")
        {
            entry.name = ctx->entry->name;
            size += 3;
            entry.value = to_string(size);
        }
        else if (ctx->entry->type->getKind() == "char")
        {
            entry.name = ctx->entry->name;
            size += 1;
            entry.value = to_string(size);
        }
        else if (ctx->entry->type->getKind() == "boolean")
        {
            entry.name = ctx->entry->name;
            size += 1;
            entry.value = to_string(size);
        }
        else //an array check its typeSpec via extras member function of symbEntry
        {
            entry.name = ctx->entry->name;

            typeSpec* spec = ctx->entry->extras.array;
            while (spec->getType() != nullptr)
            {
                x *= spec->getAmt();
                spec = spec->getType();
            }

            //cout << x << endl;
            if (spec->getElemType() == "integer")
            {
                x *= 3;
            }
            else if (spec->getElemType() == "char")
            {
                x *= 1;
                //multiply x by char amount amount of bytes
            }
            else if (spec->getElemType() == "boolean")
            {
                x *= 1;
                //multiply x by boolean amount of bytes
            }

            if (spec != nullptr)
                //cout << spec->getElemType() << endl;
                size += x;
            entry.value = to_string(size);
        }

        entry.max = size;
        rtFrame.push_back(entry);
        return 0;
    }

    virtual antlrcpp::Any visitFunctions(ExprParser::FunctionsContext* ctx) override {

        //will do later
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFunct_type(ExprParser::Funct_typeContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitProc(ExprParser::ProcContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFunct(ExprParser::FunctContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFunct_identifier(ExprParser::Funct_identifierContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParameters(ExprParser::ParametersContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParam_list(ExprParser::Param_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParam_declaration(ExprParser::Param_declarationContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParam_identifier_list(ExprParser::Param_identifier_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitParam_identifier(ExprParser::Param_identifierContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStatement_list(ExprParser::Statement_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitStatement(ExprParser::StatementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCompound_statement(ExprParser::Compound_statementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitAssign_statement(ExprParser::Assign_statementContext* ctx) override 
    {
        cout << endl;
        int x = visitExpression(ctx->expression());
        //cout << value.name << " " << value.value << endl;
        //cout << "assign" << endl;
        int offset = 0;
        for (int i = 0; i < rtFrame.size(); i++)
        {
            if (rtFrame[i].name == ctx->variable()->IDENTIFIER()->getText())
            {
                offset = stoi(rtFrame[i].value);
            }
        }
        //cout << rtFrame[rtFrame.size()-1].max << endl;
        int max = rtFrame[rtFrame.size() - 1].max + 9;
        if (ctx->variable()->IDENTIFIER() != nullptr)
        {

            if (x > 0)
            {
                cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                cout << "\t\t\t\tSUB #" << 9 + x << endl;
                cout << instructTabs << "CLEAR X" << endl;
                cout << instructTabs << "ADDR A,X" << endl;               //load addr to X
                cout << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
            }
            else
            {
                if (ctx->variable()->entry->type->getKind() == "integer")
                {
                    cout << instructTabs << "LDA stackindex" << endl;         //load index to A
                    cout << instructTabs << "SUB #3" << endl;                 //decrement index to get addr of rhs value
                    cout << instructTabs << "STA stackindex" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    cout << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
                else if (ctx->variable()->entry->type->getKind() == "char")
                {
                    cout << instructTabs << "LDA stackindex" << endl;         //load index to A
                    cout << instructTabs << "SUB #1" << endl;                 //decrement index to get addr of rhs value
                    cout << instructTabs << "STA stackindex" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    cout << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
                else if (ctx->variable()->entry->type->getKind() == "boolean")
                {
                    cout << instructTabs << "LDA stackindex" << endl;         //load index to A
                    cout << instructTabs << "SUB #1" << endl;                 //decrement index to get addr of rhs value
                    cout << instructTabs << "STA stackindex" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    cout << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
            }
        }
        else if (ctx->variable()->function_call() != nullptr)
        {

        }
        else if (ctx->variable()->array_element() != nullptr)
        {

        }

        cout << instructTabs << "LDA stackindex" << endl;                 //load index to A
        cout << instructTabs << "SUB #" << 9 + offset << endl;            //subtract 9 and offset to get addr of lhs
        cout << instructTabs << "CLEAR X" << endl;
        cout << instructTabs << "ADDR A,X" << endl;                       //load addr to x
        cout << instructTabs << "STT stack,X" << endl;                    //store T(rhs) value to lhs

        return 0;
    }

    virtual antlrcpp::Any visitRepeat_statement(ExprParser::Repeat_statementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitIf_statement(ExprParser::If_statementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitWhile_statement(ExprParser::While_statementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCase_statement(ExprParser::Case_statementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitCondition(ExprParser::ConditionContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFor_statement(ExprParser::For_statementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext* ctx) override
    {

        int size = ctx->simple_expression().size();
        int x1 = visitSimple_expression(ctx->simple_expression(size - 1));
        //cout << "exp" << endl;

        return x1;
    }

    virtual antlrcpp::Any visitSimple_expression(ExprParser::Simple_expressionContext* ctx) override
    {

        int size = ctx->term().size();
        int x1 = visitTerm(ctx->term(0));
        int x2 = 0;
        int p = 0; //plus index
        int m = 0; //minus index

        for (int i = 1; i < size; i++)
        {
            x2 = visitTerm(ctx->term(i));

            if (p < ctx->PLUSOP().size())
            {
                if ((x1 > 0) && (x2 > 0))
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tADD #3" << endl;
                    cout << "\t\t\t\tSTA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 > 0) && (x2 == 0))
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 == 0) && (x2 > 0))
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else
                {
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tSTA stackindex" << endl;   //pop top factor from stack
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }

                p++;
            }
            else if (m < ctx->MINUSOP().size())
            {
                if ((x1 > 0) && (x2 > 0))
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tADD #3" << endl;
                    cout << "\t\t\t\tSTA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 > 0) && (x2 == 0))
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 == 0) && (x2 > 0))
                {
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else
                {
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tSTA stackindex" << endl;   //pop top factor from stack
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }

                m++;
            }
        }
 
        return x1;
    }

    virtual antlrcpp::Any visitTerm(ExprParser::TermContext* ctx) override
    {
        int size = ctx->factor().size();
        int x1 = visitFactor(ctx->factor(0));
        int x2 = 0;
        int m = 0;
        ExprParser::MdopContext* mtx;

        for (int i = 1; i < size; i++)
        {
            x2 = visitFactor(ctx->factor(i));

            mtx = ctx->mdop(m);

            //cout << x1 << " " << x2 << endl;

            if ((x1 > 0) && (x2 > 0))
            {
                //cout << x1 << " " << x2 << endl;
                if (mtx->MULTOP() != nullptr)
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tMULR A,T" << endl;         //multiply A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tADD #3" << endl;
                    cout << "\t\t\t\tSTA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tDIVR A,T" << endl;         //divide T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tADD #3" << endl;
                    cout << "\t\t\t\tSTA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }

                x1 = 0;
            }
            else if ((x1 > 0) && (x2 == 0))
            {
                if (mtx->MULTOP() != nullptr)
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tMULR A,T" << endl;         //multiply A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tDIVR A,T" << endl;         //divide T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                x1 = 0;
            }
            else if ((x1 == 0) && (x2 > 0))
            {
                if (mtx->MULTOP() != nullptr)
                {
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tMULR A,T" << endl;         //multiply A and T store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    cout << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    cout << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    cout << "\t\t\t\tDIVR A,T" << endl;         //divide T by A store in T
                    cout << "\t\t\t\tLDA stackindex" << endl;
                    cout << "\t\t\t\tSUB #3" << endl;
                    cout << "\t\t\t\tCLEAR X" << endl;
                    cout << "\t\t\t\tADDR A,X" << endl;
                    cout << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
            }
            else
            {
                if (mtx->MULTOP() != nullptr)
                {
                    cout << instructTabs << "LDA stackindex" << endl;
                    cout << instructTabs << "SUB #3" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;
                    cout << instructTabs << "LDT stack,X" << endl;      //store factor in T register
                    cout << instructTabs << "SUB #3" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;
                    cout << instructTabs << "LDA stack,X" << endl;      //store factor in A register
                    cout << instructTabs << "MULR A,T" << endl;         //multiply A and T store in T
                    cout << instructTabs << "LDA stackindex" << endl;
                    cout << instructTabs << "SUB #3" << endl;
                    cout << instructTabs << "STA stackindex" << endl;   //pop top factor from stack
                    cout << instructTabs << "SUB #3" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;
                    cout << instructTabs << "STT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    cout << instructTabs << "LDA stackindex" << endl;
                    cout << instructTabs << "SUB #6" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;
                    cout << instructTabs << "LDT stack,X" << endl;      //store factor in T register
                    cout << instructTabs << "ADD #3" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;
                    cout << instructTabs << "LDA stack,X" << endl;      //store factor in A register
                    cout << instructTabs << "DIVR A,T" << endl;         //divide T by A store in T
                    cout << instructTabs << "LDA stackindex" << endl;
                    cout << instructTabs << "SUB #3" << endl;
                    cout << instructTabs << "STA stackindex" << endl;   //pop top factor from stack
                    cout << instructTabs << "SUB #3" << endl;
                    cout << instructTabs << "CLEAR X" << endl;
                    cout << instructTabs << "ADDR A,X" << endl;
                    cout << instructTabs << "STT stack,X" << endl;      //store product in stack
                }
            }

            m++;
        }

        return x1;
    }

    virtual antlrcpp::Any visitMdop(ExprParser::MdopContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFactor(ExprParser::FactorContext* ctx) override
    {
        int x = 0;
        if (ctx->variable() != nullptr)
        {
            //cout << "Variable" << endl;
            x = visitVariable(ctx->variable());
        }
        else if (ctx->INTEGER() != nullptr)
        {
            cout << instructTabs << "LDA stackindex" << endl;
            cout << instructTabs << "ADD #3" << endl;
            cout << instructTabs << "STA stackindex" << endl;
            cout << instructTabs << "SUB #3" << endl;
            cout << instructTabs << "CLEAR X" << endl;
            cout << instructTabs << "ADDR A,X" << endl;
            cout << instructTabs << "LDA #" << ctx->INTEGER()->getText() << endl;
            cout << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->CHAR() != nullptr)
        {
            cout << instructTabs << "LDA stackindex" << endl;
            cout << instructTabs << "ADD #1" << endl;
            cout << instructTabs << "STA stackindex" << endl;
            cout << instructTabs << "SUB #1" << endl;
            cout << instructTabs << "CLEAR X" << endl;
            cout << instructTabs << "ADDR A,X" << endl;
            cout << instructTabs << "LDA #" << ctx->CHAR()->getText() << endl;
            cout << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->TRUE() != nullptr)
        {
            cout << instructTabs << "LDA stackindex" << endl;
            cout << instructTabs << "ADD #1" << endl;
            cout << instructTabs << "STA stackindex" << endl;
            cout << instructTabs << "SUB #1" << endl;
            cout << instructTabs << "CLEAR X" << endl;
            cout << instructTabs << "ADDR A,X" << endl;
            cout << instructTabs << "LDA #1" << endl;
            cout << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->FALSE() != nullptr)
        {
            cout << instructTabs << "LDA stackindex" << endl;
            cout << instructTabs << "ADD #1" << endl;
            cout << instructTabs << "STA stackindex" << endl;
            cout << instructTabs << "SUB #1" << endl;
            cout << instructTabs << "CLEAR X" << endl;
            cout << instructTabs << "ADDR A,X" << endl;
            cout << instructTabs << "LDA #0" << endl;
            cout << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->expression() != nullptr)
        {
           x = visitExpression(ctx->expression());
        }

        return x;
    }

    virtual antlrcpp::Any visitVariable(ExprParser::VariableContext* ctx) override
    {
        int o1 = 0;
        if (ctx->IDENTIFIER() != nullptr)
        {
            for (int i = 0; i < rtFrame.size(); i++)
            {
                if (rtFrame[i].name == ctx->IDENTIFIER()->getText())
                {
                    o1 = stoi(rtFrame[i].value);
                }
            }
        }
        else if (ctx->function_call() != nullptr)
        {

        }
        else if (ctx->array_element() != nullptr)
        {

        }
        return o1;
    }

    virtual antlrcpp::Any visitArray_element(ExprParser::Array_elementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitElement(ExprParser::ElementContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFunction_call(ExprParser::Function_callContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitFunction_name(ExprParser::Function_nameContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitArg_list(ExprParser::Arg_listContext* ctx) override {
        return visitChildren(ctx);
    }

    virtual antlrcpp::Any visitArg(ExprParser::ArgContext* ctx) override {
        return visitChildren(ctx);
    }


};

