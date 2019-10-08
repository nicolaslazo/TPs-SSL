[0-9]+(\.[0-9]+)?	{return CONSTANTE;}
[1-9][0-9]*       {return CONSTANTEDECIMAL;}
0[0-7]*           {return CONSTANTEOCTAL;}
0[xX][0-9a-fA-F]+ {return CONSTANTEHEXADECIMAL;}
[0-9]*\.[0-9]+([eE][\+\-]?[0-9]+)?|[0-9]+\.([eE][\+\-]?[0-9]+)?|[0-9]([eE][\+\-]?[0-9]+)? {return CONSTANTEREAL:} 
'[ -~]'|'\\[abefnrtv\\\'\"\?]' {return CONSTANTECARACTER;}
\"[ -~]*\"        {return LITERALCADENA;}
auto|break|case|char|const|continue|default|do|double|else|enum|extern|float|for|goto|if|int|long|register|return|short|signed|sizeof|static|struct|switch|typedef|union|unsigned|void|volatile|while {return PALABRARESERVADA;} 
[_a-zA-Z][_a-zA-Z0-9]* {return IDENTIFICADORES;}
[,\.;:\?\(\)\[\]\{\}]  {return CARACTERDEPUNTUACION;}
[=!&\*\+\-/|%><\?]     {return OPERADORDEC;}
\/\/(.)*           {return COMENTARIOS;}

//ACA FALTARIA DEFINIR LA ERX DE LOS DEMAS

"="   {return ASIGNACION;}
"||"	{return OR;}
"&&"	{return AND;}
"=="	{return IGUALDAD;}
">="	{return MAYORIGUAL;}
"<="	{return MENORIGUAL;}
"!="  {return "DESIGUALDAD;}
//operadores unarios no van!!!!




/*ver lineas 16 y 17,24 ver si estan bien*/
