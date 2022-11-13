
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"
#include "symbEntry.h"



class  ExprParser : public antlr4::Parser {
public:
  enum {
    DOT_DOT = 1, DOT = 2, COLON = 3, CHAR = 4, STRINGS = 5, AND = 6, ARRAY = 7, 
    ASM = 8, BEGIN = 9, BOOLEAN = 10, BREAK = 11, CASE = 12, CONST = 13, 
    CONSTRUCTOR = 14, CONTINUE = 15, DESTRUCTOR = 16, DIV = 17, DO = 18, 
    DOWNTO = 19, ELSE = 20, END = 21, FALSE = 22, FILE = 23, FOR = 24, FUNCTION = 25, 
    GOTO = 26, IF = 27, IMPLEMENTATION = 28, IN = 29, INLINE = 30, INTERFACE = 31, 
    LABEL = 32, MOD = 33, NIL = 34, NOT = 35, OBJECT = 36, OF = 37, ON = 38, 
    OPERATOR = 39, OR = 40, PACKED = 41, PROCEDURE = 42, PROGRAM = 43, RECORD = 44, 
    REPEAT = 45, SET = 46, SHL = 47, SHR = 48, STRING = 49, THEN = 50, TO = 51, 
    TRUE = 52, TYPE = 53, UNIT = 54, UNTIL = 55, USES = 56, VAR = 57, WHILE = 58, 
    WITH = 59, XOR = 60, IDENTIFIER = 61, INTEGER = 62, REAL = 63, PLUSOP = 64, 
    MINUSOP = 65, MULTOP = 66, DIVOP = 67, ASSIGN = 68, EQUAL = 69, NE = 70, 
    LTEQ = 71, GTEQ = 72, LT = 73, GT = 74, PLUSEQUAL = 75, MINUSEQUAL = 76, 
    MULTEQUAL = 77, DIVEQUAL = 78, CARAT = 79, SEMICOLON = 80, COMMA = 81, 
    LPAREN = 82, RPAREN = 83, LBRACKET = 84, RBRACKET = 85, LBRACE = 86, 
    RBRACE = 87, LCOMMENT = 88, RCOMMENT = 89, ERROR = 90, WS = 91, COMMENT = 92
  };

  enum {
    RuleProgram = 0, RuleProgram_header = 1, RuleDeclarations = 2, RuleConstants = 3, 
    RuleConstant_list = 4, RuleConstant_declaration = 5, RuleConst_identifier = 6, 
    RuleTypes = 7, RuleType_list = 8, RuleType_declaration = 9, RuleType_identifier_list = 10, 
    RuleType_identifier = 11, RuleType_specification = 12, RuleSimpletype = 13, 
    RuleArraytype = 14, RuleArray_start = 15, RuleDimensions = 16, RuleScalar = 17, 
    RuleRange = 18, RuleVariables = 19, RuleVariable_list = 20, RuleVariable_declarations = 21, 
    RuleVar_identifier_list = 22, RuleVar_identifier = 23, RuleFunctions = 24, 
    RuleFunct_type = 25, RuleProc = 26, RuleFunct = 27, RuleFunct_identifier = 28, 
    RuleParameters = 29, RuleParam_list = 30, RuleParam_declaration = 31, 
    RuleParam_identifier_list = 32, RuleParam_identifier = 33, RuleStatement_list = 34, 
    RuleStatement = 35, RuleCompound_statement = 36, RuleAssign_statement = 37, 
    RuleRepeat_statement = 38, RuleIf_statement = 39, RuleWhile_statement = 40, 
    RuleCase_statement = 41, RuleCondition = 42, RuleFor_statement = 43, 
    RuleExpression = 44, RuleSimple_expression = 45, RuleTerm = 46, RuleFactor = 47, 
    RuleVariable = 48, RuleArray_element = 49, RuleElement = 50, RuleFunction_call = 51, 
    RuleFunction_name = 52, RuleArg_list = 53, RuleArg = 54
  };

