grammar Expr;

program: program_header declarations compound_statement DOT;

program_header: PROGRAM IDENTIFIER SEMICOLON;

declarations: (constants SEMICOLON)? (types SEMICOLON)? (variables SEMICOLON)?
	(functions SEMICOLON)?;

constants: CONST constant_list;
constant_list: constant_declaration (SEMICOLON constant_declaration)*;
constant_declaration: const_identifier EQUAL (CHAR | STRINGS | INTEGER | REAL | IDENTIFIER | BOOLEAN);
const_identifier: IDENTIFIER;

types: TYPE type_list;
type_list: type_declaration (SEMICOLON type_declaration)*;
type_declaration: type_identifier_list EQUAL type_specification;
type_identifier_list: type_identifier (COMMA type_identifier)*;
type_identifier: IDENTIFIER;

type_specification: simpletype | arraytype;
simpletype: scalar | range;
arraytype: array_start type_specification;
array_start: ARRAY LBRACKET dimensions RBRACKET OF ;

dimensions: simpletype;
scalar: (CHAR | INTEGER | IDENTIFIER | BOOLEAN);
range: INTEGER DOT_DOT INTEGER
	| CHAR DOT_DOT CHAR;

variables: VAR variable_list;
variable_list: variable_declarations (SEMICOLON variable_declarations)*;
variable_declarations: var_identifier_list COLON type_specification;
var_identifier_list: var_identifier (COMMA var_identifier)*;
var_identifier: IDENTIFIER;

functions: funct_type (SEMICOLON funct_type)*;
funct_type: (proc | funct) declarations compound_statement;
proc: PROCEDURE funct_identifier parameters?;
funct: FUNCTION funct_identifier parameters? COLON type_identifier;
funct_identifier: IDENTIFIER;

parameters: LPAREN param_list RPAREN;
param_list: param_declaration (SEMICOLON param_declaration)* ;
param_declaration: VAR? param_identifier_list COLON type_identifier;
param_identifier_list: param_identifier (COMMA param_identifier)*;
param_identifier: IDENTIFIER;
 

statement_list: (statement* SEMICOLON)+;

statement: compound_statement              
	| assign_statement 
	| repeat_statement 
	| if_statement 
	| while_statement 
	| case_statement 
	| for_statement
	| function_call	          
	;

compound_statement: BEGIN statement_list END ;

assign_statement: variable ASSIGN expression ;

repeat_statement: REPEAT statement_list UNTIL expression ;

if_statement: IF LPAREN expression RPAREN THEN statement
	| IF LPAREN expression RPAREN THEN statement ELSE statement
	;

while_statement: WHILE LPAREN expression RPAREN DO statement ;

case_statement: CASE LPAREN IDENTIFIER RPAREN OF (condition statement SEMICOLON)+ END;

condition: INTEGER COLON 
	| (INTEGER COMMA)+ INTEGER COLON
	;

for_statement: FOR IDENTIFIER ASSIGN INTEGER TO INTEGER DO statement ;

expression: simple_expression (EQUAL | NE | LTEQ | GTEQ | LT | GT) simple_expression
	| simple_expression
	;

simple_expression: ((PLUSOP | MINUSOP)* term)+ ;

term: factor
	| factor ((MULTOP | DIVOP) factor)+
	;

factor: variable
	| INTEGER
	| CHAR
	| TRUE
	| FALSE
	| MINUSOP INTEGER
	| LPAREN expression RPAREN
	;

variable : IDENTIFIER | function_call | array_element;

array_element: IDENTIFIER element+;
element: LBRACKET (CHAR | INTEGER | IDENTIFIER | TRUE
		| FALSE) RBRACKET;

function_call: function_name LPAREN arg_list? RPAREN;
function_name: IDENTIFIER;
arg_list: arg (COMMA arg)*;
arg: expression;

