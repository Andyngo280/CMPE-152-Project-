

	#include "symbEntry.h"



// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "ExprParser.h"



/**
 * This class defines an abstract visitor for a parse tree
 * produced by ExprParser.
 */
class  ExprVisitor : public antlr4::tree::AbstractParseTreeVisitor {
public:

  /**
   * Visit parse trees produced by ExprParser.
   */
    virtual antlrcpp::Any visitProgram(ExprParser::ProgramContext *context) = 0;

    virtual antlrcpp::Any visitProgram_header(ExprParser::Program_headerContext *context) = 0;

    virtual antlrcpp::Any visitDeclarations(ExprParser::DeclarationsContext *context) = 0;

    virtual antlrcpp::Any visitConstants(ExprParser::ConstantsContext *context) = 0;

    virtual antlrcpp::Any visitConstant_list(ExprParser::Constant_listContext *context) = 0;

    virtual antlrcpp::Any visitConstant_declaration(ExprParser::Constant_declarationContext *context) = 0;

    virtual antlrcpp::Any visitConst_identifier(ExprParser::Const_identifierContext *context) = 0;

    virtual antlrcpp::Any visitTypes(ExprParser::TypesContext *context) = 0;

    virtual antlrcpp::Any visitType_list(ExprParser::Type_listContext *context) = 0;

    virtual antlrcpp::Any visitType_declaration(ExprParser::Type_declarationContext *context) = 0;

    virtual antlrcpp::Any visitType_identifier_list(ExprParser::Type_identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitType_identifier(ExprParser::Type_identifierContext *context) = 0;

    virtual antlrcpp::Any visitType_specification(ExprParser::Type_specificationContext *context) = 0;

    virtual antlrcpp::Any visitSimpletype(ExprParser::SimpletypeContext *context) = 0;

    virtual antlrcpp::Any visitArraytype(ExprParser::ArraytypeContext *context) = 0;

    virtual antlrcpp::Any visitArray_start(ExprParser::Array_startContext *context) = 0;

    virtual antlrcpp::Any visitDimensions(ExprParser::DimensionsContext *context) = 0;

    virtual antlrcpp::Any visitScalar(ExprParser::ScalarContext *context) = 0;

    virtual antlrcpp::Any visitRange(ExprParser::RangeContext *context) = 0;

    virtual antlrcpp::Any visitVariables(ExprParser::VariablesContext *context) = 0;

    virtual antlrcpp::Any visitVariable_list(ExprParser::Variable_listContext *context) = 0;

    virtual antlrcpp::Any visitVariable_declarations(ExprParser::Variable_declarationsContext *context) = 0;

    virtual antlrcpp::Any visitVar_identifier_list(ExprParser::Var_identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitVar_identifier(ExprParser::Var_identifierContext *context) = 0;

    virtual antlrcpp::Any visitFunctions(ExprParser::FunctionsContext *context) = 0;

    virtual antlrcpp::Any visitFunct_type(ExprParser::Funct_typeContext *context) = 0;

    virtual antlrcpp::Any visitProc(ExprParser::ProcContext *context) = 0;

    virtual antlrcpp::Any visitFunct(ExprParser::FunctContext *context) = 0;

    virtual antlrcpp::Any visitFunct_identifier(ExprParser::Funct_identifierContext *context) = 0;

    virtual antlrcpp::Any visitParameters(ExprParser::ParametersContext *context) = 0;

    virtual antlrcpp::Any visitParam_list(ExprParser::Param_listContext *context) = 0;

    virtual antlrcpp::Any visitParam_declaration(ExprParser::Param_declarationContext *context) = 0;

    virtual antlrcpp::Any visitParam_identifier_list(ExprParser::Param_identifier_listContext *context) = 0;

    virtual antlrcpp::Any visitParam_identifier(ExprParser::Param_identifierContext *context) = 0;

    virtual antlrcpp::Any visitStatement_list(ExprParser::Statement_listContext *context) = 0;

    virtual antlrcpp::Any visitStatement(ExprParser::StatementContext *context) = 0;

    virtual antlrcpp::Any visitCompound_statement(ExprParser::Compound_statementContext *context) = 0;

    virtual antlrcpp::Any visitAssign_statement(ExprParser::Assign_statementContext *context) = 0;

    virtual antlrcpp::Any visitRepeat_statement(ExprParser::Repeat_statementContext *context) = 0;

    virtual antlrcpp::Any visitIf_statement(ExprParser::If_statementContext *context) = 0;

    virtual antlrcpp::Any visitWhile_statement(ExprParser::While_statementContext *context) = 0;

    virtual antlrcpp::Any visitCase_statement(ExprParser::Case_statementContext *context) = 0;

    virtual antlrcpp::Any visitCondition(ExprParser::ConditionContext *context) = 0;

    virtual antlrcpp::Any visitFor_statement(ExprParser::For_statementContext *context) = 0;

    virtual antlrcpp::Any visitExpression(ExprParser::ExpressionContext *context) = 0;

    virtual antlrcpp::Any visitSimple_expression(ExprParser::Simple_expressionContext *context) = 0;

    virtual antlrcpp::Any visitTerm(ExprParser::TermContext *context) = 0;

    virtual antlrcpp::Any visitMdop(ExprParser::MdopContext *context) = 0;

    virtual antlrcpp::Any visitFactor(ExprParser::FactorContext *context) = 0;

    virtual antlrcpp::Any visitVariable(ExprParser::VariableContext *context) = 0;

    virtual antlrcpp::Any visitArray_element(ExprParser::Array_elementContext *context) = 0;

    virtual antlrcpp::Any visitElement(ExprParser::ElementContext *context) = 0;

    virtual antlrcpp::Any visitFunction_call(ExprParser::Function_callContext *context) = 0;

    virtual antlrcpp::Any visitFunction_name(ExprParser::Function_nameContext *context) = 0;

    virtual antlrcpp::Any visitArg_list(ExprParser::Arg_listContext *context) = 0;

    virtual antlrcpp::Any visitArg(ExprParser::ArgContext *context) = 0;


};

