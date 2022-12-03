Our team cannot generate ANTLR4 files using makefile, we have to input the following command directly onto the shell:

	antlr4 -o ./target/generated-sources/ant4 -no-listener -visitor -encoding UTF-8 -Dlanguage=Cpp Expr.g4 

Afterwards, can just run the program using either "make" or

	make compile


Need to run this in a place where you have antlr4-runtime library for this to work

We believe we can generate code for assignment and if statments
We stopped and could not finish loop statements, we couldnt finish coding for repeat
Change the input file in make to access our different test-cases
You can manually change where to output the generated code by editing the open statement in target, codeVisitor, line 61
	codeVisitor is where we do our code generation
To check if we did it correctly we had to generate instructions that 
	will load the value stored in beta into the T register before we declare our variables at the end
You can uncomment it to check the beta variable

