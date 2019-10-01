[0-9]+(\.[0-9]+)?	{return CONSTANTE;}
//ACA FALTARIA DEFINIR LA ERX DE LOS DEMAS

"="   {return ASIGNACION;}
"+="  {return ASIGNACION;}
"||"	{return OR;}
"&&"	{return AND;}
"=="	{return IGUALDAD;}
">="	{return MAYORIGUAL;}
"<="	{return MENORIGUAL;}
"!="  {return "DESIGUALDAD;}
"++"  {return "";}




/*ver lineas 4 y 5, ver si estan bien*/
