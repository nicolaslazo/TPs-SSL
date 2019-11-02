%{ 
	#include <stdio.h>
	#include "BNF.tab.h"

	int numLinea = 1;
%}

%%

while 		{ return WHILE; }
if		{ return IF; }
else		{ return ELSE; }
do		{ return DO; }
switch		{ return SWITCH; }
for		{ return FOR; }
case		{ return CASE; }
break		{ return BREAK; }
default		{ return DEFAULT; }
char		{ return CHAR; }
double		{ return DOUBLE; }
float		{ return FLOAT; }
int		{ return INT; }
long		{ return LONG; }
short		{ return SHORT; }

\n		{ numLinea++; }

[1-9][0-9]*       { yylval.s.esNum = 1; return CONSTANTEDECIMAL; }
0[0-7]*           { yylval.s.esNum = 1; return CONSTANTEOCTAL; }
0[xX][0-9a-fA-F]+ { yylval.s.esNum = 1; return CONSTANTEHEXADECIMAL; }
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)? { yylval.s.esNum = 1; return CONSTANTEREAL; } 
[0-9]+(\.[0-9]+)?	{ yylval.s.esNum = 1; return CONSTANTE; }
'[ -~]'|'\\[abefnrtv\\\'\"\?]' { yylval.s.esNum = 1; return CONSTANTECARACTER; }
\"[ -~]*\"        { return LITERALCADENA; }
auto|const|continue|enum|extern|goto|register|signed|sizeof|static|struct|typedef|union|unsigned|void|volatile { return PALABRARESERVADA; } 
[_a-zA-Z][_a-zA-Z0-9]* { return IDENTIFICADOR; }
[,\.;:\?\(\)\[\]]  { return CARACTERDEPUNTUACION; }
[!&\*\+\-/|%><\?]     { return OPERADORDEC; }
\/\/(.)*|\/\*(.)*\*\/           { return COMENTARIO; }

"||"	{ return OR; }
"&&"	{ return AND; }
"=="	{ return IGUALDAD; }
">="	{ return MAYORIGUAL; }
"<="	{ return MENORIGUAL; }
"!=" 	{ return DESIGUALDAD; }

%%

int main() {
	yyin = fopen("entrada.txt", "r");
	yyout = fopen("salida.txt", "w");
	yyparse();

	reportarVariables(listaVariables);

	return 0;
}
