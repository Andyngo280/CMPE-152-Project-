ANTLRFILE=Expr.g4

antlr=java -jar ${ANTLR_JAR}

PROJECTPATH=$(shell pwd)
ANTLR_RUNTIME_INCLUDES=antlr4-runtime
ANTLR_INCLUDES=$(PROJECTPATH)/target/generated-sources/ant4
LIB_PATH=/usr/local/lib
LIB=antlr4-runtime
PROG=ExprMain.cpp
OUT=prog.out
ANTLR_SOURCES=target/generated-sources/ant4/*.cpp
SOURCES=$(ANLTR_SOURCES) $(PROG)

compile:
	g++ -o prog.out -I$(ANTLR_RUNTIME_INCLUDES) -I$(ANTLR_INCLUDES) -I$(PROJECTPATH) -L/usr/local/lib -w \
target/generated-sources/ant4/*.cpp ExprMain.cpp -lantlr4-runtime
	./prog.out loop_test.expr

antlr:
	antlr4 -o ./target/generated-sources/ant4 -no-listener -visitor -encoding UTF-8 -Dlanguage=Cpp Expr.g4 
