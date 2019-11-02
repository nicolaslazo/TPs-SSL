target lex.yy.c BNF.tab.c:
	flex -d expresionesDeC.l
	bison -d BNF.y
	gcc -Wno-implicit-function-declaration -g lex.yy.c BNF.tab.c -ll -ly -o output

clean:
	rm output lex.yy.c BNF.tab.c BNF.tab.h
