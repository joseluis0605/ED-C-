#include <stdio.h>
#include <string.h>
#include "TElemento.h"

void print (TElemento t){
    printf("%c ",t);
    
}

void asignar(TElemento* copia, TElemento original){
    *copia=original;
}

int igual(TElemento* uno, TElemento* dos){
    return  ((*uno)==(*dos));
}

void crear(char i, TElemento* e){
   *e=i;
}
int damePosicion (TElemento e) {
	return (int) (e-'a');
}
void dameElemento (int posicion, TElemento *e) {
	*e =  (char) (posicion+'a');
}
