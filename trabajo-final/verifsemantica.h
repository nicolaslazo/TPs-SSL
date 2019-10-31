#ifndef VERIFSEMANTICA_H_
#define VERIFSEMANTICA_H_

typedef enum {
	NUM,
	ERROR
} StatusSemantico;

int verifTiposValidos(StatusSemantico, StatusSemantico);

#endif
