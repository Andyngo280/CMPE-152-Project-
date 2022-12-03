
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"
#include "typeSpec.h"
#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <fstream>


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
    int local_jump = 0;
    int size = 0;
    struct values 
    {

        string val;
        //will declare these to store values
        //for arithmetic, use stoi() to convert strings to integer
    };

    string instructTabs = "\t\t\t\t";

    ofstream output;

public:

    virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext* ctx) override
    {
        output.open("assign_test.asm");

        labels = 1;
        output << "test\t\t\tSTART\t0" << endl;
        visitChildren(ctx);
        //output << endl;

        /*//checking if a variable holds the correct value
        output << instructTabs << "CLEAR X" << endl;
        output << instructTabs << "CLEAR T" << endl;
        output << instructTabs << "LDA #1747" << endl;    //finding beta: stackindex-offset => 1762-15
        output << instructTabs << "ADDR A,X" << endl;
        output << instructTabs << "LDT stack,X" << endl;*/

        output << "stack\t\t\tRESB 10000" << endl;
        output << "stackindex\t\tWORD 0" << endl;
        output << "stackmax\t\tWORD 10000" << endl;
        output << "returnvalue\t\tRESB 500" << endl;
        output << "returnmax\t\tWORD 500" << endl;
        output << instructTabs << "END  0" << endl;

        output.close();
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
          output << rtFrame[i].name << " " << rtFrame[i].value << endl;
        }*/

        size += 9;
        output << instructTabs << "LDA stackindex" << endl;     //  load stack index to A
        output << instructTabs << "ADD #" << size << endl;      //  add (max stack frame size) to A
        output << instructTabs << "STA stackindex" << endl;     //  store ^^ into stack index
        output << instructTabs << "CLEAR X" << endl;            //  empty X
        output << instructTabs << "LDA #" << size - 3 << endl;  //  load (address of prev frame index) to A
        output << instructTabs << "ADDR A,X" << endl;           //  X = X + A
        output << instructTabs << "LDA #0" << endl;             //  load previous frame index to A
        output << instructTabs << "STA stack,X" << endl;        //  store ^^ to stack
        output << instructTabs << "CLEAR X" << endl;
        output << instructTabs << "LDA #" << size - 6 << endl;  //load address of frames scope
        output << instructTabs << "ADDR A,X" << endl;
        output << instructTabs << "LDA #1" << endl;
        output << instructTabs << "STA stack,X" << endl;        //store scope
        //output << endl;
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

        //output << ctx->entry->name << endl;

        //  check each entry type
        //  depending on type, we increment size by an amount
        //  we also create a node to hold the name and size value
        //  then we add the struct to the vector called rtFrame;

        int x = 1;
        //output << ctx->entry->name << " " << ctx->entry->type->getKind() << endl;

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

            //output << x << endl;
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
                //output << spec->getElemType() << endl;
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
        //output << endl;
        int x = visitExpression(ctx->expression());
        //output << value.name << " " << value.value << endl;
        //output << "assign" << endl;
        int offset = 0;
        //output << rtFrame[rtFrame.size()-1].max << endl;
        int max = rtFrame[rtFrame.size() - 1].max + 9;
        if (ctx->variable()->IDENTIFIER() != nullptr)
        {
            offset = visitVariable(ctx->variable());

            if (x > 0)
            {
                output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                output << "\t\t\t\tSUB #" << 9 + x << endl;
                output << instructTabs << "CLEAR X" << endl;
                output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
            }
            else
            {
                if (ctx->variable()->entry->type->getKind() == "integer")
                {
                    output << instructTabs << "LDA stackindex" << endl;         //load index to A
                    output << instructTabs << "SUB #3" << endl;                 //decrement index to get addr of rhs value
                    output << instructTabs << "STA stackindex" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
                else if (ctx->variable()->entry->type->getKind() == "char")
                {
                    output << instructTabs << "LDA stackindex" << endl;         //load index to A
                    output << instructTabs << "SUB #1" << endl;                 //decrement index to get addr of rhs value
                    output << instructTabs << "STA stackindex" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
                else if (ctx->variable()->entry->type->getKind() == "boolean")
                {
                    output << instructTabs << "LDA stackindex" << endl;         //load index to A
                    output << instructTabs << "SUB #1" << endl;                 //decrement index to get addr of rhs value
                    output << instructTabs << "STA stackindex" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
            }
        }
        else if (ctx->variable()->array_element() != nullptr)
        {
            offset = visitArray_element(ctx->variable()->array_element());

            if (x > 0)
            {
                output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                output << "\t\t\t\tSUB #" << 9 + x << endl;
                output << instructTabs << "CLEAR X" << endl;
                output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
            }
            else
            {
                string y = ctx->variable()->array_element()->entry->type->getElemType();
                if (y == "integer")
                {
                    output << instructTabs << "LDA stackindex" << endl;         //load index to A
                    output << instructTabs << "SUB #3" << endl;                 //decrement index to get addr of rhs value
                    output << instructTabs << "STA stackindex" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
                else if (y == "char")
                {
                    output << instructTabs << "LDA stackindex" << endl;         //load index to A
                    output << instructTabs << "SUB #1" << endl;                 //decrement index to get addr of rhs value
                    output << instructTabs << "STA stackindex" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
                else if (y == "boolean")
                {
                    output << instructTabs << "LDA stackindex" << endl;         //load index to A
                    output << instructTabs << "SUB #1" << endl;                 //decrement index to get addr of rhs value
                    output << instructTabs << "STA stackindex" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;               //load addr to X
                    output << instructTabs << "LDT stack,X" << endl;            //T register holds rhs value
                }
            }
        }

        output << instructTabs << "LDA #" << 
            stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;          //load index to A
        output << instructTabs << "SUB #" << 9 + offset << endl;            //subtract 9 and offset to get addr of lhs
        output << instructTabs << "CLEAR X" << endl;
        output << instructTabs << "ADDR A,X" << endl;                       //load addr to x
        output << instructTabs << "STT stack,X" << endl;                    //store T(rhs) value to lhs

        return 0;
    }

    virtual antlrcpp::Any visitRepeat_statement(ExprParser::Repeat_statementContext* ctx) override 
    {
        //output << endl;
        output << "I" << local_jump;

        visitStatement_list(ctx->statement_list());

        visitExpression(ctx->expression());

        local_jump++;

        return 0;
    }

    virtual antlrcpp::Any visitIf_statement(ExprParser::If_statementContext* ctx) override 
    {
        //output << endl;
        int x = visitExpression(ctx->expression());
        x = visitStatement(ctx->statement(0));
        output << "I" << local_jump;
        local_jump++;

        if (ctx->ELSE() != nullptr)
        {
            x = visitStatement(ctx->statement(1));
        }

        return 0;
    }

    virtual antlrcpp::Any visitWhile_statement(ExprParser::While_statementContext* ctx) override 
    {
        output << "W" << local_jump;
        visitExpression(ctx->expression());

        visitStatement(ctx->statement());

        output << instructTabs << "J W" << local_jump << endl;
        output << "I" << local_jump;
        local_jump++;

        return 0;
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
        int x1 = visitSimple_expression(ctx->simple_expression(0));
        //output << "exp" << endl;

        if (size > 1)
        {
            int x2 = visitSimple_expression(ctx->simple_expression(1));

            if ((x1 > 0) && (x2 > 0))
            {
                output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                output << "\t\t\t\tCLEAR X" << endl;
                output << "\t\t\t\tADDR A,X" << endl;
                output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                output << "\t\t\t\tCLEAR X" << endl;
                output << "\t\t\t\tADDR A,X" << endl;
                output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                output << "\t\t\t\tCOMPR T,A" << endl;
            }
            else if ((x1 > 0) && (x2 == 0))
            {
                ExprParser::FactorContext* ftx = ctx->simple_expression(1)->term(0)->factor(0);

                output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                output << "\t\t\t\tCLEAR X" << endl;
                output << "\t\t\t\tADDR A,X" << endl;
                output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                output << "\t\t\t\tLDA stackindex" << endl;
                
                if(ftx->INTEGER()!= nullptr) output << "\t\t\t\tSUB #3" << endl;
                else output << "\t\t\t\tSUB #1" << endl;

                output << "\t\t\t\tSTA stackindex" << endl;
                output << "\t\t\t\tCLEAR X" << endl;
                output << "\t\t\t\tADDR A,X" << endl;
                output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                output << "\t\t\t\tCOMPR T,A" << endl;
            }
            else if ((x1 == 0) && (x2 > 0))
            {
                ExprParser::FactorContext* ftx = ctx->simple_expression(0)->term(0)->factor(0);

                output << "\t\t\t\tLDA stackindex" << endl;

                if (ftx->INTEGER() != nullptr) output << "\t\t\t\tSUB #3" << endl;
                else output << "\t\t\t\tSUB #1" << endl;

                output << "\t\t\t\tSTA stackindex" << endl;
                output << "\t\t\t\tCLEAR X" << endl;
                output << "\t\t\t\tADDR A,X" << endl;
                output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                output << "\t\t\t\tCLEAR X" << endl;
                output << "\t\t\t\tADDR A,X" << endl;
                output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                output << "\t\t\t\tCOMPR T,A" << endl;
            }
            else
            {
                ExprParser::FactorContext* ftx1 = ctx->simple_expression(0)->term(0)->factor(0);
                ExprParser::FactorContext* ftx2 = ctx->simple_expression(1)->term(0)->factor(0);

                output << instructTabs << "LDA stackindex" << endl;

                if (ftx2->INTEGER() != nullptr) output << "\t\t\t\tSUB #3" << endl;
                else output << "\t\t\t\tSUB #1" << endl;

                output << instructTabs << "STA stackindex" << endl;
                output << instructTabs << "CLEAR X" << endl;
                output << instructTabs << "ADDR A,X" << endl;
                output << instructTabs << "LDT stack,X" << endl;      //store factor in T register
                
                if (ftx1->INTEGER() != nullptr) output << "\t\t\t\tSUB #3" << endl;
                else output << "\t\t\t\tSUB #1" << endl;

                output << instructTabs << "STA stackindex" << endl;
                output << instructTabs << "CLEAR X" << endl;
                output << instructTabs << "ADDR A,X" << endl;
                output << instructTabs << "LDA stack,X" << endl;      //store factor in A register
                output << instructTabs << "COMPR A, T" << endl;
            }

            if (ctx->EQUAL() != nullptr)
            {
                output << instructTabs << "JLT I" << local_jump << endl;
                output << instructTabs << "JGT I" << local_jump << endl;
            }
            else if (ctx->NE() != nullptr)
            {
                output << instructTabs << "JEQ I" << local_jump << endl;
            }
            else if (ctx->LTEQ() != nullptr)
            {
                output << instructTabs << "JGT I" << local_jump << endl;
            }
            else if (ctx->GTEQ() != nullptr)
            {
                output << instructTabs << "JLT I" << local_jump << endl;
            }
            else if (ctx->LT() != nullptr)
            {
                output << instructTabs << "JEQ I" << local_jump << endl;
                output << instructTabs << "JGT I" << local_jump << endl;
            }
            else if (ctx->GT() != nullptr)
            {
                output << instructTabs << "JEQ I" << local_jump << endl;
                output << instructTabs << "JLT I" << local_jump << endl;
            }
        }

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
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tADD #3" << endl;
                    output << "\t\t\t\tSTA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 > 0) && (x2 == 0))
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 == 0) && (x2 > 0))
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else
                {
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tADDR A,T" << endl;         //add A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tSTA stackindex" << endl;   //pop top factor from stack
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }

                p++;
            }
            else if (m < ctx->MINUSOP().size())
            {
                if ((x1 > 0) && (x2 > 0))
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tADD #3" << endl;
                    output << "\t\t\t\tSTA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 > 0) && (x2 == 0))
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                    x1 = 0;
                }
                else if ((x1 == 0) && (x2 > 0))
                {
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else
                {
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tSUBR A,T" << endl;         //subtract T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tSTA stackindex" << endl;   //pop top factor from stack
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
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

            //output << x1 << " " << x2 << endl;

            if ((x1 > 0) && (x2 > 0))
            {
                //output << x1 << " " << x2 << endl;
                if (mtx->MULTOP() != nullptr)
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tMULR A,T" << endl;         //multiply A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tADD #3" << endl;
                    output << "\t\t\t\tSTA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tDIVR A,T" << endl;         //divide T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tADD #3" << endl;
                    output << "\t\t\t\tSTA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }

                x1 = 0;
            }
            else if ((x1 > 0) && (x2 == 0))
            {
                if (mtx->MULTOP() != nullptr)
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tMULR A,T" << endl;         //multiply A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x1 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tDIVR A,T" << endl;         //divide T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                x1 = 0;
            }
            else if ((x1 == 0) && (x2 > 0))
            {
                if (mtx->MULTOP() != nullptr)
                {
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tMULR A,T" << endl;         //multiply A and T store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDT stack,X" << endl;      //store factor in T register
                    output << "\t\t\t\tLDA #" << stoi(rtFrame[rtFrame.size() - 1].value) + 9 << endl;
                    output << "\t\t\t\tSUB #" << 9 + x2 << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tLDA stack,X" << endl;      //store factor in A register
                    output << "\t\t\t\tDIVR A,T" << endl;         //divide T by A store in T
                    output << "\t\t\t\tLDA stackindex" << endl;
                    output << "\t\t\t\tSUB #3" << endl;
                    output << "\t\t\t\tCLEAR X" << endl;
                    output << "\t\t\t\tADDR A,X" << endl;
                    output << "\t\t\t\tSTT stack,X" << endl;      //store product in stack
                }
            }
            else
            {
                if (mtx->MULTOP() != nullptr)
                {
                    output << instructTabs << "LDA stackindex" << endl;
                    output << instructTabs << "SUB #3" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;
                    output << instructTabs << "LDT stack,X" << endl;      //store factor in T register
                    output << instructTabs << "SUB #3" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;
                    output << instructTabs << "LDA stack,X" << endl;      //store factor in A register
                    output << instructTabs << "MULR A,T" << endl;         //multiply A and T store in T
                    output << instructTabs << "LDA stackindex" << endl;
                    output << instructTabs << "SUB #3" << endl;
                    output << instructTabs << "STA stackindex" << endl;   //pop top factor from stack
                    output << instructTabs << "SUB #3" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;
                    output << instructTabs << "STT stack,X" << endl;      //store product in stack
                }
                else if (mtx->DIVOP() != nullptr)
                {
                    output << instructTabs << "LDA stackindex" << endl;
                    output << instructTabs << "SUB #6" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;
                    output << instructTabs << "LDT stack,X" << endl;      //store factor in T register
                    output << instructTabs << "ADD #3" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;
                    output << instructTabs << "LDA stack,X" << endl;      //store factor in A register
                    output << instructTabs << "DIVR A,T" << endl;         //divide T by A store in T
                    output << instructTabs << "LDA stackindex" << endl;
                    output << instructTabs << "SUB #3" << endl;
                    output << instructTabs << "STA stackindex" << endl;   //pop top factor from stack
                    output << instructTabs << "SUB #3" << endl;
                    output << instructTabs << "CLEAR X" << endl;
                    output << instructTabs << "ADDR A,X" << endl;
                    output << instructTabs << "STT stack,X" << endl;      //store product in stack
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
            //output << "Variable" << endl;
            x = visitVariable(ctx->variable());
        }
        else if (ctx->INTEGER() != nullptr)
        {
            output << instructTabs << "LDA stackindex" << endl;
            output << instructTabs << "ADD #3" << endl;
            output << instructTabs << "STA stackindex" << endl;
            output << instructTabs << "SUB #3" << endl;
            output << instructTabs << "CLEAR X" << endl;
            output << instructTabs << "ADDR A,X" << endl;
            output << instructTabs << "LDA #" << ctx->INTEGER()->getText() << endl;
            output << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->CHAR() != nullptr)
        {
            output << instructTabs << "LDA stackindex" << endl;
            output << instructTabs << "ADD #1" << endl;
            output << instructTabs << "STA stackindex" << endl;
            output << instructTabs << "SUB #1" << endl;
            output << instructTabs << "CLEAR X" << endl;
            output << instructTabs << "ADDR A,X" << endl;
            output << instructTabs << "LDA #" << ctx->CHAR()->getText() << endl;
            output << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->TRUE() != nullptr)
        {
            output << instructTabs << "LDA stackindex" << endl;
            output << instructTabs << "ADD #1" << endl;
            output << instructTabs << "STA stackindex" << endl;
            output << instructTabs << "SUB #1" << endl;
            output << instructTabs << "CLEAR X" << endl;
            output << instructTabs << "ADDR A,X" << endl;
            output << instructTabs << "LDA #1" << endl;
            output << instructTabs << "STA stack,X" << endl;
        }
        else if (ctx->FALSE() != nullptr)
        {
            output << instructTabs << "LDA stackindex" << endl;
            output << instructTabs << "ADD #1" << endl;
            output << instructTabs << "STA stackindex" << endl;
            output << instructTabs << "SUB #1" << endl;
            output << instructTabs << "CLEAR X" << endl;
            output << instructTabs << "ADDR A,X" << endl;
            output << instructTabs << "LDA #0" << endl;
            output << instructTabs << "STA stack,X" << endl;
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
            o1 = visitArray_element(ctx->array_element());
        }
        return o1;
    }

    virtual antlrcpp::Any visitArray_element(ExprParser::Array_elementContext* ctx) override 
    {
        int x = 0;
        int y = 0;
        int s = ctx->element().size() - 1;
        for (int i = 0; i < ctx->element().size(); i++)
        {
            y = visitElement(ctx->element(i));
            x += y * pow(10,s);
            s--;
        }

        for (int i = 0; i < rtFrame.size(); i++)
        {
            if (ctx->IDENTIFIER()->getText() == rtFrame[i].name)
            {
                y = stoi(rtFrame[i].value);
            }
        }

        x = y - x;

        return x;
    }

    virtual antlrcpp::Any visitElement(ExprParser::ElementContext* ctx) override 
    {
        int x = stoi(ctx->INTEGER()->getText());
        return x;
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

