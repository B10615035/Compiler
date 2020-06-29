all: parser

parser: lex.yy.cpp y.tab.cpp symbol.cpp symbol.hpp
	g++ y.tab.cpp symbol.cpp -o parser -std=c++11

lex.yy.cpp: lex.l
	lex -o lex.yy.cpp lex.l

y.tab.cpp: yacc.y
	yacc -d yacc.y -o y.tab.cpp

clean:
	rm parser lex.yy.* y.tab.*

run:
	./parser ./test/$(file)
	javaa/javaa ./jasm/$(file).jasm
	java $(file)
