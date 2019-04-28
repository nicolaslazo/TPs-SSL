#include <stdio.h>

/*	Tabla de transicion:
 *			|	Num	+	*	(	)	Lambda
 *		---------------------------------------------------------------
 *		E	|	TF	-	-	TF	-	-
 *		F	|	-	TF	-	-	-	e
 *		T	|	FU	-	-	FU	-	-
 *		U	|	-	-	FU	-	-	e
 * 	 	P	|	N	-	-	E)	-	-
 *		N	|	e	-	-	-	-	-
 *		X	|	?	?	?	?	?	?
 *
 *	Gramatica:
 *		1. E -> TF
 *		2. F -> +TF
 *		3. F -> Lambda
 *		4. T -> FU
 *		5. U -> *FU
 *		6. U -> Lambda
 *		7. F -> (E)
 *		8. F -> N
 *		9. N -> { 1, 2, 3, 4, 5, 6, 7, 8, 9, 0 }
 */

struct Nodo {
	char valor;
	Nodo *sig = NULL;
}

enum estados {
	E,
	F,
	T,
	U,
	P,
	N
}

enum caracteres {
	NUMERO,
	MAS,
	POR,
	PARENTESIS1,
	PARENTESIS2,
	LAMBDA
}

int tablaDeTransicion[6][6] = { { 1, 0, 0, 1, 0, 0},
			      { 0, 2, 0, 0, 0, 3},
			      { 4, 0, 0, 4, 0, 0},
			      { 0, 0, 5, 0, 0, 6},
			      { 7, 0, 0, 8, 0, 0},
			      { 9, 0, 0, 0, 0, 0}
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
