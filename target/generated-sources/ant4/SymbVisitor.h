
#pragma once


#include "antlr4-runtime.h"
#include "ExprBaseVisitor.h"
#include "symbStack.h"
#include "typeSpec.h"
#include <string>
#include <iostream>

using namespace std;


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */

class  SymbVisitor : public ExprBaseVisitor {
public:

  symbStack stack;
  symbStack print;
  int lvl;
  typeSpec *spec;

  void printAllTables()
  {
    print.printTables();
  }

  virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *ctx) override 
  {
    lvl = 0;
    visitProgram_header(ctx->program_header());
    visitDeclarations(ctx->declarations());
    visitCompound_statement(ctx->compound_statement());

    symbtab *type = stack.getLocal();
    print.push(type);
    stack.pop();

    //print.printTables();
    return 0;
  }

  virtual antlrcpp::Any visitProgram_header(ExprParser::Program_headerContext *ctx) override 
  {
    symbEntry *node = new symbEntry;
    node->name = ctx->IDENTIFIER()->getText();
    node->kind = "program";
    node->type = nullptr;
    node->nlvl = 0;

    ctx->entry = node;

    stack.getLocal()->addEntry(ctx->IDENTIFIER()->getText(), node);

    //stack.printTables();

    lvl++;

    symbtab *newtable = new symbtab;
    newtable->setName(ctx->IDENTIFIER()->getText());
    newtable->setlvl(lvl);

    stack.push(newtable);
    
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

  virtual antlrcpp::Any visitConstant_declaration(ExprParser::Constant_declarationContext *ctx) override 
  {
      symbEntry *node = new symbEntry;
      node->name = ctx->const_identifier()->IDENTIFIER()->getText();
      node->kind = "CONST";
      node->nlvl = lvl;

      typeSpec *type = new typeSpec;

      if(ctx->CHAR() != nullptr)
      {
        type->setKind("char");
        node->value = ctx->CHAR()->getText();
      }
      else if(ctx->STRINGS() != nullptr)
      {
        type->setKind("string");
        node->value = ctx->STRINGS()->getText();
      }
      else if(ctx->INTEGER() != nullptr)
      {
        type->setKind("integer");
        node->value = ctx->INTEGER()->getText();
      }
      else if(ctx->REAL() != nullptr)
      {
        type->setKind("real");
        node->value = ctx->REAL()->getText();
      }
      else if(ctx->BOOLEAN() != nullptr)
      {
        type->setKind("boolean");
        node->value = ctx->BOOLEAN()->getText();
      }
      else if(ctx->IDENTIFIER() != nullptr)
      {
        type->setKind(ctx->IDENTIFIER()->getText());
        node->value = ctx->IDENTIFIER()->getText();
      }
      node->type = type;

      ctx->const_identifier()->entry = node;

      /*if(ctx->const_identifier()->entry != nullptr)
      {
        cout << "Const_declaration: " << ctx->const_identifier()->entry->name << " ";
        ctx->const_identifier()->entry->type->printType();
      }*/

      stack.getLocal()->addEntry(ctx->const_identifier()->IDENTIFIER()->getText(), node);

      return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitConst_identifier(ExprParser::Const_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTypes(ExprParser::TypesContext *ctx) override 
  {
    //stack.printTables();
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_list(ExprParser::Type_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_declaration(ExprParser::Type_declarationContext *ctx) override 
  {
    spec = visitType_specification(ctx->type_specification());
    visitType_identifier_list(ctx->type_identifier_list());
    //spec->printType();
    return 0;
  }

  virtual antlrcpp::Any visitType_identifier_list(ExprParser::Type_identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_identifier(ExprParser::Type_identifierContext *ctx) override 
  {
    symbEntry *node = new symbEntry;
    node->name = ctx->IDENTIFIER()->getText();
    node->kind = "TYPE";
    node->nlvl = lvl;
    node->type = spec;

    ctx->entry = node;

    stack.getLocal()->addEntry(ctx->IDENTIFIER()->getText(), node);

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitType_specification(ExprParser::Type_specificationContext *ctx) override 
  {
    typeSpec *newType;

    if(ctx->simpletype() != nullptr)
    {
      newType = visitSimpletype(ctx->simpletype());
      //newType->printType();
    }
    else if(ctx->arraytype() != nullptr)
    {
      newType = visitArraytype(ctx->arraytype());
    }

    return newType;
  }

  virtual antlrcpp::Any visitSimpletype(ExprParser::SimpletypeContext *ctx) override 
  {
    typeSpec *newType = new typeSpec;
    
    newType->setKind(visitScalar(ctx->scalar()));


    return newType;
  }

  virtual antlrcpp::Any visitArraytype(ExprParser::ArraytypeContext *ctx) override 
  {
    typeSpec *newType = new typeSpec;
    newType->setKind("ARRAY");
    typeSpec* buff = visitArray_start(ctx->array_start());
    newType->setIndex(buff);
    newType->setElement(visitType_specification(ctx->type_specification()));
    newType->setMax(buff->getMax());
    newType->setMin(buff->getMin());
    //newType->setAmount(stoi(ctx->array_start()->dimensions()->simpletype()->scalar()->INTEGER()->getText()));
    newType->setAmount(buff->getMax() - buff->getMin() + 1);

    //newType->printType();

    return newType;
  }

  virtual antlrcpp::Any visitArray_start(ExprParser::Array_startContext *ctx) override 
  {
    return visitDimensions(ctx->dimensions());
  }

  virtual antlrcpp::Any visitDimensions(ExprParser::DimensionsContext *ctx) override 
  {
      typeSpec *newType = new typeSpec;
      if (ctx->simpletype()->scalar() != nullptr)
      {
          ExprParser::ScalarContext* stx = ctx->simpletype()->scalar();
          if (stx->CHAR() != nullptr)
          {
              newType->setKind("char");
          }
          else if (stx->INTEGER() != nullptr)
          {
              newType->setKind("integer");
          }
          else if (stx->BOOLEAN() != nullptr)
          {
              newType->setKind("boolean");
          }
          else if (stx->IDENTIFIER() != nullptr)
          {
              newType->setKind(stx->IDENTIFIER()->getText());
          }
      }
      else // range
      {
          ExprParser::RangeContext* rtx = ctx->simpletype()->range();
          newType->setMin(stoi(rtx->INTEGER(0)->getText()));
          newType->setMax(stoi(rtx->INTEGER(1)->getText()));
          newType->setKind("integer");
      }

      return newType;
  }

  virtual antlrcpp::Any visitScalar(ExprParser::ScalarContext *ctx) override 
  {
      if(ctx->CHAR() != nullptr)
      {
        return "char";
      }
      else if(ctx->INTEGER() != nullptr)
      {
        return ctx->INTEGER()->getText();
      }
      else if(ctx->BOOLEAN() != nullptr)
      {
        return "boolean";
      }
      else if(ctx->IDENTIFIER() != nullptr)
      {
        if(stack.checkStack(ctx->IDENTIFIER()->getText()) == false)
          cout << "Semantic Error " << ctx->IDENTIFIER()->getText() << " is undefined." << endl;
        return ctx->IDENTIFIER()->getText();
      }
  }

  virtual antlrcpp::Any visitRange(ExprParser::RangeContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariables(ExprParser::VariablesContext *ctx) override 
  {
    //stack.printTables();
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_list(ExprParser::Variable_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable_declarations(ExprParser::Variable_declarationsContext *ctx) override 
  {
    spec = visitType_specification(ctx->type_specification());
    visitVar_identifier_list(ctx->var_identifier_list());

    return 0;
  }

  virtual antlrcpp::Any visitVar_identifier_list(ExprParser::Var_identifier_listContext *ctx) override 
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVar_identifier(ExprParser::Var_identifierContext *ctx) override 
  {
    symbEntry *node = new symbEntry;
    node->name = ctx->IDENTIFIER()->getText();
    node->type = spec;
    node->kind = "VARIABLE";
    node->nlvl = lvl;

    symbEntry* t = stack.getEntry(spec->getKind());

    if ((t != nullptr) && (t->type->getKind() == "ARRAY"))
    {
        node->extras.array = t->type;
        //cout << node->name << endl;
        //cout << node->extras.array->getElemType() << endl;
    }
    else if ((t != nullptr) && (t->kind == "PREDEF_CONST"))
    {
        typeSpec* x = new typeSpec;
        x->setKind(t->name);
    }

    ctx->entry = node;

    stack.getLocal()->addEntry(ctx->IDENTIFIER()->getText(), node);

    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctions(ExprParser::FunctionsContext *ctx) override 
  {
    //stack.printTables();
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunct_type(ExprParser::Funct_typeContext *ctx) override 
  {
    if(ctx->proc() != nullptr) visitProc(ctx->proc());
    else visitFunct(ctx->funct());
    visitDeclarations(ctx->declarations());
    visitCompound_statement(ctx->compound_statement());

    //stack.printTables();

    symbtab *type = stack.getLocal();
    print.push(type);
    stack.pop();
    lvl--;

    return 0;
  }

  virtual antlrcpp::Any visitProc(ExprParser::ProcContext *ctx) override 
  {
    symbEntry *node = new symbEntry;
    node->name = ctx->funct_identifier()->IDENTIFIER()->getText();
    node->kind = "PROCEDURE";
    node->nlvl = lvl;
    node->type = nullptr;

    ctx->entry = node;

    stack.getLocal()->addEntry(ctx->funct_identifier()->IDENTIFIER()->getText(), node);
    lvl++;

    symbtab *tab = new symbtab;
    tab->setName(ctx->funct_identifier()->IDENTIFIER()->getText());
    tab->setlvl(lvl);

    stack.push(tab);

    if(ctx->parameters() != nullptr) visitParameters(ctx->parameters());

    return 0;
  }

  virtual antlrcpp::Any visitFunct(ExprParser::FunctContext *ctx) override 
  {
    symbEntry *node = new symbEntry;
    node->name = ctx->funct_identifier()->IDENTIFIER()->getText();
    node->kind = "FUNCTION";
    node->nlvl = lvl;
    
    typeSpec *type = new typeSpec;
    if(stack.checkStack(ctx->type_identifier()->IDENTIFIER()->getText()) == false)
          cout << "Semantic Error " << ctx->type_identifier()->IDENTIFIER()->getText() << " is undefined." << endl;
    type->setKind(ctx->type_identifier()->IDENTIFIER()->getText());

    node->type = type;

    ctx->entry = node;

    stack.getLocal()->addEntry(ctx->funct_identifier()->IDENTIFIER()->getText(), node);
    lvl++;

    symbtab *tab = new symbtab;
    tab->setName(ctx->funct_identifier()->IDENTIFIER()->getText());
    tab->setlvl(lvl);

    stack.push(tab);

    if(ctx->parameters() != nullptr) visitParameters(ctx->parameters());

    return 0;
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

  virtual antlrcpp::Any visitParam_declaration(ExprParser::Param_declarationContext *ctx) override 
  {
    typeSpec *type = new typeSpec;
    if(stack.checkStack(ctx->type_identifier()->IDENTIFIER()->getText()) == false)
          cout << "Semantic Error " << ctx->type_identifier()->IDENTIFIER()->getText() << " is undefined." << endl;
    type->setKind(ctx->type_identifier()->IDENTIFIER()->getText());

    spec = type;
    visitParam_identifier_list(ctx->param_identifier_list());

    return 0;
  }

  virtual antlrcpp::Any visitParam_identifier_list(ExprParser::Param_identifier_listContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitParam_identifier(ExprParser::Param_identifierContext *ctx) override 
  {
    symbEntry *node = new symbEntry;
    node->name = ctx->IDENTIFIER()->getText();
    node->nlvl = lvl;
    node->kind = "PARAMETER";
    node->type = spec;

    ctx->entry = node;

    stack.getLocal()->addEntry(ctx->IDENTIFIER()->getText(), node);

    return 0;
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

  virtual antlrcpp::Any visitAssign_statement(ExprParser::Assign_statementContext *ctx) override 
  { 
    //cout << "assign" << endl;

    int x = visitVariable(ctx->variable());
    int y = visitExpression(ctx->expression());

    if(x != y) cout << "Semantic Error: Type mismatch" << endl;

    //visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitRepeat_statement(ExprParser::Repeat_statementContext *ctx) override 
  {

    //cout << "rep" << endl;
    visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitIf_statement(ExprParser::If_statementContext *ctx) override 
  {
 
    //cout << "if" << endl;

    visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitWhile_statement(ExprParser::While_statementContext *ctx) override 
  {

    //cout << "while" << endl;
    visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitCase_statement(ExprParser::Case_statementContext *ctx) override 
  {
 
    //cout << "case" << endl;

    if(stack.checkStack(ctx->IDENTIFIER()->getText()) == false)
        cout << "Semantic Error " << ctx->IDENTIFIER()->getText() << " is undefined." << endl;

    visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitCondition(ExprParser::ConditionContext *ctx) override 
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFor_statement(ExprParser::For_statementContext *ctx) override 
  {

    //cout << "for" << endl;

    if(stack.checkStack(ctx->IDENTIFIER()->getText()) == false)
        cout << "Semantic Error " << ctx->IDENTIFIER()->getText() << " is undefined." << endl;
    else
    {
      if(stack.getEntry(ctx->IDENTIFIER()->getText())->type->getElemType() != "integer")
        cout << "Semantic Error: Type mismatch " << endl;
    }

   visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *ctx) override 
  {
    int x = visitSimple_expression(ctx->simple_expression(0));
    int y;
    int size = ctx->simple_expression().size();
    for(int i = 1; i < size; i++)
    {
      y = visitSimple_expression(ctx->simple_expression(i));
      if(y != x) cout << "Semantic Error: Type mismatch" << endl;
    }

    return x;
    //return visitChildren(ctx);;
  }

  virtual antlrcpp::Any visitSimple_expression(ExprParser::Simple_expressionContext *ctx) override 
  {
    int x = visitTerm(ctx->term(0));
    int y;
    int size = ctx->term().size();
    for(int i = 1; i < size; i++)
    {
      y = visitTerm(ctx->term(i));
      if(y != x) cout << "Semantic Error: Type mismatch" << endl;
    }

    return x;
    //return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(ExprParser::TermContext *ctx) override 
  {
    int x = visitFactor(ctx->factor(0));
    int y;
    int size = ctx->factor().size();
    for(int i = 1; i < size; i++)
    {
      y = visitFactor(ctx->factor(i));
      if(y != x) cout << "Semantic Error: Type mismatch" << endl;
    }

    return x;
    //return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(ExprParser::FactorContext *ctx) override 
  {
    int x = 0;

    if(ctx->INTEGER() != nullptr) return 1;
    else if(ctx->CHAR() != nullptr) return 2;
    else if(ctx->TRUE() != nullptr) return 3;
    else if(ctx->FALSE() != nullptr) return 3;
    else if(ctx->variable() != nullptr) x = visitVariable(ctx->variable());
    else if(ctx->expression() != nullptr) x = visitExpression(ctx->expression());

    return x;
    //return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *ctx) override 
  { 
    int x = 0;
    if(ctx->IDENTIFIER() != nullptr)
    {
      if(stack.checkStack(ctx->IDENTIFIER()->getText()) == false) 
        cout << "Semantic Error: "<< ctx->IDENTIFIER()->getText() << " is unidentified." << endl;
      else
      {
        symbEntry *node = stack.getEntry(ctx->IDENTIFIER()->getText());
        string type = node->type->getKind();
        ctx->entry = node;
        if(type == "integer") return 1;
        else if(type == "char") return 2;
        else if(type == "boolean") return 3;
        else if(stack.checkStack(type))
        {
          symbEntry* t = stack.getEntry(type);
          if((t->type != nullptr) && (t->type->getKind() != "ARRAY"))
          {
            if(t->type->getKind() == "integer") return 1;
            else if(t->type->getKind() == "char") return 2;
            else if(t->type->getKind() == "boolean") return 3;
          }
        }
      }
    }
    else if(ctx->function_call() != nullptr) x = visitFunction_call(ctx->function_call());
    else if(ctx->array_element() != nullptr) x = visitArray_element(ctx->array_element());

    return x;
  }

  virtual antlrcpp::Any visitArray_element(ExprParser::Array_elementContext *ctx) override 
  {
    int size = ctx->element().size();
    int x;
    for(int i = 0; i < size; i++)
    {
      x = visitElement(ctx->element(i));
      if(x != 1) cout << "Semantic Error: Type mismatch expecting integer" << endl;
    }

    if(stack.checkStack(ctx->IDENTIFIER()->getText()) == false) 
      cout << "Semantic Error: " << ctx->IDENTIFIER()->getText() << " is unidentified." << endl;
    else
    {
      symbEntry *node = stack.getEntry(ctx->IDENTIFIER()->getText());
      string type = node->type->getElemType();
      node = stack.getEntry(type);
      type = node->type->getElemType();
      if(type == "integer") return 1;
      else if(type == "char") return 2;
      else if(type == "boolean") return 3;
    }

    return 0;
  }

  virtual antlrcpp::Any visitElement(ExprParser::ElementContext *ctx) override 
  {
    if(ctx->IDENTIFIER() != nullptr)
    {
      if(stack.checkStack(ctx->IDENTIFIER()->getText()) == false) 
        cout << "Semantic Error: " << ctx->IDENTIFIER()->getText() << " is unidentified." << endl;
      else
      {
        symbEntry *node = stack.getEntry(ctx->IDENTIFIER()->getText());
        string type = node->type->getElemType();
        if(type == "integer") return 1;
        else if(type == "char") return 2;
        else if(type == "boolean") return 3;
      }
    }
    else if(ctx->CHAR() != nullptr) return 2;
    else if(ctx->INTEGER() != nullptr) return 1;
    else if(ctx->TRUE() != nullptr) return 3;
    else if(ctx->FALSE() != nullptr) return 3;

    //return visitChildren(ctx);

    return 0;
  }

  virtual antlrcpp::Any visitFunction_call(ExprParser::Function_callContext *ctx) override 
  {
    symbEntry *node;

    if(stack.checkStack(ctx->function_name()->IDENTIFIER()->getText()) == false)
    {
      cout << "Semantic Error " << ctx->function_name()->IDENTIFIER()->getText() << " is undefined." << endl;
    }
    else 
    {
      node = stack.getLocal()->getEntry(ctx->function_name()->IDENTIFIER()->getText());
      ctx->entry = node;
      ctx->table = print.findTab(ctx->function_name()->IDENTIFIER()->getText());
    }

    if(node->type->getElemType() == "integer") return 1;
    else if(node->type->getElemType() == "char") return 2;
    else if(node->type->getElemType() == "boolean") return 3;

    //return visitChildren(ctx);

    return 0;
    
  }

  virtual antlrcpp::Any visitFunction_name(ExprParser::Function_nameContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg_list(ExprParser::Arg_listContext *ctx) override 
  {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitArg(ExprParser::ArgContext *ctx) override 
  {
    return visitChildren(ctx);
  }


};

