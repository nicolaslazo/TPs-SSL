%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "LibLista.h"

NodoListaConCant ** listaIdentificadores = NULL;
NodoListaSimple ** listaLiteralesCadena = NULL;
NodoListaSimple ** listaPalabrasReservadas = NULL;
NodoListaInts ** listaOctales = NULL;
NodoListaInts ** listaHexadecimales = NULL;
NodoListaInts ** listaDecimales = NULL;
NodoListaFloats ** listaReales = NULL;
NodoListaConCant ** listaCaracteresDePuntuacion = NULL;
NodoListaConCant ** listaOperadores = NULL;
NodoListaSimple ** listaComentarios = NULL;
NodoListaSimple ** listaOtros = NULL;

%}

constantes enteras decimal		[1-9][0-9]*
constantes enteras octal		0[0-7]*
constantes enteras hexadecimal		0[xX][0-9a-fA-F]+
constantes reales			[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)? 
	| 				[0-9]+\.([eE][\+\-]?[0-9]+)?
	|				[0-9]+([eE][\+\-]?[0-9]+)?
constante caracter			'[ -&\\(-~]' | \\[t n 0 ' ...]
literal cadena				\"([ -!#-~] | \\\")*\"
palabras reservadas			auto | break | case | char | const | continue | default
	| 				do | double | else | enum | extern | float | for | goto
	| 				if | int | long | register | return | short | signed 
	|				sizeof | static | struct | switch | typedef | union 
	|				unsigned | void | volatile | while 
identificadores				[a-z A-Z _][a-z A-Z 0-9 _]*
caracteres de puntuacion		[, . ; : ... ¿? ¡! () [] {} " ' « »_ - ¨ / * §]
operadores de c				[=!&*+-/|%><?]
comentarios				\/\/(.)*

%%

{constantes enteras decimal}		agregarALista(yytext, listaDecimales);
{constantes enteras octal}		agregarALista(yytext, listaOctales);
{constantes enteras hexadecimal}	agregarALista(yytext, listaHexadecimales);
{constantes reales}			agregarALista(yytext, listaReales);
{literal cadena}			agregarALista(yytext, listaLiteralesCadena);
{palabras reservadas}			agregarALista(yytext, listaPalabrasReservadas);
{identificadores}			agregarALista(yytext, listaIdentificadores);
{caracteres de puntuacion}		agregarALista(yytext, listaCaracteresDePuntuacion);
{operadores de c}			agregarALista(yytext, listaOperadores);
{comentarios}				agregarALista(yytext, listaComentarios);
{no reconocidos}			agregarALista(yytext, listaOtros);						 
%%

int main(){
   
    yyin = fopen("entrada.txt","r");
	
    while (cadena =/ <NULL)
    {
    	//recorrer el archivo,(tal vez mejor con un for), e ir comparando con los literales cadenas
    }
    switch (cadena)
	    case 1:
		if (cadena = constante enteras decimal ) {}
	    case 2:
		if (cadena = constante enteras octal ) {}
	    case 3:
		if (cadena = constante enteras hexadecimal ) {}
	    case 4:
		if (cadena = constantes reales ) {}
	    case 5:
		if (cadena = literal cadena ) {}
	    case 6:
		if (cadena = palabras reservadas ) {}
	    case 7:
		if (cadena = identificadores ) {}
	    case 8:
		if (cadena = caracteres de puntuacion ) {}
	    case 9:
		if (cadena = operadores de c ) {}
	    case 10:
		if (cadena = comentarios ) {}
	    case 11:
		if (cadena = no reconicidos ) {}

    yyout = fopen("salida.txt","w");
	
    yylex();
	
    return 0;
}

