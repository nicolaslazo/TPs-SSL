%{  /* seccion de definiciones */

#define YYDEBUG 1
#include <stdio.h>
#include "utils/liblista.h"
#include "utils/verifsemantica.h"


TipoVariable datoDeclarado;

%}

%union { 
  struct {
     char cadena[50];
     float  valor;
     int  tipo;
  } s;
}

/* los tokens son los simbolos no terminales, type son los terminales */
%token <s> CONSTANTE CONSTANTEREAL CONSTANTEOCTAL CONSTANTEDECIMAL CONSTANTEHEXADECIMAL CONSTANTECARACTER
%token <s> LITERALCADENA
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

expresion: 	  expresion OR expresion
		| expresion AND expresion
		| expresion MAYORIGUAL expresion
		| expresion '>' expresion
		| expresion MENORIGUAL expresion
		| expresion '<' expresion
		| expresion DESIGUALDAD expresion 
		| expresion '+' expresion   
		| expresion '-' expresion  
		| expresion '*' expresion  
		| expresion '/' expresion   
		| expresion '^' expresion   
		| expresion '%' expresion
		| IDENTIFICADOR
		| num
		| LITERALCADENA
		| error ';'	{ printf("Error en expresion\n"); }
;

num: 	  CONSTANTE
	| CONSTANTEREAL
	| CONSTANTEDECIMAL
	| CONSTANTEOCTAL
	| CONSTANTEHEXADECIMAL
	| error ';'		{ printf("Entero no valido\n"); }
;

sentencia:  sentCompuesta	{ printf("Sentencia compuesta encontrada\n"); }
	| sentAsignacion
	| sentSeleccion
	| sentInteraccion
	| sentSalto
	| BREAK ';'
	| expresion ';'
	| error ';'		{ printf("Sentencia no valida\n"); }
;
	
sentInteraccion: WHILE '(' expresion ')' sentencia 	{ printf("While encontrado\n"); }
		| DO sentencia WHILE'(' expresion')' ';'		{ printf("Do encontrado\n"); }
		| FOR'(' expresion ';' expresion ';' expresion ')' sentencia 	{ printf("For encontrado\n"); }
;

sentCompuesta: '{' listaDeclaracion listaSentencia '}'
	     	| '{' listaDeclaracion '}'
		| '{' '}'
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

inicializacionDeclarado: IDENTIFICADOR ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num
		       | IDENTIFICADOR
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
;

sentAsignacion: IDENTIFICADOR '=' expresion ';'
