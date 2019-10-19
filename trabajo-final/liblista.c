#define LONG_MAX_IDENT 31
#include <string.h>

int agregarIdentificador(NodoIdentificador *listaIdentificadores, tipoDato tipo, char *identificador) {
	if (estaEnLista(listaIdentificadores, identificador)) {
		printf("Variable %s ya habia sido declarada.\n", identificador);

		return 1;
	}

	NodoIdentificador *nuevoNodo;
	nuevoNodo->tipo = tipo;
	nuevoNodo->identificador = identificador;
	nuevoNodo->sig = listaIdentificadores;

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

void reportarVariables(NodoIdentificador *lista) {
	NodoIdentificador *inspector;

	printf("Se declararon las siguientes variables: \n");

	while (inspector != NULL) {
		printf("\t%s: (%s)\n", inspector->identificador, inspector->tipo);

		inspector = inspector->sig;
	}
}
