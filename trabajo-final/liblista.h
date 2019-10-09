#ifndef LIBLISTA_H_
#define LIBLISTA_H_

	typedef struct {
		char *identificador;
		NodoIdentificador *sig = NULL;
	} NodoIdentificador;

	int agregarIdentificador(NodoIdentificador *, char *);
	int estaEnLista(NodoIdentificador *, char *);

#endif
