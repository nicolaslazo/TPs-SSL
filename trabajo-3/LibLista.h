/*
 * 	LibLista.h: Libreria de utilidades basicas para uso de listas
 */

struct NodoListaSimple {
	char * val;
	struct NodoListaSimple * sig;
};

struct NodoListaConCant {
	char * val;
	int apariciones;
	struct NodoListaConCant * sig;
};

struct NodoListaInts {
	int val;
	struct NodoListaInts * sig;
}

struct NodoListaFloats {
	float val;
	struct NodoListaFloats * sig;
}

void agregarALista(char * valor, struct NodoListaSimple ** lista) {
	struct NodoListaSimple * inspector = *lista;

	while ( inspector != NULL ) {
		if ( inspector->val == valor ) {
			inspector->apariciones++;

			return; // Hubo match, sale de la funcion
		}

		inspector = inspector->sig;
	}

	// A este punto ya se sabe que el item no existe en la lista
	
	struct NodoListaSimple * nuevoNodo = NULL;
	nuevoNodo = (struct NodoListaSimple *) malloc(sizeof(struct NodoListaSimple));
	nuevoNodo->val = valor;
	nuevoNodo->sig = (*lista);

void agregarALista(char * valor, struct NodoListaConCant ** lista) {
	struct NodoListaConCant * inspector = *lista;

	while ( inspector != NULL ) {
		if ( inspector->val == valor ) {
			inspector->apariciones++;

			return; // Hubo match, sale de la función
		}

		inspector = inspector->sig;
	}

	// A este punto ya se sabe que el item no existe en la lista
	
	struct NodoListaConCant * nuevoNodo = NULL;
	nuevoNodo = (struct NodoListaConCant *) malloc(sizeof(struct NodoListaConCant));
	nuevoNodo->val = valor;
	nuevoNodo->apariciones = 1;
	nuevoNodo->sig = (*lista);

	(*lista) = nuevoNodo;
}

void agregarALista(int valor, struct NodoListaSimple ** lista) {
	struct NodoListaSimple * inspector = *lista;

	while ( inspector != NULL ) {
		if ( inspector->val == valor ) {
			inspector->apariciones++;

			return; // Hubo match, sale de la funcion
		}

		inspector = inspector->sig;
	}

	// A este punto ya se sabe que el item no existe en la lista
	
	struct NodoListaSimple * nuevoNodo = NULL;
	nuevoNodo = (struct NodoListaSimple *) malloc(sizeof(struct NodoListaSimple));
	nuevoNodo->val = valor;
	nuevoNodo->sig = (*lista);

void agregarALista(float valor, struct NodoListaSimple ** lista) {
	struct NodoListaSimple * inspector = *lista;

	while ( inspector != NULL ) {
		if ( inspector->val == valor ) {
			inspector->apariciones++;

			return; // Hubo match, sale de la funcion
		}

		inspector = inspector->sig;
	}

	// A este punto ya se sabe que el item no existe en la lista
	
	struct NodoListaSimple * nuevoNodo = NULL;
	nuevoNodo = (struct NodoListaSimple *) malloc(sizeof(struct NodoListaSimple));
	nuevoNodo->val = valor;
	nuevoNodo->sig = (*lista);

int sumaListaInts(NodoListaInts ** lista) {
	struct NodoListaInts * inspector = *lista;
	int acumulador = 0;

	while ( inspector != NULL ) {
		acumulador += inspector->val;
		inspector = inspector->sig;
	}

	return acumulador;
}

void imprimirLista(struct NodoListaConCant ** lista) {
	/* Funcion para debugging */
	struct NodoListaConCant * inspector = (*lista);

	if ( inspector == NULL ) {
		printf("La lista esta vacia\n");
		return;
	}

	while ( inspector != NULL ) {
		printf("%d: %d\n", inspector->val, inspector->apariciones);

		inspector = inspector->sig;
	}
}

/* Ejemplo de uso
	int main() {
		struct NodoLista * unaLista = NULL;
		agregarALista(1, &unaLista);
		agregarALista(2, &unaLista);
		agregarALista(1, &unaLista);

		imprimirLista(&unaLista);

		return 0;
	}

*/