  ExprParser(antlr4::TokenStream *input);
  ~ExprParser();

  virtual std::string getGrammarFileName() const override;
  virtual const antlr4::atn::ATN& getATN() const override { return _atn; };
  virtual const std::vector<std::string>& getTokenNames() const override { return _tokenNames; }; // deprecated: use vocabulary instead.
  virtual const std::vector<std::string>& getRuleNames() const override;
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;


  class ProgramContext;
  class Program_headerContext;
  class DeclarationsContext;
  class ConstantsContext;
  class Constant_listContext;
  class Constant_declarationContext;
  class Const_identifierContext;
  class TypesContext;
  class Type_listContext;
  class Type_declarationContext;
  class Type_identifier_listContext;
  class Type_identifierContext;
  class Type_specificationContext;
  class SimpletypeContext;
  class ArraytypeContext;
  class Array_startContext;
  class DimensionsContext;
  class ScalarContext;
  class RangeContext;
  class VariablesContext;
  class Variable_listContext;
  class Variable_declarationsContext;
  class Var_identifier_listContext;
  class Var_identifierContext;
  class FunctionsContext;
  class Funct_typeContext;
  class ProcContext;
  class FunctContext;
  class Funct_identifierContext;
  class ParametersContext;
  class Param_listContext;
  class Param_declarationContext;
  class Param_identifier_listContext;
  class Param_identifierContext;
  class Statement_listContext;
  class StatementContext;
  class Compound_statementContext;
  class Assign_statementContext;
  class Repeat_statementContext;
  class If_statementContext;
  class While_statementContext;
  class Case_statementContext;
  class ConditionContext;
  class For_statementContext;
  class ExpressionContext;
  class Simple_expressionContext;
  class TermContext;
  class FactorContext;
  class VariableContext;
  class Array_elementContext;
  class ElementContext;
  class Function_callContext;
  class Function_nameContext;
  class Arg_listContext;
  class ArgContext; 

  class  ProgramContext : public antlr4::ParserRuleContext {
  public:
    ProgramContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Program_headerContext *program_header();
    DeclarationsContext *declarations();
    Compound_statementContext *compound_statement();
    antlr4::tree::TerminalNode *DOT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProgramContext* program();

  class  Program_headerContext : public antlr4::ParserRuleContext {
  public:
    Program_headerContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROGRAM();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *SEMICOLON();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Program_headerContext* program_header();

  class  DeclarationsContext : public antlr4::ParserRuleContext {
  public:
    DeclarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ConstantsContext *constants();
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    TypesContext *types();
    VariablesContext *variables();
    FunctionsContext *functions();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DeclarationsContext* declarations();

  class  ConstantsContext : public antlr4::ParserRuleContext {
  public:
    ConstantsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CONST();
    Constant_listContext *constant_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConstantsContext* constants();

  class  Constant_listContext : public antlr4::ParserRuleContext {
  public:
    Constant_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Constant_declarationContext *> constant_declaration();
    Constant_declarationContext* constant_declaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_listContext* constant_list();

  class  Constant_declarationContext : public antlr4::ParserRuleContext {
  public:
    Constant_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Const_identifierContext *const_identifier();
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *STRINGS();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *REAL();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *BOOLEAN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Constant_declarationContext* constant_declaration();

  class  Const_identifierContext : public antlr4::ParserRuleContext {
  public:
    Const_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Const_identifierContext* const_identifier();

  class  TypesContext : public antlr4::ParserRuleContext {
  public:
    TypesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *TYPE();
    Type_listContext *type_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TypesContext* types();

  class  Type_listContext : public antlr4::ParserRuleContext {
  public:
    Type_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_declarationContext *> type_declaration();
    Type_declarationContext* type_declaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_listContext* type_list();

  class  Type_declarationContext : public antlr4::ParserRuleContext {
  public:
    Type_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Type_identifier_listContext *type_identifier_list();
    antlr4::tree::TerminalNode *EQUAL();
    Type_specificationContext *type_specification();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_declarationContext* type_declaration();

