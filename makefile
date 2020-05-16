main: lex.l
	lex lex.l
	gcc lex.yy.c -ll -o lex.o
	./lex.o < test