#define LONG_MAX_IDENT 31
#include <string.h>
#include <stdio.h>

int registrarDeclaracion(NodoIdentificador *listaIdentificadores, int tipo, char *identificador) {
	if (identificadorEnLista(listaIdentificadores, identificador)) {
		printf("Variable %s ya habia sido declarada.\n", identificador);

		return 1;
	}

	if ( listaIdentificadores == NULL) 

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
				return 1
		}

		printf("\t[%s] %s\n", tipoAImprimir, inspector->identificador);

		inspector = inspector->sig;

		return 0;
	}
}
