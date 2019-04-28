#include <stdio.h>
#include <string.h>

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


void escribirResultado(int estado, char stringAEscribir[]) //Funcion que va a devolver un archivo de texto, con la clasificacion de cada cadena de caracteres(separados por una coma)
{
	FILE* g = fopen("output.txt","a+");
	switch (estado) // TODO: Asignarle a stringAEscribir el renglon que se tiene que escribir en el archivo
	{
	//estado 1 : DECIMAL
		case 1:
		    strcat(stringAEscribir, "\t DECIMAL \n");
		    fprintf(g,stringAEscribir);
			break;

	// estado 2 y 4: OCTAL
		case 2: case 4:
		    strcat(stringAEscribir, "\t OCTAL \n");
		    fprintf(g,stringAEscribir);
		break;

	//estado 3 y 5 : HEXADECIMAL
		case 3: case 5 :
		    strcat(stringAEscribir, "\t HEXADECIMAL \n");
		    fprintf(g,stringAEscribir);
		break;

	// estado 6 : NO RECONOCIDO
		case 6 :
		    strcat(stringAEscribir, "\t NO RECONOCIDO \n");
		    fprintf(g,stringAEscribir);
		break;
	}
	fclose(g);
    return;
}

int main()
{
    FILE* f = fopen( "input.txt" , "r+" ); //Abro y leo el archivo de texto
    char charLeido; //Guardo lo que leo del archivo de texto
    char palabraGuardada [50];
	  int estado = 0, i = 0;
	  int transiciones[7][6] = 
        {
                   {2, 1, 1, 6, 6, 6},
                   {1, 1, 1, 6, 6, 6},
				           {4, 4, 6, 6, 3, 6},
				           {5, 5, 5, 5, 6, 6},
				           {4, 4, 6, 6, 6, 6},
				           {5, 5, 5, 5, 6, 6},
				           {6, 6, 6, 6, 6, 6}
				 };
  
    memset(palabraGuardada,'\0',50); //Me aseguro que dentro del array palabraGuardada no haya basura

	while ( !feof(f) )
	{
      charLeido = getc(f); //Leo un char del archivo input.txt

			if ( charLeido == ',' || feof(f))
			{
			  escribirResultado(estado,palabraGuardada);
			  memset(palabraGuardada,'\0',50);
        i = 0;
			  estado = 0;
			}
				else
				{
				  estado = transiciones[estado][determinarColumna(charLeido, estado)];
				  palabraGuardada[i] = charLeido;
				  i++;
				}
	}
	fclose(f);
	return 0;
}
