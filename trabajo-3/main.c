/*
	Categorias Lexicas			ERX

	constantes enteras decimal		[1-9][0-9]*
	constantes enteras octal		0[0-7]*
	constantes enteras hexadecimal		0[xX][0-9a-fA-F]+
	constantes reales			[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)? 
		| 				[0-9]+\.([eE][\+\-]?[0-9]+)?
		|				[0-9]+([eE][\+\-]?[0-9]+)?
	constante caracter			'[ -&\(-~]' | \\[t n 0 ' ...]
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
*/

/*Listados*/

struct Identificadores {
  char* nombreIdentificador;
  int aparicionesIdentificador;
  };
  
struct LiteralesCadena{
  char* nombreCadena;
  int longitudCadena;
  };
  
struct PalabrasReservadas{
  char* nombrePalabraReservada;
  };
  
struct ConstantesOctales{
  char* cadenaOctal;
  };
  
struct ConstantesHexadecimales{
  char* cadenaHexadecimal;
  };
  
struct ConstantesDecimales{
  char* cadenaDecimal;
  };
  
struct ConstantesReales{
  char* cadenaReal;
  };
  
struct CaracteresDePuntuacion{
  char* caracterPuntuacion;
  int aparicionesCaracterPuntuacion;
  };
  
struct Operadores{
  char* operador;
  int aparicionesOperador;
  };
  
struct ComentariosReconocidos{
  char* cadenaReconocida;
  };
  
struct CadenasCaracteresNoReconocidos{
  char* cadenaOCaracterNoReconocido;
  };





  
  
  
  
  
  
