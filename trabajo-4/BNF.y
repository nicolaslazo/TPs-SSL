%{  /* seccion de definiciones */

#define YYDEBUG 1
#include <stdio.h>

%}

/* los tokens son los simbolos no terminales, type son los terminales */
%token CONSTANTE CONSTANTEREAL CONSTANTEOCTAL CONSTANTEDECIMAL CONSTANTEHEXADECIMAL CONSTANTECARACTER
%token LITERALCADENA
%token CARACTER CARACTERDEPUNTUACION
%token MAYORIGUAL MENORIGUAL
%token DESIGUALDAD IGUALDAD 
%token AND OR
%token TIPODEDATO
%token IF ELSE WHILE DO SWITCH FOR CASE BREAK DEFAULT PALABRARESERVADA
%token RETURN
%token IDENTIFICADOR
%token COMENTARIO
%token OPERADORDEC

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
	
sentInteraccion:  
	|WHILE '(' expresion ')' sentencia 	{ printf("While encontrado\n"); }
	|DO sentencia WHILE'(' expresion')' ';'		{ printf("Do encontrado\n"); }
	|FOR'(' expresion ';' expresion ';' expresion ')' sentencia 	{ printf("For encontrado\n"); }
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

declaracion: TIPODEDATO inicializacionDeclarado;

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
