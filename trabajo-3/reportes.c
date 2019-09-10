int acum = 0;
%%
{constDecimales}			        {acum= acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{constOctales}				        {printf("La cadena %s representa una constante entera octal\n", yytext);}
{constHexadecimales}			    {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);}
{constReales}				          {printf("La cadena %s representa una constante real\n", yytext);
                              int dec = octToDec(yytext);
{literalCadena}				        {printf("La cadena %s representa un literal cadena\n", yytext);}
{palabrasReservadas}			    {printf("La cadena %s representa una palabra reservada\n", yytext);}
{identificadores}			        {printf("La cadena %s representa un identificador\n", yytext);}
{caracteresDePuntuacion}		
{operadoresDeC}				
{comentarios}				          {printf("La cadena %s representa un comentario\n", yytext);} 

%%                               
int octToDec(char oct[]){
    int i=0,dec=0;
    for(i,oct[i]!='\0',i++);
    for(j=0,oct[j]!='\0',j++){
        dec += oct[j] * pow(10,i);
        i--;
    }
    return dec;
struct listadoDeIdentificadores{ //cant de veces q aparecen listaId
  char* nombreIdentificador;
  int aparicionesIdentificador;
};
  
struct listadoDeLiteralesCadena{ //longitud d los mismos listaLiteralesCadena
  char* nombreCadena;
  int longitudCadena;
};
  
struct listadoDePalabrasReservadas{ // listaPalabrasReservadas
  char* nombrePalabrasReservadas;
};

struct listadoDeConstantesOctales{ //valor entero decimal listaOctales
  char* constanteOctal;
};
  
struct listadoDeConstantesHexadecimales{ //valor entero decimal listaHexadecimales
  char* constanteHexadecimal;
};
  
struct listadoDeConstantesDecimales{ //valor acumulado listaDecimales
  char* constantesDecimales;
};
  
struct listadoDeConstantesReales{ //valor de mantisa y parte entera listaReales
  char* constantesReales;
};
  
struct listadoDeCaracteresDePuntuacion{ //cant de veces q aparecen listaCaracteresDePuntuacion
  char* caracterDePuntuacion;
  int aparicionesCaracterDePuntuacion;
};
  
struct listadoDeOperadores{ //cant de veces q aparecen listaOperadores
  char* operadores;
  int aparicionesOperadores;
};
  
struct listadoDeComentariosReconocidos{ //listaComentarios
  char* comentarioReconocido;
};
  
struct listadoDeCadenasNoReconocidas{
  char* cadenaNoReconocidas;
};
