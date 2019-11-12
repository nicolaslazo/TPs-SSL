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

typedef struct NodoPila{
   int simboloNodo;
   struct NodoPila *sig;
} pila ;

//typedef struct NodoPila Stack;
//typedef Stack *sig;
//typedef Stack *pila;

char error [30];

int reportarError (error){
    printf("%s", error);
    return 1; };

void push (int valor, pila *top){
    pila* nuevo;
    nuevo = (pila*) malloc(sizeof(pila));

     if(nuevo != NULL)
       {
       nuevo -> simboloNodo = valor;
       nuevo -> sig = top;
       top = nuevo;
       }

    else
       {printf("\nERROR !!! (Not enough space)");
   }
};

int pop(pila *top)
{
   int v; //variable for value at the top
   pila* tempPtr; //temporary pointer

   tempPtr = top;
   v = top -> simboloNodo;
    top = top -> sig;
   free(tempPtr); //free temporary pointer value
   return v;

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

int ejecutarTransicion (pila *top, char lectura){

      int simboloActual = pop(top);

      switch (simboloActual)
      {
         case E1:
            if (lectura == NUMERO || lectura == PARENTESIS1)
               {
               push(E2, top);
               push(T1, top);
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
               push(E2, top);
               push(T1, top);
             }
            return 1;
            break;
            case T1:
               if (lectura == NUMERO || lectura == PARENTESIS1)
               {
                  push(T2, top);
                  push(F1, top);
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
               push(T2, top);
               push(F1, top);
            }
            return 1;
            break;
            case F1:
               if (lectura == NUMERO)
                 {
                  push(N, top);
                  return 0;
                 }
               else if (lectura == PARENTESIS1)
                  {
                     push (PARENTESIS2, top);
                     push (E1, top);
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
                     push (N, top);
                     push (D, top);
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
    char input[30] = {0};
    int index= 0;
    //typedef Stack *pila;
   // NodoPila* pila;
    pila * top;
    top=NULL;

   printf("Ingrese calculo > ");
   scanf("%s", &input);

   push (E1,top); // Seteo inicial de pila
   int huboMatch = 1;

    while (top != NULL)
    {
      if (huboMatch)
      {
        int nuevaLectura = determinarSimbolo(input[index]);

        huboMatch = ejecutarTransicion (top, nuevaLectura);

      } // devuelve 1 o 0

        if (huboMatch == 1)
        {
            index ++;
        }
        else if (huboMatch==-1)
        {
           exit(0);
        }
        else{
        int nuevaLectura = determinarSimbolo(input[index]);
            huboMatch = ejecutarTransicion(top, nuevaLectura);
           }
    return 0;
    }
 };

