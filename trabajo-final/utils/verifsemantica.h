#ifndef VERIFSEMANTICA_H_
#define VERIFSEMANTICA_H_

typedef enum {
	NUM,
	ERROR
} TipoSemantico;

typedef enum {
	TIPOCHAR,
	TIPODOUBLE,
	TIPOFLOAT,
	TIPOINT,
	TIPOLONG,
	TIPOSHORT
} TipoVariable;

int verifTiposValidos(TipoSemantico, TipoSemantico);

#endif
