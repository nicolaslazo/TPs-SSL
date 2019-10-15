%{ 
	#include <stdio.h>
%}
%%
[0-9]	{return DIGITO} //uno de 0 1 2 3 4 5 6 7 8 9 
[0-9]+(\.[0-9]+)?	{return CONSTANTE;}
[1-9][0-9]*       {return CONSTANTEDECIMAL;}
0[0-7]*           {return CONSTANTEOCTAL;}
0[xX][0-9a-fA-F]+ {return CONSTANTEHEXADECIMAL;}
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)? {return CONSTANTEREAL:} 
'[ -~]'|'\\[abefnrtv\\\'\"\?]' {return CONSTANTECARACTER;}
\"[ -~]*\"        {return LITERALCADENA;}
char|double|float|int|long|short {return TIPODEDATO;}
auto|break|case|const|continue|default|do|else|enum|extern|for|goto|if|register|return|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {return PALABRARESERVADA;} 
[_a-zA-Z][_a-zA-Z0-9]* {return IDENTIFICADORES;}
[,\.;:\?\(\)\[\]\{\}]  {return CARACTERDEPUNTUACION;}
[=!&\*\+\-/|%><\?]     {return OPERADORDEC;}
\/\/(.)*           {return COMENTARIOS;}

"="   {return ASIGNACION;}
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
