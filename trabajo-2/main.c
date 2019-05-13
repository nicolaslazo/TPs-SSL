#include <stdio.h>
#include <stdlib.h>
#define Simbolo Int
#define vuelveABUSCAR -1


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
     //
}

//Simbolo peek(/* ??? */) {
	// TODO: Esta funcion deberia leer el caracter de la string input
	// que estamos procesando y guardarlo en la variable char caracter

	//return determinarSimbolo(caracter)
}

enum simbolo {E1,E2,T1,T2,F1,N,NUMERO,MAS,POR,PARENTESIS1,PARENTESIS2}

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
		    {if (lectura==' ' || lectura == '\n' || lectura == '\t')
		         return vuelveABUSCAR;
			else reportarError("Input invalido");
		    }
	}
}

void ejecutarTransicion(/* caracter de String input? */, NodoPila*& pila) {
    enum simbolo simboloActual;
	bool buscaSiguiente; //es true al principio o cuando se hace un pop de la pila (más adelante)

	if (pila.simbolo = Null)
     {
       buscaSiguiente=true;
	   push(E1, pila); // carga el axioma
     }

	simboloActual = pop(pila);

	if (buscaSiguiente)
    //Simbolo sigSimbolo = peek(/* caracter de String input */);
     Simbolo sigSimbolo = determinarSimbolo(charInput[&i])

     if (sigSimbolo != vuelveABUSCAR){ // pregunta si es espacio en blanco, si no vuelve a buscar

	switch (simboloActual) {
		case E1 // así o el numero asociado enum?
        {
			if (sigSimbolo == NUMERO || sigSimbolo == PARENTESIS1) {
                push(E2, pila);
				push(T1, pila);
				buscaSiguiente=false;
			}
			else {
				/* reportarError("Input inválido")?*/
			}
        }
			break;
        case T1
        {
			if (sigSimbolo == NUMERO || sigSimbolo == PARENTESIS1) {
                push(T2, pila);
				push(F1, pila);
				buscaSiguiente=false;
			}
			else {
				/* reportarError("Input inválido")? */
			}
        }
			break;

        case F1
        {
			if (sigSimbolo == NUMERO)
                push(N, pila);
            if (sigSimbolo == PARENTESIS1)
                {push (PARENTESIS2, pila);
                push (E1, pila);
				buscaSiguiente=false;
                }
        }
			else {
				/* reportarError("Input inválido")? */
			}
			break;

	     case N
        {
			if (sigSimbolo == NUMERO)
                pop(pila);
                &i++;

			else {
				/* reportarError("Input inválido")? */
			}
        }
			break;
			case T2
        {
			if (sigSimbolo == MAS){
                push (T2, pila);
                push (F1, pila);
			     }
			else {
				pop (pila);
				&i++;
			     }
        }
        break;
        case E2
        {
			if (sigSimbolo == POR){
                push (E2, pila);
                push (T1, pila);
			     }
			else {
				pop (pila);
				&i++;
			     }
        }
        break;
        default: /*reportarError("Input inválido")*/

	   }
     }
     else {
        buscaSiguiente = true;
        &i++;
     }
}

////	ACA EMPIEZA LA SECCION DE EZE, SOL Y VICTORIA

int main() {

char charInput[longitudInput];

	do {
		ejecutarTransicion(/* charInput[&i] ? */);
	} while (/* &i<longitudInput*/);

	return 0;
}
