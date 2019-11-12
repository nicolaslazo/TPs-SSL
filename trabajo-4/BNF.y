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
	
	TipoVariable datoDeclarado;
	NodoIdentificador *listaVariables = NULL;

%}

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
		| error ';'	{ printf("Error en expresion\n"); }
;

num: 	  CONSTANTE
	| CONSTANTEREAL
	| CONSTANTEDECIMAL
	| CONSTANTEOCTAL
	| CONSTANTEHEXADECIMAL
	| error ';'		{ printf("Error: entero no valido\n"); }
;

sentencia:  sentCompuesta
	| sentAsignacion
	| sentSeleccion
	| sentInteraccion
	| sentSalto
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
;

inicializacionDeclarado: IDENTIFICADOR { registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num { registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } ',' inicializacionDeclarado
		       | IDENTIFICADOR '=' num { registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); } 
		       | IDENTIFICADOR { registrarDeclaracion(listaVariables, datoDeclarado, $<s.valor>1); }
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
	 | error ';'	{ printf("Error en sentencia de salto\n"); }
;

sentAsignacion: IDENTIFICADOR '=' expresion ';' 
