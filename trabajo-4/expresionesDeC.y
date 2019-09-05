[0-9]+(\.[0-9]+)?	{return CONSTANTE;}
//ACA FALTARIA DEFINIR LA ERX DE LOS DEMAS

"&&"	{return AND;}
"||"	{return OR;}
"<="	{return MENORIGUAL;}
">="	{return MAYORIGUAL;}
"=="	{return "IGUALDAD";}
"!="  {return "DESIGUALDAD;}
