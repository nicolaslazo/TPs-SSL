/*
 * 	LibLista.h: Libreria de utilidades basicas para uso de listas
 */

struct NodoLista {
	char * val;
	int apariciones;
	struct NodoLista * sig;
};


void agregarALista(char * valor, struct NodoLista ** lista) {
	struct NodoLista * inspector = *lista;

	while ( inspector != NULL ) {
		if ( inspector->val == valor ) {
			inspector->apariciones++;

			return; // Hubo match, sale de la función
		}

		inspector = inspector->sig;
	}

	// A este punto ya se sabe que el item no existe en la lista
	
	struct NodoLista * nuevoNodo = NULL;
	nuevoNodo = (struct NodoLista *) malloc(sizeof(struct NodoLista));
	nuevoNodo->val = valor;
	nuevoNodo->apariciones = 1;
	nuevoNodo->sig = (*lista);

	(*lista) = nuevoNodo;
}

void imprimirLista(struct NodoLista ** lista) {
	struct NodoLista * inspector = (*lista);

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
