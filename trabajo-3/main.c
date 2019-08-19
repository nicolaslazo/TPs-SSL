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
%%

constDecimales				[1-9][0-9]*
constOctales				0[0-7]*
constHexadecimales			0[xX][0-9 a-f A-F]+
constReales				[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)? | [0-9]+\.([eE][\+\-]?[0-9]+)? | [0-9]([eE][\+\-]?[0-9]+)?
constCaracter				'[ -&\\(-~]' | '\\[t n 0 ' ...]'
literal cadena				\"([ -!#-~] | \\\")*\"
palabras reservadas			auto | break | case | char | const | continue | default | do | double | else | enum | extern | float | for | goto | if | int | long | register | return | short | signed | sizeof | static | struct | switch | typedef | union | unsigned | void | volatile | while 
identificadores				[a-z A-Z _][a-z A-Z 0-9 _]*
caracteres de puntuacion		[, . ; : ... ¿? ¡! () [] {} " ' « »_ - ¨ / * §]
operadores de c				[=!&*+-/|%><?]
comentarios				\/\/(.)*

%%

{constDecimales}			agregarAListaInts(atoi(yytext), listaDecimales);
{constOctales}				agregarAListaInts(yytext, listaOctales);
{constHexadecimales}			agregarAListaInts(atof(yytext), listaHexadecimales);
{constReales}				agregarAListaFloats(yytext, listaReales);
{literal cadena}			agregarAListaSimple(yytext, listaLiteralesCadena);
{palabras reservadas}			agregarAListaSimple(yytext, listaPalabrasReservadas);
{identificadores}			agregarAListaConCant(yytext, listaIdentificadores);
{caracteres de puntuacion}		agregarAListaConCant(yytext, listaCaracteresDePuntuacion);
{operadores de c}			agregarAListaConCant(yytext, listaOperadores);
{comentarios}				agregarAListaSimple(yytext, listaComentarios);
*					agregarAListaSimple(yytext, listaOtros);						 
%%

int main() {
   
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	
    yylex();
	
    return 0;
}

