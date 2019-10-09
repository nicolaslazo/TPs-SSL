%{  /* seccion de definiciones */

#define YYDEBBUG 1
#include <stdio.h>

int flag_error=0;

%}

%%

%union{
	char  *t_cadena;
	float t_float;
	int t_entero;
	int t_tipo;	
}

/* los tokens son los simbolos no terminales, type son los terminales */
%token <t_entero>DIGITO
%token <t_cadena>CARACTERES 
%token MAYORIGUAL MENORIGUAL
%token DESIGUALDAD IGUALDAD
%token AND OR
%token ERROR
%token IF ELSE WHILE DO SWITCH FOR RETURN CASE BREAK

%type expresion
%type identificador
%type num
%type constoctal constdec consthexa
%type listaSentencia sentencia sentCompuesta sentInteraccion sentSalto sentSeleccion sentenciaExp
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
	| ERROR					{ printf("Error en expresion"); }

identificador: 
	| CARACTERES //noDigito
	| identificador CARACTERES
	| identificador DIGITO 
	| ERROR                                         { printf("Identificador desconocido"); }

num: //num seria constanteEntera en la BNF de C
	| constdec 
	| constoctal
	| consthexa
	| ERROR                                         { printf("Entero no valido"); }

constdec:
		| constdec DIGITO {}

constoctal: 0
	| constoctal DIGITO // ACA IRIA DIGITO? 

consthexa: 0x DIGITO
		| 0X DIGITO
		| consthexa CARACTERES
		

sentencia:  sentCompuesta
	| sentenciaExp
	| sentSeleccion
	| sentInteraccion
	| sentSalto

sentCompuesta: 
	| listaDeclaraciones listaSentencia  //esta ggramatica es sentCompuesta -> {listaDeclaraciones listaSentencia} como pongo los llaves, bison entiende de llaves?

listaDeclaraciones: declaracion
	| listaDeclaraciones declaracion

listaSentencia: sentencia
	| listaSentencia sentencia

sentenciaExp:
	| exp

sentSeleccion: IF '(' expresion ')' sentencia
	| IF '(' expresion ')' sentencia ELSE sentencia 
	| WHILE'(' expresion ')' sentencia
	| SWITCH'(' expresion ')' CASE constExpres ':' sentencia BREAK
	| DO sentencia WHILE'(' expresion')' 
	| FOR'(' expresion ';' expresion ';' expresion ')' sentencia
	| RETURN expresion 
	| RETURN
        | ERROR		{ printf("Error en sentSeleccion\n"); }
