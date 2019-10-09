#define LONG_MAX_IDENT 31
#include <string.h>

typedef struct {
	char *identificador;
	NodoIdentificador *sig = NULL;
} NodoIdentificador;

int agregarIdentificador(NodoIdentificador *listaIdentificadores, char *identificador) {
	if (estaEnLista(listaIdentificadores, identificador)) return 1;

	NodoIdentificador *nuevoNodo;
	nuevoNodo->identificador = identificador;
	nuevoNodo->sig = listaIdentificadores;

	return 0;
}

int estaEnLista(NodoIdentificador *listaIdentificadores, char *identificador) {
	NodoIdentificador *inspector = listaIdentificadores;

	while (inspector != NULL) {
		if (!strncmp(inspector, identificador, LONG_MAX_IDENT)) return 1;

		inspector = inspector->sig;
	}

	return 0;
}
