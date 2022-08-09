#include <stdio.h>
#include <string.h>
#include "TElemento.h"

void print (TElemento t){
    printf("\nNombre: %s\n",t.nombre);
    printf("Dni: %s\n",t.dni);
    printf("Nota media: %f\n",t.notaMedia);
}

void asignar(TElemento* copia, TElemento original){
    strcpy((*copia).dni,original.dni);
    strcpy((*copia).nombre,original.nombre);
    (*copia).notaMedia=original.notaMedia;
}

int igual(TElemento* uno, TElemento* dos){
    return  ( (strcmp((*uno).dni,dos->dni)==0)&&(strcmp((*uno).nombre,dos->nombre)==0)&&((*uno).notaMedia==dos->notaMedia));
}

void crear(char* n, char* d, float nt, TElemento* e){
    strcpy(e->nombre,n);
    strcpy(e->dni,d);
    e->notaMedia=nt;
}

int esMayor(TElemento lhs, TElemento rhs){
    return (lhs.notaMedia)>(rhs.notaMedia);
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