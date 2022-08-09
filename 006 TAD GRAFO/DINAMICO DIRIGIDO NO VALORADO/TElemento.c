#include <stdio.h>
#include <string.h>
#include "TElemento.h"


void print (TElemento t){
    printf(" %d ",t);
}

void asignar(TElemento* copia, TElemento original){
    *copia=original;
}

int igual(TElemento* uno, TElemento* dos){
    return (*uno)==(*dos);
}

void crear(int i, TElemento* e){
    (*e)=i;
} 
int esMayor(TElemento* lhs, TElemento* rhs){
    return (*lhs)>(*rhs);
}
