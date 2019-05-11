#include <stdio.h>
#include <stdlib.h>

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

Simbolo pop(NodoPila*& pila) { // acá devolvería un string (ej: T1)?
}

Simbolo peek(/* ??? */) {
	// TODO: Esta funcion deberia leer el caracter de la string input
	// que estamos procesando y guardarlo en la variable char caracter

	return determinarSimbolo(caracter)
}

enum simbolo {
	E1=1,       // NoTerminales
	E2=2,
	T1=3,
	T2=4,
	F1=5,
    N=6
	NUMERO=7, //Terminales
	MAS=8,
	POR=9,
	PARENTESIS1=10,
	PARENTESIS2=11
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
		default:
			reportarError("Input invalido");
	}
}

void ejecutarTransicion(/* String de input? */, NodoPila*& pila) {
    enum simbolo simboloActual;
	bool buscaSiguiente = true; //es true al principio y cuando se hace un pop de la pila
	Simbolo simboloActual = pop(pila);

	if (buscaSiguiente)
	Simbolo sigSimbolo = peek(/* input? */);

	switch ( simboloActual ) {
		case 1: //E1
        {
			if (sigSimbolo == NUMERO || sigSimbolo == PARENTESIS1) {
                push(E2, pila);
				push(T1, pila);
				buscaSiguiente=false;
			}
			else {
				/* deberia cortar??? */
			}
        case 3: // T1
        {
			if (sigSimbolo == NUMERO || sigSimbolo == PARENTESIS1) {
                push(T2, pila);
				push(F1, pila);
				buscaSiguiente=false;
			}
			else {
				/* ??? */
			}
			break;
		default:
			/* ??? */
	    }
			break;
    case 5: //F1
        {
			if (sigSimbolo == NUMERO)
                push(N, pila);
            if (sigSimbolo == PARENTESIS1)
                push (PARENTESIS2, pila);
                push (E1, pila);
				buscaSiguiente=false;
        }
			else {
				/* ??? */
			}
			break;
		default:
			/* ??? */
	    }
		default:
			/* ??? */
	    }

}

////	ACA EMPIEZA LA SECCION DE EZE, SOL Y VICTORIA

int main() {
	do {
		ejecutarTransicion(/* ??? */);
	} while (/* No se llega a EOF*/);

	return 0;
}
