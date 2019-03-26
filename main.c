#include <stdio.h>

int determinarCategoria(char charLeido) // Determina la categoria de cambio de estado.
{
	/* Tabla de outputs:
	 * 	0: {0}
	 * 	1: [1-7]
	 * 	2: [8-9]
	 * 	3: [A-F] U [a-f]
	 * 	4: {x, X}
	 * 	5: Otros
	 */

	// Les dije que quedaria mejor como un char, pero me di cuenta de que era agregar pasos al pedo. Ahora es un index en la tabla de transiciones.
	// Les diria que dejemos esa tabla en el comentario como documentacion del programa.

	/* Tip: se puede usar
	 * 	if ( charLeido >= 'a' && charLeido <= 'f' )
	 * Para verificar que esta en ese rango
	 */

	// TODO: Completar
}

void escribirResultado(int estado) //Funcion que va a devolver un archivo de texto, con la clasificacion de cada cadena de caracteres(separados por una coma)
{
	char stringAEscribir[40];

	switch (estado) // TODO: Asignarle a stringAEscribir el renglon que se tiene que escribir en el archivo
	{
	// Asumimos que estado 2 es hexadecimal
		case 2:
			stringAEscribir = numeroCompleto(concat)"\tHEXADECIMAL\n"
			break;	
	}

	// TODO: Hacer la parte de guardar en archivo
}

int main() 
{
	int estado = 0;
	int transiciones[6][7] = { 
		                   {2, 1, 1, 6, 6, 6},
				   {1, 1, 1, 6, 6, 6},
				   {4, 4, 6, 6, 3, 6},
				   {5, 5, 5, 5, 6, 6},
				   {4, 4, 6, 6, 6, 6},
				   {5, 5, 5, 5, 6, 6},
				   {6, 6, 6, 6, 6, 6}
				 };
	FILE* f = fopen( "ArchivoDeTexto.txt" , "r+b" ) //Abro y leo el archivo de texto

	char charLeido; //Guardo lo que leo del archivo de texto 

	fread ( &charLeido , sizeof(char) , 1 , f ) //Leo el primer caracter	

	while ( !feof(f) ) 
	{
		cout << charLeido << endl; //Muestro el caracter que lei 	
		

			if ( charLeido == ',' ) 
			{
			escribirResultado(estado);
			estado = 0;
			}
				else 
				{
				estado = transiciones[determinarCategoria(charLeido)][estado]; //Fila-Columna [estado][determinarCategoria(charLeido)] Corregir
				}
		fread ( &charLeido , sizeof(char) , 1 , f ) //Leo el siguiente caracter
	}
	fclose(f);
	return 0;
}
