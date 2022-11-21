#include <iostream>
#include <fstream>

#include "antlr4-runtime.h"
#include "ExprLexer.h"
#include "ExprParser.h"
#include "SymbVisitor.h"
#include "codeVisitor.h"
#include "symbStack.h"

using namespace antlrcpp;
using namespace antlr4;
using namespace std;



int main(int argc, const char *args[])
{
    ifstream source;

    // Create the input stream.
    source.open(args[1]);
    ANTLRInputStream input(source);

    // Create a lexer which scans the input stream
    // to create a token stream.
    ExprLexer lexer(&input);
    CommonTokenStream tokens(&lexer);

    // Print the token stream.
    //cout << "Tokens:" << endl;
    tokens.fill();

    /*for(Token *ctokens : tokens.getTokens())
    {
        cout << "Label: " << lexer.getVocabulary().getSymbolicName(ctokens->getType());
        cout << "        name: " << ctokens->getText() << endl;
    };*/

    // Create a parser which parses the token stream
    // to create a parse tree.
    ExprParser parser(&tokens);
    tree::ParseTree *tree = parser.program();

    // Print the parse tree in Lisp format.
    /*cout << endl << "Parse tree (Lisp format):" << endl;
    std::cout << tree->toStringTree(&parser) << endl;*/

    SymbVisitor *visitor = new SymbVisitor;
    visitor->visit(tree);
    
    //cout << "----------------All Tables----------------------" << endl;
    //visitor->printAllTables();
    

    codeVisitor *code = new codeVisitor;
    code->visit(tree);

    source.close();

    return 0;
}
