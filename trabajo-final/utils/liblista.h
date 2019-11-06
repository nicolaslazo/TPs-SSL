#ifndef LIBLISTA_H_
#define LIBLISTA_H_

	struct s_NodoIdentificador {
		int tipo;
		char *identificador;
		struct s_NodoIdentificador *sig;
	};

	typedef struct s_NodoIdentificador NodoIdentificador;

	int registrarDeclaracion(NodoIdentificador *, int, char *);
	int identificadorEnLista(NodoIdentificador *, char *);
	int reportarVariable(NodoIdentificador *);

#endif
