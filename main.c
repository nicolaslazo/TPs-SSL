#include <stdio.h>

int determinarCategoria(char charLeido) {
	// Determina la categoria de cambio de estado.
	
	/* Tabla de outputs:
	 * 	0: {0}
	 * 	1: [1-7]
	 * 	2: [8-9]
	 * 	3: [A-Z] U [a-z]
	 * 	4: {x, X}
	 * 	5: Otros
	 */

	// Les dije que quedaria mejor como un char, pero me di cuenta de que era agregar pasos al pedo. Ahora es un index en la tabla de transiciones.
	// Les diria que dejemos esa tabla en el comentario como documentacion del programa.

	/* Tip: se puede usar
	 * 	if ( charLeido >= 'a' && charLeido <= 'z' )
	 * Para verificar que esta en ese rango
	 */

	// TODO: Completar
}

void escribirResultado(int estado) {
	// Llamada cuando la palabra termina. Escribe a output la palabra y su categoria
	
	char stringAEscribir[40];

	switch (estado) {
		// TODO: Asignarle a stringAEscribir el renglon que se tiene que escribir en el archivo
	}

	// TODO: Hacer la parte de guardar en archivo
}

int main() {
	int estado = 0;

	char charLeido;

	int transiciones[6][7] = { 
		                   {2, 1, 1, 6, 6, 6},
				   {1, 1, 1, 6, 6, 6},
				   {4, 4, 6, 6, 3, 6},
				   {5, 5, 5, 5, 6, 6},
				   {4, 4, 6, 6, 6, 6},
				   {5, 5, 5, 5, 6, 6},
				   {6, 6, 6, 6, 6, 6}
				 };

	while ( /* No se llega a EOF */ ) {
		// TODO: Hacer la lectura de char

		if ( charLeido == ',' ) {
			escribirResultado(estado);
			estado = 0;
		}
		else {
			estado = transiciones[determinarCategoria(charLeido)][estado];
		}
	}

	return 0;
}
