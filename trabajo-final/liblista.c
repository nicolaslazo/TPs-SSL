#define LONG_MAX_IDENT 31
#include <string.h>
#include <stdio.h>

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
	char * tipoAImprimir;

	printf("Se declararon las siguientes variables: \n");

	while (inspector != NULL) {
		switch (inspector->tipo) {
			case CHAR:
				tipoAImprimir = "Char";
				break;
			case FLOAT:
				tipoAImprimir = "Float";
				break;
			case INT:
				tipoAImprimir = "Int";
				break;
			default:
				return 1
		}

		printf("\t%s: (%s)\n", inspector->identificador, tipoAImprimir);

		inspector = inspector->sig;

		return 0;
	}
}
