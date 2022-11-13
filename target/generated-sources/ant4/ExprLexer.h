
// Generated from Expr.g4 by ANTLR 4.7.2

#pragma once


#include "antlr4-runtime.h"




class  ExprLexer : public antlr4::Lexer {
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

  ExprLexer(antlr4::CharStream *input);
  ~ExprLexer();

  virtual std::string getGrammarFileName() const override;
  virtual const std::vector<std::string>& getRuleNames() const override;

  virtual const std::vector<std::string>& getChannelNames() const override;
  virtual const std::vector<std::string>& getModeNames() const override;
  virtual const std::vector<std::string>& getTokenNames() const override; // deprecated, use vocabulary instead
  virtual antlr4::dfa::Vocabulary& getVocabulary() const override;

  virtual const std::vector<uint16_t> getSerializedATN() const override;
  virtual const antlr4::atn::ATN& getATN() const override;

private:
  static std::vector<antlr4::dfa::DFA> _decisionToDFA;
  static antlr4::atn::PredictionContextCache _sharedContextCache;
  static std::vector<std::string> _ruleNames;
  static std::vector<std::string> _tokenNames;
  static std::vector<std::string> _channelNames;
  static std::vector<std::string> _modeNames;

  static std::vector<std::string> _literalNames;
  static std::vector<std::string> _symbolicNames;
  static antlr4::dfa::Vocabulary _vocabulary;
  static antlr4::atn::ATN _atn;
  static std::vector<uint16_t> _serializedATN;


  // Individual action functions triggered by action() above.

  // Individual semantic predicate functions triggered by sempred() above.

  struct Initializer {
    Initializer();
  };
  static Initializer _init;
};

