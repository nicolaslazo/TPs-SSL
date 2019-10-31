#ifndef LIBLISTA_H_
#define LIBLISTA_H_

	typedef enum {
		CHAR,
		FLOAT,
		INT
	} tipoSemantico;

	
	typedef enum {
		TIPOCHAR,
		TIPODOUBLE,
		TIPOFLOAT,
		TIPOINT,
		TIPOLONG,
		TIPOSHORT
	} tipoVariable;

	typedef struct {
		tipoDato tipo;
		char *identificador;
		NodoIdentificador *sig = NULL;
	} NodoIdentificador;

	int agregarIdentificador(NodoIdentificador *, char *, char *);
	int identificadorEnLista(NodoIdentificador *, char *);
	void reportarVariables(NodoIdentificador *);

#endif