DOT_DOT: '.' '.';
DOT: '.';
COLON: ':';
CHAR: '\'' ~('\'') '\'';
STRINGS: '\'' ~('\'')* '\'';
AND : [aA][nN][dD];
ARRAY : [aA][rR][rR][aA][yY];
ASM : [aA][sS][mM];
BEGIN : [bB][eE][gG][iI][nN];
BOOLEAN : [bB][oO][oO][lL][lL][eE][aA][nN];
BREAK : [bB][rR][eE][aA][kK];
CASE : [cC][aA][sS][eE];
CONST : [cC][oO][nN][sS][tT];
CONSTRUCTOR : [cC][oO][nN][sS][tT][rR][uU][cC][tT][oO][rR];
CONTINUE : [cC][oO][nN][tT][iI][nN][uU][eE];
DESTRUCTOR : [dD][eE][sS][tT][rR][uU][cC][tT][oO][rR];
DIV : [dD][iI][vV];
DO : [dD][oO];
DOWNTO : [dD][oO][wW][nN][tT][oO];
ELSE : [eE][lL][sS][eE];
END : [eE][nN][dD];
FALSE : [fF][aA][lL][sS][eE];
FILE : [fF][iI][lL][eE];
FOR : [fF][oO][rR];
FUNCTION : [fF][uU][nN][cC][tT][iI][oO][nN];
GOTO :[gG][oO][tT][oO];
IF : [iI][fF];
IMPLEMENTATION : [iI][mM][pP][lL][eE][mM][eE][nN][tT][aA][tT][iI][oO][nN];
IN : [iI][nN];
INLINE : [iI][nN][lL][iI][nN][eE];
INTERFACE : [iI][nN][tT][eE][rR][fF][aA][cC][eE];
LABEL : [lL][aA][bB][eE][lL];
MOD : [mM][oO][dD];
NIL : [nN][iI][lL];
NOT : [nN][oO][tT];
OBJECT : [oO][bB][jJ][eE][cC][tT];
OF: [oO][fF];
ON: [oO][nN];
OPERATOR: [oO][pP][eE][rR][aA][tT][oO][rR];
OR: [oO][rR];
PACKED: [pP][aA][cC][kK][eE][dD];
PROCEDURE : [pP][rR][oO][cC][eE][dD][uU][rR][eE];
PROGRAM : [pP][rR][oO][gG][rR][aA][mM];
RECORD : [rR][eE][cC][oO][rR][dD];
REPEAT : [rR][eE][pP][eE][aA][tT];
SET : [sS][eE][tT];
SHL : [sS][hH][lL];
SHR : [sS][hH][rR];
STRING : [sS][tT][rR][iI][nN][gG];
THEN : [tT][hH][eE][nN];
TO : [tT][oO];
TRUE : [tT][rR][uU][eE];
TYPE : [tT][yY][pP][eE];
UNIT : [uU][nN][iI][tT];
UNTIL : [uU][nN][tT][iI][lL];
USES : [uU][sS][eE][sS];
VAR : [vV][aA][rR];
WHILE : [wW][hH][iI][lL][eE];
WITH : [wW][iI][tT][hH];
XOR : [xX][oO][rR];
IDENTIFIER : [a-zA-Z]+; 
INTEGER   : [0-9]+;
REAL : [0-9]+'.'[0-9]+;
PLUSOP : '+';
MINUSOP : '-';
MULTOP : '*';
DIVOP : '/';
ASSIGN : ':=';
EQUAL : '=';
NE : '<>';
LTEQ : '<=';
GTEQ : '>=';
LT : '<';
GT : '>';
PLUSEQUAL : '+=';
MINUSEQUAL : '-=';
MULTEQUAL : '*=';
DIVEQUAL : '/=';
CARAT : '^';
SEMICOLON : ';';
COMMA : ',';
LPAREN : '(';
RPAREN : ')';
LBRACKET : '[';
RBRACKET : ']';
LBRACE : '{';
RBRACE : '}';
LCOMMENT : '(*';
RCOMMENT : '*)';
ERROR: [.?!':]+ | [0-9]+'.'[0-9]+'.'[0-9]+;

WS : [ \t\r\n]+ -> skip ;  // skip whitespace
COMMENT : '(*' ~('\'')* '*)' -> skip ;