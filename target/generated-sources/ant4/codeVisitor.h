
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"
#include "typeSpec.h"
#include <iostream>
#include <string>
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
};

/* Will act like a mini runtime stack frame holding the index of each variable
*/

vector<node> rtFrame; 


class  codeVisitor : public ExprBaseVisitor 
{
private:
  int labels = 0;
  int size = 0;
  struct values{
  
    string val;
    //will declare these to store values
    //for arithmetic, use stoi() to convert strings to integer
  };

public:

  virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *ctx) override 
  {
    labels = 1;
    cout << "stack \t\t RESB \t 10000" << endl;
    cout << "stackindex \t WORD \t 0" << endl;
    cout << "stackmax \t WORD \t 10000" << endl;
    cout << "returnvalue \t RESB \t 500" << endl;
    cout << "returnmax  \t WORD \t 500" << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_header(ExprParser::Program_headerContext *ctx) override 
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDeclarations(ExprParser::DeclarationsContext *ctx) override {

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstants(ExprParser::ConstantsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_list(ExprParser::Constant_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConstant_declaration(ExprParser::Constant_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_identifier(ExprParser::Const_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypes(ExprParser::TypesContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_list(ExprParser::Type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_declaration(ExprParser::Type_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_identifier_list(ExprParser::Type_identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_identifier(ExprParser::Type_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_specification(ExprParser::Type_specificationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimpletype(ExprParser::SimpletypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArraytype(ExprParser::ArraytypeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArray_start(ExprParser::Array_startContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitDimensions(ExprParser::DimensionsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitScalar(ExprParser::ScalarContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRange(ExprParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariables(ExprParser::VariablesContext *ctx) override 
  {
       //   do not know how to declare variables yet
       //   need to know how to access them later on
       //   will change 'return visitChild...'
       //   will manually visit variable identifier list
       //   after, declare a stack frame/increment stack index by size amount

      visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitVariable_list(ExprParser::Variable_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_declarations(ExprParser::Variable_declarationsContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_identifier_list(ExprParser::Var_identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_identifier(ExprParser::Var_identifierContext *ctx) override 
  {

    //cout << ctx->entry->name << endl;
    
    //  check each entry type
    //  depending on type, we increment size by an amount
    //  we also create a node to hold the name and size value
    //  then we add the struct to the vector called rtFrame;

      int x = 1;

      if (ctx->entry->type->getKind() == "integer")
      {
          //increment size by integer amount of bytes
      }
      else if (ctx->entry->type->getKind() == "char")
      {
          //increment size by char amount amount of bytes
      }
      else if (ctx->entry->type->getKind() == "boolean")
      {
          //increment size by boolean amount of bytes
      }
      else //an array check its typeSpec via extras member function of symbEntry
      {
          typeSpec* spec = ctx->entry->type;
          while (spec != nullptr)
          {
              if (spec->getElemType() == "integer")
              {
                  //multiply x by integer amount of bytes
              }
              else if (spec->getElemType() == "char")
              {
                  //multiply x by char amount amount of bytes
              }
              else if (spec->getElemType() == "boolean")
              {
                  //multiply x by boolean amount of bytes
              }
              else
              {
                  x *= spec->getAmt();
              }

              spec = spec->getType();
          }
      }
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctions(ExprParser::FunctionsContext *ctx) override {

    //will do later
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunct_type(ExprParser::Funct_typeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProc(ExprParser::ProcContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunct(ExprParser::FunctContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunct_identifier(ExprParser::Funct_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParameters(ExprParser::ParametersContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_list(ExprParser::Param_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_declaration(ExprParser::Param_declarationContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_identifier_list(ExprParser::Param_identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_identifier(ExprParser::Param_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement_list(ExprParser::Statement_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitStatement(ExprParser::StatementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCompound_statement(ExprParser::Compound_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitAssign_statement(ExprParser::Assign_statementContext *ctx) override {

    //values x = visitExpression(ctx->expression());
    //cout << x.val << endl;
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitRepeat_statement(ExprParser::Repeat_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitIf_statement(ExprParser::If_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitWhile_statement(ExprParser::While_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCase_statement(ExprParser::Case_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitCondition(ExprParser::ConditionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_statement(ExprParser::For_statementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *ctx) override 
  {
    /*
    int size = ctx->simple_expression().size();
    int type;
    for(int i = 0; i < size; i++)
    {
      type = visitSimple_expression(ctx->simple_expression(i));
    }

    cout << type << endl;
    
    return type;
    */
    return visitChildren(ctx);
    
    /*values v;
    v.val = "100";
    return v;*/
  }

  virtual antlrcpp::Any visitSimple_expression(ExprParser::Simple_expressionContext *ctx) override 
  {
      /*
    int size = ctx->term().size();
    int x;
    for(int i = 0; i < size; i++)
    {
      x = visitTerm(ctx->term(i));
    }
    return x;
    */
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(ExprParser::TermContext *ctx) override 
  {/*
    int size = ctx->factor().size();
    int x;
    for(int i = 0; i < size; i++)
    {
      x = visitFactor(ctx->factor(i));
    }
    */
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(ExprParser::FactorContext *ctx) override 
  {
      /*
    int type = 0;
    if(ctx->variable() != nullptr) type = visitVariable(ctx->variable());
    else if(ctx->INTEGER() != nullptr) type = 1;
    else if(ctx->CHAR() != nullptr) type = 2;
    else if(ctx->TRUE() != nullptr) type = 3;
    else if(ctx->FALSE() != nullptr) type = 3;
    else if(ctx->expression() != nullptr) type = visitExpression(ctx->expression());
    */
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *ctx) override 
  {
    return visitChildren(ctx);
    //return 1;
  }

  virtual antlrcpp::Any visitArray_element(ExprParser::Array_elementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitElement(ExprParser::ElementContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_call(ExprParser::Function_callContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunction_name(ExprParser::Function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg_list(ExprParser::Arg_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg(ExprParser::ArgContext *ctx) override {
    return visitChildren(ctx);
  }


};

