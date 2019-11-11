target lex.yy.c BNF.tab.c:
	flex -d expresionesDeC.l
	bison -d BNF.y
	gcc -g -Wno-implicit-function-declaration lex.yy.c BNF.tab.c -ll -ly -o output

clean:
	rm output lex.yy.c BNF.tab.c BNF.tab.h
