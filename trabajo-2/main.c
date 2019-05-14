#include <stdio.h>

#define Simbolo Int
//	TODO: Averiguar si hacer este tipo de alias es buena practica

/*	Tabla de transicion:
 *			|	Num	+	*	(	)	Lambda
 *		---------------------------------------------------------------
 *		E	|	T1E2	-	-	T1E2	-	-
 *		F	|	-	T1E2	-	-	-	e
 *		T	|	F1T2	-	-	F1T2	-	-
 *		U	|	-	-	F1T2	-	-	e
 * 	 	P	|	N	-	-	E1)	-	-
 *		N	|	e	-	-	-	-	-
 *		X	|	?	?	?	?	?	?
 *
 *	Axiomas:
 *		1. E -> T
 *		2. E -> E+T
 *		3. T -> F
 *		4. T -> T*F
 *		5. F -> N
 *		6. F -> (E)
 *		7. N -> DN
 *		8. N -> D
 *		9. D -> [0-9]
 */

//	TODO: Funcion reportarError que imprime un mensaje en pantalla y sale con codigo de salida 1

////	ACA EMPIEZA LA SECCION DE ALFRED Y NICO

struct NodoPila {
	Simbolo simbolo;
	NodoPila * sig = NULL;
};

void push(Categoria categoria, NodoPila*& pila) {
	struct NodoPila nuevoNodo;

	nuevoNodo.categoria = valor;

	nuevoNodo.sig = pila;
	pila = &nuevoNodo;
}

Simbolo pop(NodoPila*& pila) {
}

Simbolo peek(NodoPila*& pila) { return pila.simbolo; }

enum simbolos {
	// No terminales
	E1,
	E2,
	T1,
	T2,
	F1,
	N,

	// Terminales
	NUMERO,
	MAS,
	POR,
	PARENTESIS1,
	PARENTESIS2,

	// Simbolos especiales
	FONDODEPILA,
	ESPACIO
}

Simbolo determinarSimbolo(char lectura) {
	switch ( lectura ) {
		case '0':
		case '1':
		case '2':
		case '3':
		case '4':
		case '5':
		case '6':
		case '7':
		case '8':
		case '9':
			return NUMERO;
		case '+':
			return MAS;
		case '*':
			return POR;
		case '(':
			return PARENTESIS1;
		case ')':
			return PARENTESIS2;
		case ' ':
			return ESPACIO;
		default:
			reportarError("Input invalido");
	}
}

int ejecutarTransicion(NodoPila*& pila) {
	// Tiene que devolver 1 cuando un terminal y un no terminal matchean, sino 0
	Simbolo simboloActual = pop(pila);
	Simbolo sigSimbolo = peek(pila);

	switch ( simboloActual ) {
		case E1:
			if (sigSimbolo == NUMERO || sigSimbolo == PARENTESIS1) {
				push(T1, pila);
				push(E2, pila);
			}
			else {
				/* ??? */
			}
			break;
		default:
			/* ??? */
	}
}

////	ACA EMPIEZA LA SECCION DE EZE, SOL Y VICTORIA

int main() {
	char * input[30] = {0};

	printf("Ingrese calculo > ");
	scanf("%s", &input);

	// Seteo inicial de pila
	push(E1);

	for (int index = 0; index != NULL; index++) {
		Simbolo nuevaLectura = determinarSimbolo(input[index]);

		if ( peek(pila) == NUMERO && nuevaLectura == NUMERO || nuevaLectura == ESPACIO) continue;

		push(nuevaLectura);

		int huboMatch = 0;

		do { huboMatch = ejecutarTransicion(pila); } while (huboMatch != 1);
	}

	return 0;
}
