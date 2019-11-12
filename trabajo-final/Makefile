target lex.yy.c BNF.tab.c:
	bison -d BNF.y
	flex -d expresionesDeC.l
	gcc -Wno-implicit-function-declaration -g lex.yy.c BNF.tab.c -ll -ly -o output

clean:
	rm output lex.yy.c BNF.tab.c BNF.tab.h
