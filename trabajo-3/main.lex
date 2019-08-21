%{
#include <math.h>
#include <stdio.h>
#include <string.h>
#include "LibLista.h"

struct NodoListaConCant ** listaIdentificadores = NULL;
struct NodoListaSimple ** listaLiteralesCadena = NULL;
struct NodoListaSimple ** listaPalabrasReservadas = NULL;
struct NodoListaInts ** listaOctales = NULL;
struct NodoListaInts ** listaHexadecimales = NULL;
struct NodoListaInts ** listaDecimales = NULL;
struct NodoListaFloats ** listaReales = NULL;
struct NodoListaConCant ** listaCaracteresDePuntuacion = NULL;
struct NodoListaConCant ** listaOperadores = NULL;
struct NodoListaSimple ** listaComentarios = NULL;
struct NodoListaSimple ** listaOtros = NULL;
%}

constDecimales				[1-9][0-9]*
constOctales				0[0-7]*
constHexadecimales			0[xX][0-9a-fA-F]+
constReales				[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)? | [0-9]+\.([eE][\+\-]?[0-9]+)? | [0-9]([eE][\+\-]?[0-9]+)?
constCaracter				'[ -~]' | '\\[abefnrtv\\\'\"\?]'
literalCadena				\"([ -~])*\"
palabrasReservadas			auto | break | case | char | const | continue | default | do | double | else | enum | extern | float | for | goto | if | int | long | register | return | short | signed | sizeof | static | struct | switch | typedef | union | unsigned | void | volatile | while 
identificadores				[_a-zA-Z][_a-zA-Z0-9]*
caracteresDePuntuacion			, | . | ; | : | ¿ | ? | ( | ) | [ | ] | { | }
operadoresDeC				[=!&*+-/|%><?]
comentarios				\/\/(.)*

%%

{constDecimales}			agregarAListaInts(atoi(yytext), listaDecimales);
{constOctales}				agregarAListaInts(yytext, listaOctales);
{constHexadecimales}			agregarAListaInts(atof(yytext), listaHexadecimales);
{constReales}				agregarAListaFloats(yytext, listaReales);
{literalCadena}				agregarAListaSimple(yytext, listaLiteralesCadena);
{palabrasReservadas}			agregarAListaSimple(yytext, listaPalabrasReservadas);
{identificadores}			agregarAListaConCant(yytext, listaIdentificadores);
{caracteresDePuntuacion}		agregarAListaConCant(yytext, listaCaracteresDePuntuacion);
{operadoresDeC}				agregarAListaConCant(yytext, listaOperadores);
{comentarios}				agregarAListaSimple(yytext, listaComentarios);
*					agregarAListaSimple(yytext, listaOtros);
			 
%%

int main() {
   
    yyin = fopen("entrada.txt", "r");
    yyout = fopen("salida.txt", "w");	
    yylex();
	
    return 0;
}