  class  Type_identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Type_identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Type_identifierContext *> type_identifier();
    Type_identifierContext* type_identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_identifier_listContext* type_identifier_list();

  class  Type_identifierContext : public antlr4::ParserRuleContext {
  public:
    Type_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_identifierContext* type_identifier();

  class  Type_specificationContext : public antlr4::ParserRuleContext {
  public:
    Type_specificationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpletypeContext *simpletype();
    ArraytypeContext *arraytype();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Type_specificationContext* type_specification();

  class  SimpletypeContext : public antlr4::ParserRuleContext {
  public:
    SimpletypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ScalarContext *scalar();
    RangeContext *range();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  SimpletypeContext* simpletype();

  class  ArraytypeContext : public antlr4::ParserRuleContext {
  public:
    ArraytypeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Array_startContext *array_start();
    Type_specificationContext *type_specification();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArraytypeContext* arraytype();

  class  Array_startContext : public antlr4::ParserRuleContext {
  public:
    Array_startContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *ARRAY();
    antlr4::tree::TerminalNode *LBRACKET();
    DimensionsContext *dimensions();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *OF();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_startContext* array_start();

  class  DimensionsContext : public antlr4::ParserRuleContext {
  public:
    DimensionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    SimpletypeContext *simpletype();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  DimensionsContext* dimensions();

  class  ScalarContext : public antlr4::ParserRuleContext {
  public:
    ScalarContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *BOOLEAN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ScalarContext* scalar();

