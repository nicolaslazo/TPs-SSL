#include <stdlib.h>
#include <stdio.h>
/* Tabla de transicion:
 *       |  Num   +  *   (      )   Lambda
 *    ---------------------------------------------------------------
 *    E1 |  T1E2- -  T1E2  -  -
 *    E2 |  -  T1E2   -    -     e
 *    T1 |  F1T2  -   F1T2 -  -
 *    T2 |  -  -  F1T2 -       - e
 *       F1 |  N  -  -   E1)  -   -
 *    N  |  DN -  -   -    -   e
 *    D  |  e  -   -    -      -   -
        )   |   -   -   -    -      e   --
 *
 *    Axiomas:
 *    1. E1 -> T1E2
 *    2. E2 -> +T1E2
 *      3. E2 -> e
 *    3. T1 -> F1T1
 *    4. T2 -> *F1T2
 *      5. T2 -> e
 *    6. F1 -> (E1)
 *      7. F1 -> N
 *    8. N -> DN
 *    9. N -> D
 *    10. D -> [0-9]
 */

struct NodoPila{
   int simboloNodo;
   NodoPila *sig;
};

char error [30];

int reportarError (error){
    printf("%s", error);
    return 1; }

void push (int valor, NodoPila*& pila){
    NodoPila* nuevo = new NodoPila();
   (*nuevo).simboloNodo = valor;
    (*nuevo).sig = NULL;

    if (pila== NULL)
    {
     pila = nuevo;
    }
     else
        {
          (*nuevo).sig=pila;
          pila = nuevo;
        }
};

int pop(NodoPila*& pila)
{
    int cimaPila = (*pila).simboloNodo;
    NodoPila aux = (*pila).sig;
    delete pila;
    pila = aux;
    return cimaPila;
};

enum simbolos {
   // No terminales
   E1,
   E2,
   T1,
   T2,
   F1,
   N,
   D,

   // Terminales
   NUMERO,
   MAS,
   POR,
   PARENTESIS1,
   PARENTESIS2,

   // Simbolos especiales
   FONDODEPILA,
   ESPACIO
};

char determinarSimbolo(char lectura){
   switch ( lectura )
   {
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
};

int ejecutarTransicion (NodoPila*& pila, char lectura){

      int simboloActual = pop(pila);

      switch (simboloActual)
      {
         case E1:
            if (lectura == NUMERO || lectura == PARENTESIS1)
               {
               push(E2, pila);
               push(T1, pila);
               return 0;
               }
            else
               {
            reportarError("Input invalido");
               }
         break;
         case E2:
            if (lectura == MAS)
             {
               push(E2, pila);
               push(T1, pila);
             }
            return 1;
            break;
            case T1:
               if (lectura == NUMERO || lectura == PARENTESIS1)
               {
                  push(T2, pila);
                  push(F1, pila);
                  return 0;
               }
               else
                  {
                     reportarError("Input invalido");
                  }
           break;
           case T2:
            if (lectura == POR)
            {
               push(T2, pila);
               push(F1, pila);
            }
            return 1;
            break;
            case F1:
               if (lectura == NUMERO)
                 {
                  push(N, pila);
                  return 0;
                 }
               else if (lectura == PARENTESIS1)
                  {
                     push (PARENTESIS2, pila);
                     push (E1, pila);
                     return 1;
                  }
               else
               {
                  reportarError("Input invalido");
               }
            break;
            case N:
               if (lectura == NUMERO)
                  {
                     push (N, pila);
                     push (D, pila);
                     return 0;
                  }
           break;
           case D:
            if (lectura == NUMERO)
            {
               return 1;
            }
            else
            {
               reportarError("Input invalido");
            }
         break;
         case PARENTESIS2:
            if (lectura == PARENTESIS2)
               {
                  return 1;
               }
            else
               {
                  reportarError("Input invalido");
               }
         break;
         default:
         reportarError("Simbolo desconocido en la pila");
   }
};

int main(){
    char * input[30] = {0};
    int index= 0;
    NodoPila* pila= NULL;

   printf("Ingrese calculo > ");

   scanf("%s", &input);

   push (E1,&pila); // Seteo inicial de pila
   int huboMatch = 1;

    while (&pila != NULL)
    {
      if (huboMatch)
      {
        int nuevaLectura = determinarSimbolo(input[index]);

        huboMatch = ejecutarTransicion (pila, nuevaLectura);

      } // devuelve 1 o 0

        if (huboMatch == 1)
        {
            index ++;
        }
        else if
        {
            (huboMatch==-1)
        }
        else huboMatch = ejecutarTransicion(pila,nuevaLectura);
    }
    return 0;
};
