int acum = 0;
%%
{constDecimales}			        {acum= acum + atoi(yytext); printf("El valor acumulado es %d\n", acum);} o mejor {imprimirLista(&listaDecimales);}
{constOctales}				        {printf("La cadena %s representa una constante entera octal\n", yytext);} o mejor {imprimirLista(&listaOctales);}
{constHexadecimales}			    {printf("La cadena %s representa una constante entera hexadecimal\n", yytext);} o mejor {imprimirLista(&listaHexadecimales);}
{constReales}				          {printf("La cadena %s representa una constante real\n", yytext); o mejor {imprimirLista(&listaReales);}
{literalCadena}				        {printf("La cadena %s representa un literal cadena\n", yytext);} o mejor {imprimirLista(&listaLiteralesCadena);}
{palabrasReservadas}			    {printf("La cadena %s representa una palabra reservada\n", yytext);} o mejor {imprimirLista(&listaPalabrasReservadas);}
{identificadores}			        {printf("La cadena %s representa un identificador\n", yytext);} o mejor {imprimirLista(&listaIdentificadores);}
{caracteresDePuntuacion}		  o mejor {imprimirLista(&listaCaracteresDePuntuacion);}
{operadoresDeC}				        o mejor {imprimirLista(&listaOperadores);}
{comentarios}				          {printf("La cadena %s representa un comentario\n", yytext);}  o mejor {imprimirLista(&listaComentarios);}
.                             {imprimirLista(&listaOtros);}
%%                               
