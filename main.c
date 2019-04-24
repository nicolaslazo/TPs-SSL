#include <stdio.h>

/*	Tabla de transicion:
 *			|	Num	+	*	(	)	Lambda
 *		----------------------------------------------------------------
 *		E	|	TF	-	-	TF	-	-
 *		F	|	-	TF	-	-	-	e
 *		T	|	FU	-	-	FU	-	-
 *		U	|	-	-	FU	-	-	e
 *		F	|	N	-	-	E)	-	-
 *		N	|	e	-	-	-	-	-
 *		X	|	?	?	?	?	?	?
 */

struct Nodo {
	char valor;
	Nodo *sig = NULL;
}

enum simbolos {
	// Herramienta a tener en cuenta, estaria excelente si leen del tema
}

char leerCaracter(); // Esto no tiene que ser una funcion necesariamente, es una abstraccion

int main() {
	Nodo * cola = new Nodo;
	cola->valor = '$';

	char caracterLeido;
	
	do {
		caracterLeido = leerCaracter();


	} while (cola->valor != '$')

	return 0;
}
