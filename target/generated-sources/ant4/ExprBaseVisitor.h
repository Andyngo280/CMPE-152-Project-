

	#include "symbEntry.h"



// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprVisitor.h"


/**
 * This class provides an empty implementation of ExprVisitor, which can be
 * extended to create a visitor which only needs to handle a subset of the available methods.
 */
class  ExprBaseVisitor : public ExprVisitor {
public:

  virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitProgram_header(ExprParser::Program_headerContext *ctx) override {
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

  virtual antlrcpp::Any visitVariables(ExprParser::VariablesContext *ctx) override {
    return visitChildren(ctx);
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

  virtual antlrcpp::Any visitVar_identifier(ExprParser::Var_identifierContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFunctions(ExprParser::FunctionsContext *ctx) override {
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

  virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitSimple_expression(ExprParser::Simple_expressionContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitTerm(ExprParser::TermContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitMdop(ExprParser::MdopContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitFactor(ExprParser::FactorContext *ctx) override {
    return visitChildren(ctx);
  }

  virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *ctx) override {
    return visitChildren(ctx);
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

