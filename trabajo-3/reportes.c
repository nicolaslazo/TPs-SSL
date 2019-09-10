{constDecimales}			agregarAListaInts(atoi(yytext), listaDecimales);
{constOctales}				agregarAListaInts(atoi(yytext), listaOctales);
{constHexadecimales}			agregarAListaInts(atof(yytext), listaHexadecimales);
{constReales}				agregarAListaFloats(atof(yytext), listaReales);
{literalCadena}				agregarAListaSimple(yytext, listaLiteralesCadena);
{palabrasReservadas}			agregarAListaSimple(yytext, listaPalabrasReservadas);
{identificadores}			agregarAListaConCant(yytext, listaIdentificadores);
{caracteresDePuntuacion}		agregarAListaConCant(yytext, listaCaracteresDePuntuacion);
{operadoresDeC}				agregarAListaConCant(yytext, listaOperadores);
{comentarios}				agregarAListaSimple(yytext, listaComentarios);
.	
