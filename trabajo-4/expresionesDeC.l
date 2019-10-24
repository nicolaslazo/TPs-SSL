%{ 
	#include <stdio.h>
	#include "BNF.tab.h"
%}

%%

"while" 	{ return WHILE; }
"if"		{ return IF; }
"else"		{ return ELSE; }
"do"		{ return DO; }
"switch"	{ return SWITCH; }
"for"		{ return FOR; }
"case"		{ return CASE; }
"break"		{ return BREAK; }
"default"	{ return DEFAULT; }

[1-9][0-9]*       {printf("Num found\n"); return CONSTANTEDECIMAL;}
0[0-7]*           {return CONSTANTEOCTAL;}
0[xX][0-9a-fA-F]+ {return CONSTANTEHEXADECIMAL;}
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)? {return CONSTANTEREAL;} 
[0-9]+(\.[0-9]+)?	{return CONSTANTE;}
'[ -~]'|'\\[abefnrtv\\\'\"\?]' {return CONSTANTECARACTER;}
\"[ -~]*\"        {return LITERALCADENA;}
char|double|float|int|long|short {printf("Type found\n"); return TIPODEDATO;}
auto|const|continue|enum|extern|goto|register|signed|sizeof|static|struct|typedef|union|unsigned|void|volatile { return PALABRARESERVADA; } 
[_a-zA-Z][_a-zA-Z0-9]* {printf("Identifier found\n"); return IDENTIFICADOR;}
[,\.;:\?\(\)\[\]]  {return CARACTERDEPUNTUACION;}
[!&\*\+\-/|%><\?]     {return OPERADORDEC;}
\/\/(.)*|\/\*(.)*\*\/           {printf("Comment found\n"); return COMENTARIO;}

"||"	{return OR;}
"&&"	{return AND;}
"=="	{return IGUALDAD;}
">="	{return MAYORIGUAL;}
"<="	{return MENORIGUAL;}
"!="  {return DESIGUALDAD;}

%%

int main() {
	yyin = fopen("entrada.txt", "r");
	yyout = fopen("salida.txt", "w");
	yyparse();

	return 0;
}
