#include <stdio.h>

char determinarCategoria(char charLeido) {
	// Determina la categoria de cambio de estado.
	
	/* Tabla de outputs:
	 * 	'0': {0}
	 * 	'7': [0-7]
	 * 	'9': [8-9]
	 * 	'x': {x, X}
	 * 	'z': [A-Z] U [a-z]
	 */

	// Les diria que dejemos esa tabla en el comentario como documentacion del programa, es mas facil para mostrarle al profe

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
		
	}

	// TODO: Completar
}

int main() {
	unsigned int estado = 0;

	// TODO: Hacer lectura de archivo
	// TODO: Hacer la tabla de transicion
	// TODO: Crear el main loop


	return 0;
}
