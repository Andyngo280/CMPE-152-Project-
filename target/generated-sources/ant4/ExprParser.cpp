
// Generated from Expr.g4 by ANTLR 4.7.2


#include "ExprVisitor.h"

#include "ExprParser.h"


using namespace antlrcpp;
using namespace antlr4;

ExprParser::ExprParser(TokenStream *input) : Parser(input) {
  _interpreter = new atn::ParserATNSimulator(this, _atn, _decisionToDFA, _sharedContextCache);
}

ExprParser::~ExprParser() {
  delete _interpreter;
}

std::string ExprParser::getGrammarFileName() const {
  return "Expr.g4";
}

const std::vector<std::string>& ExprParser::getRuleNames() const {
  return _ruleNames;
}

dfa::Vocabulary& ExprParser::getVocabulary() const {
  return _vocabulary;
}


//----------------- ProgramContext ------------------------------------------------------------------

ExprParser::ProgramContext::ProgramContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Program_headerContext* ExprParser::ProgramContext::program_header() {
  return getRuleContext<ExprParser::Program_headerContext>(0);
}

ExprParser::DeclarationsContext* ExprParser::ProgramContext::declarations() {
  return getRuleContext<ExprParser::DeclarationsContext>(0);
}

ExprParser::Compound_statementContext* ExprParser::ProgramContext::compound_statement() {
  return getRuleContext<ExprParser::Compound_statementContext>(0);
}

tree::TerminalNode* ExprParser::ProgramContext::DOT() {
  return getToken(ExprParser::DOT, 0);
}


size_t ExprParser::ProgramContext::getRuleIndex() const {
  return ExprParser::RuleProgram;
}


