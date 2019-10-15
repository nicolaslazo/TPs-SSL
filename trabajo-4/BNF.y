%{  /* seccion de definiciones */

#define YYDEBUG 1
#include <stdio.h>

%}

/* los tokens son los simbolos no terminales, type son los terminales */
%token DIGITO
%token CONSTANTE CONSTANTEREAL CONSTANTEOCTAL CONSTANTEDECIMAL CONSTANTEHEXADECIMAL
%token LITERALCADENA
%token CARACTERES 
%token MAYORIGUAL MENORIGUAL
%token DESIGUALDAD IGUALDAD
%token AND OR
%token ERROR
%token TIPODEDATO
%token IF ELSE WHILE DO SWITCH FOR RETURN CASE BREAK DEFAULT

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

expresion: /* Vacio */
	| expresion '=' expresion
	| expresion OR expresion
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
	| identificador
	| num
	| LITERALCADENA
	| error ';'					{ printf("Error en expresion"); }
	;

identificador: /* Vacio */
	| CARACTERES //noDigito
	| identificador CARACTERES
	| identificador DIGITO 
	| error ';'            			     { printf("Identificador desconocido"); }
	;

num: /* Vacio */ //num seria constanteEntera en la BNF de C
   	| CONSTANTE
	| CONSTANTEREAL
	| CONSTANTEDECIMAL
	| CONSTANTEOCTAL
	| CONSTANTEHEXADECIMAL
	| error ';'                                         { printf("Entero no valido"); }
	;

sentencia:  sentCompuesta
	| sentSeleccion
	| sentInteraccion
	| sentSalto 
	| expresion
	;
	
sentInteraccion:  
	|WHILE'(' expresion ')' sentencia
	|DO sentencia WHILE'(' expresion')'
	|FOR'(' expresion ';' expresion ';' expresion ')' sentencia
	;

sentCompuesta: 
	| '{' listaDeclaraciones listaSentencia '}'
	;

listaDeclaraciones: declaracion
	| listaDeclaraciones declaracion 
	;

listaSentencia: sentencia
	| listaSentencia sentencia
	;

declaracion: TIPODEDATO inicializacionDeclarado;

inicializacionDeclarado: identificador
		       | identificador '=' num
		       ;

sentSeleccion: IF '(' expresion ')' sentencia
	| IF '(' expresion ')' sentencia ELSE sentencia 
	| SWITCH'(' expresion ')' sentenciaSwitch 
	| RETURN expresion 
	| RETURN
        | error ';'		{ printf("Error en sentSeleccion\n"); }
	;

sentenciaSwitch: '{' sentenciaCase sentenciaSwitchDefault '}';

sentenciaCase: /* Vacio */
	     | CASE num ':' sentencia
	     ;

sentenciaSwitchDefault: /* Vacio */
		      | DEFAULT ':' sentencia
		      ;

sentSalto: /* Vacio */
	| RETURN expresion
	| RETURN
	;