  class  RangeContext : public antlr4::ParserRuleContext {
  public:
    RangeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    antlr4::tree::TerminalNode *DOT_DOT();
    std::vector<antlr4::tree::TerminalNode *> CHAR();
    antlr4::tree::TerminalNode* CHAR(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  RangeContext* range();

  class  VariablesContext : public antlr4::ParserRuleContext {
  public:
    VariablesContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *VAR();
    Variable_listContext *variable_list();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariablesContext* variables();

  class  Variable_listContext : public antlr4::ParserRuleContext {
  public:
    Variable_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Variable_declarationsContext *> variable_declarations();
    Variable_declarationsContext* variable_declarations(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_listContext* variable_list();

  class  Variable_declarationsContext : public antlr4::ParserRuleContext {
  public:
    Variable_declarationsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Var_identifier_listContext *var_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    Type_specificationContext *type_specification();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Variable_declarationsContext* variable_declarations();

  class  Var_identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Var_identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Var_identifierContext *> var_identifier();
    Var_identifierContext* var_identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_identifier_listContext* var_identifier_list();

  class  Var_identifierContext : public antlr4::ParserRuleContext {
  public:
    Var_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Var_identifierContext* var_identifier();

  class  FunctionsContext : public antlr4::ParserRuleContext {
  public:
    FunctionsContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Funct_typeContext *> funct_type();
    Funct_typeContext* funct_type(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctionsContext* functions();

  class  Funct_typeContext : public antlr4::ParserRuleContext {
  public:
    Funct_typeContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    DeclarationsContext *declarations();
    Compound_statementContext *compound_statement();
    ProcContext *proc();
    FunctContext *funct();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Funct_typeContext* funct_type();

  class  ProcContext : public antlr4::ParserRuleContext {
  public:
    ProcContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *PROCEDURE();
    Funct_identifierContext *funct_identifier();
    ParametersContext *parameters();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ProcContext* proc();

  class  FunctContext : public antlr4::ParserRuleContext {
  public:
    FunctContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FUNCTION();
    Funct_identifierContext *funct_identifier();
    antlr4::tree::TerminalNode *COLON();
    Type_identifierContext *type_identifier();
    ParametersContext *parameters();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FunctContext* funct();

  class  Funct_identifierContext : public antlr4::ParserRuleContext {
  public:
    Funct_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Funct_identifierContext* funct_identifier();

  class  ParametersContext : public antlr4::ParserRuleContext {
  public:
    ParametersContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LPAREN();
    Param_listContext *param_list();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ParametersContext* parameters();

  class  Param_listContext : public antlr4::ParserRuleContext {
  public:
    Param_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Param_declarationContext *> param_declaration();
    Param_declarationContext* param_declaration(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_listContext* param_list();

  class  Param_declarationContext : public antlr4::ParserRuleContext {
  public:
    Param_declarationContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Param_identifier_listContext *param_identifier_list();
    antlr4::tree::TerminalNode *COLON();
    Type_identifierContext *type_identifier();
    antlr4::tree::TerminalNode *VAR();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_declarationContext* param_declaration();

  class  Param_identifier_listContext : public antlr4::ParserRuleContext {
  public:
    Param_identifier_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Param_identifierContext *> param_identifier();
    Param_identifierContext* param_identifier(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_identifier_listContext* param_identifier_list();

  class  Param_identifierContext : public antlr4::ParserRuleContext {
  public:
    Param_identifierContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Param_identifierContext* param_identifier();

  class  Statement_listContext : public antlr4::ParserRuleContext {
  public:
    Statement_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Statement_listContext* statement_list();

  class  StatementContext : public antlr4::ParserRuleContext {
  public:
    StatementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Compound_statementContext *compound_statement();
    Assign_statementContext *assign_statement();
    Repeat_statementContext *repeat_statement();
    If_statementContext *if_statement();
    While_statementContext *while_statement();
    Case_statementContext *case_statement();
    For_statementContext *for_statement();
    Function_callContext *function_call();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  StatementContext* statement();

  class  Compound_statementContext : public antlr4::ParserRuleContext {
  public:
    Compound_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *BEGIN();
    Statement_listContext *statement_list();
    antlr4::tree::TerminalNode *END();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Compound_statementContext* compound_statement();

  class  Assign_statementContext : public antlr4::ParserRuleContext {
  public:
    Assign_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *ASSIGN();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Assign_statementContext* assign_statement();

  class  Repeat_statementContext : public antlr4::ParserRuleContext {
  public:
    Repeat_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *REPEAT();
    Statement_listContext *statement_list();
    antlr4::tree::TerminalNode *UNTIL();
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Repeat_statementContext* repeat_statement();

  class  If_statementContext : public antlr4::ParserRuleContext {
  public:
    If_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IF();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *THEN();
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    antlr4::tree::TerminalNode *ELSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  If_statementContext* if_statement();

  class  While_statementContext : public antlr4::ParserRuleContext {
  public:
    While_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *WHILE();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  While_statementContext* while_statement();

  class  Case_statementContext : public antlr4::ParserRuleContext {
  public:
    Case_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *CASE();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *RPAREN();
    antlr4::tree::TerminalNode *OF();
    antlr4::tree::TerminalNode *END();
    std::vector<ConditionContext *> condition();
    ConditionContext* condition(size_t i);
    std::vector<StatementContext *> statement();
    StatementContext* statement(size_t i);
    std::vector<antlr4::tree::TerminalNode *> SEMICOLON();
    antlr4::tree::TerminalNode* SEMICOLON(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Case_statementContext* case_statement();

  class  ConditionContext : public antlr4::ParserRuleContext {
  public:
    ConditionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    antlr4::tree::TerminalNode *COLON();
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ConditionContext* condition();

  class  For_statementContext : public antlr4::ParserRuleContext {
  public:
    For_statementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *FOR();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *ASSIGN();
    std::vector<antlr4::tree::TerminalNode *> INTEGER();
    antlr4::tree::TerminalNode* INTEGER(size_t i);
    antlr4::tree::TerminalNode *TO();
    antlr4::tree::TerminalNode *DO();
    StatementContext *statement();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  For_statementContext* for_statement();

  class  ExpressionContext : public antlr4::ParserRuleContext {
  public:
    ExpressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<Simple_expressionContext *> simple_expression();
    Simple_expressionContext* simple_expression(size_t i);
    antlr4::tree::TerminalNode *EQUAL();
    antlr4::tree::TerminalNode *NE();
    antlr4::tree::TerminalNode *LTEQ();
    antlr4::tree::TerminalNode *GTEQ();
    antlr4::tree::TerminalNode *LT();
    antlr4::tree::TerminalNode *GT();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ExpressionContext* expression();

  class  Simple_expressionContext : public antlr4::ParserRuleContext {
  public:
    Simple_expressionContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<TermContext *> term();
    TermContext* term(size_t i);
    std::vector<antlr4::tree::TerminalNode *> PLUSOP();
    antlr4::tree::TerminalNode* PLUSOP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MINUSOP();
    antlr4::tree::TerminalNode* MINUSOP(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Simple_expressionContext* simple_expression();

  class  TermContext : public antlr4::ParserRuleContext {
  public:
    TermContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<FactorContext *> factor();
    FactorContext* factor(size_t i);
    std::vector<antlr4::tree::TerminalNode *> MULTOP();
    antlr4::tree::TerminalNode* MULTOP(size_t i);
    std::vector<antlr4::tree::TerminalNode *> DIVOP();
    antlr4::tree::TerminalNode* DIVOP(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  TermContext* term();

  class  FactorContext : public antlr4::ParserRuleContext {
  public:
    FactorContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    VariableContext *variable();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();
    antlr4::tree::TerminalNode *MINUSOP();
    antlr4::tree::TerminalNode *LPAREN();
    ExpressionContext *expression();
    antlr4::tree::TerminalNode *RPAREN();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  FactorContext* factor();

  class  VariableContext : public antlr4::ParserRuleContext {
  public:
    VariableContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    Function_callContext *function_call();
    Array_elementContext *array_element();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  VariableContext* variable();

  class  Array_elementContext : public antlr4::ParserRuleContext {
  public:
    Array_elementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();
    std::vector<ElementContext *> element();
    ElementContext* element(size_t i);

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Array_elementContext* array_element();

  class  ElementContext : public antlr4::ParserRuleContext {
  public:
    ElementContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *LBRACKET();
    antlr4::tree::TerminalNode *RBRACKET();
    antlr4::tree::TerminalNode *CHAR();
    antlr4::tree::TerminalNode *INTEGER();
    antlr4::tree::TerminalNode *IDENTIFIER();
    antlr4::tree::TerminalNode *TRUE();
    antlr4::tree::TerminalNode *FALSE();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ElementContext* element();

  class  Function_callContext : public antlr4::ParserRuleContext {
  public:
    Function_callContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    Function_nameContext *function_name();
    antlr4::tree::TerminalNode *LPAREN();
    antlr4::tree::TerminalNode *RPAREN();
    Arg_listContext *arg_list();

    symbEntry *entry;


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_callContext* function_call();

  class  Function_nameContext : public antlr4::ParserRuleContext {
  public:
    Function_nameContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    antlr4::tree::TerminalNode *IDENTIFIER();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Function_nameContext* function_name();

  class  Arg_listContext : public antlr4::ParserRuleContext {
  public:
    Arg_listContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    std::vector<ArgContext *> arg();
    ArgContext* arg(size_t i);
    std::vector<antlr4::tree::TerminalNode *> COMMA();
    antlr4::tree::TerminalNode* COMMA(size_t i);


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  Arg_listContext* arg_list();

  class  ArgContext : public antlr4::ParserRuleContext {
  public:
    ArgContext(antlr4::ParserRuleContext *parent, size_t invokingState);
    virtual size_t getRuleIndex() const override;
    ExpressionContext *expression();


    virtual antlrcpp::Any accept(antlr4::tree::ParseTreeVisitor *visitor) override;
   
  };

  ArgContext* arg();


private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