antlrcpp::Any ExprParser::ProgramContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProgram(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProgramContext* ExprParser::program() {
  ProgramContext *_localctx = _tracker.createInstance<ProgramContext>(_ctx, getState());
  enterRule(_localctx, 0, ExprParser::RuleProgram);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(110);
    program_header();
    setState(111);
    declarations();
    setState(112);
    compound_statement();
    setState(113);
    match(ExprParser::DOT);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Program_headerContext ------------------------------------------------------------------

ExprParser::Program_headerContext::Program_headerContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Program_headerContext::PROGRAM() {
  return getToken(ExprParser::PROGRAM, 0);
}

tree::TerminalNode* ExprParser::Program_headerContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::Program_headerContext::SEMICOLON() {
  return getToken(ExprParser::SEMICOLON, 0);
}


size_t ExprParser::Program_headerContext::getRuleIndex() const {
  return ExprParser::RuleProgram_header;
}


antlrcpp::Any ExprParser::Program_headerContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProgram_header(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Program_headerContext* ExprParser::program_header() {
  Program_headerContext *_localctx = _tracker.createInstance<Program_headerContext>(_ctx, getState());
  enterRule(_localctx, 2, ExprParser::RuleProgram_header);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(115);
    match(ExprParser::PROGRAM);
    setState(116);
    match(ExprParser::IDENTIFIER);
    setState(117);
    match(ExprParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DeclarationsContext ------------------------------------------------------------------

ExprParser::DeclarationsContext::DeclarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ConstantsContext* ExprParser::DeclarationsContext::constants() {
  return getRuleContext<ExprParser::ConstantsContext>(0);
}

std::vector<tree::TerminalNode *> ExprParser::DeclarationsContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::DeclarationsContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}

ExprParser::TypesContext* ExprParser::DeclarationsContext::types() {
  return getRuleContext<ExprParser::TypesContext>(0);
}

ExprParser::VariablesContext* ExprParser::DeclarationsContext::variables() {
  return getRuleContext<ExprParser::VariablesContext>(0);
}

ExprParser::FunctionsContext* ExprParser::DeclarationsContext::functions() {
  return getRuleContext<ExprParser::FunctionsContext>(0);
}


size_t ExprParser::DeclarationsContext::getRuleIndex() const {
  return ExprParser::RuleDeclarations;
}


antlrcpp::Any ExprParser::DeclarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDeclarations(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::DeclarationsContext* ExprParser::declarations() {
  DeclarationsContext *_localctx = _tracker.createInstance<DeclarationsContext>(_ctx, getState());
  enterRule(_localctx, 4, ExprParser::RuleDeclarations);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(122);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::CONST) {
      setState(119);
      constants();
      setState(120);
      match(ExprParser::SEMICOLON);
    }
    setState(127);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::TYPE) {
      setState(124);
      types();
      setState(125);
      match(ExprParser::SEMICOLON);
    }
    setState(132);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::VAR) {
      setState(129);
      variables();
      setState(130);
      match(ExprParser::SEMICOLON);
    }
    setState(137);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::FUNCTION

    || _la == ExprParser::PROCEDURE) {
      setState(134);
      functions();
      setState(135);
      match(ExprParser::SEMICOLON);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConstantsContext ------------------------------------------------------------------

ExprParser::ConstantsContext::ConstantsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ConstantsContext::CONST() {
  return getToken(ExprParser::CONST, 0);
}

ExprParser::Constant_listContext* ExprParser::ConstantsContext::constant_list() {
  return getRuleContext<ExprParser::Constant_listContext>(0);
}


size_t ExprParser::ConstantsContext::getRuleIndex() const {
  return ExprParser::RuleConstants;
}


antlrcpp::Any ExprParser::ConstantsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstants(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConstantsContext* ExprParser::constants() {
  ConstantsContext *_localctx = _tracker.createInstance<ConstantsContext>(_ctx, getState());
  enterRule(_localctx, 6, ExprParser::RuleConstants);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(139);
    match(ExprParser::CONST);
    setState(140);
    constant_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_listContext ------------------------------------------------------------------

ExprParser::Constant_listContext::Constant_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Constant_declarationContext *> ExprParser::Constant_listContext::constant_declaration() {
  return getRuleContexts<ExprParser::Constant_declarationContext>();
}

ExprParser::Constant_declarationContext* ExprParser::Constant_listContext::constant_declaration(size_t i) {
  return getRuleContext<ExprParser::Constant_declarationContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Constant_listContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::Constant_listContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::Constant_listContext::getRuleIndex() const {
  return ExprParser::RuleConstant_list;
}


antlrcpp::Any ExprParser::Constant_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstant_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Constant_listContext* ExprParser::constant_list() {
  Constant_listContext *_localctx = _tracker.createInstance<Constant_listContext>(_ctx, getState());
  enterRule(_localctx, 8, ExprParser::RuleConstant_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(142);
    constant_declaration();
    setState(147);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(143);
        match(ExprParser::SEMICOLON);
        setState(144);
        constant_declaration(); 
      }
      setState(149);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 4, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Constant_declarationContext ------------------------------------------------------------------

ExprParser::Constant_declarationContext::Constant_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Const_identifierContext* ExprParser::Constant_declarationContext::const_identifier() {
  return getRuleContext<ExprParser::Const_identifierContext>(0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::STRINGS() {
  return getToken(ExprParser::STRINGS, 0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::INTEGER() {
  return getToken(ExprParser::INTEGER, 0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::REAL() {
  return getToken(ExprParser::REAL, 0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::Constant_declarationContext::BOOLEAN() {
  return getToken(ExprParser::BOOLEAN, 0);
}


size_t ExprParser::Constant_declarationContext::getRuleIndex() const {
  return ExprParser::RuleConstant_declaration;
}


antlrcpp::Any ExprParser::Constant_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConstant_declaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Constant_declarationContext* ExprParser::constant_declaration() {
  Constant_declarationContext *_localctx = _tracker.createInstance<Constant_declarationContext>(_ctx, getState());
  enterRule(_localctx, 10, ExprParser::RuleConstant_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(150);
    const_identifier();
    setState(151);
    match(ExprParser::EQUAL);
    setState(152);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::CHAR)
      | (1ULL << ExprParser::STRINGS)
      | (1ULL << ExprParser::BOOLEAN)
      | (1ULL << ExprParser::IDENTIFIER)
      | (1ULL << ExprParser::INTEGER)
      | (1ULL << ExprParser::REAL))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Const_identifierContext ------------------------------------------------------------------

ExprParser::Const_identifierContext::Const_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Const_identifierContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}


size_t ExprParser::Const_identifierContext::getRuleIndex() const {
  return ExprParser::RuleConst_identifier;
}


antlrcpp::Any ExprParser::Const_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitConst_identifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Const_identifierContext* ExprParser::const_identifier() {
  Const_identifierContext *_localctx = _tracker.createInstance<Const_identifierContext>(_ctx, getState());
  enterRule(_localctx, 12, ExprParser::RuleConst_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(154);
    match(ExprParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TypesContext ------------------------------------------------------------------

ExprParser::TypesContext::TypesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::TypesContext::TYPE() {
  return getToken(ExprParser::TYPE, 0);
}

ExprParser::Type_listContext* ExprParser::TypesContext::type_list() {
  return getRuleContext<ExprParser::Type_listContext>(0);
}


size_t ExprParser::TypesContext::getRuleIndex() const {
  return ExprParser::RuleTypes;
}


antlrcpp::Any ExprParser::TypesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTypes(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TypesContext* ExprParser::types() {
  TypesContext *_localctx = _tracker.createInstance<TypesContext>(_ctx, getState());
  enterRule(_localctx, 14, ExprParser::RuleTypes);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(156);
    match(ExprParser::TYPE);
    setState(157);
    type_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_listContext ------------------------------------------------------------------

ExprParser::Type_listContext::Type_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Type_declarationContext *> ExprParser::Type_listContext::type_declaration() {
  return getRuleContexts<ExprParser::Type_declarationContext>();
}

ExprParser::Type_declarationContext* ExprParser::Type_listContext::type_declaration(size_t i) {
  return getRuleContext<ExprParser::Type_declarationContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Type_listContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::Type_listContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::Type_listContext::getRuleIndex() const {
  return ExprParser::RuleType_list;
}


antlrcpp::Any ExprParser::Type_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Type_listContext* ExprParser::type_list() {
  Type_listContext *_localctx = _tracker.createInstance<Type_listContext>(_ctx, getState());
  enterRule(_localctx, 16, ExprParser::RuleType_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(159);
    type_declaration();
    setState(164);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(160);
        match(ExprParser::SEMICOLON);
        setState(161);
        type_declaration(); 
      }
      setState(166);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 5, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_declarationContext ------------------------------------------------------------------

ExprParser::Type_declarationContext::Type_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Type_identifier_listContext* ExprParser::Type_declarationContext::type_identifier_list() {
  return getRuleContext<ExprParser::Type_identifier_listContext>(0);
}

tree::TerminalNode* ExprParser::Type_declarationContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

ExprParser::Type_specificationContext* ExprParser::Type_declarationContext::type_specification() {
  return getRuleContext<ExprParser::Type_specificationContext>(0);
}


size_t ExprParser::Type_declarationContext::getRuleIndex() const {
  return ExprParser::RuleType_declaration;
}


antlrcpp::Any ExprParser::Type_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType_declaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Type_declarationContext* ExprParser::type_declaration() {
  Type_declarationContext *_localctx = _tracker.createInstance<Type_declarationContext>(_ctx, getState());
  enterRule(_localctx, 18, ExprParser::RuleType_declaration);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(167);
    type_identifier_list();
    setState(168);
    match(ExprParser::EQUAL);
    setState(169);
    type_specification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_identifier_listContext ------------------------------------------------------------------

ExprParser::Type_identifier_listContext::Type_identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Type_identifierContext *> ExprParser::Type_identifier_listContext::type_identifier() {
  return getRuleContexts<ExprParser::Type_identifierContext>();
}

ExprParser::Type_identifierContext* ExprParser::Type_identifier_listContext::type_identifier(size_t i) {
  return getRuleContext<ExprParser::Type_identifierContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Type_identifier_listContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::Type_identifier_listContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::Type_identifier_listContext::getRuleIndex() const {
  return ExprParser::RuleType_identifier_list;
}


antlrcpp::Any ExprParser::Type_identifier_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType_identifier_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Type_identifier_listContext* ExprParser::type_identifier_list() {
  Type_identifier_listContext *_localctx = _tracker.createInstance<Type_identifier_listContext>(_ctx, getState());
  enterRule(_localctx, 20, ExprParser::RuleType_identifier_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(171);
    type_identifier();
    setState(176);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(172);
      match(ExprParser::COMMA);
      setState(173);
      type_identifier();
      setState(178);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_identifierContext ------------------------------------------------------------------

ExprParser::Type_identifierContext::Type_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Type_identifierContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}


size_t ExprParser::Type_identifierContext::getRuleIndex() const {
  return ExprParser::RuleType_identifier;
}


antlrcpp::Any ExprParser::Type_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType_identifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Type_identifierContext* ExprParser::type_identifier() {
  Type_identifierContext *_localctx = _tracker.createInstance<Type_identifierContext>(_ctx, getState());
  enterRule(_localctx, 22, ExprParser::RuleType_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(179);
    match(ExprParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Type_specificationContext ------------------------------------------------------------------

ExprParser::Type_specificationContext::Type_specificationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpletypeContext* ExprParser::Type_specificationContext::simpletype() {
  return getRuleContext<ExprParser::SimpletypeContext>(0);
}

ExprParser::ArraytypeContext* ExprParser::Type_specificationContext::arraytype() {
  return getRuleContext<ExprParser::ArraytypeContext>(0);
}


size_t ExprParser::Type_specificationContext::getRuleIndex() const {
  return ExprParser::RuleType_specification;
}


antlrcpp::Any ExprParser::Type_specificationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitType_specification(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Type_specificationContext* ExprParser::type_specification() {
  Type_specificationContext *_localctx = _tracker.createInstance<Type_specificationContext>(_ctx, getState());
  enterRule(_localctx, 24, ExprParser::RuleType_specification);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(183);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::CHAR:
      case ExprParser::BOOLEAN:
      case ExprParser::IDENTIFIER:
      case ExprParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(181);
        simpletype();
        break;
      }

      case ExprParser::ARRAY: {
        enterOuterAlt(_localctx, 2);
        setState(182);
        arraytype();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- SimpletypeContext ------------------------------------------------------------------

ExprParser::SimpletypeContext::SimpletypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ScalarContext* ExprParser::SimpletypeContext::scalar() {
  return getRuleContext<ExprParser::ScalarContext>(0);
}

ExprParser::RangeContext* ExprParser::SimpletypeContext::range() {
  return getRuleContext<ExprParser::RangeContext>(0);
}


size_t ExprParser::SimpletypeContext::getRuleIndex() const {
  return ExprParser::RuleSimpletype;
}


antlrcpp::Any ExprParser::SimpletypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSimpletype(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::SimpletypeContext* ExprParser::simpletype() {
  SimpletypeContext *_localctx = _tracker.createInstance<SimpletypeContext>(_ctx, getState());
  enterRule(_localctx, 26, ExprParser::RuleSimpletype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(187);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 8, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(185);
      scalar();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(186);
      range();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArraytypeContext ------------------------------------------------------------------

ExprParser::ArraytypeContext::ArraytypeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Array_startContext* ExprParser::ArraytypeContext::array_start() {
  return getRuleContext<ExprParser::Array_startContext>(0);
}

ExprParser::Type_specificationContext* ExprParser::ArraytypeContext::type_specification() {
  return getRuleContext<ExprParser::Type_specificationContext>(0);
}


size_t ExprParser::ArraytypeContext::getRuleIndex() const {
  return ExprParser::RuleArraytype;
}


antlrcpp::Any ExprParser::ArraytypeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArraytype(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ArraytypeContext* ExprParser::arraytype() {
  ArraytypeContext *_localctx = _tracker.createInstance<ArraytypeContext>(_ctx, getState());
  enterRule(_localctx, 28, ExprParser::RuleArraytype);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(189);
    array_start();
    setState(190);
    type_specification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_startContext ------------------------------------------------------------------

ExprParser::Array_startContext::Array_startContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Array_startContext::ARRAY() {
  return getToken(ExprParser::ARRAY, 0);
}

tree::TerminalNode* ExprParser::Array_startContext::LBRACKET() {
  return getToken(ExprParser::LBRACKET, 0);
}

ExprParser::DimensionsContext* ExprParser::Array_startContext::dimensions() {
  return getRuleContext<ExprParser::DimensionsContext>(0);
}

tree::TerminalNode* ExprParser::Array_startContext::RBRACKET() {
  return getToken(ExprParser::RBRACKET, 0);
}

tree::TerminalNode* ExprParser::Array_startContext::OF() {
  return getToken(ExprParser::OF, 0);
}


size_t ExprParser::Array_startContext::getRuleIndex() const {
  return ExprParser::RuleArray_start;
}


antlrcpp::Any ExprParser::Array_startContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArray_start(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Array_startContext* ExprParser::array_start() {
  Array_startContext *_localctx = _tracker.createInstance<Array_startContext>(_ctx, getState());
  enterRule(_localctx, 30, ExprParser::RuleArray_start);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(192);
    match(ExprParser::ARRAY);
    setState(193);
    match(ExprParser::LBRACKET);
    setState(194);
    dimensions();
    setState(195);
    match(ExprParser::RBRACKET);
    setState(196);
    match(ExprParser::OF);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- DimensionsContext ------------------------------------------------------------------

ExprParser::DimensionsContext::DimensionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::SimpletypeContext* ExprParser::DimensionsContext::simpletype() {
  return getRuleContext<ExprParser::SimpletypeContext>(0);
}


size_t ExprParser::DimensionsContext::getRuleIndex() const {
  return ExprParser::RuleDimensions;
}


antlrcpp::Any ExprParser::DimensionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitDimensions(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::DimensionsContext* ExprParser::dimensions() {
  DimensionsContext *_localctx = _tracker.createInstance<DimensionsContext>(_ctx, getState());
  enterRule(_localctx, 32, ExprParser::RuleDimensions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(198);
    simpletype();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ScalarContext ------------------------------------------------------------------

ExprParser::ScalarContext::ScalarContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ScalarContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

tree::TerminalNode* ExprParser::ScalarContext::INTEGER() {
  return getToken(ExprParser::INTEGER, 0);
}

tree::TerminalNode* ExprParser::ScalarContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::ScalarContext::BOOLEAN() {
  return getToken(ExprParser::BOOLEAN, 0);
}


size_t ExprParser::ScalarContext::getRuleIndex() const {
  return ExprParser::RuleScalar;
}


antlrcpp::Any ExprParser::ScalarContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitScalar(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ScalarContext* ExprParser::scalar() {
  ScalarContext *_localctx = _tracker.createInstance<ScalarContext>(_ctx, getState());
  enterRule(_localctx, 34, ExprParser::RuleScalar);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(200);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::CHAR)
      | (1ULL << ExprParser::BOOLEAN)
      | (1ULL << ExprParser::IDENTIFIER)
      | (1ULL << ExprParser::INTEGER))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- RangeContext ------------------------------------------------------------------

ExprParser::RangeContext::RangeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ExprParser::RangeContext::INTEGER() {
  return getTokens(ExprParser::INTEGER);
}

tree::TerminalNode* ExprParser::RangeContext::INTEGER(size_t i) {
  return getToken(ExprParser::INTEGER, i);
}

tree::TerminalNode* ExprParser::RangeContext::DOT_DOT() {
  return getToken(ExprParser::DOT_DOT, 0);
}

std::vector<tree::TerminalNode *> ExprParser::RangeContext::CHAR() {
  return getTokens(ExprParser::CHAR);
}

tree::TerminalNode* ExprParser::RangeContext::CHAR(size_t i) {
  return getToken(ExprParser::CHAR, i);
}


size_t ExprParser::RangeContext::getRuleIndex() const {
  return ExprParser::RuleRange;
}


antlrcpp::Any ExprParser::RangeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRange(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::RangeContext* ExprParser::range() {
  RangeContext *_localctx = _tracker.createInstance<RangeContext>(_ctx, getState());
  enterRule(_localctx, 36, ExprParser::RuleRange);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(208);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::INTEGER: {
        enterOuterAlt(_localctx, 1);
        setState(202);
        match(ExprParser::INTEGER);
        setState(203);
        match(ExprParser::DOT_DOT);
        setState(204);
        match(ExprParser::INTEGER);
        break;
      }

      case ExprParser::CHAR: {
        enterOuterAlt(_localctx, 2);
        setState(205);
        match(ExprParser::CHAR);
        setState(206);
        match(ExprParser::DOT_DOT);
        setState(207);
        match(ExprParser::CHAR);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariablesContext ------------------------------------------------------------------

ExprParser::VariablesContext::VariablesContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::VariablesContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}

ExprParser::Variable_listContext* ExprParser::VariablesContext::variable_list() {
  return getRuleContext<ExprParser::Variable_listContext>(0);
}


size_t ExprParser::VariablesContext::getRuleIndex() const {
  return ExprParser::RuleVariables;
}


antlrcpp::Any ExprParser::VariablesContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariables(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariablesContext* ExprParser::variables() {
  VariablesContext *_localctx = _tracker.createInstance<VariablesContext>(_ctx, getState());
  enterRule(_localctx, 38, ExprParser::RuleVariables);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(210);
    match(ExprParser::VAR);
    setState(211);
    variable_list();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_listContext ------------------------------------------------------------------

ExprParser::Variable_listContext::Variable_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Variable_declarationsContext *> ExprParser::Variable_listContext::variable_declarations() {
  return getRuleContexts<ExprParser::Variable_declarationsContext>();
}

ExprParser::Variable_declarationsContext* ExprParser::Variable_listContext::variable_declarations(size_t i) {
  return getRuleContext<ExprParser::Variable_declarationsContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Variable_listContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::Variable_listContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::Variable_listContext::getRuleIndex() const {
  return ExprParser::RuleVariable_list;
}


antlrcpp::Any ExprParser::Variable_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariable_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Variable_listContext* ExprParser::variable_list() {
  Variable_listContext *_localctx = _tracker.createInstance<Variable_listContext>(_ctx, getState());
  enterRule(_localctx, 40, ExprParser::RuleVariable_list);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(213);
    variable_declarations();
    setState(218);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(214);
        match(ExprParser::SEMICOLON);
        setState(215);
        variable_declarations(); 
      }
      setState(220);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 10, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Variable_declarationsContext ------------------------------------------------------------------

ExprParser::Variable_declarationsContext::Variable_declarationsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Var_identifier_listContext* ExprParser::Variable_declarationsContext::var_identifier_list() {
  return getRuleContext<ExprParser::Var_identifier_listContext>(0);
}

tree::TerminalNode* ExprParser::Variable_declarationsContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::Type_specificationContext* ExprParser::Variable_declarationsContext::type_specification() {
  return getRuleContext<ExprParser::Type_specificationContext>(0);
}


size_t ExprParser::Variable_declarationsContext::getRuleIndex() const {
  return ExprParser::RuleVariable_declarations;
}


antlrcpp::Any ExprParser::Variable_declarationsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariable_declarations(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Variable_declarationsContext* ExprParser::variable_declarations() {
  Variable_declarationsContext *_localctx = _tracker.createInstance<Variable_declarationsContext>(_ctx, getState());
  enterRule(_localctx, 42, ExprParser::RuleVariable_declarations);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(221);
    var_identifier_list();
    setState(222);
    match(ExprParser::COLON);
    setState(223);
    type_specification();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_identifier_listContext ------------------------------------------------------------------

ExprParser::Var_identifier_listContext::Var_identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Var_identifierContext *> ExprParser::Var_identifier_listContext::var_identifier() {
  return getRuleContexts<ExprParser::Var_identifierContext>();
}

ExprParser::Var_identifierContext* ExprParser::Var_identifier_listContext::var_identifier(size_t i) {
  return getRuleContext<ExprParser::Var_identifierContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Var_identifier_listContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::Var_identifier_listContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::Var_identifier_listContext::getRuleIndex() const {
  return ExprParser::RuleVar_identifier_list;
}


antlrcpp::Any ExprParser::Var_identifier_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVar_identifier_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Var_identifier_listContext* ExprParser::var_identifier_list() {
  Var_identifier_listContext *_localctx = _tracker.createInstance<Var_identifier_listContext>(_ctx, getState());
  enterRule(_localctx, 44, ExprParser::RuleVar_identifier_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(225);
    var_identifier();
    setState(230);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(226);
      match(ExprParser::COMMA);
      setState(227);
      var_identifier();
      setState(232);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Var_identifierContext ------------------------------------------------------------------

ExprParser::Var_identifierContext::Var_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Var_identifierContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}


size_t ExprParser::Var_identifierContext::getRuleIndex() const {
  return ExprParser::RuleVar_identifier;
}


antlrcpp::Any ExprParser::Var_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVar_identifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Var_identifierContext* ExprParser::var_identifier() {
  Var_identifierContext *_localctx = _tracker.createInstance<Var_identifierContext>(_ctx, getState());
  enterRule(_localctx, 46, ExprParser::RuleVar_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(233);
    match(ExprParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctionsContext ------------------------------------------------------------------

ExprParser::FunctionsContext::FunctionsContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Funct_typeContext *> ExprParser::FunctionsContext::funct_type() {
  return getRuleContexts<ExprParser::Funct_typeContext>();
}

ExprParser::Funct_typeContext* ExprParser::FunctionsContext::funct_type(size_t i) {
  return getRuleContext<ExprParser::Funct_typeContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::FunctionsContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::FunctionsContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::FunctionsContext::getRuleIndex() const {
  return ExprParser::RuleFunctions;
}


antlrcpp::Any ExprParser::FunctionsContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunctions(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FunctionsContext* ExprParser::functions() {
  FunctionsContext *_localctx = _tracker.createInstance<FunctionsContext>(_ctx, getState());
  enterRule(_localctx, 48, ExprParser::RuleFunctions);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(235);
    funct_type();
    setState(240);
    _errHandler->sync(this);
    alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
      if (alt == 1) {
        setState(236);
        match(ExprParser::SEMICOLON);
        setState(237);
        funct_type(); 
      }
      setState(242);
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 12, _ctx);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Funct_typeContext ------------------------------------------------------------------

ExprParser::Funct_typeContext::Funct_typeContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::DeclarationsContext* ExprParser::Funct_typeContext::declarations() {
  return getRuleContext<ExprParser::DeclarationsContext>(0);
}

ExprParser::Compound_statementContext* ExprParser::Funct_typeContext::compound_statement() {
  return getRuleContext<ExprParser::Compound_statementContext>(0);
}

ExprParser::ProcContext* ExprParser::Funct_typeContext::proc() {
  return getRuleContext<ExprParser::ProcContext>(0);
}

ExprParser::FunctContext* ExprParser::Funct_typeContext::funct() {
  return getRuleContext<ExprParser::FunctContext>(0);
}


size_t ExprParser::Funct_typeContext::getRuleIndex() const {
  return ExprParser::RuleFunct_type;
}


antlrcpp::Any ExprParser::Funct_typeContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunct_type(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Funct_typeContext* ExprParser::funct_type() {
  Funct_typeContext *_localctx = _tracker.createInstance<Funct_typeContext>(_ctx, getState());
  enterRule(_localctx, 50, ExprParser::RuleFunct_type);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(245);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::PROCEDURE: {
        setState(243);
        proc();
        break;
      }

      case ExprParser::FUNCTION: {
        setState(244);
        funct();
        break;
      }

    default:
      throw NoViableAltException(this);
    }
    setState(247);
    declarations();
    setState(248);
    compound_statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ProcContext ------------------------------------------------------------------

ExprParser::ProcContext::ProcContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ProcContext::PROCEDURE() {
  return getToken(ExprParser::PROCEDURE, 0);
}

ExprParser::Funct_identifierContext* ExprParser::ProcContext::funct_identifier() {
  return getRuleContext<ExprParser::Funct_identifierContext>(0);
}

ExprParser::ParametersContext* ExprParser::ProcContext::parameters() {
  return getRuleContext<ExprParser::ParametersContext>(0);
}


size_t ExprParser::ProcContext::getRuleIndex() const {
  return ExprParser::RuleProc;
}


antlrcpp::Any ExprParser::ProcContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitProc(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ProcContext* ExprParser::proc() {
  ProcContext *_localctx = _tracker.createInstance<ProcContext>(_ctx, getState());
  enterRule(_localctx, 52, ExprParser::RuleProc);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(250);
    match(ExprParser::PROCEDURE);
    setState(251);
    funct_identifier();
    setState(253);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(252);
      parameters();
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FunctContext ------------------------------------------------------------------

ExprParser::FunctContext::FunctContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::FunctContext::FUNCTION() {
  return getToken(ExprParser::FUNCTION, 0);
}

ExprParser::Funct_identifierContext* ExprParser::FunctContext::funct_identifier() {
  return getRuleContext<ExprParser::Funct_identifierContext>(0);
}

tree::TerminalNode* ExprParser::FunctContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::Type_identifierContext* ExprParser::FunctContext::type_identifier() {
  return getRuleContext<ExprParser::Type_identifierContext>(0);
}

ExprParser::ParametersContext* ExprParser::FunctContext::parameters() {
  return getRuleContext<ExprParser::ParametersContext>(0);
}


size_t ExprParser::FunctContext::getRuleIndex() const {
  return ExprParser::RuleFunct;
}


antlrcpp::Any ExprParser::FunctContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunct(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FunctContext* ExprParser::funct() {
  FunctContext *_localctx = _tracker.createInstance<FunctContext>(_ctx, getState());
  enterRule(_localctx, 54, ExprParser::RuleFunct);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(255);
    match(ExprParser::FUNCTION);
    setState(256);
    funct_identifier();
    setState(258);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::LPAREN) {
      setState(257);
      parameters();
    }
    setState(260);
    match(ExprParser::COLON);
    setState(261);
    type_identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Funct_identifierContext ------------------------------------------------------------------

ExprParser::Funct_identifierContext::Funct_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Funct_identifierContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}


size_t ExprParser::Funct_identifierContext::getRuleIndex() const {
  return ExprParser::RuleFunct_identifier;
}


antlrcpp::Any ExprParser::Funct_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunct_identifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Funct_identifierContext* ExprParser::funct_identifier() {
  Funct_identifierContext *_localctx = _tracker.createInstance<Funct_identifierContext>(_ctx, getState());
  enterRule(_localctx, 56, ExprParser::RuleFunct_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(263);
    match(ExprParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ParametersContext ------------------------------------------------------------------

ExprParser::ParametersContext::ParametersContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ParametersContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::Param_listContext* ExprParser::ParametersContext::param_list() {
  return getRuleContext<ExprParser::Param_listContext>(0);
}

tree::TerminalNode* ExprParser::ParametersContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::ParametersContext::getRuleIndex() const {
  return ExprParser::RuleParameters;
}


antlrcpp::Any ExprParser::ParametersContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParameters(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ParametersContext* ExprParser::parameters() {
  ParametersContext *_localctx = _tracker.createInstance<ParametersContext>(_ctx, getState());
  enterRule(_localctx, 58, ExprParser::RuleParameters);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(265);
    match(ExprParser::LPAREN);
    setState(266);
    param_list();
    setState(267);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_listContext ------------------------------------------------------------------

ExprParser::Param_listContext::Param_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Param_declarationContext *> ExprParser::Param_listContext::param_declaration() {
  return getRuleContexts<ExprParser::Param_declarationContext>();
}

ExprParser::Param_declarationContext* ExprParser::Param_listContext::param_declaration(size_t i) {
  return getRuleContext<ExprParser::Param_declarationContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Param_listContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::Param_listContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::Param_listContext::getRuleIndex() const {
  return ExprParser::RuleParam_list;
}


antlrcpp::Any ExprParser::Param_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParam_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Param_listContext* ExprParser::param_list() {
  Param_listContext *_localctx = _tracker.createInstance<Param_listContext>(_ctx, getState());
  enterRule(_localctx, 60, ExprParser::RuleParam_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(269);
    param_declaration();
    setState(274);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::SEMICOLON) {
      setState(270);
      match(ExprParser::SEMICOLON);
      setState(271);
      param_declaration();
      setState(276);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_declarationContext ------------------------------------------------------------------

ExprParser::Param_declarationContext::Param_declarationContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Param_identifier_listContext* ExprParser::Param_declarationContext::param_identifier_list() {
  return getRuleContext<ExprParser::Param_identifier_listContext>(0);
}

tree::TerminalNode* ExprParser::Param_declarationContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

ExprParser::Type_identifierContext* ExprParser::Param_declarationContext::type_identifier() {
  return getRuleContext<ExprParser::Type_identifierContext>(0);
}

tree::TerminalNode* ExprParser::Param_declarationContext::VAR() {
  return getToken(ExprParser::VAR, 0);
}


size_t ExprParser::Param_declarationContext::getRuleIndex() const {
  return ExprParser::RuleParam_declaration;
}


antlrcpp::Any ExprParser::Param_declarationContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParam_declaration(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Param_declarationContext* ExprParser::param_declaration() {
  Param_declarationContext *_localctx = _tracker.createInstance<Param_declarationContext>(_ctx, getState());
  enterRule(_localctx, 62, ExprParser::RuleParam_declaration);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(278);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if (_la == ExprParser::VAR) {
      setState(277);
      match(ExprParser::VAR);
    }
    setState(280);
    param_identifier_list();
    setState(281);
    match(ExprParser::COLON);
    setState(282);
    type_identifier();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_identifier_listContext ------------------------------------------------------------------

ExprParser::Param_identifier_listContext::Param_identifier_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Param_identifierContext *> ExprParser::Param_identifier_listContext::param_identifier() {
  return getRuleContexts<ExprParser::Param_identifierContext>();
}

ExprParser::Param_identifierContext* ExprParser::Param_identifier_listContext::param_identifier(size_t i) {
  return getRuleContext<ExprParser::Param_identifierContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Param_identifier_listContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::Param_identifier_listContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::Param_identifier_listContext::getRuleIndex() const {
  return ExprParser::RuleParam_identifier_list;
}


antlrcpp::Any ExprParser::Param_identifier_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParam_identifier_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Param_identifier_listContext* ExprParser::param_identifier_list() {
  Param_identifier_listContext *_localctx = _tracker.createInstance<Param_identifier_listContext>(_ctx, getState());
  enterRule(_localctx, 64, ExprParser::RuleParam_identifier_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(284);
    param_identifier();
    setState(289);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(285);
      match(ExprParser::COMMA);
      setState(286);
      param_identifier();
      setState(291);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Param_identifierContext ------------------------------------------------------------------

ExprParser::Param_identifierContext::Param_identifierContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Param_identifierContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}


size_t ExprParser::Param_identifierContext::getRuleIndex() const {
  return ExprParser::RuleParam_identifier;
}


antlrcpp::Any ExprParser::Param_identifierContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitParam_identifier(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Param_identifierContext* ExprParser::param_identifier() {
  Param_identifierContext *_localctx = _tracker.createInstance<Param_identifierContext>(_ctx, getState());
  enterRule(_localctx, 66, ExprParser::RuleParam_identifier);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(292);
    match(ExprParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Statement_listContext ------------------------------------------------------------------

ExprParser::Statement_listContext::Statement_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ExprParser::Statement_listContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::Statement_listContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}

std::vector<ExprParser::StatementContext *> ExprParser::Statement_listContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::Statement_listContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}


size_t ExprParser::Statement_listContext::getRuleIndex() const {
  return ExprParser::RuleStatement_list;
}


antlrcpp::Any ExprParser::Statement_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatement_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Statement_listContext* ExprParser::statement_list() {
  Statement_listContext *_localctx = _tracker.createInstance<Statement_listContext>(_ctx, getState());
  enterRule(_localctx, 68, ExprParser::RuleStatement_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(301); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(297);
      _errHandler->sync(this);
      _la = _input->LA(1);
      while ((((_la & ~ 0x3fULL) == 0) &&
        ((1ULL << _la) & ((1ULL << ExprParser::BEGIN)
        | (1ULL << ExprParser::CASE)
        | (1ULL << ExprParser::FOR)
        | (1ULL << ExprParser::IF)
        | (1ULL << ExprParser::REPEAT)
        | (1ULL << ExprParser::WHILE)
        | (1ULL << ExprParser::IDENTIFIER))) != 0)) {
        setState(294);
        statement();
        setState(299);
        _errHandler->sync(this);
        _la = _input->LA(1);
      }
      setState(300);
      match(ExprParser::SEMICOLON);
      setState(303); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::BEGIN)
      | (1ULL << ExprParser::CASE)
      | (1ULL << ExprParser::FOR)
      | (1ULL << ExprParser::IF)
      | (1ULL << ExprParser::REPEAT)
      | (1ULL << ExprParser::WHILE)
      | (1ULL << ExprParser::IDENTIFIER))) != 0) || _la == ExprParser::SEMICOLON);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- StatementContext ------------------------------------------------------------------

ExprParser::StatementContext::StatementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Compound_statementContext* ExprParser::StatementContext::compound_statement() {
  return getRuleContext<ExprParser::Compound_statementContext>(0);
}

ExprParser::Assign_statementContext* ExprParser::StatementContext::assign_statement() {
  return getRuleContext<ExprParser::Assign_statementContext>(0);
}

ExprParser::Repeat_statementContext* ExprParser::StatementContext::repeat_statement() {
  return getRuleContext<ExprParser::Repeat_statementContext>(0);
}

ExprParser::If_statementContext* ExprParser::StatementContext::if_statement() {
  return getRuleContext<ExprParser::If_statementContext>(0);
}

ExprParser::While_statementContext* ExprParser::StatementContext::while_statement() {
  return getRuleContext<ExprParser::While_statementContext>(0);
}

ExprParser::Case_statementContext* ExprParser::StatementContext::case_statement() {
  return getRuleContext<ExprParser::Case_statementContext>(0);
}

ExprParser::For_statementContext* ExprParser::StatementContext::for_statement() {
  return getRuleContext<ExprParser::For_statementContext>(0);
}

ExprParser::Function_callContext* ExprParser::StatementContext::function_call() {
  return getRuleContext<ExprParser::Function_callContext>(0);
}


size_t ExprParser::StatementContext::getRuleIndex() const {
  return ExprParser::RuleStatement;
}


antlrcpp::Any ExprParser::StatementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitStatement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::StatementContext* ExprParser::statement() {
  StatementContext *_localctx = _tracker.createInstance<StatementContext>(_ctx, getState());
  enterRule(_localctx, 70, ExprParser::RuleStatement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(313);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 21, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(305);
      compound_statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(306);
      assign_statement();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(307);
      repeat_statement();
      break;
    }

    case 4: {
      enterOuterAlt(_localctx, 4);
      setState(308);
      if_statement();
      break;
    }

    case 5: {
      enterOuterAlt(_localctx, 5);
      setState(309);
      while_statement();
      break;
    }

    case 6: {
      enterOuterAlt(_localctx, 6);
      setState(310);
      case_statement();
      break;
    }

    case 7: {
      enterOuterAlt(_localctx, 7);
      setState(311);
      for_statement();
      break;
    }

    case 8: {
      enterOuterAlt(_localctx, 8);
      setState(312);
      function_call();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Compound_statementContext ------------------------------------------------------------------

ExprParser::Compound_statementContext::Compound_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Compound_statementContext::BEGIN() {
  return getToken(ExprParser::BEGIN, 0);
}

ExprParser::Statement_listContext* ExprParser::Compound_statementContext::statement_list() {
  return getRuleContext<ExprParser::Statement_listContext>(0);
}

tree::TerminalNode* ExprParser::Compound_statementContext::END() {
  return getToken(ExprParser::END, 0);
}


size_t ExprParser::Compound_statementContext::getRuleIndex() const {
  return ExprParser::RuleCompound_statement;
}


antlrcpp::Any ExprParser::Compound_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCompound_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Compound_statementContext* ExprParser::compound_statement() {
  Compound_statementContext *_localctx = _tracker.createInstance<Compound_statementContext>(_ctx, getState());
  enterRule(_localctx, 72, ExprParser::RuleCompound_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(315);
    match(ExprParser::BEGIN);
    setState(316);
    statement_list();
    setState(317);
    match(ExprParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Assign_statementContext ------------------------------------------------------------------

ExprParser::Assign_statementContext::Assign_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::VariableContext* ExprParser::Assign_statementContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

tree::TerminalNode* ExprParser::Assign_statementContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

ExprParser::ExpressionContext* ExprParser::Assign_statementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::Assign_statementContext::getRuleIndex() const {
  return ExprParser::RuleAssign_statement;
}


antlrcpp::Any ExprParser::Assign_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitAssign_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Assign_statementContext* ExprParser::assign_statement() {
  Assign_statementContext *_localctx = _tracker.createInstance<Assign_statementContext>(_ctx, getState());
  enterRule(_localctx, 74, ExprParser::RuleAssign_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(319);
    variable();
    setState(320);
    match(ExprParser::ASSIGN);
    setState(321);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Repeat_statementContext ------------------------------------------------------------------

ExprParser::Repeat_statementContext::Repeat_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Repeat_statementContext::REPEAT() {
  return getToken(ExprParser::REPEAT, 0);
}

ExprParser::Statement_listContext* ExprParser::Repeat_statementContext::statement_list() {
  return getRuleContext<ExprParser::Statement_listContext>(0);
}

tree::TerminalNode* ExprParser::Repeat_statementContext::UNTIL() {
  return getToken(ExprParser::UNTIL, 0);
}

ExprParser::ExpressionContext* ExprParser::Repeat_statementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::Repeat_statementContext::getRuleIndex() const {
  return ExprParser::RuleRepeat_statement;
}


antlrcpp::Any ExprParser::Repeat_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitRepeat_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Repeat_statementContext* ExprParser::repeat_statement() {
  Repeat_statementContext *_localctx = _tracker.createInstance<Repeat_statementContext>(_ctx, getState());
  enterRule(_localctx, 76, ExprParser::RuleRepeat_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(323);
    match(ExprParser::REPEAT);
    setState(324);
    statement_list();
    setState(325);
    match(ExprParser::UNTIL);
    setState(326);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- If_statementContext ------------------------------------------------------------------

ExprParser::If_statementContext::If_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::If_statementContext::IF() {
  return getToken(ExprParser::IF, 0);
}

tree::TerminalNode* ExprParser::If_statementContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::ExpressionContext* ExprParser::If_statementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::If_statementContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

tree::TerminalNode* ExprParser::If_statementContext::THEN() {
  return getToken(ExprParser::THEN, 0);
}

std::vector<ExprParser::StatementContext *> ExprParser::If_statementContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::If_statementContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}

tree::TerminalNode* ExprParser::If_statementContext::ELSE() {
  return getToken(ExprParser::ELSE, 0);
}


size_t ExprParser::If_statementContext::getRuleIndex() const {
  return ExprParser::RuleIf_statement;
}


antlrcpp::Any ExprParser::If_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitIf_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::If_statementContext* ExprParser::if_statement() {
  If_statementContext *_localctx = _tracker.createInstance<If_statementContext>(_ctx, getState());
  enterRule(_localctx, 78, ExprParser::RuleIf_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(344);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 22, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(328);
      match(ExprParser::IF);
      setState(329);
      match(ExprParser::LPAREN);
      setState(330);
      expression();
      setState(331);
      match(ExprParser::RPAREN);
      setState(332);
      match(ExprParser::THEN);
      setState(333);
      statement();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(335);
      match(ExprParser::IF);
      setState(336);
      match(ExprParser::LPAREN);
      setState(337);
      expression();
      setState(338);
      match(ExprParser::RPAREN);
      setState(339);
      match(ExprParser::THEN);
      setState(340);
      statement();
      setState(341);
      match(ExprParser::ELSE);
      setState(342);
      statement();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- While_statementContext ------------------------------------------------------------------

ExprParser::While_statementContext::While_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::While_statementContext::WHILE() {
  return getToken(ExprParser::WHILE, 0);
}

tree::TerminalNode* ExprParser::While_statementContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::ExpressionContext* ExprParser::While_statementContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::While_statementContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

tree::TerminalNode* ExprParser::While_statementContext::DO() {
  return getToken(ExprParser::DO, 0);
}

ExprParser::StatementContext* ExprParser::While_statementContext::statement() {
  return getRuleContext<ExprParser::StatementContext>(0);
}


size_t ExprParser::While_statementContext::getRuleIndex() const {
  return ExprParser::RuleWhile_statement;
}


antlrcpp::Any ExprParser::While_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitWhile_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::While_statementContext* ExprParser::while_statement() {
  While_statementContext *_localctx = _tracker.createInstance<While_statementContext>(_ctx, getState());
  enterRule(_localctx, 80, ExprParser::RuleWhile_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(346);
    match(ExprParser::WHILE);
    setState(347);
    match(ExprParser::LPAREN);
    setState(348);
    expression();
    setState(349);
    match(ExprParser::RPAREN);
    setState(350);
    match(ExprParser::DO);
    setState(351);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Case_statementContext ------------------------------------------------------------------

ExprParser::Case_statementContext::Case_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Case_statementContext::CASE() {
  return getToken(ExprParser::CASE, 0);
}

tree::TerminalNode* ExprParser::Case_statementContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

tree::TerminalNode* ExprParser::Case_statementContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::Case_statementContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

tree::TerminalNode* ExprParser::Case_statementContext::OF() {
  return getToken(ExprParser::OF, 0);
}

tree::TerminalNode* ExprParser::Case_statementContext::END() {
  return getToken(ExprParser::END, 0);
}

std::vector<ExprParser::ConditionContext *> ExprParser::Case_statementContext::condition() {
  return getRuleContexts<ExprParser::ConditionContext>();
}

ExprParser::ConditionContext* ExprParser::Case_statementContext::condition(size_t i) {
  return getRuleContext<ExprParser::ConditionContext>(i);
}

std::vector<ExprParser::StatementContext *> ExprParser::Case_statementContext::statement() {
  return getRuleContexts<ExprParser::StatementContext>();
}

ExprParser::StatementContext* ExprParser::Case_statementContext::statement(size_t i) {
  return getRuleContext<ExprParser::StatementContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Case_statementContext::SEMICOLON() {
  return getTokens(ExprParser::SEMICOLON);
}

tree::TerminalNode* ExprParser::Case_statementContext::SEMICOLON(size_t i) {
  return getToken(ExprParser::SEMICOLON, i);
}


size_t ExprParser::Case_statementContext::getRuleIndex() const {
  return ExprParser::RuleCase_statement;
}


antlrcpp::Any ExprParser::Case_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCase_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Case_statementContext* ExprParser::case_statement() {
  Case_statementContext *_localctx = _tracker.createInstance<Case_statementContext>(_ctx, getState());
  enterRule(_localctx, 82, ExprParser::RuleCase_statement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(353);
    match(ExprParser::CASE);
    setState(354);
    match(ExprParser::LPAREN);
    setState(355);
    match(ExprParser::IDENTIFIER);
    setState(356);
    match(ExprParser::RPAREN);
    setState(357);
    match(ExprParser::OF);
    setState(362); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(358);
      condition();
      setState(359);
      statement();
      setState(360);
      match(ExprParser::SEMICOLON);
      setState(364); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::INTEGER);
    setState(366);
    match(ExprParser::END);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ConditionContext ------------------------------------------------------------------

ExprParser::ConditionContext::ConditionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<tree::TerminalNode *> ExprParser::ConditionContext::INTEGER() {
  return getTokens(ExprParser::INTEGER);
}

tree::TerminalNode* ExprParser::ConditionContext::INTEGER(size_t i) {
  return getToken(ExprParser::INTEGER, i);
}

tree::TerminalNode* ExprParser::ConditionContext::COLON() {
  return getToken(ExprParser::COLON, 0);
}

std::vector<tree::TerminalNode *> ExprParser::ConditionContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::ConditionContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::ConditionContext::getRuleIndex() const {
  return ExprParser::RuleCondition;
}


antlrcpp::Any ExprParser::ConditionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitCondition(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ConditionContext* ExprParser::condition() {
  ConditionContext *_localctx = _tracker.createInstance<ConditionContext>(_ctx, getState());
  enterRule(_localctx, 84, ExprParser::RuleCondition);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    setState(378);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 25, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(368);
      match(ExprParser::INTEGER);
      setState(369);
      match(ExprParser::COLON);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(372); 
      _errHandler->sync(this);
      alt = 1;
      do {
        switch (alt) {
          case 1: {
                setState(370);
                match(ExprParser::INTEGER);
                setState(371);
                match(ExprParser::COMMA);
                break;
              }

        default:
          throw NoViableAltException(this);
        }
        setState(374); 
        _errHandler->sync(this);
        alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 24, _ctx);
      } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
      setState(376);
      match(ExprParser::INTEGER);
      setState(377);
      match(ExprParser::COLON);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- For_statementContext ------------------------------------------------------------------

ExprParser::For_statementContext::For_statementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::For_statementContext::FOR() {
  return getToken(ExprParser::FOR, 0);
}

tree::TerminalNode* ExprParser::For_statementContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::For_statementContext::ASSIGN() {
  return getToken(ExprParser::ASSIGN, 0);
}

std::vector<tree::TerminalNode *> ExprParser::For_statementContext::INTEGER() {
  return getTokens(ExprParser::INTEGER);
}

tree::TerminalNode* ExprParser::For_statementContext::INTEGER(size_t i) {
  return getToken(ExprParser::INTEGER, i);
}

tree::TerminalNode* ExprParser::For_statementContext::TO() {
  return getToken(ExprParser::TO, 0);
}

tree::TerminalNode* ExprParser::For_statementContext::DO() {
  return getToken(ExprParser::DO, 0);
}

ExprParser::StatementContext* ExprParser::For_statementContext::statement() {
  return getRuleContext<ExprParser::StatementContext>(0);
}


size_t ExprParser::For_statementContext::getRuleIndex() const {
  return ExprParser::RuleFor_statement;
}


antlrcpp::Any ExprParser::For_statementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFor_statement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::For_statementContext* ExprParser::for_statement() {
  For_statementContext *_localctx = _tracker.createInstance<For_statementContext>(_ctx, getState());
  enterRule(_localctx, 86, ExprParser::RuleFor_statement);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(380);
    match(ExprParser::FOR);
    setState(381);
    match(ExprParser::IDENTIFIER);
    setState(382);
    match(ExprParser::ASSIGN);
    setState(383);
    match(ExprParser::INTEGER);
    setState(384);
    match(ExprParser::TO);
    setState(385);
    match(ExprParser::INTEGER);
    setState(386);
    match(ExprParser::DO);
    setState(387);
    statement();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ExpressionContext ------------------------------------------------------------------

ExprParser::ExpressionContext::ExpressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::Simple_expressionContext *> ExprParser::ExpressionContext::simple_expression() {
  return getRuleContexts<ExprParser::Simple_expressionContext>();
}

ExprParser::Simple_expressionContext* ExprParser::ExpressionContext::simple_expression(size_t i) {
  return getRuleContext<ExprParser::Simple_expressionContext>(i);
}

tree::TerminalNode* ExprParser::ExpressionContext::EQUAL() {
  return getToken(ExprParser::EQUAL, 0);
}

tree::TerminalNode* ExprParser::ExpressionContext::NE() {
  return getToken(ExprParser::NE, 0);
}

tree::TerminalNode* ExprParser::ExpressionContext::LTEQ() {
  return getToken(ExprParser::LTEQ, 0);
}

tree::TerminalNode* ExprParser::ExpressionContext::GTEQ() {
  return getToken(ExprParser::GTEQ, 0);
}

tree::TerminalNode* ExprParser::ExpressionContext::LT() {
  return getToken(ExprParser::LT, 0);
}

tree::TerminalNode* ExprParser::ExpressionContext::GT() {
  return getToken(ExprParser::GT, 0);
}


size_t ExprParser::ExpressionContext::getRuleIndex() const {
  return ExprParser::RuleExpression;
}


antlrcpp::Any ExprParser::ExpressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitExpression(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ExpressionContext* ExprParser::expression() {
  ExpressionContext *_localctx = _tracker.createInstance<ExpressionContext>(_ctx, getState());
  enterRule(_localctx, 88, ExprParser::RuleExpression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(394);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 26, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(389);
      simple_expression();
      setState(390);
      _la = _input->LA(1);
      if (!(((((_la - 69) & ~ 0x3fULL) == 0) &&
        ((1ULL << (_la - 69)) & ((1ULL << (ExprParser::EQUAL - 69))
        | (1ULL << (ExprParser::NE - 69))
        | (1ULL << (ExprParser::LTEQ - 69))
        | (1ULL << (ExprParser::GTEQ - 69))
        | (1ULL << (ExprParser::LT - 69))
        | (1ULL << (ExprParser::GT - 69)))) != 0))) {
      _errHandler->recoverInline(this);
      }
      else {
        _errHandler->reportMatch(this);
        consume();
      }
      setState(391);
      simple_expression();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(393);
      simple_expression();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Simple_expressionContext ------------------------------------------------------------------

ExprParser::Simple_expressionContext::Simple_expressionContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::TermContext *> ExprParser::Simple_expressionContext::term() {
  return getRuleContexts<ExprParser::TermContext>();
}

ExprParser::TermContext* ExprParser::Simple_expressionContext::term(size_t i) {
  return getRuleContext<ExprParser::TermContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Simple_expressionContext::PLUSOP() {
  return getTokens(ExprParser::PLUSOP);
}

tree::TerminalNode* ExprParser::Simple_expressionContext::PLUSOP(size_t i) {
  return getToken(ExprParser::PLUSOP, i);
}

std::vector<tree::TerminalNode *> ExprParser::Simple_expressionContext::MINUSOP() {
  return getTokens(ExprParser::MINUSOP);
}

tree::TerminalNode* ExprParser::Simple_expressionContext::MINUSOP(size_t i) {
  return getToken(ExprParser::MINUSOP, i);
}


size_t ExprParser::Simple_expressionContext::getRuleIndex() const {
  return ExprParser::RuleSimple_expression;
}


antlrcpp::Any ExprParser::Simple_expressionContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitSimple_expression(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Simple_expressionContext* ExprParser::simple_expression() {
  Simple_expressionContext *_localctx = _tracker.createInstance<Simple_expressionContext>(_ctx, getState());
  enterRule(_localctx, 90, ExprParser::RuleSimple_expression);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    size_t alt;
    enterOuterAlt(_localctx, 1);
    setState(403); 
    _errHandler->sync(this);
    alt = 1;
    do {
      switch (alt) {
        case 1: {
              setState(399);
              _errHandler->sync(this);
              alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
              while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER) {
                if (alt == 1) {
                  setState(396);
                  _la = _input->LA(1);
                  if (!(_la == ExprParser::PLUSOP

                  || _la == ExprParser::MINUSOP)) {
                  _errHandler->recoverInline(this);
                  }
                  else {
                    _errHandler->reportMatch(this);
                    consume();
                  } 
                }
                setState(401);
                _errHandler->sync(this);
                alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 27, _ctx);
              }
              setState(402);
              term();
              break;
            }

      default:
        throw NoViableAltException(this);
      }
      setState(405); 
      _errHandler->sync(this);
      alt = getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 28, _ctx);
    } while (alt != 2 && alt != atn::ATN::INVALID_ALT_NUMBER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- TermContext ------------------------------------------------------------------

ExprParser::TermContext::TermContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::FactorContext *> ExprParser::TermContext::factor() {
  return getRuleContexts<ExprParser::FactorContext>();
}

ExprParser::FactorContext* ExprParser::TermContext::factor(size_t i) {
  return getRuleContext<ExprParser::FactorContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::TermContext::MULTOP() {
  return getTokens(ExprParser::MULTOP);
}

tree::TerminalNode* ExprParser::TermContext::MULTOP(size_t i) {
  return getToken(ExprParser::MULTOP, i);
}

std::vector<tree::TerminalNode *> ExprParser::TermContext::DIVOP() {
  return getTokens(ExprParser::DIVOP);
}

tree::TerminalNode* ExprParser::TermContext::DIVOP(size_t i) {
  return getToken(ExprParser::DIVOP, i);
}


size_t ExprParser::TermContext::getRuleIndex() const {
  return ExprParser::RuleTerm;
}


antlrcpp::Any ExprParser::TermContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitTerm(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::TermContext* ExprParser::term() {
  TermContext *_localctx = _tracker.createInstance<TermContext>(_ctx, getState());
  enterRule(_localctx, 92, ExprParser::RuleTerm);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(415);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 30, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(407);
      factor();
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(408);
      factor();
      setState(411); 
      _errHandler->sync(this);
      _la = _input->LA(1);
      do {
        setState(409);
        _la = _input->LA(1);
        if (!(_la == ExprParser::MULTOP

        || _la == ExprParser::DIVOP)) {
        _errHandler->recoverInline(this);
        }
        else {
          _errHandler->reportMatch(this);
          consume();
        }
        setState(410);
        factor();
        setState(413); 
        _errHandler->sync(this);
        _la = _input->LA(1);
      } while (_la == ExprParser::MULTOP

      || _la == ExprParser::DIVOP);
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- FactorContext ------------------------------------------------------------------

ExprParser::FactorContext::FactorContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::VariableContext* ExprParser::FactorContext::variable() {
  return getRuleContext<ExprParser::VariableContext>(0);
}

tree::TerminalNode* ExprParser::FactorContext::INTEGER() {
  return getToken(ExprParser::INTEGER, 0);
}

tree::TerminalNode* ExprParser::FactorContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

tree::TerminalNode* ExprParser::FactorContext::TRUE() {
  return getToken(ExprParser::TRUE, 0);
}

tree::TerminalNode* ExprParser::FactorContext::FALSE() {
  return getToken(ExprParser::FALSE, 0);
}

tree::TerminalNode* ExprParser::FactorContext::MINUSOP() {
  return getToken(ExprParser::MINUSOP, 0);
}

tree::TerminalNode* ExprParser::FactorContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

ExprParser::ExpressionContext* ExprParser::FactorContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}

tree::TerminalNode* ExprParser::FactorContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}


size_t ExprParser::FactorContext::getRuleIndex() const {
  return ExprParser::RuleFactor;
}


antlrcpp::Any ExprParser::FactorContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFactor(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::FactorContext* ExprParser::factor() {
  FactorContext *_localctx = _tracker.createInstance<FactorContext>(_ctx, getState());
  enterRule(_localctx, 94, ExprParser::RuleFactor);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(428);
    _errHandler->sync(this);
    switch (_input->LA(1)) {
      case ExprParser::IDENTIFIER: {
        enterOuterAlt(_localctx, 1);
        setState(417);
        variable();
        break;
      }

      case ExprParser::INTEGER: {
        enterOuterAlt(_localctx, 2);
        setState(418);
        match(ExprParser::INTEGER);
        break;
      }

      case ExprParser::CHAR: {
        enterOuterAlt(_localctx, 3);
        setState(419);
        match(ExprParser::CHAR);
        break;
      }

      case ExprParser::TRUE: {
        enterOuterAlt(_localctx, 4);
        setState(420);
        match(ExprParser::TRUE);
        break;
      }

      case ExprParser::FALSE: {
        enterOuterAlt(_localctx, 5);
        setState(421);
        match(ExprParser::FALSE);
        break;
      }

      case ExprParser::MINUSOP: {
        enterOuterAlt(_localctx, 6);
        setState(422);
        match(ExprParser::MINUSOP);
        setState(423);
        match(ExprParser::INTEGER);
        break;
      }

      case ExprParser::LPAREN: {
        enterOuterAlt(_localctx, 7);
        setState(424);
        match(ExprParser::LPAREN);
        setState(425);
        expression();
        setState(426);
        match(ExprParser::RPAREN);
        break;
      }

    default:
      throw NoViableAltException(this);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- VariableContext ------------------------------------------------------------------

ExprParser::VariableContext::VariableContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::VariableContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

ExprParser::Function_callContext* ExprParser::VariableContext::function_call() {
  return getRuleContext<ExprParser::Function_callContext>(0);
}

ExprParser::Array_elementContext* ExprParser::VariableContext::array_element() {
  return getRuleContext<ExprParser::Array_elementContext>(0);
}


size_t ExprParser::VariableContext::getRuleIndex() const {
  return ExprParser::RuleVariable;
}


antlrcpp::Any ExprParser::VariableContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitVariable(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::VariableContext* ExprParser::variable() {
  VariableContext *_localctx = _tracker.createInstance<VariableContext>(_ctx, getState());
  enterRule(_localctx, 96, ExprParser::RuleVariable);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    setState(433);
    _errHandler->sync(this);
    switch (getInterpreter<atn::ParserATNSimulator>()->adaptivePredict(_input, 32, _ctx)) {
    case 1: {
      enterOuterAlt(_localctx, 1);
      setState(430);
      match(ExprParser::IDENTIFIER);
      break;
    }

    case 2: {
      enterOuterAlt(_localctx, 2);
      setState(431);
      function_call();
      break;
    }

    case 3: {
      enterOuterAlt(_localctx, 3);
      setState(432);
      array_element();
      break;
    }

    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Array_elementContext ------------------------------------------------------------------

ExprParser::Array_elementContext::Array_elementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Array_elementContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

std::vector<ExprParser::ElementContext *> ExprParser::Array_elementContext::element() {
  return getRuleContexts<ExprParser::ElementContext>();
}

ExprParser::ElementContext* ExprParser::Array_elementContext::element(size_t i) {
  return getRuleContext<ExprParser::ElementContext>(i);
}


size_t ExprParser::Array_elementContext::getRuleIndex() const {
  return ExprParser::RuleArray_element;
}


antlrcpp::Any ExprParser::Array_elementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArray_element(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Array_elementContext* ExprParser::array_element() {
  Array_elementContext *_localctx = _tracker.createInstance<Array_elementContext>(_ctx, getState());
  enterRule(_localctx, 98, ExprParser::RuleArray_element);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(435);
    match(ExprParser::IDENTIFIER);
    setState(437); 
    _errHandler->sync(this);
    _la = _input->LA(1);
    do {
      setState(436);
      element();
      setState(439); 
      _errHandler->sync(this);
      _la = _input->LA(1);
    } while (_la == ExprParser::LBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ElementContext ------------------------------------------------------------------

ExprParser::ElementContext::ElementContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::ElementContext::LBRACKET() {
  return getToken(ExprParser::LBRACKET, 0);
}

tree::TerminalNode* ExprParser::ElementContext::RBRACKET() {
  return getToken(ExprParser::RBRACKET, 0);
}

tree::TerminalNode* ExprParser::ElementContext::CHAR() {
  return getToken(ExprParser::CHAR, 0);
}

tree::TerminalNode* ExprParser::ElementContext::INTEGER() {
  return getToken(ExprParser::INTEGER, 0);
}

tree::TerminalNode* ExprParser::ElementContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}

tree::TerminalNode* ExprParser::ElementContext::TRUE() {
  return getToken(ExprParser::TRUE, 0);
}

tree::TerminalNode* ExprParser::ElementContext::FALSE() {
  return getToken(ExprParser::FALSE, 0);
}


size_t ExprParser::ElementContext::getRuleIndex() const {
  return ExprParser::RuleElement;
}


antlrcpp::Any ExprParser::ElementContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitElement(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ElementContext* ExprParser::element() {
  ElementContext *_localctx = _tracker.createInstance<ElementContext>(_ctx, getState());
  enterRule(_localctx, 100, ExprParser::RuleElement);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(441);
    match(ExprParser::LBRACKET);
    setState(442);
    _la = _input->LA(1);
    if (!((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::CHAR)
      | (1ULL << ExprParser::FALSE)
      | (1ULL << ExprParser::TRUE)
      | (1ULL << ExprParser::IDENTIFIER)
      | (1ULL << ExprParser::INTEGER))) != 0))) {
    _errHandler->recoverInline(this);
    }
    else {
      _errHandler->reportMatch(this);
      consume();
    }
    setState(443);
    match(ExprParser::RBRACKET);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_callContext ------------------------------------------------------------------

ExprParser::Function_callContext::Function_callContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::Function_nameContext* ExprParser::Function_callContext::function_name() {
  return getRuleContext<ExprParser::Function_nameContext>(0);
}

tree::TerminalNode* ExprParser::Function_callContext::LPAREN() {
  return getToken(ExprParser::LPAREN, 0);
}

tree::TerminalNode* ExprParser::Function_callContext::RPAREN() {
  return getToken(ExprParser::RPAREN, 0);
}

ExprParser::Arg_listContext* ExprParser::Function_callContext::arg_list() {
  return getRuleContext<ExprParser::Arg_listContext>(0);
}


size_t ExprParser::Function_callContext::getRuleIndex() const {
  return ExprParser::RuleFunction_call;
}


antlrcpp::Any ExprParser::Function_callContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunction_call(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Function_callContext* ExprParser::function_call() {
  Function_callContext *_localctx = _tracker.createInstance<Function_callContext>(_ctx, getState());
  enterRule(_localctx, 102, ExprParser::RuleFunction_call);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(445);
    function_name();
    setState(446);
    match(ExprParser::LPAREN);
    setState(448);
    _errHandler->sync(this);

    _la = _input->LA(1);
    if ((((_la & ~ 0x3fULL) == 0) &&
      ((1ULL << _la) & ((1ULL << ExprParser::CHAR)
      | (1ULL << ExprParser::FALSE)
      | (1ULL << ExprParser::TRUE)
      | (1ULL << ExprParser::IDENTIFIER)
      | (1ULL << ExprParser::INTEGER))) != 0) || ((((_la - 64) & ~ 0x3fULL) == 0) &&
      ((1ULL << (_la - 64)) & ((1ULL << (ExprParser::PLUSOP - 64))
      | (1ULL << (ExprParser::MINUSOP - 64))
      | (1ULL << (ExprParser::LPAREN - 64)))) != 0)) {
      setState(447);
      arg_list();
    }
    setState(450);
    match(ExprParser::RPAREN);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Function_nameContext ------------------------------------------------------------------

ExprParser::Function_nameContext::Function_nameContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

tree::TerminalNode* ExprParser::Function_nameContext::IDENTIFIER() {
  return getToken(ExprParser::IDENTIFIER, 0);
}


size_t ExprParser::Function_nameContext::getRuleIndex() const {
  return ExprParser::RuleFunction_name;
}


antlrcpp::Any ExprParser::Function_nameContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitFunction_name(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Function_nameContext* ExprParser::function_name() {
  Function_nameContext *_localctx = _tracker.createInstance<Function_nameContext>(_ctx, getState());
  enterRule(_localctx, 104, ExprParser::RuleFunction_name);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(452);
    match(ExprParser::IDENTIFIER);
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- Arg_listContext ------------------------------------------------------------------

ExprParser::Arg_listContext::Arg_listContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

std::vector<ExprParser::ArgContext *> ExprParser::Arg_listContext::arg() {
  return getRuleContexts<ExprParser::ArgContext>();
}

ExprParser::ArgContext* ExprParser::Arg_listContext::arg(size_t i) {
  return getRuleContext<ExprParser::ArgContext>(i);
}

std::vector<tree::TerminalNode *> ExprParser::Arg_listContext::COMMA() {
  return getTokens(ExprParser::COMMA);
}

tree::TerminalNode* ExprParser::Arg_listContext::COMMA(size_t i) {
  return getToken(ExprParser::COMMA, i);
}


size_t ExprParser::Arg_listContext::getRuleIndex() const {
  return ExprParser::RuleArg_list;
}


antlrcpp::Any ExprParser::Arg_listContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArg_list(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::Arg_listContext* ExprParser::arg_list() {
  Arg_listContext *_localctx = _tracker.createInstance<Arg_listContext>(_ctx, getState());
  enterRule(_localctx, 106, ExprParser::RuleArg_list);
  size_t _la = 0;

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(454);
    arg();
    setState(459);
    _errHandler->sync(this);
    _la = _input->LA(1);
    while (_la == ExprParser::COMMA) {
      setState(455);
      match(ExprParser::COMMA);
      setState(456);
      arg();
      setState(461);
      _errHandler->sync(this);
      _la = _input->LA(1);
    }
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

//----------------- ArgContext ------------------------------------------------------------------

ExprParser::ArgContext::ArgContext(ParserRuleContext *parent, size_t invokingState)
  : ParserRuleContext(parent, invokingState) {
}

ExprParser::ExpressionContext* ExprParser::ArgContext::expression() {
  return getRuleContext<ExprParser::ExpressionContext>(0);
}


size_t ExprParser::ArgContext::getRuleIndex() const {
  return ExprParser::RuleArg;
}


antlrcpp::Any ExprParser::ArgContext::accept(tree::ParseTreeVisitor *visitor) {
  if (auto parserVisitor = dynamic_cast<ExprVisitor*>(visitor))
    return parserVisitor->visitArg(this);
  else
    return visitor->visitChildren(this);
}

ExprParser::ArgContext* ExprParser::arg() {
  ArgContext *_localctx = _tracker.createInstance<ArgContext>(_ctx, getState());
  enterRule(_localctx, 108, ExprParser::RuleArg);

  auto onExit = finally([=] {
    exitRule();
  });
  try {
    enterOuterAlt(_localctx, 1);
    setState(462);
    expression();
   
  }
  catch (RecognitionException &e) {
    _errHandler->reportError(this, e);
    _localctx->exception = std::current_exception();
    _errHandler->recover(this, _localctx->exception);
  }

  return _localctx;
}

// Static vars and initialization.
std::vector<dfa::DFA> ExprParser::_decisionToDFA;
atn::PredictionContextCache ExprParser::_sharedContextCache;

// We own the ATN which in turn owns the ATN states.
atn::ATN ExprParser::_atn;
std::vector<uint16_t> ExprParser::_serializedATN;

std::vector<std::string> ExprParser::_ruleNames = {
  "program", "program_header", "declarations", "constants", "constant_list", 
  "constant_declaration", "const_identifier", "types", "type_list", "type_declaration", 
  "type_identifier_list", "type_identifier", "type_specification", "simpletype", 
  "arraytype", "array_start", "dimensions", "scalar", "range", "variables", 
  "variable_list", "variable_declarations", "var_identifier_list", "var_identifier", 
  "functions", "funct_type", "proc", "funct", "funct_identifier", "parameters", 
  "param_list", "param_declaration", "param_identifier_list", "param_identifier", 
  "statement_list", "statement", "compound_statement", "assign_statement", 
  "repeat_statement", "if_statement", "while_statement", "case_statement", 
  "condition", "for_statement", "expression", "simple_expression", "term", 
  "factor", "variable", "array_element", "element", "function_call", "function_name", 
  "arg_list", "arg"
};

std::vector<std::string> ExprParser::_literalNames = {
  "", "", "'.'", "':'", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", "", 
  "", "", "", "", "", "", "", "", "", "", "", "", "'+'", "'-'", "'*'", "'/'", 
  "':='", "'='", "'<>'", "'<='", "'>='", "'<'", "'>'", "'+='", "'-='", "'*='", 
  "'/='", "'^'", "';'", "','", "'('", "')'", "'['", "']'", "'{'", "'}'", 
  "'(*'", "'*)'"
};

std::vector<std::string> ExprParser::_symbolicNames = {
  "", "DOT_DOT", "DOT", "COLON", "CHAR", "STRINGS", "AND", "ARRAY", "ASM", 
  "BEGIN", "BOOLEAN", "BREAK", "CASE", "CONST", "CONSTRUCTOR", "CONTINUE", 
  "DESTRUCTOR", "DIV", "DO", "DOWNTO", "ELSE", "END", "FALSE", "FILE", "FOR", 
  "FUNCTION", "GOTO", "IF", "IMPLEMENTATION", "IN", "INLINE", "INTERFACE", 
  "LABEL", "MOD", "NIL", "NOT", "OBJECT", "OF", "ON", "OPERATOR", "OR", 
  "PACKED", "PROCEDURE", "PROGRAM", "RECORD", "REPEAT", "SET", "SHL", "SHR", 
  "STRING", "THEN", "TO", "TRUE", "TYPE", "UNIT", "UNTIL", "USES", "VAR", 
  "WHILE", "WITH", "XOR", "IDENTIFIER", "INTEGER", "REAL", "PLUSOP", "MINUSOP", 
  "MULTOP", "DIVOP", "ASSIGN", "EQUAL", "NE", "LTEQ", "GTEQ", "LT", "GT", 
  "PLUSEQUAL", "MINUSEQUAL", "MULTEQUAL", "DIVEQUAL", "CARAT", "SEMICOLON", 
  "COMMA", "LPAREN", "RPAREN", "LBRACKET", "RBRACKET", "LBRACE", "RBRACE", 
  "LCOMMENT", "RCOMMENT", "ERROR", "WS", "COMMENT"
};

dfa::Vocabulary ExprParser::_vocabulary(_literalNames, _symbolicNames);

std::vector<std::string> ExprParser::_tokenNames;

ExprParser::Initializer::Initializer() {
	for (size_t i = 0; i < _symbolicNames.size(); ++i) {
		std::string name = _vocabulary.getLiteralName(i);
		if (name.empty()) {
			name = _vocabulary.getSymbolicName(i);
		}

		if (name.empty()) {
			_tokenNames.push_back("<INVALID>");
		} else {
      _tokenNames.push_back(name);
    }
	}

  _serializedATN = {
    0x3, 0x608b, 0xa72a, 0x8133, 0xb9ed, 0x417c, 0x3be7, 0x7786, 0x5964, 
    0x3, 0x5e, 0x1d3, 0x4, 0x2, 0x9, 0x2, 0x4, 0x3, 0x9, 0x3, 0x4, 0x4, 
    0x9, 0x4, 0x4, 0x5, 0x9, 0x5, 0x4, 0x6, 0x9, 0x6, 0x4, 0x7, 0x9, 0x7, 
    0x4, 0x8, 0x9, 0x8, 0x4, 0x9, 0x9, 0x9, 0x4, 0xa, 0x9, 0xa, 0x4, 0xb, 
    0x9, 0xb, 0x4, 0xc, 0x9, 0xc, 0x4, 0xd, 0x9, 0xd, 0x4, 0xe, 0x9, 0xe, 
    0x4, 0xf, 0x9, 0xf, 0x4, 0x10, 0x9, 0x10, 0x4, 0x11, 0x9, 0x11, 0x4, 
    0x12, 0x9, 0x12, 0x4, 0x13, 0x9, 0x13, 0x4, 0x14, 0x9, 0x14, 0x4, 0x15, 
    0x9, 0x15, 0x4, 0x16, 0x9, 0x16, 0x4, 0x17, 0x9, 0x17, 0x4, 0x18, 0x9, 
    0x18, 0x4, 0x19, 0x9, 0x19, 0x4, 0x1a, 0x9, 0x1a, 0x4, 0x1b, 0x9, 0x1b, 
    0x4, 0x1c, 0x9, 0x1c, 0x4, 0x1d, 0x9, 0x1d, 0x4, 0x1e, 0x9, 0x1e, 0x4, 
    0x1f, 0x9, 0x1f, 0x4, 0x20, 0x9, 0x20, 0x4, 0x21, 0x9, 0x21, 0x4, 0x22, 
    0x9, 0x22, 0x4, 0x23, 0x9, 0x23, 0x4, 0x24, 0x9, 0x24, 0x4, 0x25, 0x9, 
    0x25, 0x4, 0x26, 0x9, 0x26, 0x4, 0x27, 0x9, 0x27, 0x4, 0x28, 0x9, 0x28, 
    0x4, 0x29, 0x9, 0x29, 0x4, 0x2a, 0x9, 0x2a, 0x4, 0x2b, 0x9, 0x2b, 0x4, 
    0x2c, 0x9, 0x2c, 0x4, 0x2d, 0x9, 0x2d, 0x4, 0x2e, 0x9, 0x2e, 0x4, 0x2f, 
    0x9, 0x2f, 0x4, 0x30, 0x9, 0x30, 0x4, 0x31, 0x9, 0x31, 0x4, 0x32, 0x9, 
    0x32, 0x4, 0x33, 0x9, 0x33, 0x4, 0x34, 0x9, 0x34, 0x4, 0x35, 0x9, 0x35, 
    0x4, 0x36, 0x9, 0x36, 0x4, 0x37, 0x9, 0x37, 0x4, 0x38, 0x9, 0x38, 0x3, 
    0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x2, 0x3, 0x3, 0x3, 0x3, 0x3, 
    0x3, 0x3, 0x3, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x7d, 0xa, 0x4, 
    0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 0x5, 0x4, 0x82, 0xa, 0x4, 0x3, 0x4, 0x3, 
    0x4, 0x3, 0x4, 0x5, 0x4, 0x87, 0xa, 0x4, 0x3, 0x4, 0x3, 0x4, 0x3, 0x4, 
    0x5, 0x4, 0x8c, 0xa, 0x4, 0x3, 0x5, 0x3, 0x5, 0x3, 0x5, 0x3, 0x6, 0x3, 
    0x6, 0x3, 0x6, 0x7, 0x6, 0x94, 0xa, 0x6, 0xc, 0x6, 0xe, 0x6, 0x97, 0xb, 
    0x6, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x7, 0x3, 0x8, 0x3, 0x8, 0x3, 
    0x9, 0x3, 0x9, 0x3, 0x9, 0x3, 0xa, 0x3, 0xa, 0x3, 0xa, 0x7, 0xa, 0xa5, 
    0xa, 0xa, 0xc, 0xa, 0xe, 0xa, 0xa8, 0xb, 0xa, 0x3, 0xb, 0x3, 0xb, 0x3, 
    0xb, 0x3, 0xb, 0x3, 0xc, 0x3, 0xc, 0x3, 0xc, 0x7, 0xc, 0xb1, 0xa, 0xc, 
    0xc, 0xc, 0xe, 0xc, 0xb4, 0xb, 0xc, 0x3, 0xd, 0x3, 0xd, 0x3, 0xe, 0x3, 
    0xe, 0x5, 0xe, 0xba, 0xa, 0xe, 0x3, 0xf, 0x3, 0xf, 0x5, 0xf, 0xbe, 0xa, 
    0xf, 0x3, 0x10, 0x3, 0x10, 0x3, 0x10, 0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 
    0x3, 0x11, 0x3, 0x11, 0x3, 0x11, 0x3, 0x12, 0x3, 0x12, 0x3, 0x13, 0x3, 
    0x13, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 0x3, 0x14, 
    0x5, 0x14, 0xd3, 0xa, 0x14, 0x3, 0x15, 0x3, 0x15, 0x3, 0x15, 0x3, 0x16, 
    0x3, 0x16, 0x3, 0x16, 0x7, 0x16, 0xdb, 0xa, 0x16, 0xc, 0x16, 0xe, 0x16, 
    0xde, 0xb, 0x16, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x17, 0x3, 0x18, 
    0x3, 0x18, 0x3, 0x18, 0x7, 0x18, 0xe7, 0xa, 0x18, 0xc, 0x18, 0xe, 0x18, 
    0xea, 0xb, 0x18, 0x3, 0x19, 0x3, 0x19, 0x3, 0x1a, 0x3, 0x1a, 0x3, 0x1a, 
    0x7, 0x1a, 0xf1, 0xa, 0x1a, 0xc, 0x1a, 0xe, 0x1a, 0xf4, 0xb, 0x1a, 0x3, 
    0x1b, 0x3, 0x1b, 0x5, 0x1b, 0xf8, 0xa, 0x1b, 0x3, 0x1b, 0x3, 0x1b, 0x3, 
    0x1b, 0x3, 0x1c, 0x3, 0x1c, 0x3, 0x1c, 0x5, 0x1c, 0x100, 0xa, 0x1c, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1d, 0x5, 0x1d, 0x105, 0xa, 0x1d, 0x3, 0x1d, 
    0x3, 0x1d, 0x3, 0x1d, 0x3, 0x1e, 0x3, 0x1e, 0x3, 0x1f, 0x3, 0x1f, 0x3, 
    0x1f, 0x3, 0x1f, 0x3, 0x20, 0x3, 0x20, 0x3, 0x20, 0x7, 0x20, 0x113, 
    0xa, 0x20, 0xc, 0x20, 0xe, 0x20, 0x116, 0xb, 0x20, 0x3, 0x21, 0x5, 0x21, 
    0x119, 0xa, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x21, 0x3, 0x22, 
    0x3, 0x22, 0x3, 0x22, 0x7, 0x22, 0x122, 0xa, 0x22, 0xc, 0x22, 0xe, 0x22, 
    0x125, 0xb, 0x22, 0x3, 0x23, 0x3, 0x23, 0x3, 0x24, 0x7, 0x24, 0x12a, 
    0xa, 0x24, 0xc, 0x24, 0xe, 0x24, 0x12d, 0xb, 0x24, 0x3, 0x24, 0x6, 0x24, 
    0x130, 0xa, 0x24, 0xd, 0x24, 0xe, 0x24, 0x131, 0x3, 0x25, 0x3, 0x25, 
    0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x3, 0x25, 0x5, 
    0x25, 0x13c, 0xa, 0x25, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 0x3, 0x26, 
    0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x27, 0x3, 0x28, 0x3, 0x28, 0x3, 
    0x28, 0x3, 0x28, 0x3, 0x28, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 
    0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 
    0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x3, 0x29, 0x5, 0x29, 
    0x15b, 0xa, 0x29, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2a, 
    0x3, 0x2a, 0x3, 0x2a, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 
    0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2b, 0x6, 0x2b, 0x16d, 
    0xa, 0x2b, 0xd, 0x2b, 0xe, 0x2b, 0x16e, 0x3, 0x2b, 0x3, 0x2b, 0x3, 0x2c, 
    0x3, 0x2c, 0x3, 0x2c, 0x3, 0x2c, 0x6, 0x2c, 0x177, 0xa, 0x2c, 0xd, 0x2c, 
    0xe, 0x2c, 0x178, 0x3, 0x2c, 0x3, 0x2c, 0x5, 0x2c, 0x17d, 0xa, 0x2c, 
    0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 
    0x2d, 0x3, 0x2d, 0x3, 0x2d, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 0x3, 0x2e, 
    0x3, 0x2e, 0x5, 0x2e, 0x18d, 0xa, 0x2e, 0x3, 0x2f, 0x7, 0x2f, 0x190, 
    0xa, 0x2f, 0xc, 0x2f, 0xe, 0x2f, 0x193, 0xb, 0x2f, 0x3, 0x2f, 0x6, 0x2f, 
    0x196, 0xa, 0x2f, 0xd, 0x2f, 0xe, 0x2f, 0x197, 0x3, 0x30, 0x3, 0x30, 
    0x3, 0x30, 0x3, 0x30, 0x6, 0x30, 0x19e, 0xa, 0x30, 0xd, 0x30, 0xe, 0x30, 
    0x19f, 0x5, 0x30, 0x1a2, 0xa, 0x30, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 
    0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 0x31, 0x3, 
    0x31, 0x3, 0x31, 0x5, 0x31, 0x1af, 0xa, 0x31, 0x3, 0x32, 0x3, 0x32, 
    0x3, 0x32, 0x5, 0x32, 0x1b4, 0xa, 0x32, 0x3, 0x33, 0x3, 0x33, 0x6, 0x33, 
    0x1b8, 0xa, 0x33, 0xd, 0x33, 0xe, 0x33, 0x1b9, 0x3, 0x34, 0x3, 0x34, 
    0x3, 0x34, 0x3, 0x34, 0x3, 0x35, 0x3, 0x35, 0x3, 0x35, 0x5, 0x35, 0x1c3, 
    0xa, 0x35, 0x3, 0x35, 0x3, 0x35, 0x3, 0x36, 0x3, 0x36, 0x3, 0x37, 0x3, 
    0x37, 0x3, 0x37, 0x7, 0x37, 0x1cc, 0xa, 0x37, 0xc, 0x37, 0xe, 0x37, 
    0x1cf, 0xb, 0x37, 0x3, 0x38, 0x3, 0x38, 0x3, 0x38, 0x2, 0x2, 0x39, 0x2, 
    0x4, 0x6, 0x8, 0xa, 0xc, 0xe, 0x10, 0x12, 0x14, 0x16, 0x18, 0x1a, 0x1c, 
    0x1e, 0x20, 0x22, 0x24, 0x26, 0x28, 0x2a, 0x2c, 0x2e, 0x30, 0x32, 0x34, 
    0x36, 0x38, 0x3a, 0x3c, 0x3e, 0x40, 0x42, 0x44, 0x46, 0x48, 0x4a, 0x4c, 
    0x4e, 0x50, 0x52, 0x54, 0x56, 0x58, 0x5a, 0x5c, 0x5e, 0x60, 0x62, 0x64, 
    0x66, 0x68, 0x6a, 0x6c, 0x6e, 0x2, 0x8, 0x5, 0x2, 0x6, 0x7, 0xc, 0xc, 
    0x3f, 0x41, 0x5, 0x2, 0x6, 0x6, 0xc, 0xc, 0x3f, 0x40, 0x3, 0x2, 0x47, 
    0x4c, 0x3, 0x2, 0x42, 0x43, 0x3, 0x2, 0x44, 0x45, 0x6, 0x2, 0x6, 0x6, 
    0x18, 0x18, 0x36, 0x36, 0x3f, 0x40, 0x2, 0x1cb, 0x2, 0x70, 0x3, 0x2, 
    0x2, 0x2, 0x4, 0x75, 0x3, 0x2, 0x2, 0x2, 0x6, 0x7c, 0x3, 0x2, 0x2, 0x2, 
    0x8, 0x8d, 0x3, 0x2, 0x2, 0x2, 0xa, 0x90, 0x3, 0x2, 0x2, 0x2, 0xc, 0x98, 
    0x3, 0x2, 0x2, 0x2, 0xe, 0x9c, 0x3, 0x2, 0x2, 0x2, 0x10, 0x9e, 0x3, 
    0x2, 0x2, 0x2, 0x12, 0xa1, 0x3, 0x2, 0x2, 0x2, 0x14, 0xa9, 0x3, 0x2, 
    0x2, 0x2, 0x16, 0xad, 0x3, 0x2, 0x2, 0x2, 0x18, 0xb5, 0x3, 0x2, 0x2, 
    0x2, 0x1a, 0xb9, 0x3, 0x2, 0x2, 0x2, 0x1c, 0xbd, 0x3, 0x2, 0x2, 0x2, 
    0x1e, 0xbf, 0x3, 0x2, 0x2, 0x2, 0x20, 0xc2, 0x3, 0x2, 0x2, 0x2, 0x22, 
    0xc8, 0x3, 0x2, 0x2, 0x2, 0x24, 0xca, 0x3, 0x2, 0x2, 0x2, 0x26, 0xd2, 
    0x3, 0x2, 0x2, 0x2, 0x28, 0xd4, 0x3, 0x2, 0x2, 0x2, 0x2a, 0xd7, 0x3, 
    0x2, 0x2, 0x2, 0x2c, 0xdf, 0x3, 0x2, 0x2, 0x2, 0x2e, 0xe3, 0x3, 0x2, 
    0x2, 0x2, 0x30, 0xeb, 0x3, 0x2, 0x2, 0x2, 0x32, 0xed, 0x3, 0x2, 0x2, 
    0x2, 0x34, 0xf7, 0x3, 0x2, 0x2, 0x2, 0x36, 0xfc, 0x3, 0x2, 0x2, 0x2, 
    0x38, 0x101, 0x3, 0x2, 0x2, 0x2, 0x3a, 0x109, 0x3, 0x2, 0x2, 0x2, 0x3c, 
    0x10b, 0x3, 0x2, 0x2, 0x2, 0x3e, 0x10f, 0x3, 0x2, 0x2, 0x2, 0x40, 0x118, 
    0x3, 0x2, 0x2, 0x2, 0x42, 0x11e, 0x3, 0x2, 0x2, 0x2, 0x44, 0x126, 0x3, 
    0x2, 0x2, 0x2, 0x46, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x48, 0x13b, 0x3, 0x2, 
    0x2, 0x2, 0x4a, 0x13d, 0x3, 0x2, 0x2, 0x2, 0x4c, 0x141, 0x3, 0x2, 0x2, 
    0x2, 0x4e, 0x145, 0x3, 0x2, 0x2, 0x2, 0x50, 0x15a, 0x3, 0x2, 0x2, 0x2, 
    0x52, 0x15c, 0x3, 0x2, 0x2, 0x2, 0x54, 0x163, 0x3, 0x2, 0x2, 0x2, 0x56, 
    0x17c, 0x3, 0x2, 0x2, 0x2, 0x58, 0x17e, 0x3, 0x2, 0x2, 0x2, 0x5a, 0x18c, 
    0x3, 0x2, 0x2, 0x2, 0x5c, 0x195, 0x3, 0x2, 0x2, 0x2, 0x5e, 0x1a1, 0x3, 
    0x2, 0x2, 0x2, 0x60, 0x1ae, 0x3, 0x2, 0x2, 0x2, 0x62, 0x1b3, 0x3, 0x2, 
    0x2, 0x2, 0x64, 0x1b5, 0x3, 0x2, 0x2, 0x2, 0x66, 0x1bb, 0x3, 0x2, 0x2, 
    0x2, 0x68, 0x1bf, 0x3, 0x2, 0x2, 0x2, 0x6a, 0x1c6, 0x3, 0x2, 0x2, 0x2, 
    0x6c, 0x1c8, 0x3, 0x2, 0x2, 0x2, 0x6e, 0x1d0, 0x3, 0x2, 0x2, 0x2, 0x70, 
    0x71, 0x5, 0x4, 0x3, 0x2, 0x71, 0x72, 0x5, 0x6, 0x4, 0x2, 0x72, 0x73, 
    0x5, 0x4a, 0x26, 0x2, 0x73, 0x74, 0x7, 0x4, 0x2, 0x2, 0x74, 0x3, 0x3, 
    0x2, 0x2, 0x2, 0x75, 0x76, 0x7, 0x2d, 0x2, 0x2, 0x76, 0x77, 0x7, 0x3f, 
    0x2, 0x2, 0x77, 0x78, 0x7, 0x52, 0x2, 0x2, 0x78, 0x5, 0x3, 0x2, 0x2, 
    0x2, 0x79, 0x7a, 0x5, 0x8, 0x5, 0x2, 0x7a, 0x7b, 0x7, 0x52, 0x2, 0x2, 
    0x7b, 0x7d, 0x3, 0x2, 0x2, 0x2, 0x7c, 0x79, 0x3, 0x2, 0x2, 0x2, 0x7c, 
    0x7d, 0x3, 0x2, 0x2, 0x2, 0x7d, 0x81, 0x3, 0x2, 0x2, 0x2, 0x7e, 0x7f, 
    0x5, 0x10, 0x9, 0x2, 0x7f, 0x80, 0x7, 0x52, 0x2, 0x2, 0x80, 0x82, 0x3, 
    0x2, 0x2, 0x2, 0x81, 0x7e, 0x3, 0x2, 0x2, 0x2, 0x81, 0x82, 0x3, 0x2, 
    0x2, 0x2, 0x82, 0x86, 0x3, 0x2, 0x2, 0x2, 0x83, 0x84, 0x5, 0x28, 0x15, 
    0x2, 0x84, 0x85, 0x7, 0x52, 0x2, 0x2, 0x85, 0x87, 0x3, 0x2, 0x2, 0x2, 
    0x86, 0x83, 0x3, 0x2, 0x2, 0x2, 0x86, 0x87, 0x3, 0x2, 0x2, 0x2, 0x87, 
    0x8b, 0x3, 0x2, 0x2, 0x2, 0x88, 0x89, 0x5, 0x32, 0x1a, 0x2, 0x89, 0x8a, 
    0x7, 0x52, 0x2, 0x2, 0x8a, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8b, 0x88, 0x3, 
    0x2, 0x2, 0x2, 0x8b, 0x8c, 0x3, 0x2, 0x2, 0x2, 0x8c, 0x7, 0x3, 0x2, 
    0x2, 0x2, 0x8d, 0x8e, 0x7, 0xf, 0x2, 0x2, 0x8e, 0x8f, 0x5, 0xa, 0x6, 
    0x2, 0x8f, 0x9, 0x3, 0x2, 0x2, 0x2, 0x90, 0x95, 0x5, 0xc, 0x7, 0x2, 
    0x91, 0x92, 0x7, 0x52, 0x2, 0x2, 0x92, 0x94, 0x5, 0xc, 0x7, 0x2, 0x93, 
    0x91, 0x3, 0x2, 0x2, 0x2, 0x94, 0x97, 0x3, 0x2, 0x2, 0x2, 0x95, 0x93, 
    0x3, 0x2, 0x2, 0x2, 0x95, 0x96, 0x3, 0x2, 0x2, 0x2, 0x96, 0xb, 0x3, 
    0x2, 0x2, 0x2, 0x97, 0x95, 0x3, 0x2, 0x2, 0x2, 0x98, 0x99, 0x5, 0xe, 
    0x8, 0x2, 0x99, 0x9a, 0x7, 0x47, 0x2, 0x2, 0x9a, 0x9b, 0x9, 0x2, 0x2, 
    0x2, 0x9b, 0xd, 0x3, 0x2, 0x2, 0x2, 0x9c, 0x9d, 0x7, 0x3f, 0x2, 0x2, 
    0x9d, 0xf, 0x3, 0x2, 0x2, 0x2, 0x9e, 0x9f, 0x7, 0x37, 0x2, 0x2, 0x9f, 
    0xa0, 0x5, 0x12, 0xa, 0x2, 0xa0, 0x11, 0x3, 0x2, 0x2, 0x2, 0xa1, 0xa6, 
    0x5, 0x14, 0xb, 0x2, 0xa2, 0xa3, 0x7, 0x52, 0x2, 0x2, 0xa3, 0xa5, 0x5, 
    0x14, 0xb, 0x2, 0xa4, 0xa2, 0x3, 0x2, 0x2, 0x2, 0xa5, 0xa8, 0x3, 0x2, 
    0x2, 0x2, 0xa6, 0xa4, 0x3, 0x2, 0x2, 0x2, 0xa6, 0xa7, 0x3, 0x2, 0x2, 
    0x2, 0xa7, 0x13, 0x3, 0x2, 0x2, 0x2, 0xa8, 0xa6, 0x3, 0x2, 0x2, 0x2, 
    0xa9, 0xaa, 0x5, 0x16, 0xc, 0x2, 0xaa, 0xab, 0x7, 0x47, 0x2, 0x2, 0xab, 
    0xac, 0x5, 0x1a, 0xe, 0x2, 0xac, 0x15, 0x3, 0x2, 0x2, 0x2, 0xad, 0xb2, 
    0x5, 0x18, 0xd, 0x2, 0xae, 0xaf, 0x7, 0x53, 0x2, 0x2, 0xaf, 0xb1, 0x5, 
    0x18, 0xd, 0x2, 0xb0, 0xae, 0x3, 0x2, 0x2, 0x2, 0xb1, 0xb4, 0x3, 0x2, 
    0x2, 0x2, 0xb2, 0xb0, 0x3, 0x2, 0x2, 0x2, 0xb2, 0xb3, 0x3, 0x2, 0x2, 
    0x2, 0xb3, 0x17, 0x3, 0x2, 0x2, 0x2, 0xb4, 0xb2, 0x3, 0x2, 0x2, 0x2, 
    0xb5, 0xb6, 0x7, 0x3f, 0x2, 0x2, 0xb6, 0x19, 0x3, 0x2, 0x2, 0x2, 0xb7, 
    0xba, 0x5, 0x1c, 0xf, 0x2, 0xb8, 0xba, 0x5, 0x1e, 0x10, 0x2, 0xb9, 0xb7, 
    0x3, 0x2, 0x2, 0x2, 0xb9, 0xb8, 0x3, 0x2, 0x2, 0x2, 0xba, 0x1b, 0x3, 
    0x2, 0x2, 0x2, 0xbb, 0xbe, 0x5, 0x24, 0x13, 0x2, 0xbc, 0xbe, 0x5, 0x26, 
    0x14, 0x2, 0xbd, 0xbb, 0x3, 0x2, 0x2, 0x2, 0xbd, 0xbc, 0x3, 0x2, 0x2, 
    0x2, 0xbe, 0x1d, 0x3, 0x2, 0x2, 0x2, 0xbf, 0xc0, 0x5, 0x20, 0x11, 0x2, 
    0xc0, 0xc1, 0x5, 0x1a, 0xe, 0x2, 0xc1, 0x1f, 0x3, 0x2, 0x2, 0x2, 0xc2, 
    0xc3, 0x7, 0x9, 0x2, 0x2, 0xc3, 0xc4, 0x7, 0x56, 0x2, 0x2, 0xc4, 0xc5, 
    0x5, 0x22, 0x12, 0x2, 0xc5, 0xc6, 0x7, 0x57, 0x2, 0x2, 0xc6, 0xc7, 0x7, 
    0x27, 0x2, 0x2, 0xc7, 0x21, 0x3, 0x2, 0x2, 0x2, 0xc8, 0xc9, 0x5, 0x1c, 
    0xf, 0x2, 0xc9, 0x23, 0x3, 0x2, 0x2, 0x2, 0xca, 0xcb, 0x9, 0x3, 0x2, 
    0x2, 0xcb, 0x25, 0x3, 0x2, 0x2, 0x2, 0xcc, 0xcd, 0x7, 0x40, 0x2, 0x2, 
    0xcd, 0xce, 0x7, 0x3, 0x2, 0x2, 0xce, 0xd3, 0x7, 0x40, 0x2, 0x2, 0xcf, 
    0xd0, 0x7, 0x6, 0x2, 0x2, 0xd0, 0xd1, 0x7, 0x3, 0x2, 0x2, 0xd1, 0xd3, 
    0x7, 0x6, 0x2, 0x2, 0xd2, 0xcc, 0x3, 0x2, 0x2, 0x2, 0xd2, 0xcf, 0x3, 
    0x2, 0x2, 0x2, 0xd3, 0x27, 0x3, 0x2, 0x2, 0x2, 0xd4, 0xd5, 0x7, 0x3b, 
    0x2, 0x2, 0xd5, 0xd6, 0x5, 0x2a, 0x16, 0x2, 0xd6, 0x29, 0x3, 0x2, 0x2, 
    0x2, 0xd7, 0xdc, 0x5, 0x2c, 0x17, 0x2, 0xd8, 0xd9, 0x7, 0x52, 0x2, 0x2, 
    0xd9, 0xdb, 0x5, 0x2c, 0x17, 0x2, 0xda, 0xd8, 0x3, 0x2, 0x2, 0x2, 0xdb, 
    0xde, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xda, 0x3, 0x2, 0x2, 0x2, 0xdc, 0xdd, 
    0x3, 0x2, 0x2, 0x2, 0xdd, 0x2b, 0x3, 0x2, 0x2, 0x2, 0xde, 0xdc, 0x3, 
    0x2, 0x2, 0x2, 0xdf, 0xe0, 0x5, 0x2e, 0x18, 0x2, 0xe0, 0xe1, 0x7, 0x5, 
    0x2, 0x2, 0xe1, 0xe2, 0x5, 0x1a, 0xe, 0x2, 0xe2, 0x2d, 0x3, 0x2, 0x2, 
    0x2, 0xe3, 0xe8, 0x5, 0x30, 0x19, 0x2, 0xe4, 0xe5, 0x7, 0x53, 0x2, 0x2, 
    0xe5, 0xe7, 0x5, 0x30, 0x19, 0x2, 0xe6, 0xe4, 0x3, 0x2, 0x2, 0x2, 0xe7, 
    0xea, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe6, 0x3, 0x2, 0x2, 0x2, 0xe8, 0xe9, 
    0x3, 0x2, 0x2, 0x2, 0xe9, 0x2f, 0x3, 0x2, 0x2, 0x2, 0xea, 0xe8, 0x3, 
    0x2, 0x2, 0x2, 0xeb, 0xec, 0x7, 0x3f, 0x2, 0x2, 0xec, 0x31, 0x3, 0x2, 
    0x2, 0x2, 0xed, 0xf2, 0x5, 0x34, 0x1b, 0x2, 0xee, 0xef, 0x7, 0x52, 0x2, 
    0x2, 0xef, 0xf1, 0x5, 0x34, 0x1b, 0x2, 0xf0, 0xee, 0x3, 0x2, 0x2, 0x2, 
    0xf1, 0xf4, 0x3, 0x2, 0x2, 0x2, 0xf2, 0xf0, 0x3, 0x2, 0x2, 0x2, 0xf2, 
    0xf3, 0x3, 0x2, 0x2, 0x2, 0xf3, 0x33, 0x3, 0x2, 0x2, 0x2, 0xf4, 0xf2, 
    0x3, 0x2, 0x2, 0x2, 0xf5, 0xf8, 0x5, 0x36, 0x1c, 0x2, 0xf6, 0xf8, 0x5, 
    0x38, 0x1d, 0x2, 0xf7, 0xf5, 0x3, 0x2, 0x2, 0x2, 0xf7, 0xf6, 0x3, 0x2, 
    0x2, 0x2, 0xf8, 0xf9, 0x3, 0x2, 0x2, 0x2, 0xf9, 0xfa, 0x5, 0x6, 0x4, 
    0x2, 0xfa, 0xfb, 0x5, 0x4a, 0x26, 0x2, 0xfb, 0x35, 0x3, 0x2, 0x2, 0x2, 
    0xfc, 0xfd, 0x7, 0x2c, 0x2, 0x2, 0xfd, 0xff, 0x5, 0x3a, 0x1e, 0x2, 0xfe, 
    0x100, 0x5, 0x3c, 0x1f, 0x2, 0xff, 0xfe, 0x3, 0x2, 0x2, 0x2, 0xff, 0x100, 
    0x3, 0x2, 0x2, 0x2, 0x100, 0x37, 0x3, 0x2, 0x2, 0x2, 0x101, 0x102, 0x7, 
    0x1b, 0x2, 0x2, 0x102, 0x104, 0x5, 0x3a, 0x1e, 0x2, 0x103, 0x105, 0x5, 
    0x3c, 0x1f, 0x2, 0x104, 0x103, 0x3, 0x2, 0x2, 0x2, 0x104, 0x105, 0x3, 
    0x2, 0x2, 0x2, 0x105, 0x106, 0x3, 0x2, 0x2, 0x2, 0x106, 0x107, 0x7, 
    0x5, 0x2, 0x2, 0x107, 0x108, 0x5, 0x18, 0xd, 0x2, 0x108, 0x39, 0x3, 
    0x2, 0x2, 0x2, 0x109, 0x10a, 0x7, 0x3f, 0x2, 0x2, 0x10a, 0x3b, 0x3, 
    0x2, 0x2, 0x2, 0x10b, 0x10c, 0x7, 0x54, 0x2, 0x2, 0x10c, 0x10d, 0x5, 
    0x3e, 0x20, 0x2, 0x10d, 0x10e, 0x7, 0x55, 0x2, 0x2, 0x10e, 0x3d, 0x3, 
    0x2, 0x2, 0x2, 0x10f, 0x114, 0x5, 0x40, 0x21, 0x2, 0x110, 0x111, 0x7, 
    0x52, 0x2, 0x2, 0x111, 0x113, 0x5, 0x40, 0x21, 0x2, 0x112, 0x110, 0x3, 
    0x2, 0x2, 0x2, 0x113, 0x116, 0x3, 0x2, 0x2, 0x2, 0x114, 0x112, 0x3, 
    0x2, 0x2, 0x2, 0x114, 0x115, 0x3, 0x2, 0x2, 0x2, 0x115, 0x3f, 0x3, 0x2, 
    0x2, 0x2, 0x116, 0x114, 0x3, 0x2, 0x2, 0x2, 0x117, 0x119, 0x7, 0x3b, 
    0x2, 0x2, 0x118, 0x117, 0x3, 0x2, 0x2, 0x2, 0x118, 0x119, 0x3, 0x2, 
    0x2, 0x2, 0x119, 0x11a, 0x3, 0x2, 0x2, 0x2, 0x11a, 0x11b, 0x5, 0x42, 
    0x22, 0x2, 0x11b, 0x11c, 0x7, 0x5, 0x2, 0x2, 0x11c, 0x11d, 0x5, 0x18, 
    0xd, 0x2, 0x11d, 0x41, 0x3, 0x2, 0x2, 0x2, 0x11e, 0x123, 0x5, 0x44, 
    0x23, 0x2, 0x11f, 0x120, 0x7, 0x53, 0x2, 0x2, 0x120, 0x122, 0x5, 0x44, 
    0x23, 0x2, 0x121, 0x11f, 0x3, 0x2, 0x2, 0x2, 0x122, 0x125, 0x3, 0x2, 
    0x2, 0x2, 0x123, 0x121, 0x3, 0x2, 0x2, 0x2, 0x123, 0x124, 0x3, 0x2, 
    0x2, 0x2, 0x124, 0x43, 0x3, 0x2, 0x2, 0x2, 0x125, 0x123, 0x3, 0x2, 0x2, 
    0x2, 0x126, 0x127, 0x7, 0x3f, 0x2, 0x2, 0x127, 0x45, 0x3, 0x2, 0x2, 
    0x2, 0x128, 0x12a, 0x5, 0x48, 0x25, 0x2, 0x129, 0x128, 0x3, 0x2, 0x2, 
    0x2, 0x12a, 0x12d, 0x3, 0x2, 0x2, 0x2, 0x12b, 0x129, 0x3, 0x2, 0x2, 
    0x2, 0x12b, 0x12c, 0x3, 0x2, 0x2, 0x2, 0x12c, 0x12e, 0x3, 0x2, 0x2, 
    0x2, 0x12d, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x12e, 0x130, 0x7, 0x52, 0x2, 
    0x2, 0x12f, 0x12b, 0x3, 0x2, 0x2, 0x2, 0x130, 0x131, 0x3, 0x2, 0x2, 
    0x2, 0x131, 0x12f, 0x3, 0x2, 0x2, 0x2, 0x131, 0x132, 0x3, 0x2, 0x2, 
    0x2, 0x132, 0x47, 0x3, 0x2, 0x2, 0x2, 0x133, 0x13c, 0x5, 0x4a, 0x26, 
    0x2, 0x134, 0x13c, 0x5, 0x4c, 0x27, 0x2, 0x135, 0x13c, 0x5, 0x4e, 0x28, 
    0x2, 0x136, 0x13c, 0x5, 0x50, 0x29, 0x2, 0x137, 0x13c, 0x5, 0x52, 0x2a, 
    0x2, 0x138, 0x13c, 0x5, 0x54, 0x2b, 0x2, 0x139, 0x13c, 0x5, 0x58, 0x2d, 
    0x2, 0x13a, 0x13c, 0x5, 0x68, 0x35, 0x2, 0x13b, 0x133, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x134, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x135, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x136, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x137, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x138, 0x3, 0x2, 0x2, 0x2, 0x13b, 0x139, 0x3, 0x2, 0x2, 
    0x2, 0x13b, 0x13a, 0x3, 0x2, 0x2, 0x2, 0x13c, 0x49, 0x3, 0x2, 0x2, 0x2, 
    0x13d, 0x13e, 0x7, 0xb, 0x2, 0x2, 0x13e, 0x13f, 0x5, 0x46, 0x24, 0x2, 
    0x13f, 0x140, 0x7, 0x17, 0x2, 0x2, 0x140, 0x4b, 0x3, 0x2, 0x2, 0x2, 
    0x141, 0x142, 0x5, 0x62, 0x32, 0x2, 0x142, 0x143, 0x7, 0x46, 0x2, 0x2, 
    0x143, 0x144, 0x5, 0x5a, 0x2e, 0x2, 0x144, 0x4d, 0x3, 0x2, 0x2, 0x2, 
    0x145, 0x146, 0x7, 0x2f, 0x2, 0x2, 0x146, 0x147, 0x5, 0x46, 0x24, 0x2, 
    0x147, 0x148, 0x7, 0x39, 0x2, 0x2, 0x148, 0x149, 0x5, 0x5a, 0x2e, 0x2, 
    0x149, 0x4f, 0x3, 0x2, 0x2, 0x2, 0x14a, 0x14b, 0x7, 0x1d, 0x2, 0x2, 
    0x14b, 0x14c, 0x7, 0x54, 0x2, 0x2, 0x14c, 0x14d, 0x5, 0x5a, 0x2e, 0x2, 
    0x14d, 0x14e, 0x7, 0x55, 0x2, 0x2, 0x14e, 0x14f, 0x7, 0x34, 0x2, 0x2, 
    0x14f, 0x150, 0x5, 0x48, 0x25, 0x2, 0x150, 0x15b, 0x3, 0x2, 0x2, 0x2, 
    0x151, 0x152, 0x7, 0x1d, 0x2, 0x2, 0x152, 0x153, 0x7, 0x54, 0x2, 0x2, 
    0x153, 0x154, 0x5, 0x5a, 0x2e, 0x2, 0x154, 0x155, 0x7, 0x55, 0x2, 0x2, 
    0x155, 0x156, 0x7, 0x34, 0x2, 0x2, 0x156, 0x157, 0x5, 0x48, 0x25, 0x2, 
    0x157, 0x158, 0x7, 0x16, 0x2, 0x2, 0x158, 0x159, 0x5, 0x48, 0x25, 0x2, 
    0x159, 0x15b, 0x3, 0x2, 0x2, 0x2, 0x15a, 0x14a, 0x3, 0x2, 0x2, 0x2, 
    0x15a, 0x151, 0x3, 0x2, 0x2, 0x2, 0x15b, 0x51, 0x3, 0x2, 0x2, 0x2, 0x15c, 
    0x15d, 0x7, 0x3c, 0x2, 0x2, 0x15d, 0x15e, 0x7, 0x54, 0x2, 0x2, 0x15e, 
    0x15f, 0x5, 0x5a, 0x2e, 0x2, 0x15f, 0x160, 0x7, 0x55, 0x2, 0x2, 0x160, 
    0x161, 0x7, 0x14, 0x2, 0x2, 0x161, 0x162, 0x5, 0x48, 0x25, 0x2, 0x162, 
    0x53, 0x3, 0x2, 0x2, 0x2, 0x163, 0x164, 0x7, 0xe, 0x2, 0x2, 0x164, 0x165, 
    0x7, 0x54, 0x2, 0x2, 0x165, 0x166, 0x7, 0x3f, 0x2, 0x2, 0x166, 0x167, 
    0x7, 0x55, 0x2, 0x2, 0x167, 0x16c, 0x7, 0x27, 0x2, 0x2, 0x168, 0x169, 
    0x5, 0x56, 0x2c, 0x2, 0x169, 0x16a, 0x5, 0x48, 0x25, 0x2, 0x16a, 0x16b, 
    0x7, 0x52, 0x2, 0x2, 0x16b, 0x16d, 0x3, 0x2, 0x2, 0x2, 0x16c, 0x168, 
    0x3, 0x2, 0x2, 0x2, 0x16d, 0x16e, 0x3, 0x2, 0x2, 0x2, 0x16e, 0x16c, 
    0x3, 0x2, 0x2, 0x2, 0x16e, 0x16f, 0x3, 0x2, 0x2, 0x2, 0x16f, 0x170, 
    0x3, 0x2, 0x2, 0x2, 0x170, 0x171, 0x7, 0x17, 0x2, 0x2, 0x171, 0x55, 
    0x3, 0x2, 0x2, 0x2, 0x172, 0x173, 0x7, 0x40, 0x2, 0x2, 0x173, 0x17d, 
    0x7, 0x5, 0x2, 0x2, 0x174, 0x175, 0x7, 0x40, 0x2, 0x2, 0x175, 0x177, 
    0x7, 0x53, 0x2, 0x2, 0x176, 0x174, 0x3, 0x2, 0x2, 0x2, 0x177, 0x178, 
    0x3, 0x2, 0x2, 0x2, 0x178, 0x176, 0x3, 0x2, 0x2, 0x2, 0x178, 0x179, 
    0x3, 0x2, 0x2, 0x2, 0x179, 0x17a, 0x3, 0x2, 0x2, 0x2, 0x17a, 0x17b, 
    0x7, 0x40, 0x2, 0x2, 0x17b, 0x17d, 0x7, 0x5, 0x2, 0x2, 0x17c, 0x172, 
    0x3, 0x2, 0x2, 0x2, 0x17c, 0x176, 0x3, 0x2, 0x2, 0x2, 0x17d, 0x57, 0x3, 
    0x2, 0x2, 0x2, 0x17e, 0x17f, 0x7, 0x1a, 0x2, 0x2, 0x17f, 0x180, 0x7, 
    0x3f, 0x2, 0x2, 0x180, 0x181, 0x7, 0x46, 0x2, 0x2, 0x181, 0x182, 0x7, 
    0x40, 0x2, 0x2, 0x182, 0x183, 0x7, 0x35, 0x2, 0x2, 0x183, 0x184, 0x7, 
    0x40, 0x2, 0x2, 0x184, 0x185, 0x7, 0x14, 0x2, 0x2, 0x185, 0x186, 0x5, 
    0x48, 0x25, 0x2, 0x186, 0x59, 0x3, 0x2, 0x2, 0x2, 0x187, 0x188, 0x5, 
    0x5c, 0x2f, 0x2, 0x188, 0x189, 0x9, 0x4, 0x2, 0x2, 0x189, 0x18a, 0x5, 
    0x5c, 0x2f, 0x2, 0x18a, 0x18d, 0x3, 0x2, 0x2, 0x2, 0x18b, 0x18d, 0x5, 
    0x5c, 0x2f, 0x2, 0x18c, 0x187, 0x3, 0x2, 0x2, 0x2, 0x18c, 0x18b, 0x3, 
    0x2, 0x2, 0x2, 0x18d, 0x5b, 0x3, 0x2, 0x2, 0x2, 0x18e, 0x190, 0x9, 0x5, 
    0x2, 0x2, 0x18f, 0x18e, 0x3, 0x2, 0x2, 0x2, 0x190, 0x193, 0x3, 0x2, 
    0x2, 0x2, 0x191, 0x18f, 0x3, 0x2, 0x2, 0x2, 0x191, 0x192, 0x3, 0x2, 
    0x2, 0x2, 0x192, 0x194, 0x3, 0x2, 0x2, 0x2, 0x193, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x194, 0x196, 0x5, 0x5e, 0x30, 0x2, 0x195, 0x191, 0x3, 0x2, 
    0x2, 0x2, 0x196, 0x197, 0x3, 0x2, 0x2, 0x2, 0x197, 0x195, 0x3, 0x2, 
    0x2, 0x2, 0x197, 0x198, 0x3, 0x2, 0x2, 0x2, 0x198, 0x5d, 0x3, 0x2, 0x2, 
    0x2, 0x199, 0x1a2, 0x5, 0x60, 0x31, 0x2, 0x19a, 0x19d, 0x5, 0x60, 0x31, 
    0x2, 0x19b, 0x19c, 0x9, 0x6, 0x2, 0x2, 0x19c, 0x19e, 0x5, 0x60, 0x31, 
    0x2, 0x19d, 0x19b, 0x3, 0x2, 0x2, 0x2, 0x19e, 0x19f, 0x3, 0x2, 0x2, 
    0x2, 0x19f, 0x19d, 0x3, 0x2, 0x2, 0x2, 0x19f, 0x1a0, 0x3, 0x2, 0x2, 
    0x2, 0x1a0, 0x1a2, 0x3, 0x2, 0x2, 0x2, 0x1a1, 0x199, 0x3, 0x2, 0x2, 
    0x2, 0x1a1, 0x19a, 0x3, 0x2, 0x2, 0x2, 0x1a2, 0x5f, 0x3, 0x2, 0x2, 0x2, 
    0x1a3, 0x1af, 0x5, 0x62, 0x32, 0x2, 0x1a4, 0x1af, 0x7, 0x40, 0x2, 0x2, 
    0x1a5, 0x1af, 0x7, 0x6, 0x2, 0x2, 0x1a6, 0x1af, 0x7, 0x36, 0x2, 0x2, 
    0x1a7, 0x1af, 0x7, 0x18, 0x2, 0x2, 0x1a8, 0x1a9, 0x7, 0x43, 0x2, 0x2, 
    0x1a9, 0x1af, 0x7, 0x40, 0x2, 0x2, 0x1aa, 0x1ab, 0x7, 0x54, 0x2, 0x2, 
    0x1ab, 0x1ac, 0x5, 0x5a, 0x2e, 0x2, 0x1ac, 0x1ad, 0x7, 0x55, 0x2, 0x2, 
    0x1ad, 0x1af, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1a3, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1a4, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1a5, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1a6, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1a7, 0x3, 0x2, 0x2, 0x2, 
    0x1ae, 0x1a8, 0x3, 0x2, 0x2, 0x2, 0x1ae, 0x1aa, 0x3, 0x2, 0x2, 0x2, 
    0x1af, 0x61, 0x3, 0x2, 0x2, 0x2, 0x1b0, 0x1b4, 0x7, 0x3f, 0x2, 0x2, 
    0x1b1, 0x1b4, 0x5, 0x68, 0x35, 0x2, 0x1b2, 0x1b4, 0x5, 0x64, 0x33, 0x2, 
    0x1b3, 0x1b0, 0x3, 0x2, 0x2, 0x2, 0x1b3, 0x1b1, 0x3, 0x2, 0x2, 0x2, 
    0x1b3, 0x1b2, 0x3, 0x2, 0x2, 0x2, 0x1b4, 0x63, 0x3, 0x2, 0x2, 0x2, 0x1b5, 
    0x1b7, 0x7, 0x3f, 0x2, 0x2, 0x1b6, 0x1b8, 0x5, 0x66, 0x34, 0x2, 0x1b7, 
    0x1b6, 0x3, 0x2, 0x2, 0x2, 0x1b8, 0x1b9, 0x3, 0x2, 0x2, 0x2, 0x1b9, 
    0x1b7, 0x3, 0x2, 0x2, 0x2, 0x1b9, 0x1ba, 0x3, 0x2, 0x2, 0x2, 0x1ba, 
    0x65, 0x3, 0x2, 0x2, 0x2, 0x1bb, 0x1bc, 0x7, 0x56, 0x2, 0x2, 0x1bc, 
    0x1bd, 0x9, 0x7, 0x2, 0x2, 0x1bd, 0x1be, 0x7, 0x57, 0x2, 0x2, 0x1be, 
    0x67, 0x3, 0x2, 0x2, 0x2, 0x1bf, 0x1c0, 0x5, 0x6a, 0x36, 0x2, 0x1c0, 
    0x1c2, 0x7, 0x54, 0x2, 0x2, 0x1c1, 0x1c3, 0x5, 0x6c, 0x37, 0x2, 0x1c2, 
    0x1c1, 0x3, 0x2, 0x2, 0x2, 0x1c2, 0x1c3, 0x3, 0x2, 0x2, 0x2, 0x1c3, 
    0x1c4, 0x3, 0x2, 0x2, 0x2, 0x1c4, 0x1c5, 0x7, 0x55, 0x2, 0x2, 0x1c5, 
    0x69, 0x3, 0x2, 0x2, 0x2, 0x1c6, 0x1c7, 0x7, 0x3f, 0x2, 0x2, 0x1c7, 
    0x6b, 0x3, 0x2, 0x2, 0x2, 0x1c8, 0x1cd, 0x5, 0x6e, 0x38, 0x2, 0x1c9, 
    0x1ca, 0x7, 0x53, 0x2, 0x2, 0x1ca, 0x1cc, 0x5, 0x6e, 0x38, 0x2, 0x1cb, 
    0x1c9, 0x3, 0x2, 0x2, 0x2, 0x1cc, 0x1cf, 0x3, 0x2, 0x2, 0x2, 0x1cd, 
    0x1cb, 0x3, 0x2, 0x2, 0x2, 0x1cd, 0x1ce, 0x3, 0x2, 0x2, 0x2, 0x1ce, 
    0x6d, 0x3, 0x2, 0x2, 0x2, 0x1cf, 0x1cd, 0x3, 0x2, 0x2, 0x2, 0x1d0, 0x1d1, 
    0x5, 0x5a, 0x2e, 0x2, 0x1d1, 0x6f, 0x3, 0x2, 0x2, 0x2, 0x26, 0x7c, 0x81, 
    0x86, 0x8b, 0x95, 0xa6, 0xb2, 0xb9, 0xbd, 0xd2, 0xdc, 0xe8, 0xf2, 0xf7, 
    0xff, 0x104, 0x114, 0x118, 0x123, 0x12b, 0x131, 0x13b, 0x15a, 0x16e, 
    0x178, 0x17c, 0x18c, 0x191, 0x197, 0x19f, 0x1a1, 0x1ae, 0x1b3, 0x1b9, 
    0x1c2, 0x1cd, 
  };

  atn::ATNDeserializer deserializer;
  _atn = deserializer.deserialize(_serializedATN);

  size_t count = _atn.getNumberOfDecisions();
  _decisionToDFA.reserve(count);
  for (size_t i = 0; i < count; i++) { 
    _decisionToDFA.emplace_back(_atn.getDecisionState(i), i);
  }
}

ExprParser::Initializer ExprParser::_init;
