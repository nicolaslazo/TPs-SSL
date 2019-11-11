%{ 
	#include <stdio.h>
	#include "BNF.tab.h"
%}

%%

"{"		{ return '{'; }
"}"		{ return '}'; }
"="		{ return '='; }
"<"		{ return '<'; }
">"		{ return '>'; }
"+"		{ return '+'; }
"-"		{ return '-'; }
"*"		{ return '*'; }
"/"		{ return '/'; }
"%"		{ return '%'; }
";"		{ return ';'; }
":"		{ return ':'; }
"("		{ return '('; }
")"		{ return ')'; }
","		{ return ','; }

"||"	{ return OR; }
"&&"	{ return AND; }
"=="	{ return IGUALDAD; }
">="	{ return MAYORIGUAL; }
"<="	{ return MENORIGUAL; }
"!=" 	{ return DESIGUALDAD; }

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

[1-9][0-9]*       { return CONSTANTEDECIMAL; }
0[0-7]*           { return CONSTANTEOCTAL; }
0[xX][0-9a-fA-F]+ { return CONSTANTEHEXADECIMAL; }
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)? { return CONSTANTEREAL; } 
[0-9]+(\.[0-9]+)?	{ return CONSTANTE; }
'[ -~]'|'\\[abefnrtv\\\'\"\?]' { return CONSTANTECARACTER; }
auto|const|continue|enum|extern|goto|register|signed|sizeof|static|struct|typedef|union|unsigned|void|volatile { return PALABRARESERVADA; } 
[_a-zA-Z][_a-zA-Z0-9]* { yylval.s.valor = yytext; return IDENTIFICADOR; }
[,\.;:\?\(\)\[\]]  { return CARACTERDEPUNTUACION; }
[!&\*\+\-/|%><\?]     { return OPERADORDEC; }
\/\/(.)*|\/\*(.)*\*\/           { return COMENTARIO; }

%%

int main() {
	yyin = fopen("entrada.txt", "r");
	yyparse();

	return 0;
}
