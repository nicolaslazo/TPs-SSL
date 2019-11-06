%{  /* seccion de definiciones */

	#define YYDEBUG 1
	#include <stdio.h>
	#include "utils/liblista.h"
	#include "utils/verifsemantica.h"

	TipoVariable datoDeclarado;
	NodoIdentificador *listaVariables = NULL;

%}

%union { 
  struct {
	int esNum;
	char *valor;
  } s;
}

/* los tokens son los simbolos no terminales, type son los terminales */
%token <s> CONSTANTE CONSTANTEREAL CONSTANTEOCTAL CONSTANTEDECIMAL CONSTANTEHEXADECIMAL CONSTANTECARACTER
%token <s> CARACTER CARACTERDEPUNTUACION
%token <s> MAYORIGUAL MENORIGUAL
%token <s> DESIGUALDAD IGUALDAD 
%token <s> AND OR
%token <s> CHAR DOUBLE FLOAT INT LONG SHORT
%token <s> IF ELSE WHILE DO SWITCH FOR CASE BREAK DEFAULT PALABRARESERVADA
%token <s> RETURN
%token <s> IDENTIFICADOR
%token <s> COMENTARIO
%token <s> OPERADORDEC

%type <s> expresion
%type <s> num
%type <s> sentencia
%type <s> sentInteraccion
%type <s> sentCompuesta
%type <s> listaSentencia
%type <s> listaDeclaracion
%type <s> declaracion
%type <s> tipoDeDato
%type <s> inicializacionDeclarado
%type <s> sentSeleccion
%type <s> sentenciaSwitch
%type <s> sentenciaCase
%type <s> sentenciaSwitchDefault
%type <s> sentSalto
%type <s> sentAsignacion

%left '='
%right OR
%right AND
%right '<' '>' MAYORIGUAL MENORIGUAL
%right DESIGUALDAD IGUALDAD
%right '+' '-'
%right '*' '/' '%'
%right '^'
 
%start sentencia

%%     /* Reglas gramaticales y las acciones */

expresion: 	  expresion OR expresion 		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion AND expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion MAYORIGUAL expresion	{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion '>' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion MENORIGUAL expresion	{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion '<' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion DESIGUALDAD expresion 	{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| expresion '+' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }   
		| expresion '-' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }  
		| expresion '*' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }  
		| expresion '/' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }   
		| expresion '^' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }   
		| expresion '%' expresion		{ if (!$<s.esNum>1 || !$<s.esNum>3) printf("Error: tipos incompatibles\n"); else $<s.esNum>$ = 1; }
		| IDENTIFICADOR 
		| num
		| error ';'	{ printf("Error en expresion\n"); }
;

num: 	  CONSTANTE
	| CONSTANTEREAL
	| CONSTANTEDECIMAL
	| CONSTANTEOCTAL
	| CONSTANTEHEXADECIMAL
	| error ';'		{ printf("Error: entero no valido\n"); }
;

sentencia:  sentCompuesta
	| sentAsignacion
	| sentSeleccion
	| sentInteraccion
	| sentSalto
	| BREAK ';'
	| expresion ';'
	| error ';'		{ printf("Error: sentencia no valida\n"); }
;
	
sentInteraccion: WHILE '(' expresion ')' sentencia 	{ printf("While encontrado\n"); }
		| DO sentencia WHILE'(' expresion')' ';'		{ printf("Do encontrado\n"); }
		| FOR'(' expresion ';' expresion ';' expresion ')' sentencia 	{ printf("For encontrado\n"); }
		| error ';'	{ printf("Error: sentencia de interaccion no valida\n"); }
;

sentCompuesta: '{' listaDeclaracion listaSentencia '}'
	     	| '{' listaDeclaracion '}'
		| '{' '}'
		| error ';'	{ printf("Error: sentencia compuesta no valida\n"); }
;

listaSentencia: sentencia
	| listaSentencia sentencia
;

listaDeclaracion: declaracion ';' listaDeclaracion
		| /* Vacio */
;

declaracion: tipoDeDato inicializacionDeclarado;

tipoDeDato: CHAR 	{ datoDeclarado = TIPOCHAR; }
	  | DOUBLE	{ datoDeclarado = TIPODOUBLE; }
	  | FLOAT	{ datoDeclarado = TIPOFLOAT; }
	  | INT		{ datoDeclarado = TIPOINT; }
	  | LONG	{ datoDeclarado = TIPOLONG; }
	  | SHORT	{ datoDeclarado = TIPOSHORT; }
;

inicializacionDeclarado: IDENTIFICADOR { registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num { if ($<s.esNum>3) { $<s.esNum>1 = 1; registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } else printf("Error: asignacion no valida\n"); } ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num { if ($<s.esNum>3) { $<s.esNum>1 = 1; registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } else printf("Error: asignacion no valida\n"); }
		       | IDENTIFICADOR { registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); }
;

sentSeleccion: IF '(' expresion ')' sentencia
	| IF '(' expresion ')' sentencia ELSE sentencia 
	| SWITCH'(' expresion ')' sentenciaSwitch 
        | error ';'		{ printf("Error en sentSeleccion\n"); }
;

sentenciaSwitch: '{' sentenciaCase sentenciaSwitchDefault '}'
	       | '{' sentenciaCase '}'
	       | '{' sentenciaSwitchDefault '}'
	       | '{' '}'
;

sentenciaCase: CASE num ':' sentencia;

sentenciaSwitchDefault: DEFAULT ':' sentencia;

sentSalto: RETURN expresion ';'
	 | RETURN ';'
	 | error ';'	{ printf("Error en sentencia de salto\n"); }
;

sentAsignacion: IDENTIFICADOR '=' expresion ';' { if ($<s.esNum>3) $<s.esNum>1 = 1; else $<s.esNum>1 = 0; }
