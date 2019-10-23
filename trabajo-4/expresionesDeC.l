%{ 
	#include <stdio.h>
	#include "BNF.tab.h"
%}

%%

[1-9][0-9]*       {printf("Num found\n"); return CONSTANTEDECIMAL;}
0[0-7]*           {return CONSTANTEOCTAL;}
0[xX][0-9a-fA-F]+ {return CONSTANTEHEXADECIMAL;}
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)? {return CONSTANTEREAL;} 
[0-9]+(\.[0-9]+)?	{return CONSTANTE;}
'[ -~]'|'\\[abefnrtv\\\'\"\?]' {return CONSTANTECARACTER;}
\"[ -~]*\"        {return LITERALCADENA;}
char|double|float|int|long|short {printf("Type found\n"); return TIPODEDATO;}
auto|break|case|const|continue|default|do|else|enum|extern|for|goto|if|register|return|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {return PALABRARESERVADA;} 
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
	yylex();

	return 0;
}
