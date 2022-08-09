#include <stdio.h>
#include <string.h>
#include "TElemento.h"

void print (TElemento t){
    printf("%d ",t);
  
}

void asignar(TElemento* copia, TElemento original){
    *copia = original;
}

int igual(TElemento uno, TElemento dos){
    return uno==dos;
}

void crear(int n, TElemento* e){
    *e = n;
}

int esMayor (TElemento a, TElemento b){
    return a>b;
}

/*


void print (TElemento t){
    printf("%f",t);
}

void asignar(TElemento* copia, TElemento original){
    *copia=original;
}

void igual(TElemento* uno, TElemento* dos){
    return (*uno)==(*dos);
}

void crear(float f, TElemento* e){
    (*e)=f;
} */