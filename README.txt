Our team cannot generate ANTLR4 files using makefile, we have to input the following command directly onto the shell:

	antlr4 -o ./target/generated-sources/ant4 -no-listener -visitor -encoding UTF-8 -Dlanguage=Cpp Expr.g4 

Afterwards, can just run the program using either "make" or

	make compile


Need to run this in a place where you have antlr4-runtime library for this to work
Need to empty test-out.txt to get new output
	for some reason it just adds to the text file instead of overwriting it

