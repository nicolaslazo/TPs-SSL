%{  /* seccion de definiciones */

	#define YYDEBUG 1
	#define LONG_MAX_IDENT 31
	#include <stdio.h>

	struct s_NodoIdentificador {
		int tipo;
		char *identificador;
		struct s_NodoIdentificador *sig;
	};

	typedef struct s_NodoIdentificador NodoIdentificador;

	typedef enum {
		TIPOCHAR,
		TIPODOUBLE,
		TIPOFLOAT,
		TIPOINT,
		TIPOLONG,
		TIPOSHORT
	} TipoVariable;

	TipoVariable datoDeclarado;
	NodoIdentificador *listaVariables = NULL;

	int registrarDeclaracion(NodoIdentificador *listaIdentificadores, int tipo, char *identificador) {
		if (estaEnLista(listaIdentificadores, identificador)) {
			printf("Variable %s ya habia sido declarada.\n", identificador);
	
			return 1;
		}
	
		NodoIdentificador nuevoNodo;
		nuevoNodo.tipo = tipo;
		nuevoNodo.identificador = identificador;
		nuevoNodo.sig = listaIdentificadores;

		listaIdentificadores = &nuevoNodo;
	
		reportarVariable(&nuevoNodo);
	
		return 0;
	}
	
	int estaEnLista(NodoIdentificador *listaIdentificadores, char *identificador) {
		NodoIdentificador *inspector = listaIdentificadores;
	
		while (inspector != NULL) {
			if (!strncmp(inspector->identificador, identificador, LONG_MAX_IDENT)) return 1;
	
			inspector = inspector->sig;
		}
	
		return 0;
	}
	
	int reportarVariable(NodoIdentificador *item) {
		char * tipoAImprimir;
	
		switch (item->tipo) {
			case TIPOCHAR:
				tipoAImprimir = "Char";
				break;
			case TIPODOUBLE:
				tipoAImprimir = "Double";
				break;
			case TIPOFLOAT:
				tipoAImprimir = "Float";
				break;
			case TIPOINT:
				tipoAImprimir = "Int";
				break;
			case TIPOLONG:
				tipoAImprimir = "Long";
				break;
			case TIPOSHORT:
				tipoAImprimir = "Short";
				break;
			default:
				return 1;
		}
	
		printf("\t[%s] %s\n", tipoAImprimir, item->identificador);
	
		return 0;
	}

%}

%define parse.error verbose

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
		| IDENTIFICADOR 			{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
		| num					{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
		| error ';'	{ printf("Error en expresion\n"); }
;

num: 	  CONSTANTE		{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
	| CONSTANTEREAL		{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
	| CONSTANTEDECIMAL	{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
	| CONSTANTEOCTAL	{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
	| CONSTANTEHEXADECIMAL	{ if ($<s.esNum>1) $<s.esNum>$ = 1; else $<s.esNum>$ = 0; }
	| error ';'		{ printf("Error: entero no valido\n"); }
;

sentencia:  sentCompuesta
	| sentAsignacion
	| sentSeleccion
	| sentInteraccion
	| sentSalto
	| COMENTARIO
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
		| '{' listaSentencia '}'
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
	  | error 	{ printf("Error: tipo de dato no reconocido\n"); }
;

inicializacionDeclarado: IDENTIFICADOR 		{ registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num 	{ if ($<s.esNum>3) { $<s.esNum>1 = 1; registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } else printf("Error: asignacion no valida\n"); } ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num 	{ if ($<s.esNum>3) { $<s.esNum>1 = 1; registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } else printf("Error: asignacion no valida\n"); }
		       | IDENTIFICADOR 		{ registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); }
		       | error 			{ printf("Error en inicializacion de la variable declarada\n"); }
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
	       | error 				{ printf("Error en sentencia switch\n"); }
;

sentenciaCase: CASE num ':' sentencia
	     | error 				{ printf("Error en sentencia case\n"); }
;

sentenciaSwitchDefault: DEFAULT ':' sentencia
		      | error 			{ printf("Error en el default de una sentencia switch\n"); }
;

sentSalto: RETURN expresion ';'
	 | RETURN ';'
	 | error ';'	{ printf("Error en sentencia de salto\n"); }
;

sentAsignacion: IDENTIFICADOR '=' expresion ';' { if ($<s.esNum>3) $<s.esNum>1 = 1; else  $<s.esNum>1 = 0; } 
	      | error ';'			{ printf("Error en asignacion\n"); }
;
