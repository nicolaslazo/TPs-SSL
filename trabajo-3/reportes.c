{constDecimales}			        {acum= acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);}
{constOctales}				        {printf("La cadena %s representa una constante entera octal\n", yytext);}
{constHexadecimales}			    {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);}
{constReales}				          {printf("La cadena %s representa una constante real\n", yytext);}
{literalCadena}				
{palabrasReservadas}			    {printf("La cadena %s representa una palabra reservada\n", yytext);}
{identificadores}			        {printf("La cadena %s representa un identificador\n", yytext);}
{caracteresDePuntuacion}		
{operadoresDeC}				
{comentarios}				
.	
int listadoDeIdentificadores //cant de veces q aparecen listaId

int listadoDeLiteralesCadena //longitud d los mismos listaLiteralesCadena

struct listadoDePalabrasReservadas // listaPalabrasReservadAS

int listadoDeConstantesOctales //valor entero decimal listaOctales

int listadoDeConstantesHexadecimales //valor entero decimal listaHexadecimales

float listadoDeConstantesDecimales //valor acumulado listaDecimales

float listadoDeConstantesReales //valor de mantisa y parte entera listaReales

int listadoDeCaracteresDePuntuacion //cant de veces q aparecen listaCaracteresDePuntuacion

int listadoDeOperadores //cant de veces q aparecen listaOperadores

listadoDeComentarios //listaComentarios

listadoDeCadenasNoReconocidas
