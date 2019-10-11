%{  /* seccion de definiciones */

#define YYDEBUG 1
#include <stdio.h>

%}

%%

%union{
	char  *t_cadena;
	float t_float;
	int t_entero;
	int t_tipo;	
} // Cuando se usan estos tipos?

/* los tokens son los simbolos no terminales, type son los terminales */
%token <t_entero>DIGITO
%token <t_cadena>CARACTERES 
%token MAYORIGUAL MENORIGUAL
%token DESIGUALDAD IGUALDAD
%token AND OR
%token ERROR
%token IF ELSE WHILE DO SWITCH FOR RETURN CASE BREAK DEFAULT

%type expresion
%type identificador
%type num
%type constoctal constdec consthexa
%type listaSentencia sentencia sentCompuesta sentInteraccion sentSalto sentSeleccion sentenciaExp sentenciaSwitch sentenciaSwitchDefault
%type listaDeclaraciones listaSentencia declaracion
%type constExpres

%left '='
%right OR
%right AND
%right '<' '>' '>=' '<='
%right '=!' '=='
%right '+' '-'
%right '*' '/' '%'
%right '^'
 

%%     /* Reglas gramaticales y las acciones */

expresion:
	
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

identificador: 
	| CARACTERES //noDigito
	| identificador CARACTERES
	| identificador DIGITO 
	| error ';'                                         { printf("Identificador desconocido"); }

num: //num seria constanteEntera en la BNF de C
	| constdec 
	| constoctal
	| consthexa
	| error ';'                                         { printf("Entero no valido"); }

constdec:
	| constdec DIGITO

constoctal: 0
	| constoctal DIGITO // Acá iría dígito, hay que ponerlo en expresionesDeC.l 

consthexa: 0x DIGITO
	| 0X DIGITO
	| consthexa CARACTERES
		

sentencia:  sentCompuesta
	| sentenciaExp
	| sentSeleccion
	| sentInteraccion
	| sentSalto // Faltan sentInteraccion (LISTO) y sentSalto (LISTO) 
	
sentInteraccion:  
	|WHILE'(' expresion ')' sentencia
	|DO sentencia WHILE'(' expresion')'
	|FOR'(' expresion ';' expresion ';' expresion ')' sentencia

sentCompuesta: 
	| '{' listaDeclaraciones listaSentencia '}'

listaDeclaraciones: declaracion
	| listaDeclaraciones declaracion // Falta declarar declaracion

listaSentencia: sentencia
	| listaSentencia sentencia

sentenciaExp:
	| exp // Redundante?

sentSeleccion: IF '(' expresion ')' sentencia
	| IF '(' expresion ')' sentencia ELSE sentencia 
	| SWITCH'(' expresion ')' sentenciaSwitch 
	| RETURN expresion 
	| RETURN
        | error ';'		{ printf("Error en sentSeleccion\n"); }

sentenciaSwitch: '{' sentenciaCase sentenciaSwitchDefault '}';

sentenciaCase: /* Vacio */
	     | CASE num ':' sentencia
	     ;

sentenciaSwitchDefault: /* Vacio */
		      | DEFAULT ':' sentencia
		      ;

sentSalto :
	| RETURN expresion
	| RETURN

// Falta ; después de cada definición de no terminal, como hice en sentenciaCase y sentenciaSwitch
