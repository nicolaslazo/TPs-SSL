#include <stdio.h>

int determinarColumna(char charLeido, int estado) // Determina la columna de cambio de estado.
{
    switch (estado){ // "estado" seria la fila

case 0: if (charLeido=='0') //case 0 es el caso de fila 1
            return 0; // te dice de ir a la columna 1, unica posibilidad. OJO: el indice del array es 0 pero es columna 1
        if (charLeido>='1' && charLeido<='9')
            return 1; //aca puede ser la columna 2 o 3, pero lo simplifico en columna 2
         else return 3; //acá puede ser la columna 4, 5 o 6, pero simplifico en columna 4
         break;
case 1:  if (charLeido>='0' && charLeido<='9')
         return 0; // aca puede ser columna 1,2 o 3
         else return 3; // pueden ser 4, 5 o 6
         break;
case 2:  if (charLeido>='0' && charLeido<='7')
         return 0; //1 o 2
         if (charLeido=='x' || charLeido=='X')
            return 4; // columna 5, unica posibilidad
         else return 2; // 3, 4 o 6
         break;
case 3: if (charLeido>='0' && charLeido<='9' || charLeido >= 'a' && charLeido <= 'f' || charLeido >= 'A' && charLeido <= 'F')
        return 0; // columnas 1, 2, 3 o 4
        else return 4; // columna 5 o 6
        break;
case 4: if (charLeido>='0' && charLeido <='7')
        return 0;
        else return 2;
        break;
case 5: if (charLeido>='0' && charLeido<='9' || charLeido >= 'a' && charLeido <= 'f' || charLeido >= 'A' && charLeido <= 'F')
        return 0;
        else return 4;
        break;
case 6: return 0;
break;
    }
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
	int transiciones[7][6] = { 
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
				estado = transiciones[estado][determinarColumna(charLeido, estado)];
				}
		fread ( &charLeido , sizeof(char) , 1 , f ) //Leo el siguiente caracter
	}
	fclose(f);
	return 0;
}
